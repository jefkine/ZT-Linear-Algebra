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
#include <math.h>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <iostream>
#include <stdexcept>
#include <functional>

#include "ZTMatrix.h"

/**
 * Constructor: Constructs a Matrix of dimensions rows by cols whose elements are
 *              initialized to the provided elements
 *
 * @param  std::size_t rows size for initialization
 * @param  std::size_t rows size for initialization
 * @param  T& elements numeric for initialization
 * @return nothing
 *
 */
template <typename T>
ZTMatrix<T>::ZTMatrix(std::size_t rows, std::size_t cols, const T& elements) : matrix_rows(rows), matrix_cols(cols) {

    for (std::size_t i = 0; i < rows; i++) {
        std::vector<double> matrix_rows(cols, elements);
        matrix_data.push_back(matrix_rows);
    }

}

/**
 * Copy Constructor
 *
 * @param  ZTMatrix<T> cp Matrix to be copied
 * @return nothing
 *
 */
template<typename T>
ZTMatrix<T>::ZTMatrix(const ZTMatrix<T>& cp) :
                                               matrix_rows(cp.matrix_rows),
                                               matrix_cols(cp.matrix_cols),
                                               matrix_data(cp.matrix_data)
{

}

/**
 * Destructor
 *
 * @param  nothing
 * @return nothing
 *
 */
template<typename T>
ZTMatrix<T>::~ZTMatrix() {}

/**
 * add : perfoms matrix to scalar addition
 *
 * @param  T& scalar
 * @return std::vector<std::vector<T>> result
 *
 */
template<typename T>
ZTMatrix<T> ZTMatrix<T>::add(const T& scalar) {
    ZTMatrix result(matrix_rows, matrix_cols, 0.0);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            result.matrix_data[i][j] = matrix_data[i][j] + scalar;
        }
    }
    return result;
}

/**
 * minus : perfoms matrix to scalar subtraction
 *
 * @param  T& scalar
 * @return std::vector<std::vector<T>> result
 *
 */
template<typename T>
ZTMatrix<T> ZTMatrix<T>::minus(const T& scalar) {
    ZTMatrix result(matrix_rows, matrix_cols, 0.0);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            result.matrix_data[i][j] = matrix_data[i][j] - scalar;
        }
    }
    return result;
}

/**
 * multiply : perfoms matrix to multiplication
 *
 * @param  T& scalar
 * @return std::vector<std::vector<T>> result
 *
 */
template<typename T>
ZTMatrix<T> ZTMatrix<T>::multiply(const T& scalar) {
    ZTMatrix result(matrix_rows, matrix_cols, 0.0);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            result.matrix_data[i][j] = matrix_data[i][j] * scalar;
        }
    }
    return result;
}

/**
 * cummulative_add : perfoms matrix to scalar cummulative add
 *
 * @param  T& scalar
 * @return *this (instance of ZTMatrix<T>)
 *
 */
template<typename T>
ZTMatrix<T>& ZTMatrix<T>::cummulative_add(const T& scalar) {
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            matrix_data[i][j] += scalar;
        }
    }

    return *this;
}

/**
 * cummulative_minus : perfoms matrix to scalar cummulative subtraction
 *
 * @param  T& scalar
 * @return *this (instance of ZTMatrix<T>)
 *
 */
template<typename T>
ZTMatrix<T>& ZTMatrix<T>::cummulative_minus(const T& scalar) {
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            matrix_data[i][j] -= scalar;
        }
    }

    return *this;
}

/**
 * cummulative_multiply : perfoms matrix to scalar cummulative multiplication
 *
 * @param  T& scalar
 * @return *this (instance of ZTMatrix<T>)
 *
 */
template<typename T>
ZTMatrix<T>& ZTMatrix<T>::cummulative_multiply(const T& scalar) {
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            matrix_data[i][j] *= scalar;
        }
    }

    return *this;
}

/**
 * add : perfoms matrix to matrix addition
 *
 * @param  ZTMatrix<T> m
 * @return std::vector<std::vector<T>> result
 *
 */
template<typename T>
ZTMatrix<T> ZTMatrix<T>::add(const ZTMatrix<T>& m) {
  try
  {
    valid_matrix_add_minus(m);
    ZTMatrix result(matrix_rows, matrix_cols, 0.0);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            result.matrix_data[i][j] = matrix_data[i][j] + m.matrix_data[i][j];
        }
    }
    return result;
  }
  catch (const std::invalid_argument& e)
  {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
  }
}

