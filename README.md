# Ft_ls
#### Recode the ls command.

This project will recode the system ls command.
His behavior should be identical to the original ls commands of
system , with the following options : -l , -R , -a, -r and -t .


## Summary
 1. [Makefile](#makefile)
 2. [Usage](#usage)
 3. [Example](#exemple)

## <a name="makefile">Makefile</a>

| Commande       	|  Actions 	|
|----------------	|----------	|
| `make`      	  | Compile all .c and create an executable "fdf"  	|
| `make clean`    | Delete all .o.  	|
| `make flcean`  	| Delete all .o and executable 'fdf'.  	|
| `make re` 	 	| Execute fclean and make.  	|

## <a name="usage">Usage</a>

* Without options, without arguments:
>./ft_ls

* Without options, with arguments:
>./ft_ls file1 file2 
>>./ft_ls dir1 file1

* With options, without arguments:
>./ft_ls -laRtr

* With options, with arguments:
>./ft_ls -laRtr dir1 file2 etc

## <a name="exemple">Example</a>

```c
./ft_ls

Makefile
auteur
ft_ls
includes
libft
srcs
test2
```

```c
./ft_ls srcs

ft_colors.c
ft_erreur.c
ft_get_info.c
ft_list.c
ft_ls.c
ft_opt_t.c
ft_option.c
ft_print_ls.c
ft_prt_info_nbr.c
ft_prt_info_str.c
ft_prt_right.c
ft_recursive.c
ft_reverse.c
ft_sort.c
main.c
```
```c
./ft_ls -la Makefile includes

-rw-r--r--  1 etermeau  2014_paris  1655  2 May 15:48 Makefile

includes:
total 24
drwxr-xr-x  2 etermeau  2014_paris  4096  2 May 15:46 .
drwxr-xr-x  6 etermeau  2014_paris  4096  2 May 16:04 ..
-rw-r--r--  1 etermeau  2014_paris  3992  2 May 15:46 ft_ls.h
```
