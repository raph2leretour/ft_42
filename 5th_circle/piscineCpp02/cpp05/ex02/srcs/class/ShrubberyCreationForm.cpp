/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) : \
			AForm( "ShrubberyCreationForm", 137, 145, target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

/******************************************************************************/
/*   METHODS                                                                  */
/******************************************************************************/
void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

	if ( executor.getGrade() > getExecGrade() ) {

		throw ShrubberyCreationForm::GradeTooLowException();
	}

	std::ofstream ofs( _target + "_shrubbery" );
	ofs << "              * *    " << std::endl;
	ofs << "           *    *  *" << std::endl;
	ofs << "      *  *    *     *  *" << std::endl;
	ofs << "     *     *    *  *    *" << std::endl;
	ofs << " * *   *    *    *    *   *" << std::endl;
	ofs << " *     *  *    * * .#  *   *" << std::endl;
	ofs << " *   *     * #.  .# *   *" << std::endl;
	ofs << "  *     \"#.  #: #\" * *    *" << std::endl;
	ofs << " *   * * \"#. ##\"       *" << std::endl;
	ofs << "   *       \"###" << std::endl;
	ofs << "             \"##" << std::endl;
	ofs << "              ##." << std::endl;
	ofs << "              .##:" << std::endl;
	ofs << "              :###" << std::endl;
	ofs << "              ;###" << std::endl;
	ofs << "            ,####." << std::endl;
	ofs << "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\" << std::endl;
	ofs.close();
}

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, ShrubberyCreationForm const & rhs ) {

	o << rhs.getName() << " Form";
	o << "; signature grade: " << rhs.getSigGrade();
	o << "; execution grade: " << rhs.getExeGrade();
	o << rhs.getSigned() ? "; " : "; not " << "signed";

	return o;
}