/**
 * minus : perfoms matrix to matrix subtraction
 *
 * @param  ZTMatrix<T> m
 * @return std::vector<std::vector<T>> result
 *
 */
template<typename T>
ZTMatrix<T> ZTMatrix<T>::minus(const ZTMatrix<T>& m) {

  try
  {
    valid_matrix_add_minus(m);
    ZTMatrix result(matrix_rows, matrix_cols, 0.0);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            result.matrix_data[i][j] = matrix_data[i][j] - m.matrix_data[i][j];
        }
    }
    return result;
  }
  catch (const std::invalid_argument& e)
  {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
  }

}

/**
 * multiply : perfoms matrix to matrix multiplication
 *
 * @param  ZTMatrix<T> m
 * @return std::vector<std::vector<T>> result
 *
 */
template<typename T>
ZTMatrix<T> ZTMatrix<T>::multiply(const ZTMatrix<T>& m) {

    try
    {
        valid_matrix_product(m);
        ZTMatrix result(matrix_rows, matrix_cols, 0.0);
        for (std::size_t i = 0; i < matrix_rows; ++i)
        {
            for (std::size_t j = 0; j < matrix_cols; ++j)
            {
               result.matrix_data[i][j] = matrix_data[i][j] * m.matrix_data[i][j];
            }
        }
        return result;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::exit(0);
    }

}

/**
 * cummulative_add : perfoms matrix to matrix cummulative addition
 *
 * @param  ZTMatrix<T>& m
 * @return *this (instance of ZTMatrix<T>)
 *
 */
template<typename T>
ZTMatrix<T>& ZTMatrix<T>::cummulative_add(const ZTMatrix<T>& m) {

  try
  {
    valid_matrix_add_minus(m);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            matrix_data[i][j] += m.matrix_data[i][j];
        }
    }
    return *this;
  }
  catch (const std::invalid_argument& e)
  {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
  }

}

/**
 * cummulative_minus : perfoms matrix to matrix cummulative subtraction
 *
 * @param  ZTMatrix<T>& m
 * @return *this (instance of ZTMatrix<T>)
 *
 */
template<typename T>
ZTMatrix<T>& ZTMatrix<T>::cummulative_minus(const ZTMatrix<T>& m) {

  try
  {
    valid_matrix_add_minus(m);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            matrix_data[i][j] -= m.matrix_data[i][j];
        }
    }
    return *this;
  }
  catch (const std::invalid_argument& e)
  {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
  }

}

/**
 * cummulative_minus : perfoms matrix to matrix cummulative multiplication
 *
 * @param  ZTMatrix<T>& m
 * @return *this (instance of ZTMatrix<T>)
 *
 */
template<typename T>
ZTMatrix<T>& ZTMatrix<T>::cummulative_multiply(const ZTMatrix<T>& m) {

  try
  {
    valid_matrix_product(m);
    for (std::size_t i = 0; i < matrix_rows; ++i) {
        for (std::size_t j = 0; j < matrix_cols; ++j) {
            matrix_data[i][j] *= m.matrix_data[i][j];
        }
    }
    return *this;
  }
  catch (const std::invalid_argument& e)
  {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
  }

}

/**
 * inline + operator : perfoms matrix to scalar addition
 *
 * @param  T& scalar
 *
 */
template <typename T>
inline ZTMatrix<T> ZTMatrix<T>::operator+(const T& scalar) {
    return ZTMatrix<T>::add(scalar);
}

/**
 * inline - operator : perfoms matrix to scalar subtraction
 *
 * @param  T& scalar
 *
 */
template <typename T>
inline ZTMatrix<T> ZTMatrix<T>::operator-(const T& scalar) {
    return ZTMatrix<T>::minus(scalar);
}

/**
 * inline * operator : perfoms matrix to scalar multiplication
 *
 * @param  T& scalar
 *
 */
template <typename T>
inline ZTMatrix<T> ZTMatrix<T>::operator*(const T& scalar) {
    return ZTMatrix<T>::multiply(scalar);
}

/**
 * inline += operator : perfoms matrix to scalar cummulative addition
 *
 * @param  T& scalar
 *
 */
template <typename T>
inline ZTMatrix<T>& ZTMatrix<T>::operator+=(const T& scalar) {
    return ZTMatrix<T>::cummulative_add(scalar);
}

