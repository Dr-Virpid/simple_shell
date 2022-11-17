## SIMPLE SHELL
---
**A Collaboration on simple shell alx se program task**
## Description :speech_balloon:

**hsh** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

### Invocation :running:

Usage: **hsh** [filename]

To invoke **hsh**, compile all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o hsh
./hsh
```
**hsh** can be invoked both interactively and non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'hello'" | ./hsh
'hello'
$
```

If **hsh** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **shellby** displays the prompt `$ ` when it is ready to read a command.

Example:
```
$./hsh
$
```

Alternatively, if command line arguments are supplied upon invocation, **shellby** treats the first argument as a file from which to read commands. The supplied file should contain one command per line. **Shellby** runs each of the commands contained in the file in order before exiting.

Example:
```
$ cat test
echo 'hello'
$ ./hsh test
'hello'
$
```

### Environment :deciduous_tree:

Upon invocation, **hsh** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$ echo "echo $HOME" | ./hsh
/home/vagrant
```

#### PWD
The current working directory as set by the **cd** command.

```
$ echo "echo $PWD" | ./hsh
/home/vagrant/holberton/simple_shell
```

#### OLDPWD
The previous working directory as set by the **cd** command.

```
$ echo "echo $OLDPWD" | ./hsh
/home/vagrant/holberton/printf
```

#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

```
$ echo "echo $PATH" | ./hsh
/home/vagrant/.cargo/bin:/home/vagrant/.local/bin:/home/vagrant/.rbenv/plugins/ruby-build/bin:/home/vagrant/.rbenv/shims:/home/vagrant/.rbenv/bin:/home/vagrant/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/vagrant/.cargo/bin:/home/vagrant/workflow:/home/vagrant/.local/bin
```

### Command Execution :hocho:

After receiving a command, **hsh** tokenizes it into words using `" "` as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. **hsh** then proceeds with the following actions:
1. If the first character of the command is neither a slash (`\`) nor dot (`.`), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
2. If the first character of the command is none of a slash (`\`), dot (`.`), nor builtin, **hsh** searches each element of the **PATH** environmental variable for a directory containing an executable file by that name.
3. If the first character of the command is a slash (`\`) or dot (`.`) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.

### Exit Status :wave:

**hsh** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.

If a command is not found, the return status is `127`; if a command is found but is not executable, the return status is 126.

All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

### Signals :exclamation:

While running in interactive mode, **hsh** ignores the keyboard input `Ctrl+c`. Alternatively, an input of end-of-file (`Ctrl+d`) will exit the program.

User hits `Ctrl+d` in the third line.
```
$ ./hsh
$ ^C
$ ^C
$
```

### Variable Replacement :heavy_dollar_sign:

**hsh** interprets the `$` character for variable replacement.

#### $ENV_VARIABLE
`ENV_VARIABLE` is substituted with its value.

Example

