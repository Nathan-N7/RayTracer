#include "window.h"

static int  esc_close(int   keysym, t_window *mlx)
{
    if (keysym == ESC)
    {
        mlx_destroy_window(mlx->ptr, mlx->win);
        mlx_destroy_display(mlx->ptr);
        free(mlx->ptr);
        free(mlx);
        exit(0);;
    }
    return (1);
}

static int  event_close(t_window *mlx)
{
    mlx_destroy_window(mlx->ptr, mlx->win);
    mlx_destroy_display(mlx->ptr);
    free(mlx->ptr);
    free(mlx);
    exit(0);
}

void    creat_window(t_window *mlx)
{
    mlx = (t_window *)malloc(sizeof(t_window));
    if (mlx == NULL)
        return ;
    mlx->ptr = mlx_init();
    if (!mlx->ptr)
        return ;
    mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGTH, "MiniRT");
    mlx_key_hook(mlx->win, esc_close, mlx);
    mlx_hook(mlx->win, 17, 0, event_close, mlx);
    mlx_loop(mlx->ptr);
}