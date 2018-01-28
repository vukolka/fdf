/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:58:42 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:58:43 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"
#include "point.h"

static t_class	g_hidden_point;
const void		*g_point;

static void		*point_ctor(void *s_self, va_list *ap)
{
	t_point		*self;

	self = s_self;
	if (!self)
		return (NULL);
	self->x = va_arg(*ap, int);
	self->y = va_arg(*ap, int);
	self->z = va_arg(*ap, int);
	return (self);
}

static void		*point_clone(const void *s_self)
{
	const t_point *self;

	self = s_self;
	if (self)
		return (new(g_point, self->x, self->y, self->z));
	else
		return (NULL);
}

static int		point_differ(const void *s_self, const void *s_b)
{
	const t_point *self;
	const t_point *b;

	self = s_self;
	b = s_b;
	if (self == b)
		return (0);
	if (!self || !b || b->class != g_point || self->class != g_point)
		return (1);
	if (self->x != b->x || self->y != b->y || self->z != b->z)
		return (1);
	return (0);
}

void			point_init(void)
{
	g_hidden_point.size = sizeof(t_point);
	g_hidden_point.ctor = point_ctor;
	g_hidden_point.dtor = NULL;
	g_hidden_point.differ = point_differ;
	g_hidden_point.clone = point_clone;
	g_point = &g_hidden_point;
}
