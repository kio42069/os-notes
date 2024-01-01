#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include "common.h"

int
main(int argc, char *argv[])
{
    // close(STDOUT_FILENO); 
	// open("test.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("helo\n");
        char *myargs[2];
        myargs[0] = stdrup("/bin/ls");
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
    } else {
        printf("bai\n");
    }
    return 0;   
}
