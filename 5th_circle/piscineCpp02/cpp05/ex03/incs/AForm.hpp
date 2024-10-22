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

	// Operators
	AForm&			operator=( AForm const & rhs );

	// Variables
	std::string const	_name;
	bool				_signed;
	int const			_execGrade;
	int const			_signGrade;

protected:
	std::string const	_target;

public:
	// Constructors / Destructor
	AForm( std::string const name, int const execGrade, int const signGrade, std::string const target );
	AForm( AForm const & src );
	virtual ~AForm( void );

	// Accessors
	std::string		getName( void ) const;
	bool			getSigned( void ) const;
	int				getExecGrade( void ) const;
	int				getSignGrade( void ) const;
	std::string		getTarget( void ) const;

	// Methods
	void			beSigned ( Bureaucrat const & bureaucrat );
	virtual void	execute( Bureaucrat const & executor ) const;

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
