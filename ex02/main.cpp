/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:49:47 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/05 21:04:00 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
bool parse_input(int ac,char ** av,std::vector<int>& input);// std::vector<int>& vec

int main(int argc,char **argv)
{
	std::vector<int> input;
    if (argc < 2)
    {
        std::cerr << "Invalid number of argument" << std::endl;
        return(1);
    }
    if(parse_input(argc,argv,input) == false)
	{
        printf("error");
	}
	
    for (size_t i = 0; i < input.size(); i++)
    {
        printf("%d\n", input[i]);
    }
    return(0); 
}
bool check_duplicate(const std::vector<int> &x)
{
    size_t i = 0;//main.cpp:30:14: error: comparison of integers of different signs: 'int' and 'std::vector::size_type' (aka 'unsigned long') [-Werror,-Wsign-compare]//   while (i < x.size())
    size_t j = 0;
    while (i < x.size())
    {
        j = i+1;
        while (j < x.size())
        {
            if(x[i] == x[j])
                return(false);
            j++;
        }
        i++;
    }
    return(true);
}
bool check_if_digit(char *av)
{
	int i = 0;
	        while (av[i])
        {
            if (!std::isdigit(static_cast<unsigned char>(av[i])) &&
                !std::isspace(static_cast<unsigned char>(av[i])))
                return false;
            i++;
        }
		return(true);
}
bool parse_input(int ac, char **av,std::vector<int>  &input)
{
    std::vector<int> temp;
	long num;
    int j = 1;
	
    while ( j < ac)  
    {
        std::stringstream ss(av[j]);
		if(check_if_digit(av[j]) == false)
		{
			return false;
		}
        while (ss >> num)
        {
            if (num > 2147483647)
                return false;
            temp.push_back(static_cast<int>(num));
        }
		j++;
    }
	input.insert(input.begin(),temp.begin(),temp.end());
    if (!check_duplicate(temp))
        return false;
    return true;
}

			