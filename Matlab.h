// ------------------------
// projects/matLab/MatLab.h
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------

#ifndef MatLab_h
#define MatLab_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <stdlib.h>
#include <time.h>

// ------
// horzcat
// ------

/**
 * Used to concatenate horizontally two matrices and return the new matrix.
 * - the two matrices must not be empty.
 * - the row number of the matrices must be the same.
 * @param x the first matrix.
 * @param y the second matrix.
 * @return a new matrix which contains the columns of the first matrix, and then the columns of the second one.
 * Reference: http://www.mathworks.com/help/matlab/ref/horzcat.html
 */
template <typename T>
T horzcat (const T& x, const T& y) {
    if ((x.size() != y.size()) || x.size() == 0 || x[0].size() == 0 || y[0].size() == 0)
        throw DimensionException();
    T result = x;
    for (size_t r = 0; r < x.size(); r++) 
        for (size_t c = 0; c < y[0].size(); c++) 
            result[r].push_back(y[r][c]);
    return result;}

// ------
// vertcat
// ------

/**
 * Used to concatenate vertically two matrices and return the new matrix.
 * - the two matrices must not be empty.
 * - the column number of the matrices must be the same.
 * @param x the first matrix.
 * @param y the second matrix.
 * @return a new matrix which contains the rows of the first matrix, and then the rows of the second one.
 * Reference: http://www.mathworks.com/help/matlab/ref/vertcat.html
 */
template <typename T>
T vertcat (const T& x, const T& y) {
    if (x.size() == 0 || y.size() == 0  || x[0].size() == 0 || y[0].size() == 0 || x[0].size() != y[0].size())
        throw DimensionException();
    T result = x;
    for (size_t i = 0; i < y.size(); i++) result.push_back(y[i]);
    return result;}

// ---
// eye
// ---

/**
 * Used to generate:
 * 1). an identity matrix that has same number rows and columns, of certain size.
 * 2). a matrix that has different number of rows and columns, and has 1's on the diagonal.
 * - the specified row and column number must be positive numbers.
 * @param r the row number of the generated matrix.
 * @param c the column number of the generated matrix.
 * @return a new matrix of row r and column c, which contains 1's on the diagonal.
 * Reference: http://www.mathworks.com/help/matlab/ref/eye.html
 */
template <typename T>
T eye (std::size_t r, std::size_t c) {
    if (r <= 0 || c <= 0) throw DimensionException();
    size_t min = r < c ? r : c;
    T result(r, c, 0);
    for (size_t i = 0; i < min; i++) 
        result[i][i] = 1;
    return result;}

// ----
// diag
// ----

/**
 * Used to generate a square matrix which has the parameter vector as main diagonal, and 0's elsewhere. 
 * - the parameter must be a vector, must not be empty. 
 * @param x the vector to be put on the main diagonal of the result matrix.
 * @return a new matrix when vector x on the main diagonal.
 * Reference: http://www.mathworks.com/help/matlab/ref/diag.html
 */
template <typename T>
T diag (const T& x) {
    if (x.size() == 0 || x[0].size() != 1)
        throw DimensionException();
    T result(x.size(), x.size(), 0);
    for (size_t i = 0; i < x.size(); i++)
        result[i][i] = x[i][0];
    return result;}

// ---
// dot
// ---

/**
 * Used to take the dot product of two vectors. 
 * - vectors are implemented as a matrix that has to have only one column.
 * - the parameter must be two vectors, must not be empty.
 * - the two vectors must have the same length.
 * @param x the first vector.
 * @param x the second vector.
 * @return a new 1x1 matrix which contains the scalar, the dot product of two vectors.
 * Reference: http://www.mathworks.com/help/matlab/ref/dot.html
 */
template <typename T>
T dot (const T& x, const T& y) {
    if (x.size() == 0 || x[0].size() != 1 || y.size() == 0 || y[0].size() != 1 || x.size() != y.size())
        throw DimensionException();
    T result(1,1,0);
    for (size_t i = 0; i < x.size(); i++) 
        result[0][0] += (x[i][0] * y[i][0]);
    return result;}

// ----------------
// linsolve (bonus)
// ----------------