/**
 * inline -= operator : perfoms matrix to scalar cummulative subtraction
 *
 * @param  T& scalar
 *
 */
template <typename T>
inline ZTMatrix<T>& ZTMatrix<T>::operator-=(const T& scalar) {
    return ZTMatrix<T>::cummulative_minus(scalar);
}

/**
 * inline *= operator : perfoms matrix to scalar cummulative multiplication
 *
 * @param  T& scalar
 *
 */
template <typename T>
ZTMatrix<T>& ZTMatrix<T>::operator*=(const T& scalar) {
    return ZTMatrix<T>::cummulative_multiply(scalar);
}

/**
 * inline + operator : perfoms matrix to matrix addition
 *
 * @param  ZTMatrix<T> m
 *
 */
template <typename T>
inline ZTMatrix<T> ZTMatrix<T>::operator+(const ZTMatrix<T>& m) {
    return ZTMatrix<T>::add(m);
}

/**
 * inline - operator : perfoms matrix to matrix subtraction
 *
 * @param  ZTMatrix<T> m
 *
 */
template <typename T>
inline ZTMatrix<T> ZTMatrix<T>::operator-(const ZTMatrix<T>& m) {
    return ZTMatrix<T>::minus(m);
}

/**
 * inline * operator : perfoms matrix to matrix multiplication
 *
 * @param  ZTMatrix<T> m
 *
 */
template <typename T>
inline ZTMatrix<T> ZTMatrix<T>::operator*(const ZTMatrix<T>& m) {
    return ZTMatrix<T>::multiply(m);
}

/**
 * inline += operator : perfoms matrix to matrix cummulative addition
 *
 * @param  ZTMatrix<T> m
 *
 */
template <typename T>
inline ZTMatrix<T>& ZTMatrix<T>::operator+=(const ZTMatrix<T>& m) {
    return ZTMatrix<T>::cummulative_add(m);
}

/**
 * inline -= operator : perfoms matrix to matrix cummulative subtraction
 *
 * @param  ZTMatrix<T> m
 *
 */
template <typename T>
inline ZTMatrix<T>& ZTMatrix<T>::operator-=(const ZTMatrix<T>& m) {
    return ZTMatrix<T>::cummulative_minus(m);
}

/**
 * inline *= operator : perfoms matrix to matrix cummulative multiplication
 *
 * @param  ZTMatrix<T> m
 *
 */
template <typename T>
inline ZTMatrix<T>& ZTMatrix<T>::operator*=(const ZTMatrix<T>& m) {
    return ZTMatrix<T>::cummulative_multiply(m);
}

/**
 * assignment operator : perfoms assignment of the given matrix to the instance one
 *
 * @param  ZTMatrix<T> m
 * @return *this (instance of ZTVector<T>)
 *
 */
template <typename T>
inline ZTMatrix<T>& ZTMatrix<T>::operator=(const ZTMatrix<T>& m) {
    if (&m != this)
    {
        matrix_data = m.matrix_data;
        matrix_rows = m.matrix_rows;
        matrix_cols = m.matrix_cols;
    }
    return *this;
}

/**
 * valid_subscript_dimensions: checks for valid matrix subscript dimensions
 *
 * @param  ZTMatrix<T> v
 * @return void
 *
 */
template<typename T>
inline void ZTMatrix<T>::valid_subscript_dimensions(std::size_t row_index, std::size_t col_index) const {
    if (row_index > matrix_rows || row_index < 1 || col_index > matrix_cols || col_index < 1)
    {
      std::ostringstream invalid_dimensions;
      invalid_dimensions << "Matrix subscripts " << row_index << " and " << col_index << " out of range!.";
      throw std::invalid_argument(invalid_dimensions.str());
    }
}

/**
 * valid_matrix_product: checks for dimensions valid matrix product
 *
 * @param  ZTMatrix<T> v
 * @return void
 *
 */
template<typename T>
inline void ZTMatrix<T>::valid_matrix_product(const ZTMatrix<T> &m)  const{
    if (matrix_cols != m.matrix_rows)
    {
      std::ostringstream invalid_dimensions;
      invalid_dimensions << "Matrices of dimensions: "<<matrix_rows<<"x"<<matrix_cols<<" and "<<m.matrix_rows<<"x"<< m.matrix_cols<<" are not suitable for matrix product!.";
      throw std::invalid_argument(invalid_dimensions.str());
    }
}

