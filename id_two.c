/*
** EPITECH PROJECT, 2017
** bootstrap
** File description:
** bootstrap my screen saver
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "my.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

info_t	*ini_info_two(void)
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
	ini_point_two(info, 800, 0);
	return (info);
}

int	ini_point_two(info_t *info, int x, int y)
{
	fill_list(info, (sfVector2i){x, y}, sfMagenta);
	y = 100;
	fill_list(info, (sfVector2i){x, y}, sfYellow);
	y = 200;
	fill_list(info, (sfVector2i){x, y}, sfWhite);
	y = 300;
	fill_list(info, (sfVector2i){x, y}, sfGreen);
	y = 400;
	fill_list(info, (sfVector2i){x, y}, sfBlue);
	y = 500;
	fill_list(info, (sfVector2i){x, y}, sfRed);
	y = 600;
	fill_list(info, (sfVector2i){x, y}, sfCyan);
	return (x);
}

void	event_window_two(info_t *info)
{
	while (sfRenderWindow_pollEvent(info->window, &info->event)){
		if (info->event.type == sfEvtClosed)
			sfRenderWindow_close(info->window);
	}
}

int	calls_circle(int ct, info_t *info)
{
	if (ct == 200) {
		ini_point_two(info, 300, 0);
		ct = 0;
	}
	ct ++;
	return (ct);
}

int	id_two(void)
{
	info_t *info = ini_info_two();
	int ct = 0;

	if (!info->window)
		return (84);

	while (sfRenderWindow_isOpen(info->window)) {
		event_window_two(info);
		opacity(info->tab);
		balls_info(info);
		ct = calls_circle(ct, info);
		sfRenderWindow_clear(info->window, sfBlack);
		sfTexture_updateFromPixels(info->texture, info->tab->pixels,
			1920, 1080, 0, 0);
		sfSprite_setTexture(info->sprite, info->texture, sfTrue);
		sfRenderWindow_drawSprite(info->window, info->sprite, NULL);
		sfRenderWindow_display(info->window);
	}
	return (0);
}
