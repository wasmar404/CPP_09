/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:31:30 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/17 19:28:54 by wasmar           ###   ########.fr       */
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
    if(odd != -1)
        sorted_pend.push_back(odd);
    
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
int calculate_jacobthal_num(int x)
{
    if(x == 0)
        return (0);
    if(x == 1)
        return(1);
    int prev_prev = 0;
    int prev = 1;
    int answer = 0;
    int i = 0;
    while(i <= x)
    {
        answer = prev_prev + 2 * prev;
        prev_prev = prev;
        prev = answer;
    }
    return(answer);
}
size_t PmergeMe::binary_search_vec(std::vector<int> vec, int value, size_t high)
{
    size_t low = 0;
    size_t mid = 0;
    if(high >=  vec.size())
        high = vec.size() -1;
    while(low <= high)
    {
        vector_comparisons++;
        mid = low + (high - low) / 2;
        if(vec[mid] < value)
            low = mid + 1;
        else
            high = mid -1;
    }
    return (low);
}
bool is_in_vector(std::vector<int>& vec, int value)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
            return true;
    }
    return false;
}
void PmergeMe::insert(std::vector<int> pend_vec,std::vector<int> main_vec)
{
    std::vector<int> j_seq;
    std::vector<int> order;
    size_t i = 3;
    int x = 1;
    size_t j_num;
    
    while (true)
    {
        j_num = calculate_jacobthal_num(i);
        if (j_num > pend_vec.size())
            break;
        j_seq.push_back(j_num);
        i++;
    }
    i = 0;
    while(i < j_seq.size())
    {
        x = j_seq[i];
        while(x > 1)
        {
            if(is_in_vector(order,x) ==  false )
            {
                order.push_back(x);
            }
            else
                break;
            x--;
        }
        i++;
    }
    i = pend_vec.size();
    while (i > 0)
    {
        if (is_in_vector(order, i) == false)
            order.push_back(i);
        i--;
    }
    (void)main_vec;
}