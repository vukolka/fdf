/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:56:23 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:56:25 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "new.h"

void	*new(const void *s_class, ...)
{
	const t_class	*class;
	void			*p;
	va_list			ap;

	class = s_class;
	p = malloc(class->size);
	*(const t_class**)p = class;
	if (class->ctor)
	{
		va_start(ap, s_class);
		p = class->ctor(p, &ap);
		va_end(ap);
	}
	return (p);
}

void	delete(void *self)
{
	const t_class **temp;

	temp = (const t_class **)self;
	if (self && (*temp)->dtor)
		self = (*temp)->dtor(self);
	free(self);
}

void	*clone(const void *self)
{
	const t_class **temp;

	temp = (const t_class **)self;
	if (self && *temp && (*temp)->clone)
		return ((*temp)->clone(self));
	else
		return (NULL);
}

int		differ(const void *self, const void *b)
{
	const t_class **temp;

	temp = (const t_class **)self;
	if (self && (*temp)->differ && b)
		return ((*temp)->differ(self, b));
	return (-1);
}

size_t	size_of(const void *self)
{
	const t_class **temp;

	temp = (const t_class **)self;
	if (self && *temp)
		return ((*temp)->size);
	else
		return (0);
}
