/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:55:04 by rtissera          #+#    #+#             */
/*   Updated: 2024/10/07 18:46:33 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>
# include <string>
# include <exception>

/******************************************************************************/
/*   DEFINES                                                                  */
/******************************************************************************/

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Bureaucrat {

private:
	Bureaucrat( void );

	int					_grade;
	std::string const &	_name;

protected:

public:
	Bureaucrat( int const grade );
	Bureaucrat( std::string const & name );
	Bureaucrat( std::string const & name, int const grade );
	Bureaucrat( Bureaucrat const & src );
	virtual ~Bureaucrat( void );

	Bureaucrat&	operator=( Bureaucrat const & rhs );

	std::string const &	getName( void ) const;
	int const			getGrade( void ) const;

};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs );
