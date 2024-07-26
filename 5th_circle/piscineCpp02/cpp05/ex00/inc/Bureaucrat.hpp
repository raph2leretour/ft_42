/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:55:04 by rtissera          #+#    #+#             */
/*   Updated: 2024/07/26 18:08:14 by rtissera         ###   ########.fr       */
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
	static st::string const	_defaultName = "Gedeon";
	static int const		_highestGrade = 1;
	static int const		_lowestGrade = 150;

	std::string const		_name;
	int						_grade;

protected:

public:
	Bureaucrat( void );
	Bureaucrat( std::string name, size_t grade );
	Bureaucrat( Bureacrat const & src );

	virtual ~Bureaucrat( void );

	// Operators
	Bureaucrat&				operator=( Bureacrat const & rhs );

	// Accessors
	std::string				getName( void ) const;
	size_t					getGrade( void ) const;

	// Functions
	void					increaseGrade( void );
	void					decreaseGrade( void );

	// Throw stuff
	class GradeTooHighException : public std::exception {

		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {

		public:
			virtual const char* what() const throw();
	};

};

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&				operator<<( std::ostream& o, Bureaucrat const & rhs );
