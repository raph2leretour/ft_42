/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "AForm.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
AForm::AForm( std::string const name, int const signGrade, int const execGrade, std::string const target ) : \
			_name( name ), _signed( false ), _execGrade( execGrade ), \
			_signGrade( signGrade ), _target( target ) {

	if ( signGrade > GRADE_MIN ) {

		throw AForm::GradeTooLowException();
	}
	if ( signGrade < GRADE_MAX ) {

		throw AForm::GradeTooHighException();
	}
	if ( execGrade > GRADE_MIN ) {

		throw AForm::GradeTooLowException();
	}
	if ( execGrade < GRADE_MAX ) {

		throw AForm::GradeTooHighException();
	}
}

AForm::AForm( AForm const & src ) : _name( src._name ), _signed( src._signed ), \
			_execGrade( src._execGrade ), _signGrade( src._signGrade ), \
			_target( src._target ) {}

AForm::~AForm( void ) {}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
std::string	AForm::getName( void ) const { return _name; }

bool	AForm::getSigned( void ) const { return _signed; }

int	AForm::getExecGrade( void ) const { return _execGrade; }

int	AForm::getSignGrade( void ) const { return _signGrade; }

std::string	AForm::getTarget( void ) const { return _target; }

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	AForm::beSigned( Bureaucrat const & bureaucrat ) {

	if ( bureaucrat.getGrade() > _signGrade  ) {

		throw AForm::GradeTooLowException();
	}

	_signed = true;
}

void	AForm::execute( Bureaucrat const & executor ) const {

	if ( executor.getGrade() > _execGrade ) {

		throw AForm::GradeTooLowException();
	}

	std::cout << "Executing " << _name << "... Nothing happened." << std::endl;
}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream& operator<<( std::ostream& o, AForm const & rhs ) {

	o << rhs.getName() << " Form";
	o << "; signature grade: " << rhs.getSignGrade();
	o << "; execution grade: " << rhs.getExecGrade();
	o << ( rhs.getSigned() ? "; " : "; not " ) << "signed";

	return o;
}
