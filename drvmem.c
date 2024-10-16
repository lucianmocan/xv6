
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
#define MINOR_DEVMEM 2
#define MINOR_DEVKEM 3

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
    else if (ip->minor == MINOR_DEVMEM)
    {
        if ( off < EXTMEM || off + n > PHYSTOP){
            return -1;
        }
        memmove(dst, (char*)P2V(off), n);
        return n;
    }
    else if (ip->minor == MINOR_DEVKEM){
        return kmemread(dst, off, n);
    }
    return -1;
}

int 
drvmemwrite(struct inode *ip, char *buf, uint off, int n)
{
    return n;
}

void 
drvmeminit(void)
{

    devsw[DEV].read = drvmemread;
    devsw[DEV].write = drvmemwrite;

}