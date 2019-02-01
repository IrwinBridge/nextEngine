/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:59:18 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/31 12:47:41 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neg.h"

void	setup(NEG *neg)
{
	neg->quit = false;
}

int		neg_exit(NEG *neg)
{
	SDL_DestroyWindow(neg->window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}

NEG		*neg_init(char *title)
{
	NEG *neg;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (init_exit("SDL couldn't be able to initialize!"));
	else
	{
		if (!(neg = ft_memalloc(sizeof(NEG))) ||
			!(neg->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
							SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
							WINDOW_HEIGHT, SDL_WINDOW_OPENGL)))
			return (init_exit(SDL_GetError()));
		else
			neg->screen = SDL_GetWindowSurface(neg->window);
	}
	setup(neg);
	return (neg);
}
