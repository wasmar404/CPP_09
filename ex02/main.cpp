/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:49:47 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/05 19:16:10 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
bool parse_input(char ** av);// std::vector<int>& vec

int main(int argc,char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid number of argument" << std::endl;
        return(1);
    }
    if(parse_input(argv) == false)
        printf("error");
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
bool parse_input(char ** av)
{
    std::vector<int> temp;
    long long num;
    std::stringstream x(av[1]);
    int i = 0;
    while(av[1][i])
    {
        if(!std::isdigit(static_cast<unsigned char>(av[1][i])) && !std::isspace(static_cast<unsigned char>(av[1][i])))
            return false;
        i++;
    }
	/*
		➜  ex02 git:(main) ✗ ./PmergeMe "3333 0-"                                                                  
		➜  ex02 git:(main) ✗ ./PmergeMe "3333 0- "
			error%                                                                                  
		➜  ex02 git:(main) ✗ 
	*/
    while (x >> num) 
    {
        if (num < 0 || num > 2147483647)
            return false;
        temp.push_back(static_cast<int>(num));
    }
    if (!check_duplicate(temp))
        return false;
    return true;
}
			