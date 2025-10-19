/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:54:21 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/19 17:51:05 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::add_to_deque_pair(std::deque<std::pair<int, int> > &pairs,
	std::deque<int> &deq)
{
	int	deque_size;
	int	i;
	int	a;
	int	b;

	deque_size = 0;
	i = 0;
	if (deq.size() % 2 == 0)
		deque_size = deq.size();
	else
		deque_size = deq.size() - 1;
	while (i < (int)deque_size)
	{
		a = deq[i];
		b = deq[i + 1];
		deque_comparisons++;
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
		i += 2;
	}
}
void PmergeMe::push_to_main_pend(std::deque<int> &main, std::deque<int> &pend,
	std::deque<std::pair<int, int> > &pairs)
{
	int	i;

	i = 0;
	while (i < (int)pairs.size())
	{
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
		i++;
	}
}
void PmergeMe::sort_the_pend(std::deque<int> &main, std::deque<int> &pend,
	std::deque<int> &sorted_main, std::deque<int> &sorted_pend)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)sorted_main.size())
	{
		j = 0;
		while (j < (int)main.size())
		{
			if (main[j] == sorted_main[i])
			{
				sorted_pend.push_back(pend[j]);
				break ;
			}
			j++;
		}
		i++;
	}
}
bool	is_in_deque(std::deque<int> &deq, int value)
{
	for (size_t i = 0; i < deq.size(); i++)
	{
		if (deq[i] == value)
			return (true);
	}
	return (false);
}
int PmergeMe::binary_search_deq(std::deque<int> &deq, int value, int high)
{
	int	low;
	int	mid;

	if (deq.empty())
		return (0);
	low = 0;
	mid = 0;
	if (high >= (int)deq.size())
		high = deq.size() - 1;
	while (low <= high)
	{
		deque_comparisons++;
		mid = low + (high - low) / 2;
		if (deq[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (low);
}
void PmergeMe::generate_insertion_sequence(std::deque<int> &pend_deq,
	std::deque<int> &j_seq, std::deque<int> &order)
{
	size_t i = 3;
	int x = 1;
	size_t j_num;
	while (true)
	{
		j_num = calculate_jacobthal_num(i);
		if (j_num > pend_deq.size())
			break ;
		j_seq.push_back(j_num);
		i++;
	}
	i = 0;
	while (i < j_seq.size())
	{
		x = j_seq[i];
		while (x > 1)
		{
			if (is_in_deque(order, x) == false)
			{
				order.push_back(x);
			}
			else
				break ;
			x--;
		}
		i++;
	}
	i = pend_deq.size();
	while (i > 0)
	{
		if (is_in_deque(order, i) == false)
			order.push_back(i);
		i--;
	}
}