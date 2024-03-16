#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const ssize_t buf_size = 5000;

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
  char name1[] = "8/fd1.fifo";
  char name2[] = "8/fd2.fifo";
  int fd, result;
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

  /* Open input file */
  if ((fd = open(inputFile, O_RDONLY)) < 0) {
    printf("process1: Can\'t open input file\n");
    exit(-1);
  }

  /* Read from input file and close it*/
  size = read(fd, buf, buf_size);
  if (size == -1) {
    printf("process1: Can\'t read from input file\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("process1: Can\'t close input file\n");
    exit(-1);
  }

  /* Write to fifo1 and close it*/
  if ((fd = open(name1, O_WRONLY)) < 0) {
    printf("process1: Can\'t open FIFO1 for writting\n");
    exit(-1);
  }
  if (write(fd, buf, size) < 0) {
    printf("process1: Can\'t write to FIFO1\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("process1: Can\'t close FIFO1\n");
    exit(-1);
  }
  /* Read data from fifo2 and close it*/
  if ((fd = open(name2, O_RDONLY)) < 0) {
    printf("process1: Can\'t open FIFO2 for reading\n");
    exit(-1);
  }
  size = read(fd, buf, buf_size);
  if (size < 0) {
    printf("process1: Can\'t read from FIFO2\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("process1: Can\'t close FIFO2\n");
    exit(-1);
  }

  /* Open output file */
    if ((fd = open(outputFile, O_WRONLY | O_CREAT | O_TRUNC, 0600)) < 0) {
    printf("process1: Can\'t open output file\n");
    exit(-1);
  }

  /* Write to output file and close it*/
  if (write(fd, buf, size) == -1) {
    printf("process1: Can\'t write to output file\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("process1: Can\'t close output file\n");
    exit(-1);
  }
  printf("process1 finished.\n");
  return 0;
}