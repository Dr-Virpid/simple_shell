# SIMPLE SHELL
---
**A simple replication of a unix shell written in C language, as a learning process in the ALX SE programme.**



# COMPILATION
**Compile the SIMPLE SHELL using this format below:**
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

./hsh
```
# FUNCTIONS USED
---
- access (man 2 access)
- execve (man 2 execve)
- exit (man 3 exit)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- getpid (man 2 getpid)
- isatty (man 3 isatty)
- malloc (man 3 malloc)
- perror (man 3 perror)
- read (man 2 read)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- write (man 2 write)

# EXAMPLES
```
#cisfun$ /bin/ls
AUTHORS    env.c       exit.c           init.c    prompt.c     repl.c     string2.c  util.c
builtin.c  error.c     handl_signint.c  main.c    read_line.c  shell.h    _string.h  util.h
cd.c       executor.c  hsh              parser.c  README.md    string1.c  token.c    vgcore.19264
#cisfun$ ls -l /tmp
total 32
-rw-r--r-- 1 root  root  515 Apr 16 14:56 count_spec.c
-rw-r--r-- 1 root  root  239 Apr 16 14:56 functions.c
-rw-r--r-- 1 root  root  476 Apr 16 14:56 main.h
-rw-r--r-- 1 root  root  917 Apr 16 14:56 _printf.c
-rw-r--r-- 1 root  root  151 Apr 16 14:56 _putchar.c
-rw-r--r-- 1 root  root  112 Apr 16 14:56 README.md
-rw-r--r-- 1 root  root    0 Feb 28 01:42 right_school
-rw-r--r-- 1 root  root   13 Dec 20 11:55 school
-rw-r--r-- 1 root  root  552 Apr 16 14:56 specifers.c
drwx------ 2 root  root   22 Dec 20 11:41 tmpa2zvokgp
drwx------ 2 mysql mysql   6 Dec 20 11:54 tmp.GMWnSs1EVB
drwx------ 2 mysql mysql   6 Dec 20 11:37 tmp.ugKboEbH00
#cisfun$
```

## LICENSE
This project is unlicensed.

> Authored by ODELOLA OLUWATOLAMISE and AZOLIKE TOCHI
