/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

static int malloc_array(navy_t *ptr)
{
	int nb = 0;

	ptr->array = malloc(sizeof(char *) * 9);
	if (ptr->array == NULL)
		return (84);
	for (int i = 0; i < 8; i++) {
		ptr->array[i] = malloc(sizeof(char) * 17);
		for (nb = 0; nb != 16; nb++)
			ptr->array[i][nb] = ' ';
		ptr->array[i][16] = '\0';
	}
	ptr->array[8] = NULL;
	return (0);
}

static int create_array(navy_t *ptr)
{
	int columns = 0;
	int lines = 0;

	if (malloc_array(ptr) == 84 || ptr->array == NULL)
		return (84);
	while (ptr->array[columns] != NULL) {
		while (ptr->array[columns][lines] != '\0') {
			ptr->array[columns][lines] = '.';
			lines += 2;
		}
		lines = 0;
		columns++;
	}
	return (0);
}

static int connect(navy_t *navy, int ac, char **av)
{
	char **array = array_cpy(navy->array);

	if (ac == 2) {
		if ((array = parser(av[1], array)) == NULL)
			return (84);
		my_putstr("my_pid:  ");
		my_putnbr(getpid());
		if (server(navy, array) == 84)
			return (84);
	} else {
		if ((array = parser(av[2], array)) == NULL)
			return (84);
		my_putstr("my_pid:  ");
		my_putnbr(getpid());
		if (client(navy, array) == 84)
			return (84);
	}
	return (0);
}

int navy_game(navy_t *navy, int ac, char **av)
{
	if (create_array(navy) == 84 || connect(navy, ac, av) == 84) {
		my_putstr_error("You must look at the -h\n");
		return (84);
	}
	return (0);
}