/**
 * <We did not implement this function>
 * http://www.mathworks.com/help/matlab/ref/linsolve.html
 */
template <typename T>
T linsolve (const T& x, const T& y) {
    // <your code>
    return x;}

// ----
// ones
// ----

/**
 * Used to generate an r by c matrix filled with 1's.
 * - the specified row and column number must be positive numbers.
 * @param r the row number of the generated matrix.
 * @param c the column number of the generated matrix.
 * @return a new matrix of row r and column c, which is filled with only 1's.
 * Reference: http://www.mathworks.com/help/matlab/ref/ones.html
 */
template <typename T>
T ones (std::size_t r, std::size_t c) {
    if (r <= 0 || c <= 0) throw DimensionException();
    return T(r, c, 1);}

// ----
// rand
// ----

/**
 * Used to generate an r by c matrix filled with random values between 0 and 1.
 * - the specified row and column number must be positive numbers.
 * @param r the row number of the generated matrix.
 * @param c the column number of the generated matrix.
 * @return a new matrix of row r and column c, which is filled with random doubles values between 0 and 1.
 * Reference: http://www.mathworks.com/help/matlab/ref/rand.html
 */
template <typename T>
T rand (std::size_t r, std::size_t c) {
    if (r <= 0 || c <= 0)
        throw DimensionException();
    srand ( time(NULL) );
    T result(r, c, 0);
    for(size_t row = 0; row < r; row++){
        for(size_t col = 0; col < c; col++){
            result[row][col] = rand() / (double)RAND_MAX;
        }
    }
    return result;
}

// ---------
// transpose
// ---------

/**
 * Used to transpose a matrix.
 * - the matrix must not be empty. 
 * @param x the matrix to be transposed.
 * @return a new matrix after transpose.
 * Reference: http://www.mathworks.com/help/matlab/ref/transpose.html
 */
template <typename T>
T transpose (const T& x) {
    if (x.size() == 0 || x[0].size() == 0)
        throw DimensionException();
    T result(x[0].size(), x.size(), 0);
    for(size_t r = 0; r < x.size(); r++){
        for(size_t c = 0; c < x[0].size(); c++){
        result[c][r] = x[r][c];
        }
    }
    return result;}

// ----
// tril
// ----

/**
 * Used to get the lower-triangle of a square matrix.
 * - the matrix must not be empty. 
 * - the matrix must be a square matrix.
 * @param x the matrix whose lower-triangle will be obtained.
 * @return the lower-triangle of matrix x.
 * Reference: http://www.mathworks.com/help/matlab/ref/tril.html
 */
template <typename T>
T tril (const T& x) {
    T result = x;
    if (x.size() == 0 || x[0].size() == 0 || x.size() != x[0].size())
        throw DimensionException();
    for (size_t r = 0; r < x.size(); r++)
        for (size_t c = 0; c < x.size(); c++)
            if (c > r) result[r][c] = 0;
    return result;}

// ----
// triu
// ----

/**
 * Used to get the upper-triangle of a square matrix.
 * - the matrix must not be empty. 
 * - the matrix must be a square matrix.
 * @param x the matrix whose upper-triangle will be obtained.
 * @return the upper-triangle of matrix x.
 * Reference: http://www.mathworks.com/help/matlab/ref/triu.html
 */
template <typename T>
T triu (const T& x) {
    T result = x;
    if (x.size() == 0 || x[0].size() == 0 || x.size() != x[0].size())
        throw DimensionException();
    for (size_t r = 0; r < x.size(); r++)
        for (size_t c = 0; c < x.size(); c++)
            if (c < r) result[r][c] = 0;
    return result;}

// -----
// zeros
// -----

/**
 * Used to generate an r by c matrix filled with 0's.
 * - the specified row and column number must be positive numbers.
 * @param r the row number of the generated matrix.
 * @param c the column number of the generated matrix.
 * @return a new matrix of row r and column c, which is filled with only 0's.
 * Reference: http://www.mathworks.com/help/matlab/ref/zeros.html
 */
template <typename T>
T zeros (std::size_t r, std::size_t c) {
    if (r <= 0 || c <= 0) throw DimensionException();
    return T(r, c, 0);}

#endif // MatLab_h
