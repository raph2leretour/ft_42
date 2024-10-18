#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

/******************************************************************************/
/*   DEFINES                                                                  */
/******************************************************************************/

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class ShruberryCreationForm : public AForm {

private:
	ShruberryCreationForm( void );

	// Operators
	ShruberryCreationForm&	operator=( ShruberryCreationForm const & rhs );

protected:

public:
	// Constructors / Destructor
	ShruberryCreationForm( std::string const & target );
	ShruberryCreationForm( ShruberryCreationForm const & src );
	virtual ~ShruberryCreationForm( void );

	// Methods
	void	execute( Bureaucrat const & executor );

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
std::ostream&	operator<<( std::ostream& o, ShruberryCreationForm const & rhs );
