#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "comms.h"

int main(int argc, char *argv[])
{
    pthread_t server_thread;

    if(pthread_create(&server_thread, NULL, comm_thread, 0))
    {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if(pthread_join(inc_x_thread, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    return 0;
}