# MINISHELL
As beautiful as shell

![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)


## Introduction

The aim of the project is to recreate a linux terminal from scratch using C programmming language.\
In this very simple version, some of the features of a shell were implemented as environment variables, pipes and redirections.\
The main goal is to have a good understanding of processes and learn more about file descriptors.

##### Development team:
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Fred](https://github.com/coderMeira) - fmeira
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Arsénio](https://github.com/RealMadnessWorld) - jarsenio

## Usage

#### Build Instructions

```bash
$ git clone https://github.com/coderMeira/Minishell/
$ cd Minishell
$ make
$ ./minishell
```

#### Run the program

```bash
$ ./minishell
```

## Functions

- Show a prompt when waiting for a new command
- Navigate through command history using up `↑` and down `↓` arrows  
- Builtin implementation:\
	-`echo` (with flag -n)\
	-`cd` (absolute and relative path)\
	-`pwd`\
	-`export`\
	-`unset`\
	-`env`\
	-`exit`
- Environment variables (`$` followed by characters)
- Simple quotes `'` and double quotes `"` should work like in bash
- Escape special chars with `\`
- Pipes `|`
- Redirections `<`, `>`, `>>`
- `ctrl-C`, `ctrl-D` and `ctrl-\` signals must be handled
- `$?` it should work like in bash.
