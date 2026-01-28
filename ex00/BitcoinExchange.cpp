/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:14:47 by wasmar            #+#    #+#             */
/*   Updated: 2026/01/28 17:27:23 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() {
}
BitcoinExchange::~BitcoinExchange() {    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& x){
    data = x.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& x)
{
    if (this != &x) {
        data = x.data;
    }
    return *this;
}
void BitcoinExchange::load_data(const std::string& file_path)
{
    std::string line;
    std::string date;
    std::string value;
    std::ifstream input(file_path.c_str());
    if(!input)
        throw std::runtime_error("could not open database file.");
    if(!std::getline(input,line))
        throw std::runtime_error("empty database file.");
    while (std::getline(input,line))
    {
        if(line.empty())
            continue;
        if(!split_lines(line,date,value,","))
            continue;
        date = trim1(date);
        value = trim1(value);
        if(!isValidDate(date))
            continue;
        char *end = 0;
        const char* a = value.c_str();
        double newvalue = std::strtod(a, &end);
        if(!a[0] || *end !='\0')
            continue;
        data[date] = newvalue;
    }
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = data.lower_bound(date);
    if (it != data.end() && it->first == date)
        return it->second;
    if (it == data.begin())
        return -1;
    --it;
    return it->second;
}

void BitcoinExchange::processInput(const std::string& input_file)
{
    std::string line;
    std::string date;
    std::string value_str;
    std::ifstream input(input_file.c_str());

    if(!input)
        throw std::runtime_error("could not open file.");
    if(!std::getline(input, line))
        throw std::runtime_error("empty file.");

    while (std::getline(input, line))
    {
        if(line.empty())
            continue;
        if(!split_lines(line, date, value_str, "|"))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = trim1(date);
        value_str = trim1(value_str);

        if(!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        char *end = 0;
        const char* a = value_str.c_str();
        double value = std::strtod(a, &end);

        if(!a[0] || *end != '\0')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if(value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if(value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = getExchangeRate(date);
        if(rate < 0)
        {
            std::cerr << "Error: date too early." << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}

void BitcoinExchange::print_data() const {
    for (std::map<std::string,double>::const_iterator it = data.begin(); it != data.end(); ++it)
        std::cout << it->first << " => " << it->second << "\n";
}

