/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:20:49 by wasmar            #+#    #+#             */
/*   Updated: 2025/10/18 16:32:10 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::add_to_vector_pair(std::vector<std::pair<int, int> > &pairs,
	std::vector<int> &vec)
{
	int	vector_size;
	int	i;
	int	a;
	int	b;

	vector_size = 0;
	i = 0;
	if (vec.size() % 2 == 0)
		vector_size = vec.size();
	else
		vector_size = vec.size() - 1;
	while (i < (int)vector_size)
	{
		a = vec[i];
		b = vec[i + 1];
		vector_comparisons++;
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
		i += 2;
	}
}
void PmergeMe::push_to_main_pend(std::vector<int> &main, std::vector<int> &pend,
	std::vector<std::pair<int, int> > &pairs)
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
void PmergeMe::sort_the_pend(std::vector<int> &main, std::vector<int> &pend,
	std::vector<int> &sorted_main, std::vector<int> &sorted_pend)
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
bool	is_in_vector(std::vector<int> &vec, int value)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
			return (true);
	}
	return (false);
}
int PmergeMe::binary_search_vec(std::vector<int> &vec, int value, int high)
{
	int	low;
	int	mid;

	if (vec.empty())
		return (0);
	low = 0;
	mid = 0;
	if (high >= (int)vec.size())
		high = vec.size() - 1;
	while (low <= high)
	{
		vector_comparisons++;
		mid = low + (high - low) / 2;
		if (vec[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (low);
}
void PmergeMe::generate_insertion_sequence(std::vector<int> &pend_vec,
	std::vector<int> &j_seq, std::vector<int> &order)
{
	size_t i = 3;
	int x = 1;
	size_t j_num;
	while (true)
	{
		j_num = calculate_jacobthal_num(i);
		if (j_num > pend_vec.size())
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
			if (is_in_vector(order, x) == false)
			{
				order.push_back(x);
			}
			else
				break ;
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
}