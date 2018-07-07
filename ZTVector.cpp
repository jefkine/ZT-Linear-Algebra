/*
 * The MIT License
 *
 * Copyright 2018 jefkine.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <cmath>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <iostream>
#include <functional>
#include <stdexcept>

#include "ZTVector.h"

template<typename T>
ZTVector<T>::ZTVector(const std::vector<T>& v) : vector_data(v) {

}

template<typename T>
ZTVector<T>::ZTVector(const ZTVector<T>& p) : vector_data(p.vector_data) {

}

template<typename T>
ZTVector<T>::~ZTVector() {}

template<typename T>
std::vector<T> ZTVector<T>::get_vector_data()
{
       return vector_data;
}

template<typename T>
void ZTVector<T>::set_vector_data(const std::vector<T>& v)
{
       vector_data = v;
}

template<typename T>
void ZTVector<T>::valid_vector_dimensions(const std::vector<T>& v)
{
    if (vector_data.size() != v.size())
    {
        std::ostringstream invalid_dimensions;
        invalid_dimensions << "vector sizes " << vector_data.size() << " and " << v.size() <<" do not match!.";
        throw std::invalid_argument(invalid_dimensions.str());
    }
}

template<typename T>
ZTVector<T>& ZTVector<T>::operator=(const ZTVector<T>& v) {

    if (this != &v)
    {
        vector_data = v.vector_data;
    }
    return *this;

}

template<typename T>
std::vector<T> ZTVector<T>::add(const T& scalar) {

    std::vector<T> result(vector_size);
    for (int i=0; i<vector_size; ++i)
    {
        result[i] = vector_data[i] + scalar;
    }
    return result;

}

template<typename T>
ZTVector<T>& ZTVector<T>::cummulative_add(const T& scalar) {

    for (int i=0; i<vector_size; ++i)
    {
        vector_data[i] += scalar;
    }

    return *this;

}

template <typename T>
inline std::vector<T> ZTVector<T>::operator+(const T& scalar)
{
   return ZTVector<T>::add(scalar);
}

template <typename T>
inline ZTVector<T> &ZTVector<T>::operator+=(const T &scalar)
{
   return ZTVector<T>::cummulative_add(scalar);
}

template<typename T>
std::vector<T> ZTVector<T>::subtract(const T& scalar) {

    std::vector<T> result(vector_size);
    for (int i=0; i<vector_size; ++i)
    {
        result[i] = vector_data[i] - scalar;
    }
    return result;

}

template<typename T>
ZTVector<T>& ZTVector<T>::cummulative_subtract(const T& scalar) {

    for (int i=0; i<vector_size; ++i)
    {
        vector_data[i] -= scalar;
    }

    return *this;

}

template <typename T>
inline std::vector<T> ZTVector<T>::operator-(const T& scalar)
{
    return ZTVector<T>::subtract(scalar);
}

template <typename T>
inline ZTVector<T>& ZTVector<T>::operator-=(const T& scalar)
{
   return ZTVector<T>::cummulative_subtract(scalar);
}

template<typename T>
std::vector<T> ZTVector<T>::multiply(const T& scalar) {

    std::vector<T> result(vector_size);
    for (int i=0; i<vector_size; ++i)
    {
        result[i] = vector_data[i] * scalar;
    }
    return result;

}

template<typename T>
ZTVector<T>& ZTVector<T>::cummulative_multiply(const T& scalar) {

    for (int i=0; i<vector_size; ++i)
    {
        vector_data[i] *= scalar;
    }
     return *this;

}

template <typename T>
inline T ZTVector<T>::operator*(const T& scalar)
{
    return ZTVector<T>::multiply(scalar);
}

template <typename T>
inline ZTVector<T>& ZTVector<T>::operator*=(const T& scalar)
{
   return ZTVector<T>::cummulative_multiply(scalar);
}

template<typename T>
std::vector<T> ZTVector<T>::add(const std::vector<T>& v) {

    try
    {
        valid_vector_dimensions(v);
        std::vector<T> result(vector_size);
        for (int i=0; i<vector_size; ++i)
        {
            result[i] = vector_data[i] + v[i];
        }
        return result;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}

template<typename T>
ZTVector<T>& ZTVector<T>::cummulative_add(const std::vector<T>& v) {

    try
    {
        valid_vector_dimensions(v);
         for (int i=0; i<vector_size; ++i)
        {
            vector_data[i] += v[i];
        }
        return *this;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}

template <typename T>
inline std::vector<T> ZTVector<T>::operator+(const std::vector<T>& v)
{
   return ZTVector<T>::add(v);
}

template <typename T>
inline ZTVector<T>& ZTVector<T>::operator+=(const std::vector<T>& v)
{
   return ZTVector<T>::cummulative_add(v);
}

template<typename T>
std::vector<T> ZTVector<T>::subtract(const std::vector<T>& v) {

    try
    {
        valid_vector_dimensions(v);
        std::vector<T> result(vector_size);
        for (int i=0; i<vector_size; ++i)
        {
            result[i] = vector_data[i] - v[i];
        }
        return result;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}

template<typename T>
ZTVector<T>& ZTVector<T>::cummulative_subtract(const std::vector<T>& v) {

    try
    {
        valid_vector_dimensions(v);
        for (int i=0; i<vector_size; ++i)
        {
            vector_data[i] -= v[i];
        }
        return *this;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}

template <typename T>
inline std::vector<T> ZTVector<T>::operator-(const std::vector<T>& v)
{
   return ZTVector<T>::subtract(v);
}

template <typename T>
inline ZTVector<T>& ZTVector<T>::operator-=(const std::vector<T>& v)
{
   return ZTVector<T>::cummulative_add(v);
}

template<typename T>
T ZTVector<T>::multiply(const std::vector<T>& v) {

    try
    {
        valid_vector_dimensions(v);
        T result = 0;
        for (int i=0; i<vector_size; ++i)
        {
            result += vector_data[i] * v[i];
        }
        return result;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}

template <typename T>
inline T ZTVector<T>::operator*(const std::vector<T>& v)
{
    return ZTVector<T>::multiply(v);
}

template <typename T>
T ZTVector<T>::dot(const std::vector<T>& v)
{

    try
    {
        valid_vector_dimensions(v);
        return std::inner_product(vector_data.begin(), vector_data.end(), v.begin(), 0);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}

template <typename T>
T ZTVector<T>::norm(const std::vector<T>& v)
{

    try
    {
        valid_vector_dimensions(v);
        return std::sqrt(ZTVector<T>::multiply(v));
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Exception: " <<  e.what() << std::endl;
        std::exit(0);
    }

}
