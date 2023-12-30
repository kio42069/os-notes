# OS Notes

### Interlude: Process API

- fork() creates a seprate thread for the child process, but there is no determined way to knowing which process will be executed first: the parent or the child

- here comes wait(): it introduces a wait period before which, for example the parent process will wait for the child process to finish first.

- 