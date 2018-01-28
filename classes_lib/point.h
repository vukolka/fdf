/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:59:32 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:59:33 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_POINT_H
# define FDF_POINT_H

extern const void	*g_point;
void				point_init();

typedef struct		s_point
{
	void			*class;
	int				x;
	int				y;
	int				z;
}					t_point;

#endif
