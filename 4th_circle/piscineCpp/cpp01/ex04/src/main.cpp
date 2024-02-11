/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:21:11 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/11 17:06:15 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BetterThanReplace.hpp"

int	main( int argc, char ** argv ) {

	if ( argc == 3 ) {

		BetterThanReplace	myReplace = BetterThanReplace( argv[1], argv[2], argv[3] );
		myReplace::myReplace();
	}
	return 0;
}
