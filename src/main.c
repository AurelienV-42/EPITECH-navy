/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

static void leaflet(void)
{
	my_putstr("USAGE\n");
	my_putstr("\t\t./navy [first_player_pid] navy_positions\n\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("\t\tfirst_player_pid  ");
	my_putstr("only for the 2nd player.  pid of the first player.\n");
	my_putstr("\t\tnavy_positions ");
	my_putstr("file representing the positions of the ships.\n");
}

static int condition_main(int ac, char **av, navy_t *ptr)
{
	if (my_strcmp(av[1], "-h") && ac == 2) {
		leaflet();
		return (1);
	}
	if (ac > 4 || ac == 1) {
		my_putstr_error("You must look the -h !\n");
		return (84);
	}
	ptr->pid_server = my_atoi(av[1]);
	if (ptr->pid_server == -1) {
		if (ac != 2) {
			my_putstr_error("You must look the -h !\n");
			return (84);
		}
	} else
		if ((ac == 3 && (my_atoi(av[2]) != -1)) || ac == 2) {
			my_putstr_error("You must look the -h !\n");
			return (84);
		}
	return (0);
}

int main(int ac, char **av)
{
	navy_t navy;
	int return_condition = 0;

	global_i = 0;
	if (ac == 1) {
		my_putstr_error("You must look the -h !\n");
		return (84);
	}
	if ((return_condition = condition_main(ac, av, &navy)) == 1)
		return (0);
	if (return_condition == 84 || navy_game(&navy, ac, av) == 84)
		return (84);
	return (0);
}
