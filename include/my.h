/*
** EPITECH PROJECT, 2018
** Library my.h
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#ifndef MY_H_
#define MY_H_

#include "navy.h"
#include "get_next_line.h"

/* Include of library */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/* My program */

int server(navy_t *navy, char **array_client);
int client(navy_t *navy, char **array_server);
int navy_game(navy_t *navy, int ac, char **av);
void print(char **array);
char *get_next_line(int fd);
int handle_gnl(char *str);
int game_is_finish(char **array);
void client_connected(int i);
void client_connected2(int i);
void server_connected(int i, siginfo_t *ptr, void *a);
void server_connected2(int i);
char **parser(char *filepath, char **array_start);
void to_free(char **array, char **array2);
int hit_or_missed(char **array, int first, int second, int pid);
int count_signals1(void);
int count_signals2(void);
int print_array_hit(char *str);
void change_array_hit(char **array, int hit, int columns, int lines);
void print_tab(char **array, char **array1);

extern int global_i;

/* Library */

void my_putchar(char c);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *str1, char const *str2);
int my_atoi(char *str);
void my_putnbr(int nb);
char **my_str_to_word_array(char const *str, char symbol);
char *my_strdup(char const *src);
char **array_cpy(char **array_to_cpy);
char *my_strcpy(char *dest, char const *str);
int my_strlen_array(char **array);
void my_free_array(char **array);

#endif
