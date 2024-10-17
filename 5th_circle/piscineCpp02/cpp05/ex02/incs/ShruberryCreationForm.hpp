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

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class ShruberryCreationForm : public AForm {

private:
	ShruberryCreationForm( void );
	ShruberryCreationForm( ShruberryCreationForm const & src );

protected:

public:
	// Constructors / Destructor
	ShruberryCreationForm( std::string const & target );
	virtual ~ShruberryCreationForm( void );

	// Operators
	ShruberryCreationForm&	operator=( ShruberryCreationForm const & rhs );

	// Accessors

	// Methods

	// Exception classes

};

/******************************************************************************/
/*   EXTERNAL FUNCTIONS                                                       */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, ShruberryCreationForm const & rhs );
