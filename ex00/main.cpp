/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:26:29 by wasmar            #+#    #+#             */
/*   Updated: 2025/11/11 21:12:25 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool split_lines(const std::string& line,std::string& date,std::string& value,const std::string& delim)
{
    std::size_t pos = line.find(delim);
    if (pos == std::string::npos) return false;
    date = line.substr(0,pos);
    value = line.substr(pos+ delim.size());
    return(true);
}

std::string trim1(const std::string& line)
{
    std::size_t a = 0;
    std::size_t b = line.size();
    while (a < b && std::isspace(static_cast<unsigned char>(line[a])))
    {
        a++;
    }
    while (b > a && std::isspace(static_cast<unsigned char>(line[b-1])))
    {
        b--;
    }
    return line.substr(a, b - a);
}
static int daysInMonth(int year, int month) {
    static const int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2) {
        bool leap = false;

        if ((year % 4 == 0) && (year % 100 != 0))
            leap = true;
        else if (year % 400 == 0)
            leap = true;

        if (leap)
            return 29;
        else
            return 28;
    }
    return days[month - 1];
}
bool isValidDate(const std::string& line)
{
    std::size_t i = 0;
    if (line.size() != 10)
        return false;

    if (line[4] != '-' || line[7] != '-')
        return false;

    while (i < line.size()) {
        if (i != 4 && i != 7) {
            if (!std::isdigit(static_cast<unsigned char>(line[i])))
                return false;
        }
        i++;
    }

    int y = std::atoi(line.substr(0, 4).c_str());
    int m = std::atoi(line.substr(5, 2).c_str());
    int d = std::atoi(line.substr(8, 2).c_str());

    if (m < 1 || m > 12)
        return false;
    int dim = daysInMonth(y, m);
    if (d < 1 || d > dim)
        return false;

    return true;
}
int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc <file>\n";
        return 1;
    }

    try {
        BitcoinExchange btc;

        btc.load_data("data.csv");
        btc.processInput(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}