/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/21 13:52:46 by rtissera         ###   ########.fr       */
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
# include <stdbool.h>
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
// int			medianificator(t_list *lst, int argc);
// void		rb(t_list *stockb, bool log);
// void		rra(t_list *stocka, bool log);
// void		struct_clean(t_struct *lst);
// void		sa(t_list *stocka, bool log);
// void		sb(t_list *stockb, bool log);
// void		ss(t_list *stocka, t_list *stockb, bool log);
// void		rr(t_list *stocka, t_list *stockb, bool log);
// void		rrr(t_list *stocka, t_list *stockb, bool log);
// void		ft_structadd_back(t_struct **lst, t_struct *new);
// t_list		*presort(t_list *stocka, t_list *tmp, int argc);
// t_struct	*ft_structnew(char *buf);
// t_struct	*ft_structlast(t_struct *lst);
int			ft_isdigit(int c);
int			ft_max(t_list *lst);
int			ft_lstsize(t_list *lst);
int			ft_atoi(const char *nptr);
int			main(int argc, char **argv);
bool		checkarg(char **argv);
bool		checksamearg(t_list *stocka);
void		ra(t_list **stocka);
void		lst_clean(t_list **lst);
void		push_swap(t_list *stocka);
void		ft_putstr_fd(char *s, int fd);
void		pa(t_list **stocka, t_list **stockb);
void		pb(t_list **stocka, t_list **stockb);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		big_sort(t_list *stocka, t_list *stockb);
void		push_last_bit_one(t_list **a, t_list **b, int bit_max);
size_t		ft_strlen(const char *s);
t_list		*ft_lstnew(int content);
t_list		*atoi_list(int argc, char **argv);
t_list		*ft_lstlast(t_list *lst);

#endif
