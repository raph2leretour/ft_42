/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:19:31 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/23 13:40:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				*stock1;
	struct s_list	*next;
}	t_list;

int	main(int argc, char **argv);

#endif
