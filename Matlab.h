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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/horzcat.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/vertcat.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/eye.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/diag.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/dot.html
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
 * <your documentation>
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/ones.html
 */
template <typename T>
T ones (std::size_t r, std::size_t c) {
    if (r <= 0 || c <= 0) throw DimensionException();
    return T(r, c, 1);}

// ----
// rand
// ----

/**
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/rand.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/transpose.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/tril.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/triu.html
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
 * <your documentation>
 * http://www.mathworks.com/help/matlab/ref/zeros.html
 */
template <typename T>
T zeros (std::size_t r, std::size_t c) {
    if (r <= 0 || c <= 0) throw DimensionException();
    return T(r, c, 0);}

#endif // MatLab_h
