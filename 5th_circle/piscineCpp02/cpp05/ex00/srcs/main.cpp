#include "Bureaucrat.hpp"

int	main( void ) {

	try {

		Bureaucrat b1( "vache", 4 );
		std::cout << b1 << std::endl;
		b1.increment();
	} catch ( const Bureaucrat::GradeTooHighException& e ) {

		std::cout << e.what() << std::endl;
	}

	try {

		Bureaucrat b3( "tonton Xav", 1 );
		std::cout << b3 << std::endl;
		b3.increment();
	} catch ( const Bureaucrat::GradeTooHighException& e ) {

		std::cout << e.what() << std::endl;
	}

	try {

		Bureaucrat b4( "moi", 150 );
		std::cout << b4 << std::endl;
		b4.decrement();
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
