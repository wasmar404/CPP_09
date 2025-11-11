/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:14:47 by wasmar            #+#    #+#             */
/*   Updated: 2025/11/11 21:09:28 by wasmar           ###   ########.fr       */
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

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& x){
    if (this != &x) {
        data = x.data;
    }
    return *this;
}
void BitcoinExchange::load_data(std::string& file_path)
{   
    std::string line;
    std::string date;
    std::string value;
    std::ifstream input(file_path.c_str());
    if(!input)
        throw std::runtime_error("error opeing file");
    if(!std::getline(input,line))
        throw std::runtime_error("empty file");
    while (std::getline(input,line))
    {
        if(line.empty())
            continue;
        if(!split_lines(line,date,value,"|"))
            continue;
        date = trim1(date);
        value = trim1(value);
        if(!isValidDate(date))
            continue;
        char *end = 0;
        const char* a= value.c_str();
        double newvalue = std::strtod(a, &end);//"123.45"   →   "123.45\0"
        if(!a[0] || *end !='\0')
            continue;
        data[date] = newvalue;
    }
    
}

void BitcoinExchange::print_data() const {
    for (std::map<std::string,double>::const_iterator it = data.begin(); it != data.end(); ++it)
        std::cout << it->first << " => " << it->second << "\n";
}

