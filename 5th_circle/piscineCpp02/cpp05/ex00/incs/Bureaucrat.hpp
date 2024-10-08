#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "GradeTooHighException.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Bureaucrat {

private:
	// Constructors
	Bureaucrat( void );

	// Variables
	int					_grade;
	std::string const &	_name;

protected:

public:
	// Constructors
	Bureaucrat( std::string const & name, int const grade );
	Bureaucrat( Bureaucrat const & src );
	virtual ~Bureaucrat( void );

	// Operators
	Bureaucrat&		operator=( Bureaucrat const & rhs );

	// Accessors
	int				getGrade( void ) const;
	std::string&	getName( void ) const;

	// Methods
	void			increment( void );
	void			decrement( void );

	// Exeption classes
	class GradeTooHighException;
	class GradeTooLowException;

};

class Bureaucrat::GradeTooHighException : public std::exception {

public:
	virtual char const * what() const throw();

};

class Bureaucrat::GradeTooLowException : public std::exception {

public:
	virtual char const * what() const throw();

};

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
// Redirection operator
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs );
