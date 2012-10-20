// ------------------------
// projects/matlab/Matrix.h
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------

#ifndef Matrix_h
#define Matrix_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // ptrdiff_t, size_t
#include <vector>  // vector
#include <iostream>
#include <string>

// ------------------
// DimensionException
// ------------------

/**
 * The exception thrown when a mismatch in the dimension of
 * the matrices being operated on occurs.
 */
class DimensionException {
private:
    std::string msg;
public:
    DimensionException(std::string s) {msg = s;}
    DimensionException() {msg = "Dimension not matched.\n";}
    std::string err() {return msg;}
};

// ------
// Matrix
// ------

/**
 * Design decision:
 *
 * When the first index of a matrix (the row) or the second index of a matrix (the column)
 * happen to be zero, we consider it to be unoperatable. Therefore, we throw an DimensionException.
 */
template <typename T>
class Matrix {
    public:
        // --------
        // typedefs
        // --------

        typedef typename std::vector< std::vector<T> >    container_type;
        typedef typename container_type::value_type       value_type;

        typedef typename container_type::size_type        size_type;
        typedef typename container_type::difference_type  difference_type;

        typedef typename container_type::pointer          pointer;
        typedef typename container_type::const_pointer    const_pointer;

        typedef typename container_type::reference        reference;
        typedef typename container_type::const_reference  const_reference;

        typedef typename container_type::iterator         iterator;
        typedef typename container_type::const_iterator   const_iterator;

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * Used to test the equality of the individual elements of the two matrices.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of boolean values which contains either 1 or 0 depending on the result of
         * comparison.
         */
        friend Matrix<bool> operator == (const Matrix& lhs, const Matrix& rhs) {
            if ((lhs._m.size() != rhs._m.size()) || lhs._m.size() == 0 || lhs._m[0].size() != rhs._m[0].size() || lhs._m[0].size() == 0)
                throw DimensionException();
            Matrix<bool> result = Matrix<bool> (lhs._m.size(), lhs._m[0].size());
            for (size_type r = 0; r < lhs._m.size(); r++) {
                for (size_type c = 0; c < lhs._m[0].size(); c++) {
                    if (lhs._m[r][c] == rhs._m[r][c]) result[r][c] = true;
                    else result[r][c] = false;
                }
            }
            return result;}

        // -----------
        // operator !=
        // -----------

        /**
         * Used to test the inequality of the individual elements of the two matrices.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of boolean values which contains either 1 or 0 depending on the result
         * of comparison.
         */
        friend Matrix<bool> operator != (const Matrix& lhs, const Matrix& rhs) {
            if ((lhs._m.size() != rhs._m.size()) || lhs._m.size() == 0 || lhs._m[0].size() != rhs._m[0].size() || lhs._m[0].size() == 0)
                throw DimensionException();
            Matrix<bool> result = Matrix<bool> (lhs._m.size(), lhs._m[0].size());
            for (size_type r = 0; r < lhs._m.size(); r++) {
                for (size_type c = 0; c < lhs._m[0].size(); c++) {
                    if (lhs._m[r][c] != rhs._m[r][c]) result[r][c] = true;
                    else result[r][c] = false;
                }
            }
            return result;}

        // ----------
        // operator <
        // ----------

        /**
         * Used to compare the individual elements of the two matrices to check which elements of
         * the lhs matrix are less than the element at same loction in the rhs matrix.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of boolean values which contains either 1 or 0 depending on the result of
         * comparison.
         */
        friend Matrix<bool> operator < (const Matrix& lhs, const Matrix& rhs) {
            if ((lhs._m.size() != rhs._m.size()) || lhs._m.size() == 0 || lhs._m[0].size() != rhs._m[0].size() || lhs._m[0].size() == 0)
                throw DimensionException();
            Matrix<bool> result = Matrix<bool> (lhs._m.size(), lhs._m[0].size());
            for (size_type r = 0; r < lhs._m.size(); r++) {
                for (size_type c = 0; c < lhs._m[0].size(); c++) {
                    if (lhs._m[r][c] < rhs._m[r][c]) result[r][c] = true;
                    else result[r][c] = false;
                }
            }
            return result;}

        // -----------
        // operator <=
        // -----------

        /**
         * Used to compare the individual elements of the two matrices to check which elements of
         * the lhs matrix are less than or equal to the element at same loction in the rhs matrix.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of boolean values which contains either 1 or 0 depending on the result
         * of comparison.
         */
        friend Matrix<bool> operator <= (const Matrix& lhs, const Matrix& rhs) {
            if ((lhs._m.size() != rhs._m.size()) || lhs._m.size() == 0 || lhs._m[0].size() != rhs._m[0].size() || lhs._m[0].size() == 0)
                throw DimensionException();
            Matrix<bool> result = Matrix<bool> (lhs._m.size(), lhs._m[0].size());
            for (size_type r = 0; r < lhs._m.size(); r++) {
                for (size_type c = 0; c < lhs._m[0].size(); c++) {
                    if (lhs._m[r][c] <= rhs._m[r][c]) result[r][c] = true;
                    else result[r][c] = false;
                }
            }
            return result;}
            

        // ----------
        // operator >
        // ----------

        /**
         * Used to compare the individual elements of the two matrices to check which elements of
         * the lhs matrix are greater than the element at same loction in the rhs matrix.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of boolean values which contains either 1 or 0 depending on the result
         * of comparison.
         */
        friend Matrix<bool> operator > (const Matrix& lhs, const Matrix& rhs) {
            if ((lhs._m.size() != rhs._m.size()) || lhs._m.size() == 0 || lhs._m[0].size() != rhs._m[0].size() || lhs._m[0].size() == 0)
                throw DimensionException();
            Matrix<bool> result = Matrix<bool> (lhs._m.size(), lhs._m[0].size());
            for (size_type r = 0; r < lhs._m.size(); r++) {
                for (size_type c = 0; c < lhs._m[0].size(); c++) {
                    if (lhs._m[r][c] > rhs._m[r][c]) result[r][c] = true;
                    else result[r][c] = false;
                }
            }
            return result;}

        // -----------
        // operator >=
        // -----------

        /**
         * Used to compare the individual elements of the two matrices to check which elements of
         * the lhs matrix are greater than or equal to than the element at same loction in the rhs matrix.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of boolean values which contains either 1 or 0 depending on the result 
         * of comparison.
         */
        friend Matrix<bool> operator >= (const Matrix& lhs, const Matrix& rhs) {
            if ((lhs._m.size() != rhs._m.size()) || lhs._m.size() == 0 || lhs._m[0].size() != rhs._m[0].size() || lhs._m[0].size() == 0)
                throw DimensionException();
            Matrix<bool> result = Matrix<bool> (lhs._m.size(), lhs._m[0].size());
            for (size_type r = 0; r < lhs._m.size(); r++) {
                for (size_type c = 0; c < lhs._m[0].size(); c++) {
                    if (lhs._m[r][c] >= rhs._m[r][c]) result[r][c] = true;
                    else result[r][c] = false;
                }
            }
            return result;}

        // ----------
        // operator +
        // ----------

        /**
         * Used to enable addition operation by calling the +=() funtion.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the component of type T which will be added to the individual elements of lhs.
         * @return a matrix of elements type T.
         */
        friend Matrix operator + (Matrix lhs, const T& rhs) {
            return lhs += rhs;}

