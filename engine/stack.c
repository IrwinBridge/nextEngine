/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:13:13 by cmelara-          #+#    #+#             */
/*   Updated: 2019/02/01 12:14:53 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "neg.h"

t_stack		*stack_add_node(int data)
{
	t_stack		*new_node;

	if (!(new_node = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

bool		stack_is_empty(t_stack *head)
{
	return (!head);
}

void		stack_push(t_stack **head, int data)
{
	t_stack		*new_node;

	new_node = stack_add_node(data);
	new_node->next = *head;
	*head = new_node;
}

int			stack_pop(t_stack **head)
{
	t_stack		*temp;
	int			popped_data;

	if (stack_is_empty(*head))
		return (0);
	temp = *head;
	*head = (*head)->next;
	popped_data = temp->data;
	free(temp);
	return (popped_data);
}

int			stack_peek(t_stack *head)
{
	if (stack_is_empty(head))
		return (0);
	return (head->data);
}
