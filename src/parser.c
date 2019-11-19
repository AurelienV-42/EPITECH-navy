/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

static char **fill_array(char *buff, char **array)
{
	int i = 0;
	int nb = 0;
	static int n = 0;
	int nbi = 0;

	if (buff[2 + n] == buff[5 + n])
		for (int parse = 0; ('0' + parse) != buff[0 + n]; parse++) {
			for (i = 0; buff[2 + n] != i + 'A'; i++);
			for (nb = 0; buff[3 + n] != nb + '1'; nb++);
			array[nb + nbi][i * 2] = buff[0 + n];
			nbi++;
		}
	else
		for (int parse = 0; ('0' + parse) != buff[0 + n]; parse++) {
			for (i = 0; buff[2 + n] != i + 'A'; i++);
			for (nb = 0; buff[3 + n] != nb + '1'; nb++);
			array[nb][(i * 2) + nbi] = buff[0 + n];
			nbi += 2;
		}
	n += 8;
	return (array);
}

static int condition(char *buff, int eof)
{
	if (buff[2 + 8 * eof] < buff[5 + 8 * eof] || buff[3 + 8 * eof]
		> buff[6 + 8 * eof])
		return (84);
	if ((buff[1 + 8 * eof] != ':' || buff[4 + 8 * eof] != ':'
		|| buff[0 + 8 * eof] < '2'
		|| buff[0 + 8 * eof] > '5') && eof < 5)
		return (84);
	return (0);
}

static int condition_map(char *buff)
{
	int eof = 0;
	int i = 0;

	for (i = 0; buff[i] != '\0' && eof <= 4; i++) {
		if (condition(buff, eof) == 84)
			return (84);
		if (buff[2 + 8 * eof] < 'A' || buff[2 + 8 * eof] > 'H'
			|| buff[5 + 8 * eof] < 'A' || buff[5 + 8 * eof] > 'H'
			|| buff[3 + 8 * eof] < '1' || buff[3 + 8 * eof] > '8'
			|| buff[6 + 8 * eof] < '1' || buff[6 + 8 * eof] > '8')
			return (84);
		if (buff[i] == '\n' && i == 7 + 8 * eof)
			eof++;
	}
	if (i != 31)
		return (84);
	return (0);
}

char **parser(char *filepath, char **array_start)
{
	char **array = array_start;
	int fd = open(filepath, O_RDONLY);
	char *buff = malloc(sizeof(char) * 32);

	if (buff == NULL)
		return (NULL);
	if (fd == -1) {
		free(buff);
		return (NULL);
	}
	read(fd, buff, 32);
	buff[31] = '\0';
	if (condition_map(buff) == 84) {
		free(buff);
		return (NULL);
	}
	for (int i = 0; i < 4; i++)
		array = fill_array(buff, array);
	free(buff);
	close(fd);
	return (array);
}