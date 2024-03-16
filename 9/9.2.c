#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const ssize_t buf_size = 128;

/* Initialize array for counting digits */
int cnt[10];

void process_data(char *buf, ssize_t size) {
  /* Count digits in the data from buffer */
  for (int i = 0; i < size; i++) {
    if (buf[i] >= '0' && buf[i] <= '9') {
      cnt[buf[i] - '0']++;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    printf("Too many arguments!\nThis program doesn't need any arguments!\n");
    exit(-1);
  }
  char name1[] = "9/fd1.fifo";
  char name2[] = "9/fd2.fifo";
  int fd1, fd2, result;
  ssize_t size;
  char buf[buf_size];

  /* Fill array for counting digits */
  for (int i = 0; i < 10; i++) {
    cnt[i] = 0;
  }

  /* Open fifo channels */
  mknod(name1, S_IFIFO | 0666, 0);
  mknod(name2, S_IFIFO | 0666, 0);

  /* Open fifo1 for reading */
  if ((fd1 = open(name1, O_RDONLY)) < 0) {
    printf("process2: Can\'t open FIFO1 for reading\n");
    exit(-1);
  }

  /* Read data from fifo1 and process it */
  do {
    size = read(fd1, buf, buf_size);
    if (size == -1) {
      printf("process2: Can\'t read from FIFO2\n");
      exit(-1);
    }
    process_data(buf, size);
  } while (buf_size == size);

  /* Close fifo1 */
  if (close(fd1) < 0) {
    printf("process2: Can\'t close FIFO1\n");
    exit(-1);
  }
  
  /* Open fifo2 for witing */
  if ((fd2 = open(name2, O_WRONLY)) < 0) {
    printf("process2: Can\'t open FIFO1 for writing\n");
    exit(-1);
  }

  /* Write processed data to fifo2 */
  const ssize_t tmp_size = 16;
  char tmp[tmp_size];
  int i = 0, curr_size;
  memset(tmp, 0, tmp_size);

  do {
    curr_size = 0;
    size = strlen(tmp);
    do {
      /* Copy excess data from tmp to buffer */
      memcpy(buf + curr_size, tmp, size);
      curr_size += size;

      /* Write new line in tmp */
      size = sprintf(tmp, "%d: %d\n", i, cnt[i]);
      if (size < 0) {
        printf("process2: Can\'t write to buffer\n");
        exit(-1);
      }
      if (++i >= 10) {
        break;
      }
    } while (curr_size + size <= buf_size);

    /* Fill up buffer */
    size = buf_size - curr_size;
    if (size > strlen(tmp)) {
      size = strlen(tmp);
    }
    memcpy(buf + curr_size, tmp, size);
    curr_size += size;

    /* Leave unused data only in tmp */
    memmove(tmp, tmp + size, tmp_size - size);

    /* Write data to fifo2 */
    size = write(fd2, buf, curr_size);
    if (size == -1) {
      printf("process2: Can\'t write to FIFO2\n");
      exit(-1);
    }
  } while (i < 10);

  /* Write final chunk of data to fifo2 */
  size = strlen(tmp);
  if (size > 0) {
    size = write(fd2, tmp, size);
    if (size == -1) {
      printf("process2: Can\'t write to FIFO2\n");
      exit(-1);
    }
  }

  /* Close fifo2 */
  if (close(fd2) < 0) {
    printf("process2: Can\'t close FIFO2\n");
    exit(-1);
  }

  return 0;
}
