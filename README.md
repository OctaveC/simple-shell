# Simple shell project

## Description

This is the reconstruction of a simple shell that use differents functionalities of the UNIX command interpreter, based on the Bourne Shell (sh). Some of them are called via the PATH and others are built-ins. This was entirely written in C language for a collaborative project for Holberton School.

## Usage

First step, clone this repository in order to obtain all the files in your local machine.

```bash
git clone https://github.com/OctaveC/simple_shell.git
```

In order to be able to use the simple shell, you should compile with GCC using the appropriate flags and after that you will be able to launch the executable of the desired name (see command below). You can run it in interactive mode, where you can exit using Ctrl+D or typing exit, and in non-interactive mode, which will exit right after the execution of the command.

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
For non-interactive mode :
```bash
echo "/bin/ls" | ./hsh
```
For interactive mode :
```bash
./hsh
```
Example of usage in interactive mode :
```bash
ls -l /tmp
```

## Functional built-ins

- **exit:** It will exit the process with it's status or with the specified status (for example: exit 98);
- **env:** It will print all the environment variables.
- **setenv:** It will add or modify an environment variable.
- **unsetenv:** It will remove an environment variable.
- **cd:** Like the real cd function it will give you the ability to navigate between directories.

## Source files description

- **shell-header.h** - This is the header of our structures and functions for the simple shell.
- **simple_shell.c** - This is the main source file where we launch our shell, manage the parsing of the line, create the child process and execute the needed functions.
- **check_builtins.c** - This is the source file of the function that will check for the specific built-in depending of the command you've entered.
- **builtin.c** - This is the source file of all the built-in functions.
- **l_list_func(_2).c** - This is the source files containing the functions managing our linked lists.
- **env_func.c** - This is the source file of the different environment functions that we use.
- **error_handler.c** - This is the source file of our error handler, managing the error cases or our shell.
- **mem_func.c** - This is the source file containing the functions managing our memory allocation.
- **help.c** - This is our help built-in that will call the files in the help directory depending of what you've asked.
- **tools_func(_(1)(2)(3)).c** - This is the source files of the differents functions that we used to build our shell.

## Authors

[LAPEYRE Nathan](https://github.com/Sarolus)
[COLLOMBEL Octave](https://github.com/OctaveC)