#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void ) {

	try {

		Bureaucrat	bureaucrat( 11, "loiccoz" );
		Form		form( 10, 123, "samy" );

		bureaucrat.signForm( form );

		std::cout << form << std::endl;
	} catch ( std::exception& e ) {

		std::cout << e.what() << std::endl;
	}
}
