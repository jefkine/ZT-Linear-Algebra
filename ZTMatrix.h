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

#ifndef ZTMATRIX_H
#define ZTMATRIX_H

#include <vector>

template <typename T> class ZTMatrix {

private:
    std::vector<std::vector<T> > matrix_data;
    std::size_t matrix_rows;
    std::size_t matrix_cols;

public:
    ZTMatrix(std::size_t rows, std::size_t cols, const T& elements);
    ZTMatrix(const ZTMatrix<T> &cp);
    virtual ~ZTMatrix();

    ZTMatrix<T> add(const T& scalar);
    ZTMatrix<T> subtract(const T& scalar);
    ZTMatrix<T> multiply(const T& scalar);

    ZTMatrix<T>& cummulative_add(const T& scalar);
    ZTMatrix<T>& cummulative_subtract(const T& scalar);
    ZTMatrix<T>& cummulative_multiply(const T& scalar);

    ZTMatrix<T> add(const ZTMatrix& m);
    ZTMatrix<T> subtract(const ZTMatrix& m);
    ZTMatrix<T> multiply(const ZTMatrix& m);

    ZTMatrix<T>& cummulative_add(const ZTMatrix& m);
    ZTMatrix<T>& cummulative_subtract(const ZTMatrix& m);
    ZTMatrix<T>& cummulative_multiply(const ZTMatrix& m);

    ZTMatrix<T> operator +(const T& scalar);
    ZTMatrix<T> operator -(const T& scalar);
    ZTMatrix<T> operator *(const T &scalar);

    ZTMatrix<T>& operator +=(const T& scalar);
    ZTMatrix<T>& operator -=(const T& scalar);
    ZTMatrix<T>& operator *=(const T& scalar);

    ZTMatrix<T> operator +(const ZTMatrix& m);
    ZTMatrix<T> operator -(const ZTMatrix& m);
    ZTMatrix<T> operator *(const ZTMatrix& m);

    ZTMatrix<T>& operator +=(const ZTMatrix& m);
    ZTMatrix<T>& operator -=(const ZTMatrix& m);
    ZTMatrix<T>& operator *=(const ZTMatrix& m);

    ZTMatrix &operator =(const ZTMatrix& m);

    T& operator()(std::size_t row, std::size_t col);
    const T& operator()(std::size_t row, std::size_t col) const;

    T trace();
    T trace(const ZTMatrix<T>& m);

    T norm();
    T norm(const ZTMatrix<T>& m);

    void valid_subscript_dimensions(std::size_t rows, std::size_t cols) const;
    void valid_matrix_product(const ZTMatrix<T> &m) const;
    void valid_matrix_add_minus(const ZTMatrix<T> &m) const;
    void valid_sqaure_matrix(const ZTMatrix<T> &m) const;
    void valid_sqaure_matrix(std::size_t rows, std::size_t cols) const;

};

#endif /* ZTMATRIX_H */
