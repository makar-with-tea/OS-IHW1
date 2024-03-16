#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const ssize_t buf_size = 128;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Not enough arguments!\nExpected format: 'input.txt output.txt'\n");
    exit(-1);
  }
  if (argc > 3) {
    printf("Too many arguments!\nExpected format: 'input.txt output.txt'\n");
    exit(-1);
  }
  const char *inputFile = argv[1];
  const char *outputFile = argv[2];
  char name1[] = "9/fd1.fifo";
  char name2[] = "9/fd2.fifo";
  int fd, fd1, fd2, result;
  ssize_t size;
  char buf[buf_size];

  /* Delete old fifo channels */
  if (access(name1, F_OK) == 0) {
    if (unlink(name1) < 0) {
      printf("process1: Can\'t delete old FIFO1");
      exit(-1);
    }
  }
  if (access(name2, F_OK) == 0) {
    if (unlink(name2) < 0) {
      printf("process1: Can\'t delete old FIFO1");
      exit(-1);
    }
  }

  /* Open fifo channels */
  mknod(name1, S_IFIFO | 0666, 0);
  mknod(name2, S_IFIFO | 0666, 0);

  /* Open input file for reading and fifo1 for writing */
  if ((fd = open(inputFile, O_RDONLY)) < 0) {
    printf("process1: Can\'t open input file\n");
    exit(-1);
  }
  if ((fd1 = open(name1, O_WRONLY)) < 0) {
    printf("process1: Can\'t open FIFO1 for writting\n");
    exit(-1);
  }

  /* Read data from input file and write it to fifo1 */
  do {
    size = read(fd, buf, buf_size);
    if (size == -1) {
      printf("process1: Can\'t read from input file\n");
      exit(-1);
    }
    size = write(fd1, buf, size);
    if (size == -1) {
      printf("process1: Can\'t write to FIFO1\n");
      exit(-1);
    }
  } while (buf_size == size);

  /* Close input file and fifo1 */
  if (close(fd) < 0) {
    printf("process1: Can\'t close input file\n");
    exit(-1);
  }
  if (close(fd1) < 0) {
    printf("process1: Can\'t close FIFO1\n");
    exit(-1);
  }

  /* Clear buffer */

  /* Open output file for writing and fifo2 for reading */
  if ((fd = open(outputFile, O_WRONLY)) < 0) {
    printf("process1: Can\'t open output file\n");
    exit(-1);
  }
  if ((fd2 = open(name2, O_RDONLY)) < 0) {
    printf("process1: Can\'t open FIFO2 for reading\n");
    exit(-1);
  }

  /* Read data from fifo2 and write it to output file */
  do {
    memset(buf, 0, buf_size);
    size = read(fd2, buf, buf_size);
    if (size == -1) {
      printf("process1: Can\'t read from FIFO2\n");
      exit(-1);
    }
    
    size = write(fd, buf, size);
    if (size == -1) {
      printf("process1: Can\'t write to output file\n");
      exit(-1);
    }
  } while (buf_size == size);

  /* Close output file and fifo2 */
  if (close(fd) < 0) {
    printf("process1: Can\'t close output file\n");
    exit(-1);
  }
  if (close(fd2) < 0) {
    printf("process1: Can\'t close FIFO2\n");
    exit(-1);
  }

  return 0;
}
