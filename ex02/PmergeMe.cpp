/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:30 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/17 15:04:03 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::fill_vector_and_deque(std::vector<int> &temp)
{
    size_t i = 0;
    while(i < temp.size())
    {
        vector.push_back(temp[i]);
        i++;
    }
    i = 0;
    while(i < temp.size())
    {
        deque.push_back(temp[i]);
        i++;
    }
}
// void PmergeMe::debug_deque()
// {
//      printf("----------Deque-------------\n");
//     for(size_t j = 0;j < deque.size();j++)
//     {
//         printf("%d\n",deque[j]);
//     }   
// }

void debug_vector(std::vector<int> debug)
{
    printf("----------Vector-------------\n");
    for(size_t j = 0;j < debug.size();j++)
    {
        printf("%d\n",debug[j]);
    }  
}
std::vector<int> PmergeMe::vector_recursive_sort(std::vector<int> &vec)
{
    size_t i = 0;
    size_t j = 0;
    int odd = -1;
    size_t vector_size = 0;
    std::vector<std::pair<int,int> >  pairs;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> sorted_pend;
    std::vector<int> sorted_main;    
    if(vec.size() <= 1)
         return vec;
    if(vec.size() % 2 == 0)
        vector_size = vec.size();
    else 
        vector_size = vec.size() - 1;


    while(i < vector_size)
    {
        int a = vec[i];
        int b = vec[i+1];
        vector_comparisons++;
        if(a > b)
            pairs.push_back(std::make_pair(a,b));
        else
            pairs.push_back(std::make_pair(b,a));
        i+=2;
    }
    if (vec.size() % 2 != 0)
        odd = vec.back();
    i = 0;
    while(i < pairs.size())
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
        i++;
    }
    sorted_main = vector_recursive_sort(main);
    i = 0;
    while(i < sorted_main.size())
    {
        j = 0;
        while(j < main.size())
        {
            if(main[j] ==  sorted_main[i])
            {
                sorted_pend.push_back(pend[j]);
                break;
            }
            j++;
        }
        i++;
    }
    return(main);
}
void debug_pairs(std::vector<std::pair<int,int> > &pairs)
{
    size_t i = 0;
    while (i < pairs.size())
    {
        printf("(%d,%d) \n",pairs[i].first,pairs[i].second);
        i++;
    } 
}