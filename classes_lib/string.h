/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:02:12 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 13:02:13 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_LIB_STRING_H
# define CLASSES_LIB_STRING_H

extern const void	*g_string;
void				string_init(void);

typedef	struct		s_string
{
	const void		*class;
	char			*text;
}					t_string;

#endif
