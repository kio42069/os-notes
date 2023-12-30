# OS Notes

### Interlude: Process API

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