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

/*
 * File:   ZTVector.h
 * Author: jefkine
 *
 * Created on July 5, 2018, 3:26 AM
 */

#ifndef ZTVECTOR_H
#define ZTVECTOR_H

#include <vector>

template <typename T> class ZTVector {

private:
    std::vector<T> vector_data;
    int vector_size = vector_data.size();

public:
    ZTVector(const std::vector<T>& v);
    ZTVector(const ZTVector<T>& cp);
    virtual ~ZTVector();

    std::vector<T> get_vector_data();
    void set_vector_data(const std::vector<T>& v);

    std::vector<T> add(const T& scalar);
    std::vector<T> subtract(const T& scalar);
    std::vector<T> multiply(const T& scalar);

    ZTVector& cummulative_add(const T& scalar);
    ZTVector& cummulative_subtract(const T& scalar);
    ZTVector& cummulative_multiply(const T& scalar);

    std::vector<T> add(const std::vector<T>& v);
    std::vector<T> subtract(const std::vector<T>& v);
    T multiply(const std::vector<T>& v);

    ZTVector& cummulative_add(const std::vector<T>& v);
    ZTVector& cummulative_subtract(const std::vector<T>& v);

    std::vector<T> operator +(const T& scalar);
    std::vector<T> operator -(const T& scalar);
    T operator *(const T &scalar);

    ZTVector& operator +=(const T& scalar);
    ZTVector& operator -=(const T& scalar);
    ZTVector& operator *=(const T& scalar);

    std::vector<T> operator +(const std::vector<T>& v);
    std::vector<T> operator -(const std::vector<T>& v);
    T operator *(const std::vector<T>& v);

    ZTVector& operator +=(const std::vector<T>& v);
    ZTVector& operator -=(const std::vector<T>& v);

    ZTVector& operator =(const ZTVector<T>& v);

    T dot(const std::vector<T>& v); // dot product
    T norm(const std::vector<T>& v);

    void valid_vector_dimensions(const std::vector<T>& v);

};

#endif /* ZTVECTOR_H */
