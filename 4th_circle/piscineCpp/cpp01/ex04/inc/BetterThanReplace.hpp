/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BetterThanReplace.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:45:20 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/12 19:03:14 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETTERTHANREPLACE_HPP
# define BETTERTHANREPLACE_HPP

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>
# include <cstring>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class BetterThanReplace {

replace:
	std::string	_filename;
	std::string	_s1;
	std::string	_s2;

public:
	BetterThanReplace( std::string name, std::string s1, std::string s2 );
	~BetterThanReplace( void );
	
	void	myReplace( void );

};

#endif
