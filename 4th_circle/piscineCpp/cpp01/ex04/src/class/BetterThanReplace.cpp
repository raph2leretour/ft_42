/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BetterThanReplace.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:50:49 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/11 17:26:06 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BetterThanReplace.hpp"

BetterThanReplace::BetterThanReplace( std::string filename, std::string s1, std::string s2 ) : _filename( filename ), _s1( s1 ), _s2( s2 ) {}

BetterThanReplace~::BetterThanReplace( void ) {}

void	BetterThanReplace::myReplace( void ) {

	std::ifstream	ifs(this->_filename);
	std::string	cur;
}
