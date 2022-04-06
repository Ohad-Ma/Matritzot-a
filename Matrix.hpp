/**
 * @file Matrix.hpp
 * @author Ohad Maday (maday.ohad.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>

namespace zich{
    /**
     * @brief Matrix class which uses unordered map as it data structure to store data (numbers within the matrix)
     * ROWS - dimension of the matrix
     * COLS - dimension of the matrix
     * Therefore, matrix size of ROWSxCOLS
     * 
     * The class holds various legal operations that done between matrice (or the matrix itself):
     * Let a,b matrice, num - a random whole/real number in R such that:     
     * 
     * list of operators -
     *      a + b
     *      a += b
     *      a + (unary)
     * 
     *      a - b
     *      a -= b
     *      a - (unary)
     * 
     *      a++
     *      ++a
     *      a--
     *      --a
     * 
     *      a*num
     *      num*a
     *      a*b
     *      a*=b
     * 
     * 
     */
    
    class Matrix{


        public:
        Matrix(std::vector<double> v, int row, int col ); // Constructor


        //Arithmetic Operators
        Matrix& operator+ (const Matrix& mat);   // a + b
        Matrix& operator+= (const Matrix& mat);  // a = a + b 
        Matrix& operator+ ();                    // Unary +
        Matrix& operator- (const Matrix& mat);   // a - b
        Matrix& operator-= (const Matrix& mat);  // a = a - b
        Matrix& operator- ();                    // Unary -


        /*
        * Boolean Operators
        * I do not want to mess with the result of the function, that's why the functions below are const 
        */
        bool operator< (const Matrix& mat)  const; // a <  b 
        bool operator<= (const Matrix& mat) const; // a <= b
        bool operator> (const Matrix& mat)  const; // a >  b
        bool operator>= (const Matrix& mat) const; // a >= b
        bool operator== (const Matrix &mat) const; // a == b
        bool operator!= (const Matrix& mat) const; // a != b

        /*
        *  Prefix Operators
        */
        Matrix& operator++ (); // ++a
        Matrix& operator-- (); // --a
        
        /*
        *  Postfix Operators
        */
        Matrix& operator++ (int); // a++
        Matrix& operator-- (int); // a--

        /*
        *  Multipication Operators - scalar multipication
        */
        Matrix& operator* (const Matrix &mat);                      // a * b
        Matrix& operator* (double num1);                            // num * a
        Matrix& operator*= (double num1);                           // a = a * num
        Matrix& operator*= (const Matrix &mat);                     // a = a * b
        friend Matrix operator*(double number, const Matrix &mat);  // a * num


        /*
        * Stream Operators: 
        * cin >> [1 0 0], [0 1 0], [0 0 1] 
        * cout << "[3 0 0]\n[0 3 0]\n[0 0 3]";
        */
        friend std::ostream& operator<<( std::ostream& os, const Matrix& mat);
        friend std::istream& operator>>( std::istream &is, Matrix &mat);

    };
}