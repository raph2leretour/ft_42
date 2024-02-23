/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:40:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:57:34 by rtissera         ###   ########.fr       */
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
class AAnimal {

protected:
	std::string	_type;

public:
	AAnimal( void );
	AAnimal( std::string type );
	AAnimal( AAnimal const & src );
	virtual ~AAnimal( void );

	AAnimal&		operator=( AAnimal const & rhs );

	std::string	getType( void ) const;

	virtual void	makeSound( void ) const = 0;
	virtual void	printIdeas( void ) const = 0;
};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&		operator<<( std::ostream& o, AAnimal const & rhs );
