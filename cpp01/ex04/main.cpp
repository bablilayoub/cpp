/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:39:22 by abablil           #+#    #+#             */
/*   Updated: 2024/07/08 17:13:21 by abablil          ###   ########.fr       */
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
	if (std::string(args[1]).empty() || std::string(args[2]).empty())
	{
		std::cout << "Arguments can't be empty" << std::endl;
		return false;
	}
	return true;
}

int main(int total, char **args)
{
	std::string line;
	std::string search_string = args[2];
	std::string replace_string = args[3];
	
	if (!check_errors(total, args))
		return 1;
		
	std::ifstream in_file(args[1]);
	if (in_file.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}
	std::ofstream out_file(std::string(args[1]) + ".replace");
	if (out_file.fail())
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}
	while (std::getline(in_file, line))
	{
		std::string new_line;
		size_t i = 0;
		while (i < line.length())
		{
			size_t found_pos = line.find(search_string, i);
			if (found_pos < line.length())
			{
				new_line.append(line, i, found_pos - i);
				new_line.append(replace_string);
				i = found_pos + search_string.length();
			}
			else
			{
				new_line.append(line, i, line.length() - i);
				break;
			}
		}
		if (in_file.eof())
			out_file << new_line;
		else
			out_file << new_line << std::endl;
	}
	in_file.close();
	out_file.close();
	return 0;
}