/*
** EPITECH PROJECT, 2017
** id_five.c
** File description:
** the fifth id of screensaver
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

info_t	*ini_info_five(void)
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
	ini_point_five(info);
	return (info);
}

void	event_window_five(info_t *info)
{
	while (sfRenderWindow_pollEvent(info->window, &info->event)){
		if (info->event.type == sfEvtClosed)
			sfRenderWindow_close(info->window);
		if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
			sfRenderWindow_close(info->window);
			id_four();
		}
	}
}

int	square_info(info_t *info, int rad, int *b)
{
	coord_t* pt = info->head;

	if (rad > 100)
		*b = 1;
	if (rad <= 10)
		*b = 0;
	while (pt != NULL) {
		rad = rad + size_radius(*b);
		my_draw_square(info, pt->point, rad, pt->color);
		pt = pt->nxt;
	}
	return (rad);
}

int	ini_point_five(info_t *info)
{
	fill_list(info, (sfVector2i){150, 150}, sfBlue);
	fill_list(info, (sfVector2i){320, 320}, sfBlue);
	fill_list(info, (sfVector2i){1900, 500}, sfBlue);
	fill_list(info, (sfVector2i){1600, 500}, sfWhite);
	fill_list(info, (sfVector2i){800, 600}, sfRed);
	fill_list(info, (sfVector2i){1000, 700}, sfRed);
	fill_list(info, (sfVector2i){1200, 800}, sfBlue);
	fill_list(info, (sfVector2i){1400, 900}, sfBlue);
	fill_list(info, (sfVector2i){200, 10}, sfRed);
	fill_list(info, (sfVector2i){400, 200}, sfWhite);
	fill_list(info, (sfVector2i){600, 1600}, sfBlue);
	fill_list(info, (sfVector2i){800, 1800}, sfRed);
	fill_list(info, (sfVector2i){1000, 1000}, sfBlue);
	fill_list(info, (sfVector2i){170, 800}, sfBlue);
	fill_list(info, (sfVector2i){1000, 10}, sfWhite);
	fill_list(info, (sfVector2i){900, 190}, sfWhite);
	fill_list(info, (sfVector2i){490, 700}, sfBlue);
	fill_list(info, (sfVector2i){100, 350}, sfRed);
	fill_list(info, (sfVector2i){200, 1550}, sfBlue);
	fill_list(info, (sfVector2i){700, 1700}, sfBlue);
	return (0);
}

int	id_five(void)
{
	info_t *info = ini_info_five();
	int rad = 10;
	int b = 0;
	int ct = 0;
	
	if (!info->window)
		return (84);
	while(sfRenderWindow_isOpen(info->window)) {
		event_window_five(info);
		opacity(info->tab);
		ct = calls_square(info, &rad, ct, &b);
		sfRenderWindow_clear(info->window, sfBlack);
		sfTexture_updateFromPixels(info->texture, info->tab->pixels, 1920, 1080, 0, 0);
		sfSprite_setTexture(info->sprite, info->texture, sfTrue);
		sfRenderWindow_drawSprite(info->window, info->sprite, NULL);
		sfRenderWindow_display(info->window);
	}
	return (0);
}
