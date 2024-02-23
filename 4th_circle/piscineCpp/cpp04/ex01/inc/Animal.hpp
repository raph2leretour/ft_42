/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:54:17 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Animal {

protected:
	std::string	_type;

public:
	Animal( void );
	Animal( std::string type );
	Animal( Animal const & src );
	virtual ~Animal( void );

	Animal&		operator=( Animal const & rhs );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const;
	virtual void	printIdeas( void ) const;
};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&		operator<<( std::ostream& o, Animal const & rhs );
