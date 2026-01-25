/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:00:00 by wasmar            #+#    #+#             */
/*   Updated: 2025/01/25 00:00:00 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;
	if (token.length() == 1 && std::isdigit(token[0]))
		return true;
	return false;
}

double RPN::applyOperator(double a, double b, const std::string& op)
{
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		return a / b;
	}
	throw std::runtime_error("Error: unknown operator");
}

double RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			_stack.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			_stack.push(applyOperator(a, b, token));
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}
