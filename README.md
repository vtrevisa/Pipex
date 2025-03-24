# Pipex

## Description
Pipex is a 42 school project that recreates the behavior of the shell pipe operator `|` in C. This program handles command execution, process forking, pipe creation, and file redirection, mimicking the way shells like bash process piped commands.

## Features
- Simulates the shell pipe operator `|`
- Handles input and output redirection with `<` and `>`
- Supports absolute paths and PATH resolution for commands
- Manages multiple processes and pipes
- Includes comprehensive error handling

## Installation
Clone this repository:
```bash
git clone https://github.com/yourusername/pipex.git
cd pipex
make
```

## Usage
Basic Pipe Simulation
```
./pipex file1 cmd1 cmd2 file2
```

This is equivalent to:
```
< file1 cmd1 | cmd2 > file2
```

Example
```
./pipex input.txt "grep hello" "wc -l" output.txt
```

### This will:

> Take input from input.txt
> Pass it through grep hello
> Then pass the result to wc -l
> Finally write the output to output.txt

### The program handles various error cases including:

> Command not found
> File permission issues
> Pipe creation failures
> Fork failures
> Invalid arguments

### Testing

You can test the program with various commands:
```
./pipex /dev/urandom "head -n 5" "wc -w" count.txt
```
```
./pipex infile "ls -l" "grep .c" outfile
```

### Technical Details
Written in C
Uses fork(), pipe(), dup2(), and execve()
Implements PATH resolution
Follows 42 Norm guidelines

## Author
Vitor Trevisan - vi.trevi.11@gmail.com - vtrevisa
