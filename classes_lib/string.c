/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:01:31 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 13:01:31 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "string.h"
#include "new.h"

static t_class	g_hidden_string;
const void		*g_string;

static void		*string_ctor(void *s_self, va_list *ap)
{
	t_string	*self;
	const char	*text;

	self = s_self;
	text = va_arg(*ap, const char *);
	self->text = ft_strnew(ft_strlen(text));
	if (!self->text)
		return (NULL);
	ft_strcpy(self->text, text);
	return (self);
}

static void		*string_dtor(void *s_self)
{
	t_string *self;

	self = s_self;
	if (!self || !self->text)
		return (self);
	free(self->text);
	self->text = 0;
	return (self);
}

static void		*string_clone(const void *s_self)
{
	const t_string *self;

	self = s_self;
	if (self)
		return (new(g_string, self->text));
	else
		return (NULL);
}

static int		string_differ(const void *s_self, const void *s_b)
{
	const t_string *self;
	const t_string *b;

	self = s_self;
	b = s_b;
	if (self == b)
		return (0);
	if (!self || !b || b->class != g_string || self->class != g_string)
		return (1);
	return (ft_strcmp(self->text, b->text));
}

void			string_init(void)
{
	g_hidden_string.size = sizeof(t_string);
	g_hidden_string.ctor = string_ctor;
	g_hidden_string.dtor = string_dtor;
	g_hidden_string.differ = string_differ;
	g_hidden_string.clone = string_clone;
	g_string = &g_hidden_string;
}
