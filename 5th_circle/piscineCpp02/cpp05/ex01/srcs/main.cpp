#include "Bureaucrat.hpp"

int	main( void ) {

	try {

		Bureaucrat b3( "tonton Xav", 2 );
		for ( int i = 0; i < 2; ++i ) {

			std::cout << b3 << std::endl;
			b3.increment();
		}
	} catch ( const Bureaucrat::GradeTooHighException& e ) {

		std::cout << e.what() << std::endl;
	}

	try {

		Bureaucrat b4( "moi", 149 );
		for ( int i = 0; i < 2; ++i ) {

			std::cout << b4 << std::endl;
			b4.decrement();
		}
	} catch ( const Bureaucrat::GradeTooLowException& e ) {

		std::cout << e.what() << std::endl;
	}

	try {

		Bureaucrat b5("poulet", 160);
	} catch ( const Bureaucrat::GradeTooLowException& e ) {

		std::cout << e.what() << std::endl;
	}

	try {

		Bureaucrat b4("bk mdr", -5);
	} catch ( const Bureaucrat::GradeTooHighException& e ) {

		std::cout << e.what() << std::endl;
	}
}
