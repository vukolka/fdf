/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_classes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvukolov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:52:08 by mvukolov          #+#    #+#             */
/*   Updated: 2018/01/28 12:52:09 by mvukolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "point.h"
#include "mlxconn.h"
#include "image.h"
#include "linked_list.h"

void	make_classes(void)
{
	llist_init();
	string_init();
	point_init();
	mlx_initiate();
	init_image();
}
