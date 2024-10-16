
#include "types.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

#define MINOR_DEVNULL 0
#define MINOR_DEVZERO 1

int 
drvmemread(struct inode *ip, char *dst, uint off, int n)
{
    if (ip->minor == MINOR_DEVNULL)
    {
        return 0;
    }
    else if (ip->minor == MINOR_DEVZERO)
    {
        memset(dst, 0, n);
        return n;
    }
    return 0;
}

int 
drvmemwrite(struct inode *ip, char *buf, uint off, int n)
{
    return n;
}

void 
drvmeminit(void)
{

    devsw[DEVNULL].read = drvmemread;
    devsw[DEVNULL].write = drvmemwrite;

}