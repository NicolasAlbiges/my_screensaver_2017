/*
** EPITECH PROJECT, 2017
** draw_func-two.c
** File description:
** second func of drawing
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <stdlib.h>
#include "my.h"
#include <stdlib.h>
#include <unistd.h>

float	my_pow(float nbr)
{
	int ct = 0;
	float rst = nbr;

	while (ct != 1) {
		rst = rst * nbr;
		ct ++;
	}
	return (rst);
}

int	draw_circle_pixel(info_t *info, coord_t* temp, int x, int y)
{
	int equa;
	int my_y = (y - temp->point.y);

	x = temp->point.x - temp->radius;
	while (x != temp->point.x + temp->radius) {
		equa = my_pow(x - temp->point.x) + my_pow(my_y);
		if (equa <= my_pow(temp->radius))
			my_put_pixel(info->tab, x, y, temp->color);
		x ++;
	}
	return (x);
}

int	draw_circle(info_t *info, coord_t* temp)
{
	int x = temp->point.x - temp->radius;
	int y = temp->point.y - temp->radius;

	while (y != temp->point.y + temp->radius) {
		x = draw_circle_pixel(info, temp, x, y);
		y ++;
	}
	return (0);
}

int	opacity(framebuffer_t *framebuffer)
{
	int x = 0;

	while (x <= framebuffer->width * framebuffer->height * 4) {
		if (framebuffer->pixels[x + 3] < 3)
			framebuffer->pixels[x + 3] = 0;
		else
			framebuffer->pixels[x + 3] -= 3;
		x = x + 4;
	}
	return (0);
}
