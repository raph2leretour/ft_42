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

class AForm {

private:
	// Constructors
	AForm( void );

	// Variables
	std::string const	_name;
	bool				_signed;
	int const			_execGrade;
	int const			_signGrade;

protected:

public:
	// Constructors / Destructor
	AForm( std::string const name, int const execGrade, int const signGrade );
	AForm( AForm const & src );
	virtual ~AForm( void );

	// Operators
	AForm&			operator=( AForm const & rhs );

	// Accessors
	std::string		getName( void ) const;
	bool			getSigned( void ) const;
	int				getExeGrade( void ) const;
	int				getSigGrade( void ) const;

	// Methods
	void			beSigned ( Bureaucrat const * bureaucrat );
	virtual void	execute( Bureaucrat const & executor );

	// Exception classes
	class GradeTooLowException : public std::exception {

	public:
		virtual char const * what() const throw() { return "Grade is too low"; }
	};
	class GradeTooHighException : public std::exception {

	public:
		virtual char const * what() const throw() { return "Grade is too high"; }
	};
};

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream& operator<<( std::ostream& o, AForm const & rhs );
