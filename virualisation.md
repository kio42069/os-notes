# OS Notes

# Interlude: Process API

- fork() creates a seprate thread for the child process, but there is no determined way to knowing which process will be executed first: the parent or the child

- here comes wait(): it introduces a wait period before which, for example the parent process will wait for the child process to finish first.

- finally, the exec() system call completely shifts that thread's control to the program called, and hence wiping out the current thread.

*Read up about **execl, execlp, execle, execv, execvp, execvpe***

Also read the man pages for ***zsh***

#### How the redirection into a file works

Example
```
wc p3.c > newfile.txt
```

Here, just before the exec is called, the shell closes the standard output, and opens the newfile.txt

Now anything the wc function returns, it will flow into the newfile.txt instead of getting rendered on the screen since the standard output is closed now

- Piping can be used to combine processes: let the output of one prgram flow into another's input

- Superuser is a user who can control all processes, and do a lot of other powerful things which a regular user cannot do. A regular user can only stop processes which they have created

## Hopefully there wasn't anything else imp in the interlude chapter

# Mechanism: Limited Direct Execution

- Here we shall discuss virutalisation in better detail

### Problem, Restricted ops

Direct execution is dangerous, so we can have two modes, a user mode and a kernel mode. 

In the user mode, the user can have pretty limited access to the hardware resources. But in kernel mode, in which the OS operates, the user has every power to do anything.

Therefore, pushing the user to the kernel mode is pretty dangerous (sudo mode in linux)

So what happens when the user needs to access more powers? The OS will raise the privilidge level of the user to kernel level. In there also, the code that will be executed will be treated as sus, and the OS will perform checks before letting the code execute.

This occurs when the program required activates a trap instruction, raising it's privilidge level. When the code execution is completed, a return-from-trap is executed, lowering the privilidge level again.

Now, how will the OS know what was the state of the program/code before the increase in the privilige level occured? It simply keeps a stack, where it pushes the required thingies before raising the privilidge level, and pops them out when the return-from-trap is executed

The OS also has a trap table, which keeps record of the where in memory the trap instructions are located, since it would be a **Very Bad Idea** to keep them out in the open, where any code will be able to access it to raise itself to kernel level.

On boot, the OS initialises the trap table.

### Problem, switching between processes

As the OS itself is also a program only, once it starts running a process, how will it be able to regain control of the CPU?

The answer is trust, it needs to simply believe that after the prgram it started running ends, it will give the access back to the OS. But what if due to either malicious or faulty code, the program gets stuck in a loop or never gives access back to the OS?

That is why the oldest programmers kept a timer system, where the OS would regularly get control back to the system, and it can then kill any malicious of bad programs. 
