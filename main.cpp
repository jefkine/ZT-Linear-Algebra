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

#include "ZTVector.cpp"
#include "ZTMatrix.cpp"

int main() {

  double scalar = 2.0;
  double scalar_result = 0.0;

  // Vector Operations

  std::vector<double> x = {1.0,2.0,3.0};
  std::vector<double> y = {5.0,6.0,7.0};
  std::vector<double> vec_result;

  // get ZTVector vector object
  ZTVector<double> vec_x(x);

  // perfom vector to scalar addition
  // vec_result = vec_x.add(scalar);
  // vec_result = vec_x + scalar;

  // perfom vector to scalar subtraction
  // vec_result = vec_x.minus(scalar);
  // vec_result = vec_x - scalar;

  // perfom vector to scalar multiplication
  // vec_result = vec_x.multiply(scalar);
  // vec_result = vec_x * scalar;

  // perfom vector to vector addition
  // vec_result = vec_x.add(y);
  // vec_result = vec_x + y;

  // perfom vector to vector subtraction
  // vec_result = vec_x.minus(y);
  // vec_result = vec_x - y;

  // perfom vector to vector multiplication
  // vec_result = vec_x.multiply(y);
  // vec_result = vec_x * y;

  // perfom vector norm
  // scalar_result = vec_x.norm(y);
  // scalar_result = vec_x.norm(x);  // norm with itself
  // scalar_result = vec_x.norm();  // norm with itself

  // perfom vector dot operation
  // scalar_result = vec_x.dot(y);

  // Matrix Operations

  // get ZTMatrix matrix objects
  ZTMatrix<double> X(3, 3, 2.2);
  ZTMatrix<double> Y(3, 3, 2.0);

  ZTMatrix<double> mat_result(3, 3, 0.0);

  // perfom matrix to scalar addition
  // mat_result = X.add(scalar);
  // mat_result = X + scalar;

  // perfom matrix to scalar subtraction
  // mat_result = X.minus(scalar);
  // mat_result = X - scalar;

  // perfom matrix to scalar multiplication
  // mat_result = X.multiply(scalar);
  // mat_result = X * scalar;
    
  // perfom matrix to matrix addition
  // mat_result = X.add(Y);
  // mat_result = X + Y;

  // perfom matrix to matrix subtraction
  // mat_result = X.minus(Y);
  // mat_result = X - Y;

  // perfom matrix to matrix multiplication
  // mat_result = X.multiply(Y);
  // mat_result = X * Y;
  
  // perfom matrix trace and norm
  // std::cout <<  X.trace() << std::endl;
  // std::cout <<  X.norm() << std::endl;

  return 0;

}
