# Ft_ls
#### Recoder la commande ls.
Ce projet consiste à recoder la commande ls du système.
Son comportement doit être identique à celui de la commands ls originale du
système, avec les options suivantes : -l, -R, -a, -r et -t.


## Summary
 1. [Makefile](#makefile)
 2. [Utilisation](#usage)
 3. [Exemple](#exemple)

## <a name="makefile">Makefile</a>

| Commande       	|  Actions 	|
|----------------	|----------	|
| `make`      	  | Compile tous les .c et créer un exécutable fdf  	|
| `make clean`    | Supprime les .o.  	|
| `make flcean`  	| Supprime les .o et fdf.  	|
| `make re` 	 	| Exécute fclean et make.  	|

## <a name="usage">Utilisation</a>

* Sans option, sans argument:
>./ft_ls

* Sans option, avec arguments:
>./ft_ls file1 file2 
>>./ft_ls dir1 file1

* Avec options, sans argument:
>./ft_ls -laRtr

* Avec options, avec arguments:
>./ft_ls -laRtr dir1 file2 etc

## <a name="exemple">Exemple</a>

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
