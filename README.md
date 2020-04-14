# Simple Shell

This repository is about a re-creation of the Shell program. It contains some of the simplest commands of the Shell program.



## Getting started

1.  Clone all the repository in your terminal.
```
$ git clone git@github.com:Eng-RonnieBM/simple_shell.git
```
2. Compile the program and header files in the root directory.
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

3. Execute the program.

```
./hsh
```
You should see something like this.
```
($)
```


> **Note:** There are other way to run this Shell, in non-interactive mode by simply piping the commands into the shell executable.

```
$ echo "/bin/ls" | ./hsh
```


## Syntax

For run some command in the program, the syntax that you have to use is the same like a usual Shell.

```
($) <command> <options or flags> <argument>
```
**Example:**
```
($)/bin/ls -l
```
or
```
($)ls -l
```

In non-interactive mode:

```
$ <command> | ./hsh
```
**Example:**

```
$ echo "/bin/ls -l" | ./hsh
```

## Builtin Commands

This re-creation of shell support  some builtin commands:

- `env` - display the current environment variables
- `exit` - exit the program.


## Authors

- Luz A. Perdomo
- Ronnie Barrios
