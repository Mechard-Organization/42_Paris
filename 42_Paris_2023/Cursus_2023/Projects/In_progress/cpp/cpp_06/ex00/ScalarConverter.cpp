/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:09:36 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 00:09:36 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isPseudo(const std::string &literal)
{
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isPseudo(literal))
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan" || literal == "nanf")
            std::cout << "float: nanf" << std::endl;
        else if (literal == "+inf" || literal == "+inff")
            std::cout << "float: +inff" << std::endl;
        else if (literal == "-inf" || literal == "-inff")
            std::cout << "float: -inff" << std::endl;
        
        if (literal == "nan" || literal == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (literal == "+inf" || literal == "+inff")
            std::cout << "double: +inf" << std::endl;
        else if (literal == "-inf" || literal == "-inff")
            std::cout << "double: -inf" << std::endl;
        return;
    }
    
    double value = 0.0;
    
    if ((literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') ||
        (literal.length() == 1 && !std::isdigit(literal[0])))
	{
        if (literal.length() == 3)
            value = literal[1];
        else
            value = literal[0];
    }
	else
	{

        char *end;
        errno = 0;
        value = std::strtod(literal.c_str(), &end);

        if (*end != '\0' && !(std::string(end) == "f"))
		{
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }
    
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else
	{
        char c = static_cast<char>(value);
        if (!std::isprint(c))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;
    }
    
    std::cout << "int: ";
    if (std::isnan(value) || value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
    
    std::cout << "float: ";
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
