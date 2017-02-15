#include "ramlab_client.h"

double getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

void createPayloadCharArray(char *payload_char, const int payload_size)
{
    int i;
    for(i = 0; i < payload_size; i++)
    {
        payload_char[i] = '0';
    }
    payload_char[i] = '\0';
    return;
}