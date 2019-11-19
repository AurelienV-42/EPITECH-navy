/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int global_i;

static void send_signal_server(char *str, navy_t *navy)
{
	char first = 'A';
	char integer = '0';
	int i_first = 0;
	int i_second = 0;
	int hit = 0;

	while (first != str[0]) {
		kill(navy->pid_client, SIGUSR1);
		first++;
		i_first++;
		usleep(10000);
	}
	while (integer != str[1]) {
		kill(navy->pid_client, SIGUSR2);
		integer++;
		i_second++;
		usleep(10000);
	}
	kill(navy->pid_client, SIGUSR1);
	hit = print_array_hit(str);
	change_array_hit(navy->array_client, hit, ++i_first, i_second);
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
	send_signal_server(str, navy);
	return (0);
}

static void manage_signal_client(void)
{
	struct sigaction act;
	struct sigaction act2;

	act.sa_sigaction = &server_connected;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	act2.sa_handler = &server_connected2;
	act2.sa_flags = 0;
	sigemptyset(&act2.sa_mask);
	sigaction(SIGUSR2, &act2, NULL);
	my_putstr("\nwaiting for enemy connection...\n");
	pause();
}

static int manage_and_count(navy_t *navy, char **array_server)
{
	static int i = 0;
	int first = 0;
	int scd = 0;
	int hit = 0;
	int return_attack = 0;

	if (i == 0) {
		if ((return_attack = attack(navy)) == 84)
			return (84);
		else if (return_attack == 1)
			return (1);
		i++;
	} else {
		first = count_signals1();
		scd = count_signals2();
		hit = hit_or_missed(array_server, first, scd, navy->pid_client);
		change_array_hit(navy->array_server, hit, first, scd);
		i = 0;
	}
	return (0);
}

int server(navy_t *navy, char **array_server)
{
	int return_manage = 0;

	navy->array_client = array_cpy(navy->array);
	navy->array_server = array_server;
	manage_signal_client();
	navy->pid_client = global_i;
	while (game_is_finish(navy->array_server) != 0) {
		print_tab(navy->array_server, navy->array_client);
		for (int i = 0; i <= 1; i++) {
			if ((return_manage = manage_and_count(
				navy, navy->array_server)) == 84)
				return (84);
			if (return_manage == 1)
				return (0);
		}
	}
	to_free(navy->array_server, navy->array_client);
	return (0);
}