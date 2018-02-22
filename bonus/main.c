/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** choose the id
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <unistd.h>

s_id_t const tab_id[] = {{"1", id_one}, {"2", id_two}, {"3", id_three},
			 {"4", id_four}, {"5", id_five}};

int	flag_h(char **av)
{
	char *str_a = "print the description of all the animations and quit.\n";
	char *str_b = "print the usage and quit.\n\n";
	char *str_c = "switch to the previous animation.\n";
	char *str_d = "switch to the next animation.\n";

	if (av[1][0] == '-' && av[1][1] == 'h') {
		my_printf("animation rendering in a CSFML window.\n\n\n");
		my_printf("USAGE\n ./my_screensaver [OPTIONS] animation_id\n");
		my_printf("  animation_id    ID of the   ");
		my_printf("animation to process (between 1 and 20).\n\n\n");
		my_printf("OPTIONS\n -d%73s", str_a);
		my_printf(" -h%46s", str_b);
		my_printf("USER INTERACTIONS\n");
		my_printf(" LEFT_ARROW %44s", str_c);
		my_printf(" RIGHT_ARROW %39s", str_d);
		return (1);
	}
	return(0);
}

int	flag_d(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'd') {
		my_printf("1:   Simple annimation with ");
		my_printf("balls stuck in a box.\n");
		my_printf("2:   Infinite number of multicolor ");
		my_printf("balls stuck in a box.\n");
		my_printf("3:   Pooring rain.\n");
		my_printf("4:   French flags together stuck in a box.\n");
		my_printf("5:   Random square fading with their size");
		my_printf("increasing and decreasing.\n");
		return (1);
	}
	return (0);
}

int error_input(int ac, char **av)
{
	if (ac == 1) {
		my_printf("./my_screensaver: bad arguments: ");
		my_printf(" 0 given but 1 is required\n");
		my_printf("retry with -h\n");
		exit (84);
	}
	if (ac > 2) {
		my_printf("./my_screensaver: bad arguments: ");
		my_printf(" %d given but 1 is required\n", ac - 1);
		my_printf("retry with -h\n");
		exit (84);
	}
	if (av[1][0] < 45 || (av[1][0] > 45 && av[1][0] < 48) || av[1][0] > 53
	|| (my_strlen(av[1]) != 1 && av[1][1] != 'd' && av[1][1] != 'h')) {
		my_printf("./my_screensaver: bad arguments: ");
		my_printf("retry with -h\n");
		exit (84);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int ct = 0;

	error_input(ac, av);
	if (flag_h(av) == 1 || flag_d(av) == 1)
		return (0);
	while (ct < 5) {
		if (my_strcmp(av[1], tab_id[ct].id_nbr) == 0)
			(tab_id[ct].id_type)();
		ct ++;
	}
}
