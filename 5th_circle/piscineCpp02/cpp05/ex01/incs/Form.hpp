#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Bureaucrat;

class Form {

private:
	// Constructors
	Form( void );

	// Operators
	Form&		operator=( Form const & rhs );

	// Variables
	std::string const	_name;
	bool				_signed;
	int const			_execGrade;
	int const			_signGrade;

protected:

public:
	// Constructors / Destructor
	Form( std::string const name, int const execGrade, int const signGrade );
	Form( Form const & src );
	virtual ~Form( void );

	// Accessors
	bool		getSigned( void ) const;
	int			getExeGrade( void ) const;
	int			getSigGrade( void ) const;
	std::string	getName( void ) const;

	// Methods
	void		beSigned ( Bureaucrat const & bureaucrat );

	// Exception classes
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
std::ostream& operator<<( std::ostream& o, Form const & rhs );
