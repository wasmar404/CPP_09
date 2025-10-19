/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:30 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/19 15:15:58 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/////////////////////////////////////VECTOR///////////////////////////////////////////////////////////////////////
std::vector<int> PmergeMe::vector_recursive_sort(std::vector<int> &vec)
{
    int odd = -1;
    std::vector<std::pair<int,int> >  pairs;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> sorted_pend;
    std::vector<int> sorted_main;    
    if(vec.size() <= 1)
         return vec;
    add_to_vector_pair(pairs,vec);
    if (vec.size() % 2 != 0)
        odd = vec.back();
    push_to_main_pend(main,pend,pairs);
    sorted_main = vector_recursive_sort(main);
    sort_the_pend(main,pend,sorted_main,sorted_pend);
    if(odd != -1)
        sorted_pend.push_back(odd);
    insert_vector(sorted_pend,sorted_main);
    return(sorted_main);
}

void PmergeMe::insert_vector(std::vector<int>& pend_vec,std::vector<int> &main_vec)
{
    std::vector<int> order;
    std::vector<int> j_seq;
    size_t i = 0;
    int index = 0;
    size_t pos;
    size_t high = 3;
    generate_insertion_sequence(pend_vec,j_seq,order);
    main_vec.insert(main_vec.begin(),pend_vec[0]);
    while(i < order.size())
    {
        if(order[i] == 1)
        {
            i++;
            continue;
        }
        if(i > 0 && order[i] > order[i-1])
            high = 2 * high + 1;
        
        index = order[i]-1;
        if(high-1 > main_vec.size())
        {
             pos = binary_search_vec(main_vec, pend_vec[index], main_vec.size());
        }
        else
        {
             pos = binary_search_vec(main_vec, pend_vec[index], high-1);
        }
        main_vec.insert(main_vec.begin() + pos, pend_vec[index]);
        i++;
    }
}
/////////////////////////////////////DEQUE///////////////////////////////////////////////////////////////////////

std::deque<int> PmergeMe::deque_recursive_sort(std::deque<int> &deq)
{
    int odd = -1;
    std::deque<std::pair<int,int> >  pairs;
    std::deque<int> main;
    std::deque<int> pend;
    std::deque<int> sorted_pend;
    std::deque<int> sorted_main;    
    if(deq.size() <= 1)
         return deq;
    add_to_deque_pair(pairs,deq);
    if (deq.size() % 2 != 0)
        odd = deq.back();
    push_to_main_pend(main,pend,pairs);
    sorted_main = deque_recursive_sort(main);
    sort_the_pend(main,pend,sorted_main,sorted_pend);
    if(odd != -1)
        sorted_pend.push_back(odd);
    insert_deque(sorted_pend,sorted_main);
    return(sorted_main);
}

void PmergeMe::insert_deque(std::deque<int>& pend_deq,std::deque<int> &main_deq)
{
    std::deque<int> order;
    std::deque<int> j_seq;
    size_t i = 0;
    int index = 0;
    size_t pos;
    size_t high = 3;
    generate_insertion_sequence(pend_deq,j_seq,order);
    main_deq.insert(main_deq.begin(),pend_deq[0]);
    while(i < order.size())
    {
        if(order[i] == 1)
        {
            i++;
            continue;
        }
        if(i > 0 && order[i] > order[i-1])
            high = 2 * high + 1;
        
        index = order[i]-1;
        if(high-1 > main_deq.size())
        {
             pos = binary_search_deq(main_deq, pend_deq[index], main_deq.size());
        }
        else
        {
             pos = binary_search_deq(main_deq, pend_deq[index], high-1);
        }
        main_deq.insert(main_deq.begin() + pos, pend_deq[index]);
        i++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
int calculate_jacobthal_num(int x)
{
    if(x == 0)
        return (0);
    if(x == 1)
        return(1);
    int prev_prev = 0;
    int prev = 1;
    int answer = 0;
    int i = 2;
    while(i <= x)
    {
        answer =  prev + 2 * prev_prev;
        prev_prev = prev;
        prev = answer;
        i++;
    }
    return(answer);
}