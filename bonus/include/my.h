/*
** EPITECH PROJECT, 2017
** header
** File description:
** my.h
*/

#include<stdarg.h>

#ifndef MY_H

#define MY_H

struct framebuffer {
        int width;
        int height;
        sfUint8 *pixels;
};

typedef struct s_coord
{
	sfVector2i point;
	sfColor color;
	int radius;
	int compteur_x;
	int compteur_y;
	struct s_coord *nxt;
}coord_t;

typedef struct framebuffer framebuffer_t;

typedef struct s_info
{
	sfRenderWindow *window;
	sfEvent event;
	sfTexture *texture;
	sfSprite *sprite;
	framebuffer_t *tab;
	int width;
	int length;
        coord_t *head;
}info_t;

typedef struct id
{
	char *id_nbr;
	int (*id_type)(void);
}s_id_t;

typedef struct spec
{
	char spec_pf;
	int (*spec_p)(va_list ap, int ct, char *str, char *str_temp);
}spec_t;

typedef struct length
{
	char *sep_pf;
	int (*sep_p)(va_list ap, int ct, char *str, char *str_temp);
}length_t;

typedef struct flag
{
	char flag_pf;
	int (*flag_p)(char *str, int ctp, long long temp, char *str_temp);
}flag_t;

typedef struct flag_char
{
	char flag_c_pf;
	int (*flag_c_p)(char *str, int ctp, char *temp, char *str_temp);
}flag_char_t;

framebuffer_t *framebuffer_create(int width, int height);
void	my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);
void	my_draw_square(info_t *info, sfVector2i pos, int size, sfColor color);
int	draw_line_one(info_t *info, sfVector2i pt_a, sfVector2i pt_b, sfColor c);
int	draw_line_two(info_t *info, sfVector2i pt_a, sfVector2i pt_b, sfColor c);
int	draw_circle(info_t *info, coord_t* temp);
int	draw_circle_pixel(info_t *info, coord_t* temp, int x, int y);
int     opacity(framebuffer_t *framebuffer);
info_t	*fill_list(info_t *info, sfVector2i point, sfColor colo);
int	ini_point(info_t *info);
info_t	*ini_info(void);
info_t	*ini_info_five(void);
int	ini_point_five(info_t *info);
info_t	*ini_info_two(void);
int	ini_point_two(info_t *info, int x, int y);
int	point_x(coord_t* temp, info_t *info);
int	point_y(coord_t* temp, info_t *info);
int	*balls_info(info_t *info);
int	*balls_info_five(info_t *info);
int	size_radius(int b);
int	calls_square(info_t *info, int *rad, int ct, int *b);
int	square_info(info_t *info, int rad, int *b);
int	balls_info_radius(info_t *info, int radius);
int     id_one(void);
void	event_window_one(info_t *info);
int     id_two(void);
void	event_window_two(info_t *info);
int	id_four(void);
int	ini_point_four(info_t *info, int x, int y);
int	id_three(void);
void	event_window_three(info_t *info);
int	ini_point_three(info_t *info, int x, int y);
info_t	*ini_info_three(void);
void	event_window_five(info_t *info);
int	id_five(void);
int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str, int len);
char	*my_revstr(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
int	my_strlen(char *str);
char	*my_strncat(char *dest, char *src, int n);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcpy(char *dest, char const *src);
char	*my_strncpy(char *dest, char *src, int n);
void	my_swap(int *a, int *b);
char	*swap_output(char *base, int nb);
long long	my_put_long_long(long long nb);
void	my_put_unsg_ll(unsigned long long nb);
int	my_long_long_len(long long nb);
int	flag_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_long(va_list ap, int ct, char *str, char *str_temp);
int	flag_h_nbr(va_list ap, int ct, char *str, char *str_temp);
int	flag_long_long(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_short(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_l(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_ll(va_list ap, int ct, char *str, char *str_temp);
int	flag_p(va_list ap, int ct, char *str, char *str_temp);
int	flag_s(va_list ap, int ct, char *str, char *str_temp);
int	flag_c(va_list ap, int ct, char *str, char *str_temp);
int	flag_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_plus(char *str_temp, long long rst, int b, int nbr);
int	flag_plus_bis(char *str_temp, long long rst, int b);
int	nbr_disp(int temp_len, char *str_temp, int nbr, int b);
int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
int	nbr_disp_thd(long long rst);
void	base(unsigned long long nbr, char *str);
void	separator_flag(char *str, va_list ap, int ct, char *str_temp);
void	flag_one(char *str, va_list ap, int ct, char *str_temp);
int	choise_flag(char *str, int ct, int b);
char	*copy_flag(char *str, char *temp, int ct);
char	*copy_str(char *str, char *str_temp, int ct);
void	my_printf(char *str, ...);
int	len_flag(char *str, int ct);
void	flag_sign(long long rst);
int	flag_flag(char *str, int ct);
int	choise_flag_flag(char *str, int ctp, long long temp, char *str_temp);
int	choise_flg_flg_c(char *str, int ctp, char* temp, char *str_temp);
void	flag_nbr_disp(int nbr, int len_f);
int	flag_nbr(char *str, char *str_temp, int ctp, int temp);
void	flag_zero_disp(int nbr, int len_f);
int	flag_long_long_d(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_u(va_list ap, int ct, char *str, char *str_temp);
int	flag_ss(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_d(va_list ap, int ct, char *str, char *str_temp);
void	flag_has_o(char *str_temp);
void	flag_has_x(char *str_temp);
void	flag_has_xx(char *str_temp);


#endif
