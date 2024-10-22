#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class PresidentialPardonForm : public AForm {

private:
	PresidentialPardonForm( void );
	PresidentialPardonForm( PresidentialPardonForm const & src );

	// Operators
	PresidentialPardonForm&	operator=( PresidentialPardonForm const & rhs );

protected:

public:
	// Constructors / Destructor
	PresidentialPardonForm( std::string const & target );
	virtual ~PresidentialPardonForm( void );

	// Methods
	void	execute( Bureaucrat const & executor ) const;

	// Exception classes
	class GradeTooLowException : public std::exception {

	public:
		virtual char const * what() const throw() { return "Grade is too low"; }
	};
	class GradeTooHighException : public std::exception {

	public:
		virtual char const * what() const throw() { return "Grade is too high"; }
	};
};

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, PresidentialPardonForm const & rhs );
