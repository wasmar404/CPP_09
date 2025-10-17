/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:24 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/17 20:47:27 by wasmar           ###   ########.fr       */
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
//Orthodoc Canonical Form !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
        std::vector<int>  vector_recursive_sort(std::vector<int> &vec);
         std::vector<int>& getVector() { return vector; }
         int getvector_comparisons(){return vector_comparisons;}
         void setvec(){ vector_comparisons = 0;}
        size_t binary_search_vec(std::vector<int> &vec, int value, size_t high);
        void insert(std::vector<int> &pend_vec,std::vector<int> &main_vec);

        };
void debug_vector(std::vector<int> debug);
void debug_pairs(std::vector<std::pair<int,int > > &pairs);

#endif