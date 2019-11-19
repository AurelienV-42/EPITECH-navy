/*
** EPITECH PROJECT, 2017
** Library : my_strcpy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
