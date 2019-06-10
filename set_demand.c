/*******************************************
 *  Author : Iosif Atzamis
 *  Email : csd3094@csd.uoc.gr
 *  Language : C
 *  File-name : set_demand.c
 * 
 * ******************************************/

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/uaccess.h>
#include <linux/sched.h>

#include <linux/d_params.h>

int total_demand = 0;

asmlinkage long sys_set_demand(int pid, int demand)
{

    printk("Iosif Atzamis AM: 3094 System Call for \n");
    printk(" sys_set_demand with arguments : %d and argument %d \n", pid, demand);

    struct d_params *process;
    struct task_struct *task;

    if (pid == -1)
    {
        if (total_demand + demand <= 100)
        {

            printk("Anaferomai sto current pid : pid == -1\n");
            total_demand = total_demand + demand;
            current->demand = demand;
            process->demand = demand;

            return (long)0;
        }
        printk("Error : pid == -1 but total_demand > 100 \n");

        return (long)EINVAL;
    }
    else if (pid < -1)
    {
        printk("Invalid pid : pid < -1 \n");
        return (long)EINVAL;
    }
    else
    {
        for_each_process(task)
        {
            if (task->pid == pid)
            {
                if (task->real_parent == current || task == current)
                {
                    if (total_demand + demand <= 100)
                    {

                        total_demand = total_demand + demand;
                        current->demand = demand;
                        return (long)0;
                    }
                    printk("Error : process->pid == pid but total_demand > 100 \n");
                    return (long)EINVAL;
                }
                printk("Error : process->pid == pid but process->real_parent != current \n");
                printk("\t  || process != current \n");
                return (long)EINVAL;
            }
        }
        printk("Error : for_each_process failed \n");
        return (long)EINVAL;
    }
}
