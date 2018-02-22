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
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int	draw_circle_pixel(info_t *info, coord_t* temp, int x, int y)
{
	int equa;

	x = temp->point.x - temp->radius;
	while (x != temp->point.x + temp->radius) {
		equa = pow(x - temp->point.x, 2) + pow(y - temp->point.y, 2);
		if (equa <= pow(temp->radius, 2))
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