/**
 * valid_matrix_add_minus: checks for dimensions valid matrix addition or subtraction
 *
 * @param  ZTMatrix<T> v
 * @return void
 *
 */
template<typename T>
inline void ZTMatrix<T>::valid_matrix_add_minus(const ZTMatrix<T>& m) const {
    if (matrix_cols != m.matrix_cols && matrix_rows != m.matrix_rows)
    {
      std::ostringstream invalid_dimensions;
      invalid_dimensions << "Matrices of dimensions: "<<matrix_rows<<"x"<<matrix_cols<<" and "<< m.matrix_rows<<"x"<< m.matrix_cols<<" are not suitable for matrix add or minus!.";
      throw std::invalid_argument(invalid_dimensions.str());
    }
}

/**
 * valid_sqaure_matrix: checks for valid sqaure matrix dimensions
 *
 * @param  ZTMatrix<T> v
 * @return void
 *
 */
template<typename T>
inline void ZTMatrix<T>::valid_sqaure_matrix(const ZTMatrix<T> &m)  const{
    if (m.matrix_cols != m.matrix_rows)
    {
      std::ostringstream invalid_dimensions;
      invalid_dimensions << "Matrices of dimensions: "<<m.matrix_rows<<"x"<<m.matrix_cols<<" is not a sqaure matrix!.";
      throw std::invalid_argument(invalid_dimensions.str());
    }
}

/**
 * valid_sqaure_matrix: checks for valid sqaure matrix dimensions
 *
 * @param  std::size_t row_size size for initialization
 * @param  std::size_t col_size size for initialization
 * @return void
 *
 */
template<typename T>
inline void ZTMatrix<T>::valid_sqaure_matrix(std::size_t row_size, std::size_t col_size)  const{
    if (row_size != col_size)
    {
      std::ostringstream invalid_dimensions;
      invalid_dimensions << "Matrices of dimensions: "<<row_size<<"x"<<col_size<<" is not a sqaure matrix!.";
      throw std::invalid_argument(invalid_dimensions.str());
    }
}

/**
 * trace : perfoms matrix to matrix trace operation
 *
 * @param  nothing
 * @return T result
 *
 */
template<typename T>
T ZTMatrix<T>::trace() {
  try
  {
    valid_sqaure_matrix(matrix_rows, matrix_cols);
    T result = 0;
    for (std::size_t i = 0; i < matrix_rows; ++i)
    {
        result +=  matrix_data[i][i];
    }
    return result;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
    std::exit(0);
  }
}

/**
 * trace : perfoms matrix to matrix trace operation
 *
 * @param  ZTMatrix<T> m
 * @return T result
 *
 */
template<typename T>
T ZTMatrix<T>::trace(const ZTMatrix<T>& m) {
    try
    {
      valid_sqaure_matrix(m);
      T result = 0;
      for (std::size_t i = 0; i < m.matrix_rows; ++i)
      {
          result +=  m.matrix_data[i][i];
      }
      return result;
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
    }
}

/**
 * norm : perfoms matrix to matrix norm operation
 *
 * @param  nothing
 * @return T result
 *
 */
template<typename T>
T ZTMatrix<T>::norm() {
     T result = 0;
     for (std::size_t i = 0; i < matrix_rows; ++i)
     {
        for (std::size_t j = 0; j < matrix_cols; ++j)
        {
            result += std::pow(matrix_data[i][j], 2);
        }
    }
     return std::sqrt(result);
}

/**
 * norm : perfoms matrix to matrix norm operation
 *
 * @param  ZTMatrix<T> m
 * @return T result
 *
 */
template<typename T>
T ZTMatrix<T>::norm(const ZTMatrix<T>& m) {
     T result = 0;
     for (std::size_t i = 0; i < m.matrix_rows; ++i)
     {
        for (std::size_t j = 0; j < m.matrix_cols; ++j)
        {
            result += std::pow(m.matrix_data[i][j], 2);
        }
    }
     return std::sqrt(result);
}

/**
 * () operator : get the matrix element given the subscripts (row, col)
 *
 * @param  std::size_t row_size size for initialization
 * @param  std::size_t col_size size for initialization
 * @return T result
 *
 */
template<typename T>
T& ZTMatrix<T>::operator()(std::size_t row_index, std::size_t col_index) {
    try
    {
      valid_subscript_dimensions(row_index, col_index);
      return matrix_data[row_index - 1][col_index - 1];
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Exception: " << e.what() << std::endl;
      std::exit(0);
    }

}
