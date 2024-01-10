## Simple Shell

The project entails creating my own Simple Shell. The challenge covers everything learnt so far in C:
- Basics of programming
- Basics of C
- Basics of thinking like an engineer
- Group work
- and Learning how to learn

### Output 
The program has the exact same output as sh(/bin/sh) as well as the exact same error output.

The only difference is when printing an error, the name of the programis equivalent to argv[0].

### Compilation
The simple is compiled this way 
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Testing

The shell in interactive mode works like this:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

