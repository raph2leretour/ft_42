#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void ) {

	try {

		Bureaucrat	bureaucrat( "loiccoz", 11 );
		Form		form( "samy", 10, 123 );

		bureaucrat.signForm( form );

		std::cout << form << std::endl;
	} catch ( std::exception& e ) {

		std::cout << e.what() << std::endl;
	}
}
