/*
** EPITECH PROJECT, 2017
** functions.c
** File description:
** funct usefull for screensaver
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

int	draw_line_two(info_t *info, sfVector2i pt_a, sfVector2i pt_b, sfColor c)
{
	int x = pt_a.x;
	int y = pt_a.y;
	int var = pt_b.y;

	if(pt_a.y > pt_b.y) {
		var = pt_a.y;
		y = pt_b.y;
	}
	while (y != var) {
		my_put_pixel(info->tab, x, y, c);
		y++;
	}
	return (0);
}

int	draw_line_one(info_t *info, sfVector2i pt_a, sfVector2i pt_b, sfColor c)
{
	int a = (pt_a.y - pt_b.y) / (pt_a.x - pt_b.x);
	int b = pt_a.y - a * pt_a.x;;
	int x = pt_a.x;
	int y;
	int var = pt_b.x;

	if (pt_a.x != pt_b.x) {
		if (pt_a.x > pt_b.x) {
			var = pt_a.x;
			x = pt_b.x;
		}
		while (x != var) {
			y = a * x + b;
			my_put_pixel(info->tab, x, y, c);
			x++;
		}
	}
	if (pt_a.x == pt_b.x)
		draw_line_two(info, pt_a, pt_b, c);
	return (0);
}

void	my_draw_square(info_t *info, sfVector2i pos, int size, sfColor color)
{
	int var;
	int stop;
	int stop_y = pos.y + size;

	while (pos.y != stop_y) {
		var = (pos.y * 1920 + pos.x) * 4;
		stop = var + (size * 4);
		while (var != stop) {
			info->tab->pixels[var] = color.r;
			info->tab->pixels[var + 1] = color.g;
			info->tab->pixels[var + 2] = color.b;
			info->tab->pixels[var + 3] = color.a;
			var += 4;
		}
		pos.y = pos.y + 1;
	}
}

void	my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color)
{
	unsigned int var = (x + y * buffer->width) * 4;

	if (x > buffer->width || y > buffer->height || x < 0 || y < 0)
		return;
	buffer->pixels[var] = color.r;
	buffer->pixels[var + 1] = color.g;
	buffer->pixels[var + 2] = color.b;
	buffer->pixels[var + 3] = color.a;
}


framebuffer_t *framebuffer_create(int width, int height)
{
	framebuffer_t *tmp = malloc(sizeof(framebuffer_t));
	int var = width * height * 4;

	tmp->width = width;
	tmp->height = height;
	tmp->pixels = malloc(sizeof(framebuffer_t) *(width * height * 4));
	while (var >= 0) {
		tmp->pixels[var] = 0;
		var--;
	}
	return (tmp);
}
