/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:24 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/11 19:42:10 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <cctype>
#include <deque>
#include <utility> //std::pair

typedef std::pair<int,int> ii;

class PmergeMe
{
	  private:
        std::vector<int>	vector;
		std::deque<int>		deque;
        int vector_comparisons;
        // int deque_comparisons;   
    public:
        void fill_vector_and_deque(std::vector<int> &input);
        // void debug_deque();
        void vector_recursive_sort(std::vector<int> &vec);
         std::vector<int>& getVector() { return vector; }
};
void debug_vector(std::vector<int> debug);
void debug_pairs(std::vector<std::pair<int,int > > &pairs);

#endif