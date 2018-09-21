#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "events/ae/ae.h"

long long print(struct aeEventLoop *loop, void *clientData)
{
    printf("%d - Hello, World\n", (int)(long)clientData);
    return -1;
}

int main( int argc, const char* argv[] )
{
    aeTimeEvent events[10];
    aeEventLoop *loop = aeCreateEventLoop(10, NULL, AE_DEFAULT_FLAGS, NULL);
    assert(loop);
    int i;
    for (i = 0; i < 10; i ++) {
        aeCreateTimeEvent(loop, &events[i], print, (void *)(long)i, NULL, NULL);
        aeSetTimeoutTimeEvent(loop, &events[i], i*1000);
    }
    aeMain(loop);
    printf("Loop Finished\n");
    aeDeleteEventLoop(loop);
    printf("Test Passed\n");
    return 0;
}