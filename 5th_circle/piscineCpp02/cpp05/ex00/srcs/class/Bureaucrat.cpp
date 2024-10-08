/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Bureaucrat.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Bureaucrat::Bureaucrat( std::string const & name, int const grade ) \
						: _grade( grade ), _name( name ) {}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) \
						: _grade( src._grade ), _name( src._name ) {}

Bureaucrat::~Bureaucrat( void ) {}

/******************************************************************************/
/*   OPERATORS                                                                */
/******************************************************************************/
Bureaucrat&	Bureaucrat::operator=( Bureaucrat const & rhs ) {

	if ( this != &rhs ) {

		// Since the name is const you cannot copy it !
		_grade = rhs._grade;
	}

	return *this;
}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
int	Bureaucrat::getGrade( void ) const { return _grade; }

std::string&	Bureaucrat::getName( void ) const { return _name; }

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/

/******************************************************************************/
/*   EXCEPTIONS                                                               */
/******************************************************************************/
/*char const * bureaucrat::gradetoohighexception::what() const throw() {

	return "grade is too high";
}*/

char const * Bureaucrat::GradeTooLowException::what() const throw() {

		return "Grade is too low";
}

/******************************************************************************/
/*   EXTERNAL FUNTIONS                                                        */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs ) {

	o << getName() << ", bureaucrat grade " << getGrade() << '.';

	return o;
}
