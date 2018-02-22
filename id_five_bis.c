/*
** EPITECH PROJECT, 2017
** id_five_bis.c
** File description:
** the fifth id with fund usefull
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int	size_radius(int b)
{
	if (b == 1)
		return (-1);
	if (b == 0)
		return (1);
	return (0);
}

int	calls_square(info_t *info, int *rad, int ct, int *b)
{
	if (ct == 150) {
		*rad = square_info(info, *rad, b);
		ct = 0;
	}
	ct ++;
	return (ct);
}
