# 0x19. C - Stacks, Queues - LIFO, FIFO

## Introduction
This project, part of the ALX Software Engineering curriculum, focuses on stacks, queues, and their respective LIFO and FIFO operations in C programming.

## Installation
To clone the repository, use:
```bash
git clone https://github.com/AnasMouak/monty.git
```

## Compilation and Execution
Compile the program using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

Run the program in interactive mode:
```bash
./monty
```

Or use it with a bytecode file:
```bash
./monty bytecodes/00.m
```

## Requirements
- **Editors**: Allowed editors are vi, vim, emacs.
- **Compilation**:
  - All files will be compiled on Ubuntu 20.04 LTS.
  - Compilation flags: `-Wall -Werror -Wextra -pedantic -std=c89`.
- **Style**:
  - Code must adhere to the Betty style.
  - Your code should use the Betty style for documentation.
- **Restrictions**:
  - Maximum of one global variable.
  - No more than five functions per file.
  - Allowed to use the C standard library.
  - Prototypes of all functions should be included in the header file `monty.h`.
  - All header files must be include guarded.

## Usage Examples
Basic Stack Operations:
```bash
$ ./monty
$ push 1
$ push 2
$ pall
2
1
$ pop
$ pall
1
$ ^C
```

Advanced Queue Features:
```bash
$ ./monty
$ queue
$ push 1
$ push 2
$ pall
1
2
$ stack
$ pall
2
1
$ exit
```

Handling Errors and Output:
```bash
$ ./monty bytecodes/01.m
Error: Can't open file bytecodes/01.m
$ echo $?
1
```

## Project Guidelines
- Adherence to the Betty coding style is mandatory.
- Developed and tested on Ubuntu 20.04 LTS.
- The project emphasizes a thorough understanding of stack and queue operations in C programming.

## Authors
- Yassine Mtejjal
- Anas Mouak
