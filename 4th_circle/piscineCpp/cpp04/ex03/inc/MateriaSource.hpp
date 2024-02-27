/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:44 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/27 16:37:55 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDE                                                                  */
/******************************************************************************/
#include "IMateriaSource.hpp"

/******************************************************************************/
/*   CLASS                                                                    */
/******************************************************************************/
class MateriaSource : public IMateriaSource {

private:
	AMateria*	_source[ 4 ];

public:
	MateriaSource( void );
	MateriaSource( MateriaSource const & src );
	virtual ~MateriaSource( void );

	MateriaSource&	operator=( MateriaSource const & rhs );

	AMateria*	getSource( void ) const;

	void		learnMateria( AMateria* src );
	AMateria*	createMateria( std::string const & type );

};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, MateriaSource const & rhs );
