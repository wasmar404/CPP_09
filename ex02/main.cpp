/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:49:47 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/19 18:38:22 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Invalid number of arguments.\n";
        return 1;
    }

    std::vector<int> input;
    if (!parse_input(argc, argv, input))
        return 1;

    PmergeMe pmerge(input);
    printf("Before: ");
    debug_vector(pmerge.getVector());
    
    clock_t start = clock();
    std::vector<int> sorted_vec = pmerge.vector_recursive_sort(pmerge.getVector());
	clock_t end = clock();
	double vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    pmerge.setvector(sorted_vec);
    
    start = clock();
    std::deque<int> sorted_deq = pmerge.deque_recursive_sort(pmerge.getdeque());
    end = clock();
	double deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    printf("After: ");
    debug_vector(pmerge.getVector());
    printf("Time to process a range of %d elements with std::vector %f\n",pmerge.getinputsize(),vector_time);
    printf("Time to process a range of %d elements with std::deque %f\n",pmerge.getinputsize(),deque_time);
    
    // printf("Number of Comparisons for vector %d\n",pmerge.getvector_comparisons());
    // printf("Number of Comparisons for deque %d\n",pmerge.getdeque_comparisons());

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
	