/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Bureaucrat.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Bureaucrat::Bureaucrat( std::string const & name, int const grade ) : \
						_name( name ), _grade( grade ) {

	if ( grade > GRADE_MIN ) {

		throw Bureaucrat::GradeTooLowException();
	}
	if ( grade < GRADE_MAX ) {

		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : \
						_name( src._name ), _grade( src._grade ) {}

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

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs ) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.';

	return o;
}
