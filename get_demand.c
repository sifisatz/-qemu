/*******************************************
 *  Author : Iosif Atzamis
 *  Email : csd3094@csd.uoc.gr
 *  Language : C
 *  File-name : get_demand.c
 * 
 * ******************************************/

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/pid.h>
#include <linux/slab.h>

#include <linux/d_params.h>

int total_demand = 0;

asmlinkage long sys_get_demand(int pid, struct d_params *d_arguments)
{

    printk("Iosif Atzamis AM: 3094 System Call for \n");
    printk(" sys_get_demand with arguments : %d  \n", pid);

    struct task_struct *task;
    struct d_params *process;

    task = kmalloc(sizeof(struct d_params), GFP_KERNEL);

    /*Use copy_from_user() to copy the struct given as parameter from user_space. Destination (t), source (t_arguments).*/
    /*If unsuccessful, return EINVAL*/

    if (copy_from_user(task, (void *)d_arguments, sizeof(struct d_params)))
    {
        printk("Unsuccessfully copied to user.\n");
        return EINVAL;
    }
    else
    {
        printk("Successful copy from user!\n");
    }

    if (pid == -1)
    {
        printk("Anaferomai sto current process! \n");
        process->demand = current->demand;
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
                if ((task->pid == current->pid) || (task->real_parent->pid == current->pid))
                {
                    process->demand = current->demand;
                }
                else
                {
                    printk("Error:  process->pid!=current->pid or parent!");
                    return (long)EINVAL;
                }
            }
        }
    }

    if (copy_from_user(task, (void *)d_arguments, sizeof(struct d_params)))
    {
        printk("Unsuccessfully copied to user.\n");
        return EINVAL;
    }
    else
    {
        printk("Successful copy from user!\n");
    }
    return ((long)0);
}
