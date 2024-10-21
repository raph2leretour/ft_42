/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Bureaucrat.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Bureaucrat::Bureaucrat( int const grade, std::string const & name ) : \
			_grade( grade ), _name( name ) {

	if ( grade > GRADE_MIN ) {

		throw Bureaucrat::GradeTooLowException();
	}
	if ( grade < GRADE_MAX ) {

		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) \
			: _grade( src._grade ), _name( src._name ) {}

Bureaucrat::~Bureaucrat( void ) {}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
int	Bureaucrat::getGrade( void ) const { return _grade; }

std::string	Bureaucrat::getName( void ) const { return _name; }

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	Bureaucrat::increment( void ) {

	if ( _grade - 1 < GRADE_MAX ) {

		throw Bureaucrat::GradeTooHighException();
	}
	--_grade;
}

void	Bureaucrat::decrement( void ) {

	if ( _grade + 1 > GRADE_MIN ) {

	throw Bureaucrat::GradeTooLowException();
	}
	++_grade;
}

void	Bureaucrat::signForm( AForm& form ) {

	try {

		form.beSigned( *this );
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch ( AForm::GradeTooLowException& e ) {

		std::cout << getName() << " couldn't sign form " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form ) {

	try {

		form.execute( *this );
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} catch ( AForm::GradeTooLowException& e ) {

		std::cout << getName() << " couldn't execute form " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

/******************************************************************************/
/*   EXTERNAL FUNTIONS                                                        */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.';

	return o;
}
