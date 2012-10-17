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

// ------
// Matrix
// ------

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
         * <your documentation>
         */
        friend Matrix<bool> operator == (const Matrix& lhs, const Matrix& rhs) {
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

        // -----------
        // operator !=
        // -----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator != (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator < (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return false;}

        // -----------
        // operator <=
        // -----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator <= (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // ----------
        // operator >
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator > (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // -----------
        // operator >=
        // -----------

        /**
         * <your documentation>
         */
        friend Matrix<bool> operator >= (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return true;}

        // ----------
        // operator +
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator + (Matrix lhs, const T& rhs) {
            return lhs += rhs;}

        /**
         * <your documentation>
         */
        friend Matrix operator + (Matrix lhs, const Matrix& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator - (Matrix lhs, const T& rhs) {
            return lhs -= rhs;}

        /**
         * <your documentation>
         */
        friend Matrix operator - (Matrix lhs, const Matrix& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator * (Matrix lhs, const T& rhs) {
            return lhs *= rhs;}

        /**
         * <your documentation>
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
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
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
         * <your documentation>
         */
        reference operator [] (size_type i) {
            return _m[i];}

        /**
         * <your documentation>
         */
        const_reference operator [] (size_type i) const {
            return (*const_cast<Matrix*>(this))[i];}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator += (const T& rhs) {
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] + rhs;
                }
            }
            return *this;}

        /**
         * <your documentation>
         */
        Matrix& operator += (const Matrix& rhs) {
            if (_m.size() == rhs._m.size()) {
                if (_m.size() == 0) {
                    return *this;
                }
                if (_m[0].size() == rhs._m[0].size()) {
                    if (_m[0].size() == 0) {
                        return *this;
                    }
                    else {
                        for (size_type r = 0; r < _m.size(); r++) {
                            for (size_type c = 0; c < _m[0].size(); c++) {
                                (*this)[r][c] = (*this)[r][c] + rhs[r][c];
                            }
                        }
                        return *this;
                    }
                }
                else {
                    std::cout << "Column numbers do not match.\n";
                    return *this;
                }
            }
            else {
                std::cout << "Row numbers do not match.\n";
                return *this;
            }
        }

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator -= (const T& rhs) {
            for (size_type r = 0; r < _m.size(); r++) {
                for (size_type c = 0; c < _m[0].size(); c++) {
                    (*this)[r][c] = (*this)[r][c] - rhs;
                }
            }
            return *this;}

        /**
         * <your documentation>
         */
        Matrix& operator -= (const Matrix& rhs) {
            if (_m.size() == rhs._m.size()) {
                if (_m.size() == 0) {
                    return *this;
                }
                if (_m[0].size() == rhs._m[0].size()) {
                    if (_m[0].size() == 0) {
                        return *this;
                    }
                    else {
                        for (size_type r = 0; r < _m.size(); r++) {
                            for (size_type c = 0; c < _m[0].size(); c++) {
                                (*this)[r][c] = (*this)[r][c] - rhs[r][c];
                            }
                        }
                        return *this;
                    }
                }
                else {
                    std::cout << "Column numbers do not match.\n";
                    return *this;
                }
            }
            else {
                std::cout << "Row numbers do not match.\n";
                return *this;
            }
        }

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator *= (const T& rhs) {
            // <your code>
            return *this;}

        /**
         * <your documentation>
         */
        Matrix& operator *= (const Matrix& rhs) {
            // <your code>
            return *this;}

        // --
        // eq
        // --

        /**
         * <your documentation>
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

        // -----
        // begin
        // -----

        /**
         * <your documentation>
         */
        iterator begin () {
            return _m.begin();}

        /**
         * <your documentation>
         */
        const_iterator begin () const {
            return const_cast<Matrix*>(this)->begin();}

        // ---
        // end
        // ---

        /**
         * <your documentation>
         */
        iterator end () {
            return _m.end();}

        /**
         * <your documentation>
         */
        const_iterator end () const {
            return const_cast<Matrix*>(this)->end();}

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const {
            return _m.size();}};

#endif // Matrix_h
