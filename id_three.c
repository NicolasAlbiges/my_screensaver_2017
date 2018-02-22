/*
** EPITECH PROJECT, 2017
** id_three.c
** File description:
** third id of screensaver with raidus
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int	balls_info_radius(info_t *info, int radius)
{
	coord_t* temp = info->head;

	if (radius > 20)
		radius = 5;
	while (temp != NULL) {
		temp->point.y = temp->compteur_y + temp->point.y;
		temp->point.y = temp->compteur_y + temp->point.y;
		temp->radius = radius;
		draw_circle(info, temp);
		if (temp->nxt == NULL && temp->point.y > 500) {
		ini_point_three(info, 800, 0);
		}
		temp = temp->nxt;
	}
	radius ++;
	return (radius);
}

info_t	*ini_info_three(void)
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
	ini_point_three(info, 800, 0);
	return (info);
}

int	ini_point_three(info_t *info, int x, int y)
{
	fill_list(info, (sfVector2i){10, y}, sfCyan);
	fill_list(info, (sfVector2i){100, y}, sfCyan);
	fill_list(info, (sfVector2i){200, y}, sfCyan);
	fill_list(info, (sfVector2i){300, y}, sfCyan);
	fill_list(info, (sfVector2i){400, y}, sfCyan);
	fill_list(info, (sfVector2i){500, y}, sfCyan);
	fill_list(info, (sfVector2i){600, y}, sfCyan);
	fill_list(info, (sfVector2i){700, y}, sfCyan);
	fill_list(info, (sfVector2i){800, y}, sfCyan);
	fill_list(info, (sfVector2i){900, y}, sfCyan);
	fill_list(info, (sfVector2i){1000, y}, sfCyan);
	fill_list(info, (sfVector2i){1100, y}, sfCyan);
	fill_list(info, (sfVector2i){1200, y}, sfCyan);
	fill_list(info, (sfVector2i){1300, y}, sfCyan);
	fill_list(info, (sfVector2i){1400, y}, sfCyan);
	fill_list(info, (sfVector2i){1500, y}, sfCyan);
	fill_list(info, (sfVector2i){1600, y}, sfCyan);
	fill_list(info, (sfVector2i){1700, y}, sfCyan);
	fill_list(info, (sfVector2i){1800, y}, sfCyan);
	fill_list(info, (sfVector2i){1900, y}, sfCyan);
	return (x);
}

void	event_window_three(info_t *info)
{
	while (sfRenderWindow_pollEvent(info->window, &info->event)){
		if (info->event.type == sfEvtClosed)
			sfRenderWindow_close(info->window);
	}
}

int	id_three(void)
{
	info_t *info = ini_info_three();
	int rad = 0;

	if (!info->window)
		return (84);

	while (sfRenderWindow_isOpen(info->window)) {
		event_window_three(info);

		opacity(info->tab);
		rad = balls_info_radius(info, rad);
		sfRenderWindow_clear(info->window, sfBlack);
		sfTexture_updateFromPixels(info->texture, info->tab->pixels,
			1920, 1080, 0, 0);
		sfSprite_setTexture(info->sprite, info->texture, sfTrue);
		sfRenderWindow_drawSprite(info->window, info->sprite, NULL);
		sfRenderWindow_display(info->window);
	}
	return (0);
}
