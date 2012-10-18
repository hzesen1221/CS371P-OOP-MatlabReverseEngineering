// ------------------------------
// projects/matlab/TestMatrix.c++
// Copyright (C) 2012
// Glenn P. Downing
// ------------------------------

/**
 * To test the program:
 *     g++ -ansi -pedantic -lcppunit -ldl -Wall TestMatrix.c++ -o TestMatrix.app
 *     valgrind TestMatrix.app >& TestMatrix.out
 */

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
#define private public
#include "Matrix.h"
// ----------
// TestMatrix
// ----------

struct TestMatrix : CppUnit::TestFixture {
    // -----------------
    // test_constructor1
    // -----------------

    void test_constructor1 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(x.size() == 0);}

    // -----------------
    // test_constructor2
    // -----------------

    void test_constructor2 () {
        Matrix<int> x;
        Matrix<double> y(2);
        Matrix<int> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(y.size() == 2);}

    // -----------------
    // test_constructor3
    // -----------------

    void test_constructor3 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<short> z(2, 3);
        Matrix<int> t(2, 3, 4);
        CPPUNIT_ASSERT(z.size() == 2);}


    // -----------------
    // test_constructor4
    // -----------------

    void test_constructor4 () {
        Matrix<int> x;
        Matrix<int> y(2);
        Matrix<int> z(2, 3);
        Matrix<float> t(2, 3, 4.4);
        CPPUNIT_ASSERT(t.size() == 2);}

    // -----------
    // test_index1
    // -----------

    void test_index1 () {
        const Matrix<int> x(1, 1);
        CPPUNIT_ASSERT(x[0][0] == 0);}

    // -----------
    // test_index2
    // -----------

    void test_index2 () {
        const Matrix<int> x(1, 1, 100);
        CPPUNIT_ASSERT(x[0][0] == 100);}

    // -----------
    // test_index3
    // -----------

    void test_index3 () {
        Matrix<int> x(5, 5, 1000);
        CPPUNIT_ASSERT(x[4][4] == 1000);}


    // -----------
    // test_equals
    // -----------

    void test_equals () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    // --------------
    // test_less_than
    // --------------

    void test_less_than () {
        Matrix<int>  x;
        Matrix<int>  y;
        Matrix<bool> z;
        Matrix<bool> t;
        z = (x == y);
        CPPUNIT_ASSERT(z.eq(t));}

    // ----------
    // test_plus1
    // ----------

    void test_plus1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x += 0;
        CPPUNIT_ASSERT(x.eq(z));
        x += y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ----------
    // test_plus2
    // ----------

    void test_plus2 () {
        Matrix<int> x(4, 4, 5);
        Matrix<int> y(4, 4, 10);
        Matrix<int> z = x + y;
        Matrix<int> w(4, 4, 15);
        CPPUNIT_ASSERT(w.eq(z));}

    // ----------
    // test_plus3
    // ----------

    void test_plus3 () {
        Matrix<int> x(10, 10, 10);
        Matrix<int> y(20, 10, 20);
        Matrix<int> z = x + y; //different dimension (row), should return x, unmodified.
        CPPUNIT_ASSERT(z.eq(x));
        z += 100;
        Matrix<int> w(10, 10, 110);
        CPPUNIT_ASSERT(z.eq(w));}

    // ----------
    // test_plus4
    // ----------

    void test_plus4 () {
        Matrix<int> x(10, 10, 10);
        Matrix<int> y(10, 20, 20);
        Matrix<int> z = x + y; //different dimension (column), should return x, unmodified.
        CPPUNIT_ASSERT(z.eq(x));
        z += 100;
        Matrix<int> w(10, 10, 110);
        CPPUNIT_ASSERT(z.eq(w));}

    // ----------
    // test_minus1
    // ----------

    void test_minus1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x -= 0;
        CPPUNIT_ASSERT(x.eq(z));
        x -= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ----------
    // test_minus2
    // ----------

    void test_minus2 () {
        Matrix<int> x(4, 4, 6);
        Matrix<int> y(4, 4, 10);
        y -= x;
        Matrix<int> w(4, 4, 4);
        CPPUNIT_ASSERT(w.eq(y));}

    // ----------
    // test_minus3
    // ----------

    void test_minus3 () {
        Matrix<int> x(10, 10, 10);
        Matrix<int> y(20, 10, 20);
        Matrix<int> z = y - x; //different dimension (row), should return y, unmodified.
        CPPUNIT_ASSERT(z.eq(y));
        z = z - 2;
        Matrix<int> w(20, 10, 18);
        CPPUNIT_ASSERT(z.eq(w));}

    // ----------
    // test_minus4
    // ----------

    void test_minus4 () {
        Matrix<int> x(10, 10, 10);
        Matrix<int> y(10, 20, 20);
        Matrix<int> z = y - x; //different dimension (column), should return y, unmodified.
        CPPUNIT_ASSERT(z.eq(y));
        z = z - 2;
        Matrix<int> w(10, 20, 18);
        CPPUNIT_ASSERT(z.eq(w));}

    // ----------
    // test_valid1
    // ----------

    void test_valid1 () {
        Matrix<int> x;
        CPPUNIT_ASSERT(x.valid());}

    // ----------
    // test_valid2
    // ----------

    void test_valid2 () {
        Matrix<int> x(5);
        CPPUNIT_ASSERT(x.valid());}

    // ----------
    // test_valid3
    // ----------

    void test_valid3 () {
        Matrix<int> x(5, 10);
        CPPUNIT_ASSERT(x.valid());}

    // ----------
    // test_valid4
    // ----------

    void test_valid4 () {
        Matrix<double> x(5, 10, 10.20);
        CPPUNIT_ASSERT(x.valid());}

    // ---------------
    // test_multiplies1
    // ---------------

    void test_multiplies1 () {
        Matrix<int> x;
        Matrix<int> y;
        Matrix<int> z;
        x *= 0;
        CPPUNIT_ASSERT(x.eq(z));
        //x *= y;
        //CPPUNIT_ASSERT(x.eq(z))
    ;}

    // ---------------
    // test_multiplies2
    // ---------------

    void test_multiplies2 () {
        Matrix<int> x(4, 2, 2);
        Matrix<int> y(2, 5, 3);
        Matrix<int> z(4, 5, 12);
        x *= y;
        CPPUNIT_ASSERT(x.eq(z));}

    // ---------------
    // test_multiplies3
    // ---------------

    void test_multiplies3 () {
        Matrix<int> x(4, 2, 2);
        Matrix<int> y;
        y = x * y;
        CPPUNIT_ASSERT(x.eq(y));}

    // ---------------
    // test_multiplies4
    // ---------------

    void test_multiplies4 () {
        Matrix<int> x(4, 2, 2);
        Matrix<int> y(3, 5, 3);
        Matrix<int> z = x * y;
        CPPUNIT_ASSERT(x.eq(z));}

    // -------------
    // test_iterator
    // -------------

    void test_iterator () {
        Matrix<int> x;
        Matrix<int>::iterator b = x.begin();
        Matrix<int>::iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -------------------
    // test_const_iterator
    // -------------------

    void test_const_iterator () {
        const Matrix<int> x;
        Matrix<int>::const_iterator b = x.begin();
        Matrix<int>::const_iterator e = x.end();
        CPPUNIT_ASSERT(b == e);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST(test_iterator);
    CPPUNIT_TEST(test_const_iterator);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_constructor4);
    CPPUNIT_TEST(test_index1);
    CPPUNIT_TEST(test_index2);
    CPPUNIT_TEST(test_index3);
    CPPUNIT_TEST(test_plus1);
    CPPUNIT_TEST(test_plus2);
    CPPUNIT_TEST(test_plus3);
    CPPUNIT_TEST(test_plus4);
    CPPUNIT_TEST(test_minus1);
    CPPUNIT_TEST(test_minus2);
    CPPUNIT_TEST(test_minus3);
    CPPUNIT_TEST(test_minus4);
    CPPUNIT_TEST(test_valid1);
    CPPUNIT_TEST(test_valid2);
    CPPUNIT_TEST(test_valid3);
    CPPUNIT_TEST(test_valid4);
    CPPUNIT_TEST(test_multiplies1);
    CPPUNIT_TEST(test_multiplies2);
    CPPUNIT_TEST(test_multiplies3);
    CPPUNIT_TEST(test_multiplies4);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestMatrix.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestMatrix::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
