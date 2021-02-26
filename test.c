#include "minirt.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int test(t_env *env)
{
	mlx_destroy_window(env->mlx, env->mlx_win);
	printf("%s\n", "OK");
	return (1);
}

int main(int argc, char **argv)
{
	t_env env;
	double x;
	double y;

	env.mlx = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx, 800, 400, "Hello world");
	env.img.img = mlx_new_image(env.mlx, 800, 400);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
  y = -1;
	while (y++ < 400 - 1)
	{
		x = -1;
		while (x++ < 800 - 1)
		{
      my_mlx_pixel_put(&env.img, x, y, 0xFF0000);
		}
	}
	mlx_put_image_to_window(env.mlx, env.mlx_win, env.img.img, 0, 0);
	mlx_mouse_hook(env.mlx_win, test, &env);
	// mlx_clear_window(env.mlx, env.mlx_win);
	mlx_loop(env.mlx);
  return (1);
}
