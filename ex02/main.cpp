/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:49:47 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/19 18:06:56 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Invalid number of arguments.\nUsage: " << argv[0] << " <list of positive integers>\n";
        return 1;
    }

    std::vector<int> input;
    if (!parse_input(argc, argv, input))
        return 1;

    // Thanks to the non-explicit ctor, this also works: PmergeMe pmerge = input;
    PmergeMe pmerge(input); // initializes both internal vector & deque and zeros the counters

    // If you want to test vector path instead:
    // std::vector<int> v_sorted = pmerge.vector_recursive_sort(pmerge.getVector());
    // debug_vector(v_sorted);
    // std::cout << pmerge.getvector_comparisons() << std::endl;

    // Deque path (as in your code)
    std::deque<int> d_sorted = pmerge.deque_recursive_sort(pmerge.getdeque());
    debug_deque(d_sorted);
    std::cout << pmerge.getdeque_comparisons() << std::endl;

    return 0;
}
bool check_duplicate(const std::vector<int> &x)
{
    size_t i = 0;
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

			