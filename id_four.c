/*
** EPITECH PROJECT, 2017
** id_four.c
** File description:
** the fourth annimation of screensaver
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

info_t	*ini_info_four(void)
{
	sfVideoMode mode = {1920, 1080, 32};
	info_t *info = malloc(sizeof(info_t));
	char *name = "My_screen_saver";

	info->window = sfRenderWindow_create(mode, name, sfResize
					| sfClose | sfFullscreen, NULL);
	info->sprite = sfSprite_create();
	info->texture = sfTexture_create(1920, 1080);
	info->tab = framebuffer_create(1920, 1080);
	info->width = 1920;
	info->length = 1080;
	info->head = NULL;
	ini_point_four(info, 800, 0);
	return (info);
}

void	event_window_four(info_t *info)
{
	while (sfRenderWindow_pollEvent(info->window, &info->event)){
		if (info->event.type == sfEvtClosed)
			sfRenderWindow_close(info->window);
	}
}

int	*balls_info_four(info_t *info)
{
	coord_t* pt = info->head;
	coord_t* tmp = info->head;
	int b = 0;

	tmp = tmp->nxt;
	while (pt != NULL) {
		point_x(pt, info);
		point_y(pt, info);
		pt->point.x = pt->compteur_x + pt->point.x;
		pt->point.y = pt->compteur_y + pt->point.y;
		b ++;
		if (tmp != NULL && b == 2) {
			draw_line_one(info, pt->point, tmp->point, pt->color);
			b = 0;
		}
		pt = pt->nxt;
		if (tmp != NULL)
			tmp = tmp->nxt;
	}
	return (0);
}

int	ini_point_four(info_t *info, int x, int y)
{
	fill_list(info, (sfVector2i){10, y}, sfBlue);
	fill_list(info, (sfVector2i){100, y}, sfBlue);
	fill_list(info, (sfVector2i){200, y}, sfBlue);
	fill_list(info, (sfVector2i){300, y}, sfWhite);
	fill_list(info, (sfVector2i){400, y}, sfRed);
	fill_list(info, (sfVector2i){500, y}, sfRed);
	fill_list(info, (sfVector2i){600, y}, sfBlue);
	fill_list(info, (sfVector2i){700, y}, sfBlue);
	fill_list(info, (sfVector2i){800, y}, sfRed);
	fill_list(info, (sfVector2i){900, y}, sfWhite);
	fill_list(info, (sfVector2i){1000, y}, sfBlue);
	fill_list(info, (sfVector2i){1100, y}, sfRed);
	fill_list(info, (sfVector2i){1200, y}, sfBlue);
	fill_list(info, (sfVector2i){1300, y}, sfBlue);
	fill_list(info, (sfVector2i){1400, y}, sfWhite);
	fill_list(info, (sfVector2i){1500, y}, sfWhite);
	fill_list(info, (sfVector2i){1600, y}, sfBlue);
	fill_list(info, (sfVector2i){1700, y}, sfRed);
	fill_list(info, (sfVector2i){1800, y}, sfBlue);
	fill_list(info, (sfVector2i){1900, y}, sfBlue);
	return (x);
}

int	id_four(void)
{
	info_t *info = ini_info_four();

	if (!info->window)
		return (84);
	while (sfRenderWindow_isOpen(info->window)) {
		event_window_four(info);
		opacity(info->tab);
		balls_info_four(info);
		sfRenderWindow_clear(info->window, sfBlack);
		sfTexture_updateFromPixels(info->texture, info->tab->pixels,
			1920, 1080, 0, 0);
		sfSprite_setTexture(info->sprite, info->texture, sfTrue);
		sfRenderWindow_drawSprite(info->window, info->sprite, NULL);
		sfRenderWindow_display(info->window);
	}
	return (0);
}
