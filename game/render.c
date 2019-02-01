/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:32:47 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/01 10:51:54 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*
** 1. We have to store current map's sectors and walls in an array.
** 2. They'll be used to determine where's the player by feeding last_sector_id.
** 3. According to knowledge about player's position we can fill up stack with
**	  walls which considered to be potentially visible
**    (world_wall_id + fully transformed coordinates (to screen-space)).
** 4. 
*/

void	render(NEG *neg)
{
	update_screen(neg);
}
