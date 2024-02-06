/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:19:49 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 11:47:33 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstring>

class Zombie {

private:
	std::string	_name;

public:
	Zombie(void);
	~Zombie();

	std::string	getName(void) const;

	void		setName(std::string str);

	void		announce(void);

};

#endif
