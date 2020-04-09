#include <iostream>
#include <sys/time.h>
#include "osm.h"


void empty(){
    //does nothing
}
double osm_operation_time(unsigned int iterations){
    if(iterations == 0){
        return -1;
    }
    int cntr = 1;
    unsigned int i = 0;
    timeval before;
    timeval after;
    gettimeofday(&before, NULL);
    for(; i < iterations-3; i+=4){
        cntr++;
        cntr++;
        cntr++;
        cntr++;
    }
    for (; i< iterations; i++){
        cntr++;
    }
    gettimeofday(&after, NULL);
    double output = (after.tv_sec*10^9) - (before.tv_sec*10^9) + (after.tv_usec*10^3)-(before.tv_usec*10^3);
    return output/iterations;
}
double osm_function_time(unsigned int iterations){
    if(iterations == 0){
        return -1;
    }
    unsigned int i = 0;
    timeval before;
    timeval after;
    gettimeofday(&before, NULL);
    for(; i < iterations-3; i+=4){
        empty();
        empty();
        empty();
        empty();
    }
    for (; i< iterations; i++){
        empty();
    }
    gettimeofday(&after, NULL);
    double output = (after.tv_sec*10^9) - (before.tv_sec*10^9) + (after.tv_usec*10^3)-(before.tv_usec*10^3);
    return output/iterations;
}
double osm_syscall_time(unsigned int iterations){
    if (iterations ==0){
        return -1;
    }
    unsigned int i = 0;
    struct timeval before;
    gettimeofday(&before, NULL);
    for(; i < iterations-3;i+=4){
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    for(; i < iterations; i++){
        OSM_NULLSYSCALL;
    }
    struct timeval after;
    gettimeofday(&after, NULL);
    double output = (after.tv_sec*10^9) - (before.tv_sec*10^9) + (after.tv_usec*10^3)-(before.tv_usec*10^3);
    return output/iterations;
}