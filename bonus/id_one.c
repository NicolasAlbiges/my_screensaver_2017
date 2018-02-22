/*
** EPITECH PROJECT, 2017
** bootstrap
** File description:
** bootstrap my screen saver
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

info_t	*ini_info(void)
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
	ini_point(info);
	return (info);
}

int	ini_point(info_t *info)
{
	fill_list(info, (sfVector2i){600, 700}, sfRed);
	fill_list(info, (sfVector2i){100, 900}, sfYellow);
	fill_list(info, (sfVector2i){20, 400}, sfBlue);
	return (0);
}

void	event_window_one(info_t *info)
{
	while (sfRenderWindow_pollEvent(info->window, &info->event)){
		if (info->event.type == sfEvtClosed)
			sfRenderWindow_close(info->window);
		if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
			sfRenderWindow_close(info->window);
			id_two();
		}
	}
}

int	id_one(void)
{
	info_t *info = ini_info();

	if (!info->window)
		return (84);
	while(sfRenderWindow_isOpen(info->window)) {
		event_window_one(info);
		opacity(info->tab);
		sfRenderWindow_clear(info->window, sfBlack);
		balls_info(info);
		sfTexture_updateFromPixels(info->texture, info->tab->pixels, 1920, 1080, 0, 0);
		sfSprite_setTexture(info->sprite, info->texture, sfTrue);
		sfRenderWindow_drawSprite(info->window, info->sprite, NULL);
		sfRenderWindow_display(info->window);
	}
	return (0);
}
