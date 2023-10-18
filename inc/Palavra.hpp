/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palavra.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:41:03 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/10/18 16:44:23 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALAVRA_HPP
# define PALAVRA_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <fstream>
# include <limits>
# include <map>
# include <iterator>
# include <iomanip>
# include <sstream>

class	Palavra
{
	private:
			std::string									_palavra;
			// std::string									_abort_word;
			std::string									_word;
			int											_vidas = 7;
			int											_remaining;
			std::string									_option;
			int											_letters[26] = {0};
			int											_tries = 0;
			std::multimap<int, std::string>				_list;
			std::multimap<int, std::string>::iterator	_ite;
			

	public:
			Palavra();
			Palavra(const Palavra &other);
			Palavra &operator=(Palavra const &cpy);
			~Palavra();

			Palavra(int opt);

			char		take_letter(void);
			void		Word(std::string string);
			int			finish(void);
			int			Play(char C);
			int			dead();
			void		display(void);
			void		win(void);
			void		loose(void);
			void		create_list(void);
			void		drawing(void);
			std::string	not_so_random(void);
			void		UpdateTries(void);
			std::string	Show_option(void);
};

#endif