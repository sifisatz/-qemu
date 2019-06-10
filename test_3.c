/*******************************************
 *  Author : Iosif Atzamis
 *  Email : csd3094@csd.uoc.gr
 *  Language : C
 *  File-name : test3.c
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
	//set_demand test case for pid = -2 should be faill
    printf("Trap to kernel level\n");
    if (!set_demand(-2, 90))
    {
        printf("System call: set_demand: exited normally\n");
    }
    else
    {
        printf("System call: set_demand: failed\n");
    }
    printf("Back to user level\n");
    return 0;
}