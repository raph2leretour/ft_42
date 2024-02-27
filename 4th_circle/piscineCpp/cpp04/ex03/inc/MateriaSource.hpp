/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:44 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/27 18:57:08 by rtissera         ###   ########.fr       */
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
	AMateria*		_source[ 4 ];

public:
	MateriaSource( void );
	MateriaSource( MateriaSource const & src );
	virtual ~MateriaSource( void );

	MateriaSource&		operator=( MateriaSource const & rhs );

	void			learnMateria( AMateria* src );
	AMateria*		createMateria( std::string const & type );

};
