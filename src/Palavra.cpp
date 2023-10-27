/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palavra.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:56:32 by pcoimbra          #+#    #+#             */
/*   Updated: 2023/10/27 12:48:27 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Palavra.hpp>

Palavra::Palavra()
{
	// int	randomValue;
	// srand(time(NULL));
	// randomValue = rand();
	// if (randomValue > 105)
	// {
	// 	randomValue = randomValue % 105;
	// }
	// if (randomValue == 0)
	// 	randomValue = 5;
	// _palavra = _animal_list[randomValue];
	// for (int i = 0; i < static_cast<int>(_palavra.size()); i++)
	// {
	// 	if (_palavra[i] == ' ')
	// 		_word[i] = ' ';
	// 	else
	// 		_word[i] = '_';
	// 	if (i + 1 ==  = {0};static_cast<int>(_palavra.size()))
	// 		_word[i + 1] = '\0';
	// }
	// std::cout << _word.c_str() << std::endl;
	// _remaining = static_cast<int>(_palavra.size());
	// std::cout << "Numero de letras: " << _remaining << std::endl;
	std::cout << "NO" << std::endl;
}

Palavra::Palavra(Palavra const &cpy)
{
	_word = cpy._word;
	_palavra = cpy._palavra;
}

Palavra &Palavra::operator=(const Palavra &cpy)
{
	_word = cpy._word;
	_palavra = cpy._palavra;
	return (*this);
}

Palavra::~Palavra()
{
}

Palavra::Palavra(int opt)
{
	int		randomValue = 0;
	std::string	options[4] = {".OwnWord.txt", ".animais.txt", ".comida.txt", ".countries.txt"};
	
	_option = options[opt];
	if (opt != 0)
	{
		srand(time(NULL));
		randomValue = rand();
		create_list();
		if ((randomValue % 3) == 0)
		{
			std::advance(_ite, (randomValue % static_cast<int>(_list.size())));
			Word(_ite->second);
		}
		else
			Word(not_so_random());
	}
	else
	{
			std::string line;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "CHOOSE YOUR WORD:";
			std::getline(std::cin, line);
			std::cout << "linha:" << line;
			Word(line);
	}
}

void	Palavra::create_list(void)
{
	std::string		line;
	std::fstream	inPutFile(_option);

	if (!inPutFile.is_open())
		std::cout << "Error opening the file." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (std::getline(inPutFile, line))
		_list.insert(std::make_pair(std::atoi(line.substr(line.find_last_of(" ") + 1).c_str()), line.substr(0, (line.find_last_of(" ")))));
	_ite = _list.begin();
	inPutFile.close();
}

std::string	Palavra::not_so_random(void)
{
	int		randomValue = 0;
	
	srand(time(NULL));
	randomValue = rand();
	randomValue = randomValue % (static_cast<int>(_list.size()) / 5);
	randomValue = static_cast<int>(_list.size()) - randomValue;
	std::cerr << "_list.size = " << _list.size() << "rndVal = " << randomValue << std::endl;
	std::advance(_ite, randomValue);
	
	return (_ite->second);
}

char	Palavra::take_letter(void)
{
	char	c;

	display();
	std::cout << "Letter: ";
	std::cin >> c;
	if (_letters[c - 'a'] == 1)
	{
		display();
		std::cout << "You've already used this letter!" << std::endl;
		return ('A');
	}
	if (c < 97 || c > 122)
	{
		display();
		std::cout << "You've used an invalid letter!" << std::endl;
		return ('A');
	}
	return (c);
}

void	Palavra::Word(std::string string)
{
	_palavra = string;
	_remaining = 0;
	// int	j = 0;
	for (int i = 0; i < static_cast<int>(_palavra.size()); i++)
	{
		if (_palavra[i] == ' ')
			_word[i] = ' ';
		else
		{
			_word[i] = '_';
			_remaining++;
		}
		if (i + 1 == static_cast<int>(_palavra.size()))
			_word[i + 1] = '\0';
	}
	// for (int i = 0; _word[i]; i++)
	// {
	// 	_abort_word[j] = _word[i];
	// 	j++;
	// 	if (_word[i + 1])
	// 	{
	// 		_abort_word[j] = ' ';
	// 		j++;
	// 	}
	// }
	// _abort_word[j] = '\0';
	std::cout << _word.c_str() << std::endl;
	std::cout << "Numero de letras: " << _remaining << std::endl;
}

int	Palavra::Play(char c)
{
	int	flag = 0;
	
	_letters[c - 'a'] = 1;
	for (int ind = 0; ind < static_cast<int>(_palavra.size()); ind++)
	{
		
		if (_palavra[ind] == c)
		{
			if (_word[ind] != c)
				_remaining -= 1;
			if (_remaining == 0)
			{
				win();
				return (1);
			}
			_word[ind] = c;
			flag = 1;
		}
	}
	_tries++;
	if (flag != 1)
	{
		_vidas -= 1;

	}

	return (0);
}

void	Palavra::display()
{
	std::string	option = _option.substr(1, _option.find_last_of("."));
	
	system("clear");
	std::cout << std::flush;
	std::cout << std::string(70, '*') << std::endl;
	std::cout << "|This is the topic: " << std::internal << std::setw(49) << option << "|" << std::endl;
	std::cout << "|Number of letters: " << std::setw(49) << static_cast<int>(_palavra.size()) << "|" << std::endl;
	std::cout << "|This is how it is: " << std::setw(49) << _word.c_str() << "|" << std::endl;
	// for (int i = 0; i < static_cast<int>(_palavra.size()); i++)
	// {
	// 	if (i + 1 == static_cast<int>(_palavra.size()))
	// 		std::cout << _word[i];
	// 	else
	// 		std::cout << _word[i] << " ";
	// }
	std::cout << std::string(70, '*') << std::endl;
	std::cout << "And you have used these letters: " << std::setw(49);
	for (int i = 0; i < 26; i++)
	{
		if (_letters[i] == 1)
			std::cout << static_cast<char>(i + 97) << " ";
	}
	std::cout 	<< std::endl;
	std::cout << "\n";
	drawing();
}

void	Palavra::win()
{
	system("clear");
	std::cout << "\nG fucking G    " << _palavra << std::endl;
	std::cout << "\n\n" << std::endl;
}

void	Palavra::loose()
{
	system("clear");
	std::cout << "L, the word was: " << _palavra << std::endl;
	std::cout << "\n\n" << std::endl;
}

int		Palavra::dead()
{
	std::cout << "REMAINING: " << _remaining << std::endl;
	if (_remaining > 0 && _vidas > 0)
		return (1);
	else if (_remaining <= 0)
	{
		win();
		return (0);
	}
	else if (_vidas <= 0)
	{
		loose();
		return (0);
	}
	return (0);
}

void	Palavra::UpdateTries(void)
{
	std::ofstream OutPutFile(_option, std::ios::trunc);
	if (!OutPutFile.is_open())
		std::cerr << "Error opening the file at the end " << _option << std::endl;
	if (_ite != _list.end())
	{
		std::string	buffer;

		buffer = _ite->second;
		_list.erase(_ite);
		_list.insert(std::make_pair(_tries, buffer));
	}
	for (_ite = _list.begin(); _ite != _list.end(); ++_ite)
		OutPutFile << _ite->second << " " << _ite->first << "\n";
	OutPutFile.close();
}

void	Palavra::drawing(void)
{
    std::cout << _vidas << " lifes remaining!" << std::endl;
    switch(_vidas)
    {
     	case 7:
     	       std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |         " <<std::endl;
			   std::cout << " |         " <<std::endl;
			   std::cout << " |         " <<std::endl;
     	       std::cout << "_|______________"<<std::endl; 
     		break;      
     	case 6:
     	       std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |         0" <<std::endl;
			   std::cout << " |         " <<std::endl;
			   std::cout << " |         " <<std::endl;
     	       std::cout << "_|______________"<<std::endl;
     		break;      
     	case 5:       
	 			std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |       \\ 0 " <<std::endl;
			   std::cout << " |         " <<std::endl;
			   std::cout << " |         " <<std::endl;
     	       std::cout << "_|______________"<<std::endl;     
     		break;
     	case 4:       
     	       std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |       \\ 0 /" <<std::endl;
			   std::cout << " |         " <<std::endl;
			   std::cout << " |         " <<std::endl;
     	       std::cout << "_|______________"<<std::endl;
     		break;      
     	case 3:
     	       std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |       \\ 0 /" <<std::endl;
     	       std::cout << " |         |"<<std::endl;
			   std::cout << " |         " <<std::endl;
     	       std::cout << "_|______________"<<std::endl;
     		break;       
     	case 2:
     	       std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |       \\ 0 /" <<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |        /  "<<std::endl;
     	       std::cout << "_|______________"<<std::endl;
     		break;       
     	case 1:  
     	       std::cout << " ___________"<<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |       \\ 0 /" <<std::endl;
     	       std::cout << " |         |"<<std::endl;
     	       std::cout << " |        / \\ "<<std::endl;
     	       std::cout << "_|______________"<<std::endl;
    }    
}

std::string	Palavra::Show_option(void)
{
	return (_option);
}