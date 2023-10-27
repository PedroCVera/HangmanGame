/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:26:00 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/10/27 12:49:22 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Palavra.hpp>

int	start2(void)
{
	int		opt;
	char	c;

	std::cout << "***********************************" << std::endl;
	std::cout << "|Choose which pool to choose from |" << std::endl;
	std::cout << "|Your own word  -       0         |" << std::endl;
	std::cout << "|Animals        -       1         |" << std::endl;
	std::cout << "|Food           -       2         |" << std::endl;
	std::cout << "|countries      -       3         |" << std::endl;
	std::cout << "|Leave          -       4         |" << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << "Option:";
	std::cin >> c;
	
	while (c < '0' || c > '4')
	{
		std::cout << "Fuck off, put a correct number next time!";
		std::cin >> c;
	}
	opt = c - '0';
	
	return (opt);
}

int	main(void)
{
	int		opt = 0;
	int		flag = 0;
	char	c;

	system("clear");
	while (opt != 4)
	{
		c = 'A';
		opt = start2();
		if (opt == 4)
		{	
			std::cout << "Thanks for playing!" << std::endl;
			break ;
		}
		Palavra Playing(opt);
		while (Playing.dead() == 1)
		{
			c = 'A';
			while (c == 'A')
				c = Playing.take_letter();
			Playing.Play(c);
		}
		if (Playing.Show_option() != ".OwnWord.txt")
			Playing.UpdateTries();
		flag++;
	}
	return (0);
}