        /**
         * Used to enable addition operation by calling the +=() funtion.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of elements type T.
         */
        friend Matrix operator + (Matrix lhs, const Matrix& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * Used to enable subtraction by calling the -=() funtion.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the component of type T which will be subtracted from the individual elements of lhs.
         * @return a matrix of elements type T.
         */
        friend Matrix operator - (Matrix lhs, const T& rhs) {
            return lhs -= rhs;}

        /**
         * Used to enable subtraction by calling the -=() funtion.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of elements type T.
         */
        friend Matrix operator - (Matrix lhs, const Matrix& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
         * Used to enable multiplication operation by calling the *=() funtion.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the component of type T which will be multiplied with the individual elements of lhs.
         * @return a matrix of elements type T.
         */
        friend Matrix operator * (Matrix lhs, const T& rhs) {
            return lhs *= rhs;}

        /**
         * Used to enable multiplication operation by calling the *=() funtion.
         * - the matrices must not be empty.
         * - the number of rows of the rhs matrix must be equal the number of columns of the 
         * - left hand side matrix.
         * @param lhs the matrix on the left hand side of the equation.
         * @param rhs the matrix on the right hand side of the equation.
         * @return a matrix of elements type T.
         */
        friend Matrix operator * (Matrix lhs, const Matrix& rhs) {
            return lhs *= rhs;}

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<T> > _m;

        // -----
        // valid
        // -----

        /**
         * Used to test the validity of this matrix: every row has the same number of columns.
         * @return a boolean that indicates wether it is a valid matrix or not.
         */
        bool valid () const {
            if (_m.size() == 0) return true;
            else {
                size_type s = _m[0].size();
                for (size_type i = 0; i < _m.size(); i++) {
                    if (_m[i].size() != s) return false;
                }
            }
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Construts a matrix of row r and column c, filled with v.
         * @param r indicates number of rows matrix will have.
         * @param c indicates number of columns matrix will have.
         * @param v indicates the value of elements type T that will be initialized in matrix.
         */
        Matrix (size_type r = 0, size_type c = 0, const T& v = T()) {
            _m = std::vector< std::vector<T> >(r, std::vector<T>(c, v));
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Matrix  (const Matrix<T>&);
        // ~Matrix ();
        // Matrix& operator = (const Matrix&);

        // -----------
        // operator []
        // -----------

        /**
         * Used to obtain an individual row of the underlying matrix.
         * @param i indicates the row number.
         * @return a read/write reference to the row.
         */
        reference operator [] (size_type i) {
            return _m[i];}

        /**
         * Used to obtain an individual row of the underlying matrix.
         * @param i indicates the row number.
         * @return a read-only reference to the row.
         */
        const_reference operator [] (size_type i) const {
            return (*const_cast<Matrix*>(this))[i];}

        // -----------
        // operator +=
        // -----------

        /**
         * Used to perform the addtion between a matrix and an individual component of type T
         * rhs, which will be added to the individual elements of the matrix.
         * @param rhs the component to be added to the individual elements of the matrix.
         * @return a reference of the matrix after addtion.
         */
        Matrix& operator += (const T& rhs) {
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] + rhs;
                }
            }
            return *this;}

        // -----------
        // operator +=
        // -----------

        /**
         * Used to perform the addtion between two matrices.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param rhs the matrix on the right hand side.
         * @return a reference of the matrix after addtion.
         */
        Matrix& operator += (const Matrix& rhs) {
            if ((_m.size() != rhs._m.size()) || _m.size() == 0 || _m[0].size() != rhs._m[0].size() || _m[0].size() == 0)
                throw DimensionException();
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] + rhs[r][c];
                }
            }
            return *this;
        }

        // -----------
        // operator -=
        // -----------

        /**
         * Used to perform the subtraction between a matrix and an individual component of type T
         * rhs, which will be subtracted from the individual elements of the matrix.
         * @param rhs the component to be subtracted from the individual elements of the matrix.
         * @return a reference of the matrix after subtraction.
         */
        Matrix& operator -= (const T& rhs) {
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] - rhs;
                }
            }
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * Used to perform the subtraction between two matrices.
         * - the matrices must not be empty.
         * - the matrices must have the same row.
         * - the matrices must have the same column.
         * @param rhs the matrix on the right hand side.
         * @return a reference of the matrix after subtraction.
         */
        Matrix& operator -= (const Matrix& rhs) {
            if ((_m.size() != rhs._m.size()) || _m.size() == 0 || _m[0].size() != rhs._m[0].size() || _m[0].size() == 0)
                throw DimensionException();
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] - rhs[r][c];
                }
            }
            return *this;
        }

        // -----------
        // operator *=
        // -----------

        /**
         * Used to perform the multiplication between a matrix and an individual component of type T
         * rhs, which will be multiplied with the individual elements of the matrix.
         * @param rhs the component to be multiplied with the individual elements of the matrix.
         * @return a reference of the matrix after multiplication.
         */
        Matrix& operator *= (const T& rhs) {
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] * rhs;
                }
            }
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * Used to perform matrix multiplication.
         * - the matrices must not be empty.
         * - the number of rows of the rhs matrix must be equal the number of columns of the 
         * - left hand side matrix.
         * @param rhs the matrix on the right hand side.
         * @return a reference of the matrix after multiplication.
         */
        Matrix& operator *= (const Matrix& rhs) { 
            if (_m.size() == 0 || rhs._m.size() == 0) {
                throw DimensionException();
            }                
            else if (_m[0].size() == rhs._m.size() ){
                Matrix<T> lhs = (*this);
                for (size_type i = 0; i < _m.size(); i++)  _m[i].resize(rhs._m[0].size(), 0);
                (*this) *= 0;
                for (size_type c = 0; c < _m[0].size(); c++) {
                    for (size_type r = 0; r < _m.size(); r++) {
                        for (size_type old_r = 0; old_r < rhs._m.size(); old_r++) {
                            _m[r][c] += (lhs._m[r][old_r] * rhs._m[old_r][c]);
                        }
                    }
                }
                return *this;
            }
            else {
                throw DimensionException();
            }
        }

        // --
        // eq
        // --

        /**
         * Used to test the equality of two matrices.
         * @param rhs the matrix on the right hand side.
         * @return true of false to indicate whether these two matrices are equal.
         */
        bool eq (const Matrix& rhs) const {
            if (_m.size() != rhs._m.size()) return false;
            else {
                if (_m.size() == 0) return true;
                else {
                    if (_m[0].size() != rhs._m[0].size()) return false;
                    else if (_m[0].size() == 0) return true;
                }
            }
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    if (_m[r][c] != rhs._m[r][c]) return false;
                }
            }
            return true;}

        // ---------
        // push_back
        // ---------

        /**
         * Used to add a row to the matrix.
         * @row the row to be added
         */
        void push_back (std::vector<T> row) {
            _m.push_back(row);
        }

        // -----
        // begin
        // -----

        /**
         * @return a read/write iterator that points to the beginning of the matrix.
         */
        iterator begin () {
            return _m.begin();}

        /**
         * @return a read-only iterator that points to the beginning of the matrix.
         */
        const_iterator begin () const {
            return const_cast<Matrix*>(this)->begin();}

        // ---
        // end
        // ---

        /**
         * @return a read/write iterator that points to the end of the matrix.
         */
        iterator end () {
            return _m.end();}

        /**
         * @return a read-only iterator that points to the end of the matrix.
         */
        const_iterator end () const {
            return const_cast<Matrix*>(this)->end();}

        // ----
        // size
        // ----

        /**
         * @return the size of the matrix, which is the row number.
         */
        size_type size () const {
            return _m.size();}};

#endif // Matrix_h
