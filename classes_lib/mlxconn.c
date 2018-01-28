/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxconn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:54:22 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:54:23 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxconn.h"
#include "new.h"
#include "../mlx.h"
#include "libft.h"

const void		*g_mlx_class;

static t_class	g_hidden_mlx;

static void		*mlx_ctor(void *s_self, va_list *ap)
{
	t_mlx_class	*self;

	self = s_self;
	self->x = va_arg(*ap, int);
	self->y = va_arg(*ap, int);
	self->title = ft_strdup(va_arg(*ap, char*));
	if (!self->title)
		return (NULL);
	self->conn = mlx_init();
	if (!self->conn)
		return (NULL);
	self->winx = mlx_new_window(self->conn, self->x, self->y, self->title);
	if (!self->winx)
		return (NULL);
	return (self);
}

static void		*mlx_dtor(void *s_self)
{
	t_mlx_class	*self;

	self = s_self;
	mlx_destroy_window(self->conn, self->winx);
	free(self->title);
	return (self);
}

void			mlx_initiate(void)
{
	g_hidden_mlx.size = sizeof(t_mlx_class);
	g_hidden_mlx.ctor = mlx_ctor;
	g_hidden_mlx.dtor = mlx_dtor;
	g_hidden_mlx.clone = NULL;
	g_hidden_mlx.differ = NULL;
	g_mlx_class = &g_hidden_mlx;
}
