
### How to add a custom syscall ?

I'll showcase it by adding `filelseek`.

#### Step 1

`lseek` operates on files. That means I have to search for `sysfile.c`, `sysfile.h`, 
`file.c`


### Step 2

I add `sys_lseek()` in `sysfile.c`. To do a system call you have to call a function in `syscall.c` which will then process the call and do the system call `filelseek()`.

### Step 3

Add the new syscall in `syscall.c`:
- update the `syscalls` table
- add `extern <type> sys_lseek()`

### Step 4 

To be able to call lseek in user mode, we have to define the function `lseek` in `usys.S`.
Add `SYSCALL(lseek)`.


### Step 5

Add prototype to `user.h`.

