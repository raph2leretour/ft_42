#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
//#include "Bureaucrat.hpp"
#include <exception>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Bureaucrat;

class Bureaucrat::GradeTooHighException : public std::exception {

public:
	virtual char const * what() const throw();

};
