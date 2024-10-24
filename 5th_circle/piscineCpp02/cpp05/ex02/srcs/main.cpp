#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void ) {

	try {

		Bureaucrat bureaucrat( 2, "Karl" ); // error with 200
		ShrubberyCreationForm form1( "Clement" );
		RobotomyRequestForm form2( "Table" );
		PresidentialPardonForm form3( "Ecouteurs" );

		std::cout << std::endl;
		std::cout << "-------------- Form 1 ( Shrubbery ) --------------";
		std::cout << std::endl;
		std::cout << std::endl;
		bureaucrat.signForm( form1 );
		bureaucrat.executeForm( form1 );
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "-------------- Form 2 ( Robotomy ) --------------";
		std::cout << std::endl;
		std::cout << std::endl;
		bureaucrat.signForm( form2 );
		bureaucrat.executeForm( form2 );
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "-------------- Form 3 ( President ) --------------";
		std::cout << std::endl;
		std::cout << std::endl;
		bureaucrat.signForm( form3 );
		bureaucrat.executeForm( form3 );
		std::cout << std::endl;
	} catch ( std::exception& e ) {

		std::cout << e.what() << std::endl;
	}
}
