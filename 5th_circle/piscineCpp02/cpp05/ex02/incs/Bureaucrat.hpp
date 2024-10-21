#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

/******************************************************************************/
/*   DEFINES                                                                  */
/******************************************************************************/
#define GRADE_MAX 1
#define GRADE_MIN 150

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class AForm;

class Bureaucrat {

private:
	// Constructors
	Bureaucrat( void );

	// Operators
	Bureaucrat&	operator=( Bureaucrat const & rhs );

	// Variables
	int					_grade;
	std::string const 	_name;

protected:

public:
	// Constructors
	Bureaucrat( int const grade, std::string const & name );
	Bureaucrat( Bureaucrat const & src );
	virtual ~Bureaucrat( void );

	// Accessors
	int			getGrade( void ) const;
	std::string	getName( void ) const;

	// Methods
	void		increment( void );
	void		decrement( void );
	void		signForm( AForm& form );
	void		executeForm( AForm const & form );

	// Exeption classes
	class GradeTooLowException : public std::exception {

	public:
		virtual char const * what() const throw() {

		return "Grade is too low";
		}
	};
	class GradeTooHighException : public std::exception {

	public:
		virtual char const * what() const throw() {

		return "Grade is too high";
		}
	};

};

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
// Redirection operator
std::ostream&	operator<<( std::ostream& o, Bureaucrat const & rhs );
