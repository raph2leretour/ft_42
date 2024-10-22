#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class RobotomyRequestForm : public AForm {

private:
	RobotomyRequestForm( void );
	RobotomyRequestForm( RobotomyRequestForm const & src );

	// Operators
	RobotomyRequestForm&	operator=( RobotomyRequestForm const & rhs );

protected:

public:
	// Constructors / Destructor
	RobotomyRequestForm( std::string const & target );
	virtual ~RobotomyRequestForm( void );

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
std::ostream&	operator<<( std::ostream& o, RobotomyRequestForm const & rhs );
