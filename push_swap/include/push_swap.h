/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/05/03 09:20:24 by rtissera         ###   ########.fr       */
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
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_list
{
	int				content;
	int				numb;
	struct s_list	*next;
}	t_list;

typedef struct s_struct
{
	char			*content;
	struct s_struct	*next;
}	t_struct;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int			ft_isdigit(int c);
int			ft_max(t_list *lst);
int			ft_lstsize(t_list *lst);
int			main(int argc, char **argv);
int			ft_min(int oldmin, t_list *lst);
bool		checkarg(char **argv);
bool		checksamearg(t_list *stocka);
bool		checksortarg(t_list *stocka);
bool		checkmaxintarg(int argc, char **argv);
void		sa(t_list **stocka);
void		ra(t_list **stocka);
void		rra(t_list **stocka);
void		lst_clean(t_list **lst);
void		littlesort(t_list **stocka);
void		ft_putstr_fd(char *s, int fd);
void		push_swap(int argc, t_list *stocka);
void		pa(t_list **stocka, t_list **stockb);
void		pb(t_list **stocka, t_list **stockb);
void		big_sort(t_list *stocka, t_list *stockb);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		convertnumb(int argc, t_list **stocka, int i);
void		littlesort2(t_list **a, t_list **b, int argc, int i);
void		push_last_bit_one(t_list **a, t_list **b, int bit_max);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_list		*atoi_list(int argc, char **argv);
size_t		ft_strlen(const char *s);
long int	ft_atoi(const char *nptr);

#endif
