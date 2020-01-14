#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syscall.h>

int main(int argc, char *argv[])
{
  int ret = syscall(SYS_write, 1, "Hello!\n", 7);
  if (ret != 7) {
    perror("Error: ");
  }
}
