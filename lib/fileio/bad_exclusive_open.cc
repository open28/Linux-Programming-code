#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../tlpi_hdr.h"
int main(int argc,char * argv[])
{
    int fd;
    fd = open(argv[1],O_WRONLY);
    if(fd == -1)
    {
        printf("[PID %ld] FILE \"%s\" already exits\n",(long)getpid(),argv[1]);
        /*for mutiPrecess*/
        if(argc > 2)
            sleep(printf("[PID %ld] Done sleeping\n",(long) getpid()));
        /*end*/
        close(fd);

    }else
    {
        if(errno != ENOENT)
        {
            fd = open(argv[1],O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR);
            if(fd == -1)
                errExit("open");
        printf("[PID %ld] Created FILE \"%s\" exclusively\n",(long)getpid(),argv[1]);/*MAY NOT BE TRUE*/
        }
    }
}
