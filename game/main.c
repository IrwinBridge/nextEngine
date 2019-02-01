/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:39:00 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/01 12:13:35 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	test_stack(void)
{
	t_stack *head = NULL;

	stack_push(&head, 10);
	stack_push(&head, 20);
	stack_push(&head, 30);

	stack_pop(&head);
	printf("%d\n", stack_peek(head));
}

int		main(void)
{
	NEG *neg;

	srand(time(NULL));
	if (!(neg = neg_init("Fire")))
		return (EXIT_FAILURE);
	test_stack();
	game_loop(neg);
	return (neg_exit(neg));
}
