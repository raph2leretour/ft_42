/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) : \
			AForm( "RobotomyRequestForm", 45, 72, target ) {}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {

	if ( executor.getExecGrade() > _execGrade ) {

		throw RobotomyRequestForm::GradeTooLowException();
	}

	std::cout << "*Makes some drilling noises*" << std::endl;
	std::srand( std::time( 0 ));
	std::cout << _target << " has" << std::rand() % 2 ? " " : "n't ";
	std::cout << "been romotomized." << std::endl;
}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, RobotomyRequestForm const & rhs ) {

	o << "RobotomyRequestForm redirection operator not set";

	return o;
}
