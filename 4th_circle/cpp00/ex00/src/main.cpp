/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:00 by rtissera          #+#    #+#             */
/*   Updated: 2024/01/30 15:05:44 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv) {
	if (argc > 1) {
		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++) {
				std::cout << (char)toupper(argv[i][j]);
			}
		}
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return (0);
}
