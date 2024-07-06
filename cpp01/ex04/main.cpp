/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:39:22 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 20:18:53 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool check_errors(int total, char **args)
{
	if (total != 4)
	{
		std::cout << "Usage : ./sed filename s1 s2" << std::endl;
		return false;
	}
	if (std::string(args[1]).empty() || std::string(args[2]).empty() || std::string(args[3]).empty())
	{
		std::cout << "Arguments can't be empty" << std::endl;
		return false;
	}
	return true;
}

int main(int total, char **args)
{
	if (!check_errors(total, args))
		return 1;

	std::ifstream file;
	std::ofstream outfile("test.txt");
	std::string line;

	file.open(args[1]);
	if (file.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	std::string search_string = args[2];
	std::string replace_string = args[3];

	while (std::getline(file, line))
	{
		std::string new_line;
		size_t pos = 0;
		while (pos < line.length())
		{
			size_t found_pos = line.find(search_string, pos);
			if (found_pos < line.length())
			{
				new_line.append(line, pos, found_pos - pos);
				new_line.append(replace_string);
				pos = found_pos + search_string.length();
			}
			else
			{
				new_line.append(line, pos, line.length() - pos);
				break;
			}
		}
		outfile << new_line << std::endl;
	}

	file.close();
	outfile.close();
	return 0;
}