#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

int main(void) {
        int fd, i;
        int wbuf[BUFSIZE], rbuf[BUFSIZE];

	for (i=0; i<BUFSIZE; i++) {
		wbuf[i] = i*10;
	}
	bzero(rbuf, sizeof(rbuf));

        fd = open("testdata", O_CREAT|O_TRUNC|O_RDWR, 0644);
        if(fd == -1) {
                perror("Open testdata");
                exit(1);
        }

	write(fd, wbuf, sizeof(wbuf));
	close(fd);

	fd = open("testdata", O_RDWR, 0644);
	read(fd, rbuf, sizeof(rbuf));

	for (i=0; i<BUFSIZE; i++) {
		printf("%d %d\n", i, rbuf[i]);
	}

	close(fd);
}

