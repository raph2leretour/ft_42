/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "AForm.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
AForm::AForm( std::string const name, int const signGrade, int const execGrade ) : \
			__name( name ), signed( false ), _execGrade( execGrade ), \
			_signGrade( signGrade ) {

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
					_execGrade( src._execGrade ), _signGrade( src._signGrade ) {}

AForm::~AForm( void ) {}

/******************************************************************************/
/*   OPERATORS                                                                */
/******************************************************************************/
AForm&	AForm::operator=( AForm const & rhs ) {

	if ( this != &rhs ) {

		_signed = rhs._signed;
	}

	return *this;
}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
std::string	AForm::getName( void ) const { return _name; }

bool	AForm::getSigned( void ) const { return _signed; }

int	AForm::getExeGrade( void ) const { return _execGrade; }

int	AForm::getSigGrade( void ) const { return _signGrade; }

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	AForm::beSigned( Bureaucrat const & bureaucrat ) {

	if ( bureaucrat.getGrade() > _signGrade  ) {

		throw AForm::GradeTooLowException();
	}

	_signed = true;
}

void	AForm::execute( Bureaucrat const & bureaucrat ) {}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream& operator<<( std::ostream& o, AForm const & rhs ) {

	o << rhs.getName() << ", form signature grade: " << rhs.getSigGrade();
	o << ", execution grade: " << rhs.getExeGrade() << ", ";
	if ( rhs.getSigned() == false )
		o << "not ";
	o << "signed";

	return o;
}
