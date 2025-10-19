/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:24 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/19 18:01:37 by wasmar           ###   ########.fr       */
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
        int deque_comparisons;   
    public:
        PmergeMe();                         
        PmergeMe(const PmergeMe& x);    
        PmergeMe& operator=(const PmergeMe& x); 
        ~PmergeMe();                       
 PmergeMe(const std::vector<int>& init);

 
        void fill_vector_and_deque(std::vector<int> &input);
         std::vector<int>& getVector() { return vector; }
         std::deque<int>& getdeque() { return deque; }

         int getvector_comparisons(){return vector_comparisons;}
         int getdeque_comparisons(){return deque_comparisons;}

         void setvec(){ vector_comparisons = 0;}
         void setd(){ deque_comparisons = 0;}
         
     


        void add_to_deque_pair(std::deque<std::pair<int, int> > &pairs,std::deque<int> &deq);
        void push_to_main_pend(std::deque<int> &main, std::deque<int> &pend,std::deque<std::pair<int, int> > &pairs);
        void sort_the_pend(std::deque<int> &main, std::deque<int> &pend,std::deque<int> &sorted_main, std::deque<int> &sorted_pend);
        int  binary_search_deq(std::deque<int> &deq, int value, int high);
        void generate_insertion_sequence(std::deque<int> &pend_deq,std::deque<int> &j_seq, std::deque<int> &order);
        void insert_deque(std::deque<int>& pend_deq,std::deque<int> &main_deq);
        std::deque<int> deque_recursive_sort(std::deque<int> &deq);

        std::vector<int>  vector_recursive_sort(std::vector<int> &vec);
        int binary_search_vec(std::vector<int> &vec, int value, int high);
        void insert_vector(std::vector<int> &pend_vec,std::vector<int> &main_vec);
        void add_to_vector_pair(std::vector<std::pair<int,int> >  &pairs,std::vector<int> &vec);
        void push_to_main_pend(std::vector<int> &main,std::vector<int> &pend,std::vector<std::pair<int,int> > &pairs);
        void sort_the_pend(std::vector<int> &main,std::vector<int> &pend,std::vector<int> &sorted_main,std::vector<int> &sorted_pend);void generate_insertion_sequence(std::vector<int>& pend_vec,std::vector<int> &j_seq ,std::vector<int> &order);
    
};
void debug_deque(std::deque<int> debug);
void debug_vector(std::vector<int> debug);

void debug_pairs(std::vector<std::pair<int,int> > &pairs);
int calculate_jacobthal_num(int x);
bool is_in_vector(std::vector<int>& vec, int value);
bool check_duplicate(const std::vector<int> &x);
bool check_if_digit(char *av);
bool parse_input(int ac, char **av,std::vector<int>  &input);
bool is_in_deque(std::deque<int>& vec, int value);
#endif