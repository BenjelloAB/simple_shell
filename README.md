#  0x16. C - Simple Shell

This project is aimed at understanding and implementing a shell in the Unix environment. It covers a range of learning objectives related to Unix shell, its history, operation, and system calls.

Refer to man or help for:
- sh (Run sh as well)

## Learning Objectives

After completing this project, you should be able to explain the following concepts without relying on external sources:
- The original designer and implementer of the Unix operating system
- The first version of the UNIX shell and its writer
- Inventor of the B programming language (predecessor to C programming language)
- Ken Thompson's contributions
- Working of a shell
- Understanding pid and ppid
- Manipulating the environment of the current process
- Differentiating between a function and a system call
- Creating processes
- Prototypes of main
- Usage of the PATH to find programs in the shell
- Executing another program with the execve system call
- Suspending the execution of a process until one of its children terminates
- EOF (end-of-file) concept

## Requirements

- Allowed editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using gcc with specific options
- README.md file at the root of the project folder is mandatory
- Adherence to the Betty style for code
- Avoiding memory leaks in the shell
- Specific rules regarding functions per file, header files, system calls, and more (as listed in the project instructions)

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

