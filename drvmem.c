
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

int 
drvmemread(struct inode *ip, char *dst, uint off, int n)
{
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