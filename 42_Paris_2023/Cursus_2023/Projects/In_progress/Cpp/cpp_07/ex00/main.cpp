/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:48:12 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 02:48:12 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template <typename T>
struct Test
{
    T value;
    int id;
    
    Test(T v, int i) : value(v), id(i) {}
};

template <typename T>
bool operator<(const Test<T>& a, const Test<T>& b)
{
    return a.value < b.value;
}

template <typename T>
bool operator>(const Test<T>& a, const Test<T>& b)
{
    return b < a;
}

int main(void)
{
    // Test avec des entiers
    std::cout << "---------First part : Integer---------" << std::endl;
    {
        // Test 1 : a < b
        std::cout << "----------------Test 1----------------" << std::endl;
        int a = 12;
        int b = 24;
        ::swap(a, b);
        std::cout << BLUE2 << "a = " << YELLOW2 << a << WHITE2 << ", " << BLUE2 << "b = " << YELLOW2 << b << RESET << std::endl << std::endl;
        std::cout << BLUE2 << "min(a, b) = " << GREEN2 << ::min(a, b) << RESET << std::endl;
        std::cout << BLUE2 << "max(a, b) = " << GREEN2 << ::max(a, b) << RESET << std::endl;
    }
    {
        // Test 2 : a > b
        std::cout << "----------------Test 2----------------" << std::endl;
        int a = 42;
        int b = 24;
        ::swap(a, b);
        std::cout << BLUE2 << "a = " << YELLOW2 << a << WHITE2 << ", " << BLUE2 << "b = " << YELLOW2 << b << RESET << std::endl << std::endl;
        std::cout << BLUE2 << "min(a, b) = " << GREEN2 << ::min(a, b) << RESET << std::endl;
        std::cout << BLUE2 << "max(a, b) = " << GREEN2 << ::max(a, b) << RESET << std::endl;
    }
    {
        // Test 3 : a = b
        std::cout << "----------------Test 3----------------" << std::endl;
        int a = 42;
        int b = 42;
        Test<int> t1(a, 1995);
        Test<int> t2(b, 2002);
        ::swap(a, b);
        Test<int> minResult = ::min(t1, t2);
        Test<int> maxResult = ::max(t1, t2);
        std::cout << RESET << "["<< BLUE2 << "a : " << YELLOW2  << "\"" << t1.value << "\"" << WHITE2 << ", " << YELLOW2 << t1.id << RESET << "]" << RESET << " [" << BLUE2 << "b : " << "\"" << t2.value << "\"" << WHITE2 << ", " << YELLOW2 << t2.id << RESET << "]" << std::endl << std::endl;
        if (minResult.id == t2.id)
            std::cout << BLUE2 << "min(a, b) = " << GREEN2 << minResult.value << ", id : " << minResult.id << ", variable : b " << RESET << std::endl;
        else
            std::cout << RED2 << "La variable retournée n'est pas la première..." << RESET << std::endl;
        
        if (maxResult.id == t2.id)
            std::cout << BLUE2 << "max(a, b) = " << GREEN2 << maxResult.value << ", id : " << maxResult.id << ", variable : b " << RESET << std::endl;
        else
            std::cout << RED2 << "La variable retournée n'est pas la première..." << RESET << std::endl;
    }

    // Test avec des chaînes de caractères
    std::cout << std::endl << "---------Second part : String---------" << std::endl;
    {
        // Test 4 : c < d
        std::cout << "----------------Test 4----------------" << std::endl;
        std::string c = "chaine12";
        std::string d = "chaine24";
        ::swap(c, d);
        std::cout << BLUE2 << "c = " << YELLOW2 << c << WHITE2 << ", " << BLUE2 << "d = " << YELLOW2 << d << RESET << std::endl << std::endl;
        std::cout << BLUE2 << "min(c, d) = " << GREEN2 << ::min(c, d) << RESET << std::endl;
        std::cout << BLUE2 << "max(c, d) = " << GREEN2 << ::max(c, d) << RESET << std::endl;
    }
    {
        // Test 5 : c > d
        std::cout << "----------------Test 5----------------" << std::endl;
        std::string c = "chaine42";
        std::string d = "chaine24";
        ::swap(c, d);
        std::cout << BLUE2 << "c = " << YELLOW2 << c << WHITE2 << ", " << BLUE2 << "d = " << YELLOW2 << d << RESET << std::endl << std::endl;
        std::cout << BLUE2 << "min(c, d) = " << GREEN2 << ::min(c, d) << RESET << std::endl;
        std::cout << BLUE2 << "max(c, d) = " << GREEN2 << ::max(c, d) << RESET << std::endl;
    }
    {
        // Test 6 : c = d en utilisant Test pour vérifier quelle variable est retournée
        std::cout << "----------------Test 6----------------" << std::endl;
        std::string c = "chaine42";
        std::string d = "chaine42";
        Test<std::string> s1(c, 1995);
        Test<std::string> s2(d, 2002);
        ::swap(c, d);
        Test<std::string> minResult = ::min(s1, s2);
        Test<std::string> maxResult = ::max(s1, s2);
        std::cout << RESET << "["<< BLUE2 << "c : " << YELLOW2 << "\"" << s1.value << "\"" << WHITE2 << ", " << YELLOW2 << s1.id << RESET << "]" << RESET << " [" << BLUE2 << "d : " << YELLOW2 << "\"" << s2.value << "\"" << WHITE2 << ", " << YELLOW2 << s2.id << RESET << "]" << std::endl << std::endl;
        if (minResult.id == s2.id)
            std::cout << BLUE2 << "min(c, d) = " << GREEN2 << minResult.value << ", id : " << minResult.id << ", variable : d " << RESET << std::endl;
        else
            std::cout << RED2 << "La variable retournée n'est pas la première..." << RESET << std::endl;
        
        if (maxResult.id == s2.id)
            std::cout << BLUE2 << "max(c, d) = " << GREEN2 << maxResult.value << ", id : " << maxResult.id << ", variable : d " << RESET << std::endl;
        else
            std::cout << RED2 << "La variable retournée n'est pas la première..." << RESET << std::endl;
    }
    
    return 0;
}