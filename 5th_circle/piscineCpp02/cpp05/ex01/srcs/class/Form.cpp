/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Form.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Form::Form( std::string const name, int const signGrade, int const execGrade ) : \
			_name( name ), _signed( false ), _execGrade( execGrade ), \
			_signGrade( signGrade ) {

	if ( signGrade > GRADE_MIN ) {

		throw Form::GradeTooLowException();
	}
	if ( signGrade < GRADE_MAX ) {

		throw Form::GradeTooHighException();
	}
	if ( execGrade > GRADE_MIN ) {

		throw Form::GradeTooLowException();
	}
	if ( execGrade < GRADE_MAX ) {

		throw Form::GradeTooHighException();
	}
}

Form::Form( Form const & src ) : _name( src._name ), _signed( src._signed ), \
				_execGrade( src._execGrade ), _signGrade( src._signGrade ) {}

Form::~Form( void ) {}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
bool	Form::getSigned( void ) const { return _signed; }

int	Form::getExeGrade( void ) const { return _execGrade; }

int	Form::getSigGrade( void ) const { return _signGrade; }

std::string	Form::getName( void ) const { return _name; }

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	Form::beSigned( Bureaucrat const & bureaucrat ) {

	if ( bureaucrat.getGrade() > _signGrade  ) {

		throw Form::GradeTooLowException();
	}

	_signed = true;
}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream& operator<<( std::ostream& o, Form const & rhs ) {

	o << rhs.getName() << ", form signature grade: " << rhs.getSigGrade();
	o << ", execution grade: " << rhs.getExeGrade() << ", ";
	o << rhs.getSigned() ? " " : "not " << "signed";

	return o;
}
