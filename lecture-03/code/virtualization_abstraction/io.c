#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void dowork()
{
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd >= 0);
    char buffer[20];
    sprintf(buffer, "hello world\n");
    int rc = write(fd, buffer, strlen(buffer));
    assert(rc == (strlen(buffer)));
    printf("pid-%d: wrote %d bytes\n", getpid(), rc);
    fsync(fd);
    close(fd);
}

int main(int argc, char* argv[])
{
    dowork();
    return 0;
}
