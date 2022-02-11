# MINISHELL
As beautiful as shell

![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)


## Introduction

The aim of the project is to recreate a linux terminal from scratch using C programmming language.\
In this very simple version, some of the features of a shell were implemented as environment variables, pipes and redirections.\
The main goal is to have a good understanding of processes and learn more about file descriptors.

##### Development team:
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Roman](https://github.com/romanbtt) - robitett\
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[Vitoria](https://github.com/vscabell) - vscabell

## Usage

#### Build Instructions

```bash
$ git clone https://github.com/vscabell/minishell
$ cd minishell
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
- Multiples commands separated with semicolon `;`
- Pipes `|` (except for multiline commands)
- Redirections `<`, `>`, `>>`
- `ctrl-C`, `ctrl-D` and `ctrl-\` signals must be handled
- `$?` it should work like in bash.
