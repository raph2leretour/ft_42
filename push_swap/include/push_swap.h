/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/13 17:21:30 by rtissera         ###   ########.fr       */
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
# include "libft.h"

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_struct
{
	char			*content;
	struct s_struct	*next;
}	t_struct;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int			ft_max(t_list *lst);
int			checkarg(char **argv);
int			main(int argc, char **argv);
int			checksamearg(t_list *stocka);
int			medianificator(t_list *lst, int argc);
void		lst_clean(t_list *lst);
void		struct_clean(t_struct *lst);
void		sa(t_list *stocka, bool log);
void		sb(t_list *stockb, bool log);
void		ra(t_list *stocka, bool log);
void		rb(t_list *stockb, bool log);
void		rra(t_list *stocka, bool log);
void		ss(t_list *stocka, t_list *stockb, bool log);
void		pa(t_list *stocka, t_list *stockb, bool log);
void		pb(t_list *stocka, t_list *stockb, bool log);
void		rr(t_list *stocka, t_list *stockb, bool log);
void		rrr(t_list *stocka, t_list *stockb, bool log);
void		ft_structadd_back(t_struct **lst, t_struct *new);
void		big_sort(t_list *stocka, t_stack *stockb, bool log);
static void	push_last_bit_one(t_list *a, t_list *b, int bit_max, bool log);
t_list		*atoi_list(char **argv);
t_list		*presort(t_list *stocka, t_list *tmp, int argc);
t_struct	*ft_structnew(char *buf);
t_struct	*ft_structlast(t_struct *lst);

#endif
