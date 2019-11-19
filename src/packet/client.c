/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int global_i;

static void send_signal_client(navy_t *navy, char *str)
{
	char first = 'A';
	char integer = '0';
	int i_first = 0;
	int i_second = 0;
	int hit = 0;

	while (first != str[0]) {
		kill(navy->pid_server, SIGUSR1);
		i_first++;
		first++;
		usleep(10000);
	}
	while (integer != str[1]) {
		kill(navy->pid_server, SIGUSR2);
		integer++;
		i_second++;
		usleep(10000);
	}
	kill(navy->pid_server, SIGUSR1);
	hit = print_array_hit(str);
	change_array_hit(navy->array_server, hit, ++i_first, i_second);
}

static int attack(navy_t *navy)
{
	char *str = NULL;

	do {
		my_putstr("\nattack: ");
		str = get_next_line(0);
		if (str == NULL)
			return (1);
	} while (handle_gnl(str) != 0);
	send_signal_client(navy, str);
	return (0);
}

static void manage_signal_client(navy_t *navy)
{
	struct sigaction act;
	struct sigaction act2;
	static int i = 0;

	act.sa_handler = &client_connected;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	act2.sa_handler = &client_connected2;
	act2.sa_flags = 0;
	sigemptyset(&act2.sa_mask);
	sigaction(SIGUSR2, &act2, NULL);
	kill(navy->pid_server, SIGUSR1);
	pause();
	my_putstr("\nsuccessfully connected\n");
	i++;
}

static int manage_and_count(navy_t *navy, char **array_client)
{
	static int i = 0;
	int first = 0;
	int scd = 0;
	int hit = 0;
	int return_attack = 0;

	if (i == 1) {
		if ((return_attack = attack(navy)) == 84)
			return (84);
		else if (return_attack == 1)
			return (1);
		i++;
	} else {
		first = count_signals1();
		scd = count_signals2();
		hit = hit_or_missed(array_client, first, scd, navy->pid_server);
		change_array_hit(navy->array_client, hit, first, scd);
		i = 1;
	}
	return (0);
}

int client(navy_t *navy, char **array_client)
{
	int return_manage = 0;

	navy->array_server = array_cpy(navy->array);
	navy->array_client = array_client;
	manage_signal_client(navy);
	while (game_is_finish(navy->array_client) != 0) {
		print_tab(navy->array_client, navy->array_server);
		for (int i = 0; i <= 1; i++) {
			if ((return_manage = manage_and_count(
				navy, navy->array_client)) == 84)
				return (84);
			if (return_manage == 1)
				return (0);
		}
	}
	to_free(navy->array_client, navy->array_server);
	return (0);
}