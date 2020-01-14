#ifndef __COMMON_H__
#define __COMMON_H__

#include <assert.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/time.h>

double get_time()
{
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double)t.tv_sec + (double)t.tv_sec * 1e-6;
}

void spin(int howlong)
{
    double t = get_time();
    while ((get_time() - t) < (double)howlong)
        ; // do nothing in loop
}

#endif // __COMMON_H__
