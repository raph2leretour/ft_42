#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class ShrubberyCreationForm : public AForm {

private:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );

	// Operators
	ShrubberyCreationForm&	operator=( ShrubberyCreationForm const & rhs );

protected:

public:
	// Constructors / Destructor
	ShrubberyCreationForm( std::string const & target );
	virtual ~ShrubberyCreationForm( void );

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
std::ostream&	operator<<( std::ostream& o, ShrubberyCreationForm const & rhs );
