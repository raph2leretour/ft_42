/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Intern.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Intern::Intern( void ) {}

Intern::~Intern( void ) {}

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
AForm*	Intern::makeForm( std::string const & form, std::string const & target ) {

	std::string	formType[ 3 ] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* formArr[ 3 ] = {
		new ShrubberyCreationForm( target ),
		new RobotomyRequestForm( target ),
		new PresidentialPardonForm( target )
	};

	for ( int i = 0; i < 3; ++i ) {

		if ( form == formType[ i ] ) {

			std::cout << "Intern creates " << form << '.' << std::endl;
			for ( ++i; i < 3; ++i ) {

				delete formArr[ i ];
			}
			return formArr[ i ];
		}
		delete formArr[ i ];
	}

	std::cout << "Error: wrong form type" << std::endl;

	return NULL;
}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Intern const & rhs ) {

	( void )rhs;
	o << "undefined cofee maker...";

	return o;
}
