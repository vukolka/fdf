/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:02:58 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 13:02:59 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_IMAGE_H
# define FDF_IMAGE_H

extern const void	*g_image;
void				image_init();

typedef struct		s_image
{
	void			*image_ptr;
	int				width;
	int				height;
	int				endian;
	int				size_line;
	int				bits;
	int				*image_data;
}					t_image;

void				init_image();
void				*get_mlx(void *s_mlx);

#endif
