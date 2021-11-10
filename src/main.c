#include "so_long.h"

int	moviment_valid(t_vars *vars, t_list *player)
{
	//fazer o calculo antes
	while (vars->pos)
	{
		if (vars->pos->content == '1' && vars->pos->height == player->height && vars->pos->width == player->width)
			return (0);
		vars->pos = vars->pos->next;
	}
	if (player->x < 250 && player->x > 50)
		return (34);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int 	img_width;
	int		img_height;
	void	*img;
	static t_list	*t = NULL;

	if (t == NULL)
	{
		while (vars->pos->content != 'P')
			vars->pos = vars->pos->next;
		t = vars->pos;
	}
	if (keycode == 'w')
		t->x = t->x - moviment_valid(vars, t);
	if (keycode == 'd')
		t->width = t->width + moviment_valid(vars, t);
	if (keycode == 's')
		t->height = t->height + moviment_valid(vars, t);
	if (keycode == 'a')
		t->width = t->width - moviment_valid(vars, t);
	mlx_clear_window(vars->mlx, vars->win);
	img = mlx_xpm_file_to_image(vars->mlx, "image/Space01.xpm", &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
}

int	render_next_frame(t_vars *vars)
{
	int		img_widthg;
	int		img_heightg;
	void	*img;
	static t_list	*t = NULL;

	if (t == NULL)
	{
		while (vars->pos->content != 'P')
			vars->pos = vars->pos->next;
		t = vars->pos;
	}
	img = mlx_xpm_file_to_image(vars->mlx, "image/1.xpm", &img_widthg, &img_heightg);
	mlx_put_image_to_window(vars->mlx, vars->win, img, t->width, t->height);
	mlx_destroy_image(vars->mlx, img);
	img = mlx_xpm_file_to_image(vars->mlx, "image/2.xpm", &img_widthg, &img_heightg);
	mlx_put_image_to_window(vars->mlx, vars->win, img, t->width, t->height);
	sleep(0.3);
	mlx_destroy_image(vars->mlx, img);
	img = mlx_xpm_file_to_image(vars->mlx, "image/3.xpm", &img_widthg, &img_heightg);
	mlx_put_image_to_window(vars->mlx, vars->win, img, t->width, t->height);
	sleep(0.3);
	mlx_destroy_image(vars->mlx, img);
}

int	main(void)
{
	t_vars	vars;
	void	*img;
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	img = mlx_xpm_file_to_image(vars.mlx, "image/Space01.xpm", &img_width, &img_height);
	vars.map = matrix_in_map();
	vars.pos = NULL;
	vars.pos = map_validator(vars.map, vars.pos);
	if (vars.pos == NULL)
		return (0);
	vars.win = mlx_new_window(vars.mlx, img_width, img_height, "so_long");
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mount_map(vars, ft_strlen(vars.map[0]) - 1, ft_lenmatrix(vars.map));
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
