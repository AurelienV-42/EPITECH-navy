/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int global_i;

void server_connected(int i, siginfo_t *ptr, void *a)
{
	static int nb = 0;

	(void) i;
	(void) a;
	if (nb == 0) {
		my_putstr("\nenemy connected\n");
		kill(ptr->si_pid, SIGUSR1);
		global_i = ptr->si_pid;
		nb++;
	} else
		global_i = 1;
}

void server_connected2(int i)
{
	(void) i;
	global_i = 2;
}
