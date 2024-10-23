#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void ) {

	try {

		Intern	someRandomIntern;
		AForm*	scf;
		AForm*	rrf;
		AForm*	ppf;
		AForm*	uwu;

		scf = someRandomIntern.makeForm( "shrubbery creation", "You" );
		delete scf;
		rrf = someRandomIntern.makeForm( "robotomy request", "Me" );
		delete rrf;
		ppf = someRandomIntern.makeForm( "presidential pardon", "Punpun" );
		delete ppf;
		uwu = someRandomIntern.makeForm( "wrongness", "^w^" );
	} catch ( std::exception& e ) {

		std::cout << e.what() << std::endl;
	}
}
