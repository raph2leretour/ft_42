/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/10 14:35:47 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************************/
/*   WRAPPER                                    */
/************************************************/
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/************************************************/
/*   INCLUDES                                   */
/************************************************/
#include "libft.h"

/************************************************/
/*   STRUCTURES                                 */
/************************************************/

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int		main(int argc, char **argv);
int		sa(t_list *stocka);
int		sb(t_list *stockb);
int		ss(t_list *stocka, t_list *stockb);
int		pa(t_list *stocka, t_list *stockb);
int		pb(t_list *stocka, t_list *stockb);
int		ra(t_list *stocka);
int		rb(t_list *stockb);
int		rr(t_list *stocka, t_list *stockb);
int		rra(t_list *stocka);
int		rrb(t_list *stockb);
int		rrr(t_list *stocka, t_list *stockb);
int		checkarg(char **argv);
int		checksamearg(t_list *stocka);
int		medianificator(t_list *lst, int argc);
void	lst_clean(t_list *lst);
t_list	*atoi_list(char **argv);
t_list	*presort(t_list *stocka, t_list *tmp, int argc);

#endif
