/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxconn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:54:25 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:54:26 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLXCONN_H
# define FDF_MLXCONN_H

extern const void	*g_mlx_class;

typedef struct		s_mlx_class
{
	void			*conn;
	void			*winx;
	int				x;
	int				y;
	char			*title;
}					t_mlx_class;

void				mlx_initiate();

#endif
