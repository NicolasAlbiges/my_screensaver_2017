/*
** EPITECH PROJECT, 2017
** circle.c
** File description:
** circle for the screensaver
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Window/Export.h>
#include "my.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int	point_x(coord_t* temp, info_t *info)
{
	if (temp->point.x == (info->width - temp->radius)
	&& temp->compteur_x == 1) {
		temp->compteur_x = temp->compteur_x * (-1);
		temp->point.x = (info->width - temp->radius);
	}
	if (temp->point.x == (0 + temp->radius) && temp->compteur_x == -1) {
		temp->compteur_x = temp->compteur_x  * (-1);
		temp->point.x = (0 + temp->radius);
	}
	temp->point.x = temp->compteur_x + temp->point.x;
	return (0);
}

int	point_y(coord_t* temp, info_t *info)
{
	if (temp->point.y == (info->length - temp->radius)
	&& temp->compteur_y == 1) {
		temp->compteur_y = temp->compteur_y * (-1);
		temp->point.y = (info->length - temp->radius);
	}
	if (temp->point.y == (0 + temp->radius) && temp->compteur_y == -1) {
		temp->compteur_y = temp->compteur_y  * (-1);
		temp->point.y = (0 + temp->radius);
	}
	temp->point.y = temp->compteur_y + temp->point.y;
	return (0);
}

int	*balls_info(info_t *info)
{
	coord_t* temp = info->head;
	int ct = 0;

	while (temp != NULL) {
		ct ++;
		point_x(temp, info);
		point_y(temp, info);
		temp->point.x = temp->compteur_x + temp->point.x;
		temp->point.y = temp->compteur_y + temp->point.y;
		draw_circle(info, temp);
		temp = temp->nxt;
	}
	return (0);
}

info_t	*fill_list(info_t *info, sfVector2i point, sfColor colo)
{
	coord_t* temp = info->head;
	coord_t* new_node = malloc(sizeof(coord_t));
	new_node->point.x = point.x;
	new_node->point.y = point.y;
	new_node->color = colo;
	new_node->radius = 20;
	new_node->compteur_x = 1;
	new_node->compteur_y = 1;
	new_node->nxt = NULL;

	if (temp == NULL)
		info->head = new_node;
	else {
		while (temp->nxt != NULL)
			temp = temp->nxt;
		temp->nxt = new_node;
	}
	return (info);
}
