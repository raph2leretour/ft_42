#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/*   DEFINES                                                                  */
/******************************************************************************/

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Intern {

private:
	Intern( Intern const & src );

	// Operators
	Intern&	operator=( Intern const & rhs );

protected:

public:
	// Constructors / Destructor
	Intern( void );
	virtual ~Intern( void );

	// Methods
	AForm*	makeForm( std::string const & form, std::string const & target );

};

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Intern const & rhs );
