/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) : \
			AForm( "PresidentialPardonForm", 5, 25, target ) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const {

	if ( executor.getGrade() > getExecGrade() ) {

		throw PresidentialPardonForm::GradeTooLowException();
	}

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, PresidentialPardonForm const & rhs ) {

	o << rhs.getName() << " Form";
	o << "; signature grade: " << rhs.getSignGrade();
	o << "; execution grade: " << rhs.getExecGrade();
	o << ( rhs.getSigned() ? "; " : "; not " ) << "signed";

	return o;
}
