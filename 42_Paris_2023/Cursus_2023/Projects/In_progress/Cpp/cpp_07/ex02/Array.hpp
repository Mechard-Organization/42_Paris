/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 06:09:44 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 06:09:44 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{

private:
    T*            _array;
    unsigned int  _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    T& operator[](int index);
    const T& operator[](int index) const;
    unsigned int size() const;

};

#include "Array.tpp"

#endif
