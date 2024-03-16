#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

const ssize_t buf_size = 5000;

ssize_t process_data(char *buf, ssize_t size) {
  /* Initialize array for counting digits */
  int cnt[10];
  for (int i = 0; i < 10; i++) {
    cnt[i] = 0;
  }

  /* Count digits in the data from buffer */
  for (int i = 0; i < size; i++) {
    if (buf[i] >= '0' && buf[i] <= '9') {
      cnt[buf[i] - '0']++;
    }
  }

  /* Write result to buffer */
  int written = 0;
  for (int i = 0; i < 10; i++) {
    written += sprintf(buf + written, "%d: %d\n", i, cnt[i]);
  }
  return written;
}


int main(int argc, char *argv[]) {
  if (argc > 1) {
    printf("Too many arguments!\nThis program doesn't need any arguments!\n");
    exit(-1);
  }
  char name1[] = "8/fd1.fifo";
  char name2[] = "8/fd2.fifo";
  int fd, result;
  ssize_t size;
  char buf[buf_size];

  /* Open fifo channels */
   mknod(name1, S_IFIFO | 0666, 0);
   mknod(name2, S_IFIFO | 0666, 0);

  /* Read data from fifo1 and close it*/
  if ((fd = open(name1, O_RDONLY)) < 0) {
     printf("parent: Can\'t open FIFO1 for reading\n");
     exit(-1);
  }
  size = read(fd, buf, buf_size);
  if (size < 0) {
    printf("parent: Can\'t read from FIFO1\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("parent: Can\'t close FIFO1\n");
    exit(-1);
  }

  /* Process data */
  size = process_data(buf, size);

  /* Write to fifo2 and close it*/
  if ((fd = open(name2, O_WRONLY)) < 0) {
     printf("process2: Can\'t open FIFO2 for writting\n");
     exit(-1);
  }
  if (write(fd, buf, size) < 0) {
    printf("process2: Can\'t write to FIFO2\n");
    exit(-1);
  }
  if (close(fd) < 0) {
    printf("process2: Can\'t close FIFO2\n");
    exit(-1);
  }
  printf("process2 finished.\n");

  return 0;
}