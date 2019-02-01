/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:33:54 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/31 12:45:15 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	handle_events(NEG *neg, SDL_Event *e)
{
	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_QUIT)
			neg->quit = 1;
		if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_ESCAPE)
			neg->quit = 1;
	}
}

void	fps_count(NEG *neg, double *time, double *old_time, double *ft)
{
	*old_time = *time;
	*time = SDL_GetTicks();
	*ft = (*time - *old_time) / 1000.0f;
	neg->frame_time = *ft;
}

void	game_loop(NEG *neg)
{
	SDL_Event	e;
	double		time;
	double		old_time;
	double		frame_time;

	time = 0;
	old_time = 0;
	while (!neg->quit)
	{
		fps_count(neg, &time, &old_time, &frame_time);
		render(neg);
		handle_events(neg, &e);
	}
}
