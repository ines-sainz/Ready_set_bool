#include <iostream>
#include <cstdint>
#include <vector>
#include <stack>
#include "draw.hpp"

// uint32_t : standard 32-bit integer in <cstdint> c++ and <stdint.h> in c
// MAX 4294967295

//Time complexity: O(1) → at most twice as many steps as the input size
//Space complexity: N/A → Not Applicable or Not Assessed

void	print_table(std::vector<std::string> table)
{
	for (std::vector<std::string>::iterator it = table.begin(); it != table.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void	make_top_line(std::string str, std::vector<std::string>& table)
{
	std::string line1 = "| ";
	std::string line2 = "|";
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			line1 += str[i];
			line1 += " | ";
			line2 += "---|";
		}
		else if (str[i] != '!' && str[i] != '&' && str[i] != '|' && str[i] != '^' && str[i] != '>' && str[i] != '=')
			throw (std::runtime_error("Error: invalid character"));
	}
	line1 += "= |";
	line2 += "---|";
	table.push_back(line1);
	table.push_back(line2);
}

int	make_middle_lines(std::string& str)
{
	int lenght = str.length();
	int carry = 0;
	for (lenght; lenght >= 0; lenght--)
	{
		if (str[lenght] == '0')
		{
			carry = 0;
			str[lenght] = '1';
			break;
		}
		if (str[lenght] == '1')
		{
			str[lenght] = '0';
			carry = 1;
		}
	}
	if (carry == 1)
		return (1);
	return (0);
}

auto eval_formula = [](const std::string& str) -> bool
{
    std::stack<char> tree;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '1' || str[i] == '0')
            tree.push(str[i]);
        else if (str[i] == '!')
        {
            if (tree.size() < 1)
                throw(std::runtime_error("Error: RPN expression not correctly written"));
            int result = !(tree.top() - '0');
            tree.pop();
            tree.push(result + '0');
        }
        else if (str[i] == '&' || str[i] == '|' || str[i] == '^' || str[i] == '>' || str[i] == '=')
        {
            if (tree.size() < 2)
                throw(std::runtime_error("Error: RPN expression not correctly written"));
            int right = tree.top() - '0';
                tree.pop();
            int left = tree.top() - '0';
                tree.pop();
            if (str[i] == '&')
                tree.push((left & right) + '0');
            else if (str[i] == '|')
                tree.push((left | right) + '0');
            else if (str[i] == '^')
                tree.push((left ^ right) + '0');
            else if (str[i] == '>')
                tree.push(((!left) | right) + '0');
            else if (str[i] == '=')
                tree.push((left == right) + '0');
        }
        else
            throw(std::runtime_error("Error: character not valid"));
    }
    if (tree.size() != 1)
        throw(std::runtime_error("Error: RPN expression not correctly written"));
    return (tree.top() - '0');
};

int	add_line(std::string str, std::vector<std::string>& table)
{
	std::string line = "| ";
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == '1' || str[i] == '0')
		{
			line += str[i];
			line += " | ";
		}
	}
	bool result = eval_formula(str);
	line += static_cast<char>('0' + result);
	line += " |";
	table.push_back(line);
	return (0);
}

int	check_line(std::string str_cpy, std::string str)
{
	for (size_t i = 0; str_cpy[i]; i++)
	{
		if (str_cpy[i] == '0' || str[i] == '1')
		{
			for (size_t j = 0; str[j]; j++)
			{
				if (str[i] == str[j] && str_cpy[i] != str_cpy[j])
					return (0);
			}
		}
	}
	return (1);
}

auto truth_table = [](const std::string& str)
{
	std::vector<std::string> table;
	std::string	str_cpy;
	make_top_line(str, table);
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		str_cpy += '0';
		else
		str_cpy += str[i];
	}
	while (1)
	{
		if (check_line(str_cpy, str) == 1)
			add_line(str_cpy, table);
		if (make_middle_lines(str_cpy) == 1)
			break ;
	}
	print_table(table);
};

int main(void)
{
	try
	{
		std::string str = "AB&";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "AB|";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "AB^";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "AB>";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "A!";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "AB=";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "AB&A!B!&|";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		std::string str = "AB&C!D!&|";
		std::cout << "truth table = " << str << std::endl;
		truth_table(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
}

//  Symbol  |   Mathematical equivalent |   Description
// --------------------------------------------------------------------------------
//  A...Z   |           A..Z            |   Distinct variables with unknown values
//  !       |           ¬               |   Negation
//  &       |           ∧               |   Conjunction
//  |       |           ∨               |   Disjunction
//  ˆ       |           ⊕               |   Exclusive disjunction
//  >       |           ⇒               |   Material condition
//  =       |           ⇔               |   Logical equivalence
