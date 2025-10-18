/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:02:26 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/18 16:03:27 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void debug_deque(std::deque<int> debug)
{
    printf("----------Deque-------------\n");
    for(size_t j = 0;j < debug.size();j++)
    {
        printf("%d\n",debug[j]);
    }   
}

void debug_vector(std::vector<int> debug)
{
    printf("----------Vector-------------\n");
    for(size_t j = 0;j < debug.size();j++)
    {
        printf("%d\n",debug[j]);
    }  
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