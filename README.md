# Minishell Project Readme

## Overview

Welcome to the Minishell project! This project is part of the 42 school curriculum, designed to help you understand and implement a basic shell. In Minishell, you will create a simplified shell that can interpret and execute basic commands.

## Project Objectives

The main objectives of the Minishell project are as follows:

1. **Command Line**: Implement a command line that can read and interpret user input.

2. **Built-in Commands**: Implement built-in commands such as `echo`, `cd`, `pwd`, `export`, `unset`, `exit` and `env`.

3. **Executable Commands**: Implement the ability to execute external commands.

4. **Redirection and Pipes**: Support input/output redirection and pipes.

5. **Environment Variables**: Implement the ability to set and use environment variables.

6. **Error Handling**: Properly handle errors, such as command not found or incorrect command syntax.

## Usage

To use the Minishell program, follow the format below:

```bash
./minishell
```

This will launch the Minishell program, and you can then enter commands interactively.

Example:

```bash
./minishell
$ echo "Hello, Minishell!"
Hello, Minishell!
```

## Supported Commands

Minishell supports various built-in commands and external commands. Here are some examples:

- `echo`: Display a message or the value of a variable.
- `cd`: Change the current directory.
- `pwd`: Print the current working directory.
- `env`: Display the environment variables.
- `export`: Display or add the environment variables.
- `unset`: Remove the environment variables.
- External commands: Execute external programs.

It also supports basic signals like ctrl-C, ctrl-\ and ctrl-D.

## Building and Running

To build the Minishell program, use the provided Makefile:

```bash
make
```

This will generate the `minishell` executable.

## Resources

Here are some resources that may be helpful for completing the Minishell project:

- [Bash Manual](https://www.gnu.org/software/bash/manual/)
- [UNIX Shell Programming](https://www.tutorialspoint.com/unix/unix-shell.htm)
