/*******************************************
 *  Author : Iosif Atzamis
 *  Email : csd3094@csd.uoc.gr
 *  Language : C
 *  File-name : test9.c
 * 
 * ******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include "d_params.h"

#define set_demand(arg1, arg2) syscall(341, arg1, arg2)
#define get_demand(arg1, arg2) syscall(342, arg1, arg2)

int main()
{

    //get_demand test case for pid = < something that exists but is not the process that
    //runs test_1.c executable or a child of it> (!!!should be an error!!!)
    struct d_params params;

    printf("Trap to kernel level\n");
    if (!get_demand(8, &params))
    {
        printf("System call: get_demand: exited normally\n");
    }
    else
    {
        printf("System call: get_demand: failed\n");
    }
    printf("Back to user level\n");

    return 0;
}