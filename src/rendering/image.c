/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor </var/spool/mail/victor>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:12:28 by victor            #+#    #+#             */
/*   Updated: 2024/10/21 17:14:30 by vvobis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	pixels_image_syncronize(t_img *image, t_pixel *pixel)
{
	uint	x;
	uint	y;

	y = 0;
	while (y < HI)
	{
		x = 0;
		while (x < WI)
		{
			pixel[y * WI + x].color = &((int *)image->data)[y * WI + x];
			x++;
		}
		y++;
	}
}

t_img	image_create(void *mlx_ptr, uint width, uint height)
{
	t_img	*image_new;
	t_img	img;

	img = (t_img){0};
	image_new = mlx_new_image(mlx_ptr, width, height);
	if (!image_new)
		return (ft_putendl_fd("Failed to create mlx_img\nExiting...", 2), \
				exit (1), img);
	img = *image_new;
	ft_free(&image_new);
	return (img);
}
