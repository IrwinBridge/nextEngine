/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:37:56 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/01 12:13:53 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEG_H
# define NEG_H

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

# define NEG			t_engine

# include <math.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include <SDL_image.h>
# include "../../dependencies/libft/libft.h"

typedef				short	bool;
# define 			true	1
# define 			false	0

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_vert2d
{
	double			x;
	double			y;
}					t_vert2d;

typedef struct		s_entity
{
	t_vert2d		pos;
}					t_entity;

typedef struct		s_engine
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	double			frame_time;
	bool			quit;
}					t_engine;

void				*init_exit(const char *msg);

int					neg_exit(NEG *neg);
NEG					*neg_init(char *title);

void				update_screen(NEG *neg);
void				put_pixel(NEG *neg, int x, int y, Uint32 color);
Uint32				get_pixel(NEG *neg, int x, int y);
void				clear_screen(NEG *neg, Uint32 color);


/*
***************************** STACK FUNCTIONALITY *****************************
*/

bool				stack_is_empty(t_stack *head);
void				stack_push(t_stack **head, int data);
int					stack_pop(t_stack **head);
int					stack_peek(t_stack *head);

#endif
