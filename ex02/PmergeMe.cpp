/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:30 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/08 09:19:41 by wasmar           ###   ########.fr       */
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
void PmergeMe::debug_deque()
{
     printf("----------Deque-------------\n");
    for(size_t j = 0;j < deque.size();j++)
    {
        printf("%d\n",deque[j]);
    }   
}

void PmergeMe::debug_vector()
{
    printf("----------Vector-------------\n");
    for(size_t j = 0;j < vector.size();j++)
    {
        printf("%d\n",vector[j]);
    }  
}
void PmergeMe::vector_recursive_sort()
{   
    size_t i = 0;
    int odd = -1;
    size_t vector_size = 0;
    std::vector<std::pair<int,int> > pairs;
    std::vector<int> main;
    std::vector<int> pend;
    if(vector.size() % 2 == 0)
        vector_size = vector.size();
    else 
        vector_size = vector.size() - 1;
    while(i < vector_size)
    {
        int a = vector[i];
        int b = vector[i+1];
        vector_comparisons++;
        if(a < b)
            pairs.push_back(std::make_pair(a,b));
        else
            pairs.push_back(std::make_pair(b,a));
        i+=2;
    }
    if (vector.size() % 2 != 0)
        odd = vector.back();
    
    
}
void PmergeMe::debug_pairs(std::vector<std::pair<int,int> > &pairs)
{
    size_t i = 0;
    while (i < pairs.size())
    {
        printf("(%d,%d) \n",pairs[i].first,pairs[i].second);
        i++;
    } 
}