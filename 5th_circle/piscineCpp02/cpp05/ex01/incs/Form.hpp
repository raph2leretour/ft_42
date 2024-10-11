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
class Form {

private:
	// Constructors
	Form( void );

	// Variables
	bool				_signed;
	int const			_sigGrade;
	int const			_exeGrade;
	std::string const	_name;

protected:

public:
	// Constructors / Destructor
	Form( int const sigGrade, int const exeGrade, std::string const name );
	Form( Form const & src );
	virtual ~Form( void );

	// Operators
	Form&		operator=( Form const & rhs );

	// Accessors
	bool		getSigned( void ) const;
	int			getSigGrade( void ) const;
	int			getExeGrade( void ) const;
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
