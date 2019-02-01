/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:37:49 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/31 13:27:24 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neg.h"

void	clear_screen(NEG *neg, Uint32 color)
{
	SDL_FillRect(neg->screen, NULL, color);
}

void	put_pixel(NEG *neg, int x, int y, Uint32 color)
{
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	*(Uint32 *)(neg->screen->pixels + (x + y * WINDOW_WIDTH)
				* neg->screen->format->BytesPerPixel) = color;
}

Uint32	get_pixel(NEG *neg, int x, int y)
{
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (0);
	return (*(Uint32 *)(neg->screen->pixels + (x + y * WINDOW_WIDTH)
				* neg->screen->format->BytesPerPixel));
}

void	update_screen(NEG *neg)
{
	SDL_UpdateWindowSurface(neg->window);
}
