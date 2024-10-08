#include "GradeTooHighException.hpp"

char const * Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade is too high";
}

