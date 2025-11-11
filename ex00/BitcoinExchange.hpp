/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:08:42 by wasmar            #+#    #+#             */
/*   Updated: 2025/11/11 21:06:16 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string,double> data;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& x);
        BitcoinExchange& operator=(const BitcoinExchange& x);
        ~BitcoinExchange();
        
        void load_data(std::string& file_path);
        void print_data() const;

};

bool split_lines(const std::string& line,std::string& date,std::string& value,const std::string& delim);
 std::string trim1(std::string& line);
bool isValidDate(std::string& line);

#endif
