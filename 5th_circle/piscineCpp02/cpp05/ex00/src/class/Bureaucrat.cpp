/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:00:41 by rtissera          #+#    #+#             */
/*   Updated: 2024/07/26 17:05:49 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Bureaucrat.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Bureaucrat::Bureaucrat( void ) : _name( _defaultName ), _grade( _lowestGrade ) {}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name ) {

	if ( grade < _highestGrade ) {

		throw Bureaucrat::GradeTooHighException();
	} else if ( grade > _lowestGrade ) {

		throw Bureaucrat::GradeTooLowException();
	} else {

		_grade = grade;
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name( src._name ), _grade( src.grade ) {}

Bureaucrat::~Bureaucrat( void ) {}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Bureaucrat&	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	if ( this != &rhs ) {

		*const_cast<std::string*>(&_name) = rhs._name;
		_grade = rhs._grade;
	}

	return *this;
}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
std::string	Bureaucrat::getName( void ) const {

	return _name;
}

std::string	Bureaucrat::getGrade( void ) const {

	return _Grade;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	Bureaucrat::increaseGrade( void ) {

	if ( _grade == _lowestGrade ) {

		throw Bureaucrat::GradeTooHighException();
	}
	++_grade;
}

void	Bureaucrat::decreaseGrade( void ) {

	if ( _grade == _highestGrade ) {

		throw Bureaucrat::GradeTooLowException();
	}
	--_grade;
}

/******************************************************************************/
/*   THROW STUFF                                                              */
/******************************************************************************/
const char*	Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade too Low";
}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";

	return o;
}
