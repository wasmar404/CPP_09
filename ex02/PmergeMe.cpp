/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:30 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/07 21:17:54 by wasmar           ###   ########.fr       */
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

void PmergeMe::debug_vecotr()
{
    printf("----------Vector-------------\n");
    for(size_t j = 0;j < vector.size();j++)
    {
        printf("%d\n",vector[j]);
    }  
}