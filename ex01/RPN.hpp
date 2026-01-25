/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:00:00 by wasmar            #+#    #+#             */
/*   Updated: 2025/01/25 00:00:00 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
	private:
		std::stack<double> _stack;

		bool isOperator(const std::string& token) const;
		bool isNumber(const std::string& token) const;
		double applyOperator(double a, double b, const std::string& op);

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		double evaluate(const std::string& expression);
};

#endif
