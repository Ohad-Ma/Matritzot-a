/**
 * @file Test.cpp
 * @author Ohad Maday (maday.ohad.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>

using namespace zich;
double WholeNumberGenerator(bool type);
double FractionGenerator(bool type);


TEST_CASE("valdiates rows and cols"){
    srand(time(NULL));
    // Declare & initialize variables - 
    double num_a = WholeNumberGenerator(true);
    double num_b = WholeNumberGenerator(false);
    double num_c = WholeNumberGenerator(true);
    double num_d = WholeNumberGenerator(false);

    /**
     * @brief Can a matrix have negative rows and cols?
     * 
     */
    SUBCASE("Negative Integer Rows & Cols"){
        // Trying to create Matrice objects using the numbers above
        CHECK_THROWS(Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},(int)num_b,3));             // Just rows
        CHECK_THROWS(Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},3,(int)num_b));             // Just cols
        CHECK_THROWS(Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},(int)num_b,(int)num_b));    // Both rows and cols are same negative number
        CHECK_THROWS(Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},(int)num_b,(int)num_d));    // Both rows and cols are different negative number

    }

    /**
     * @brief Validates that the amount of rows and cols equals the amount of numbers within the matrix
     * 
     */
    SUBCASE("Validates that the amount of row and col equals to the amount of numbers within the vector"){
        CHECK_THROWS(Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},num_a,num_a));
        CHECK_NOTHROW(Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},3,3));
    }
}
/**
 * @brief Many checks for arithmetic operators with subchecks 
 * 
 * Cases of the following operators:
 * Let a,b matrice, num a number such:
 *          a+
 *          a+b
 *          a+=b         
 * 
 *          a-
 *          a-b
 *          a-=b
 * 
 *          a*num
 *          num*a
 *          a*b
 *          a*=b
 *          a*=num
 *          
 */
TEST_CASE("Basic Arithmetics"){
    srand(time(NULL));
    // Declare & initialize variables - 
    double num_a = WholeNumberGenerator(true);
    double num_b = WholeNumberGenerator(false);
    double num_c = WholeNumberGenerator(true);
    double num_d = WholeNumberGenerator(false);
    double frac_1 = FractionGenerator(true);
    double frac_2 = FractionGenerator(false);

    // Initialize matrice - 3 with whole numbers 1 with real numbers and another one with different dimension
    Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},3,3);
    Matrix b({num_a, num_c, num_d, num_d, num_b, num_b, num_c, num_a, num_b},3,3);
    Matrix c({num_a, num_a, num_a, num_b, num_b, num_b, num_c, num_c, num_c},3,3);
    Matrix e({frac_1, num_a, frac_2, frac_1, num_b, num_b, frac_1, num_c, frac_2},3,3);
    Matrix d({num_c, num_c, num_c, num_c, num_c, num_c},2,2);

    // + operator
    SUBCASE("Normal +"){
        CHECK_NOTHROW(+a); // + Unary

        // += operator
        SUBCASE("+= operator"){
            CHECK_NOTHROW(a+=b);
            CHECK_NOTHROW(a+=c);

            // Checking for addition with a different dimension matrix
            CHECK_THROWS(a+=d); 
            CHECK_THROWS(d+=a);
        }

        // Supposed to increace every number within the matrix
        SUBCASE("Increment (++)"){
            CHECK_NOTHROW(a++);
        }
        
        /**
         * @brief  Matrix addition another Matrix
         * 
         */
        SUBCASE("Between matrices"){
            CHECK_NOTHROW(a+b);
            CHECK_NOTHROW(b+a);
            CHECK_NOTHROW(c+a);
            CHECK_NOTHROW(a+c);

            // Checking for addition with a different dimension matrix
            CHECK_THROWS(a+d); 
            CHECK_THROWS(d+b);

            SUBCASE("+ with fractions"){
            CHECK_NOTHROW(a+e);
            CHECK_NOTHROW(e+a);
            CHECK_NOTHROW(c+e);
            CHECK_NOTHROW(e+c);

            // Checking for addition with a matrix contain real numbers and a matrix with a different dimension
            CHECK_THROWS(e+d);
            CHECK_THROWS(d+e);
            }
        }
        
    }
    /**
     * @brief Check operator -
     * 
     */
    SUBCASE("operator -"){
        CHECK_NOTHROW(-a); // - Unary

        /**
         * @brief Check -= operator
         * 
         */
        SUBCASE("-= operator"){
            CHECK_NOTHROW(a-=b);
            CHECK_NOTHROW(a-=e);
            CHECK_THROWS(a-=d);  // Subtract matrice with different dimensions
        }

        /**
         * @brief Subtract matrice
         * 
         */
        SUBCASE("Between matrice"){
            CHECK_NOTHROW(a-b);
            CHECK_NOTHROW(b-a);
            CHECK_NOTHROW(c-a);
            CHECK_NOTHROW(a-c);

            // Subtract matrice with different dimensions
            CHECK_THROWS(a-d);
            CHECK_THROWS(d-b);

            /**
             * @brief - matrice with real numbers and and whole
             * 
             */
            SUBCASE("- with fractions"){
            CHECK_NOTHROW(a-e);
            CHECK_NOTHROW(e-a);
            CHECK_NOTHROW(c-e);
            CHECK_NOTHROW(e-c);
            CHECK_THROWS(e-d);
            CHECK_THROWS(d-e);
            }
        }
    }

    /**
     * @brief * operator
     * 
     */
    SUBCASE("* Operator"){
        CHECK_NOTHROW(num_a*b);
        CHECK_NOTHROW(num_b*b);
        CHECK_NOTHROW(b*num_a);
        CHECK_NOTHROW(b*num_b);
        CHECK_NOTHROW(frac_1*a);
        CHECK_NOTHROW(frac_2*c);
        CHECK_NOTHROW(a*frac_1);
        CHECK_NOTHROW(c*frac_2);
        
        /**
         * @brief *= operator
         * 
         */
        SUBCASE("*= operator"){
            CHECK_NOTHROW(b*=num_a);
            CHECK_NOTHROW(b*=num_b);
            CHECK_NOTHROW(b*=frac_1);
            CHECK_NOTHROW(b*=frac_2);
            CHECK_NOTHROW(a*=b);
            CHECK_NOTHROW(a*=c);

            // Checking for multipication with a different dimension matrix
            CHECK_THROWS(a*=d); 
            CHECK_THROWS(d*=a);
        }

        SUBCASE("Between matrices"){
            CHECK_NOTHROW(a*b);
            CHECK_NOTHROW(b*a);
            CHECK_NOTHROW(c*a);
            CHECK_NOTHROW(a*c);
            CHECK_THROWS(a*d);
            CHECK_THROWS(d*b);

            SUBCASE("* with fractions"){
            CHECK_NOTHROW(a*e);
            CHECK_NOTHROW(e*a);
            CHECK_NOTHROW(c*e);
            CHECK_NOTHROW(e*c);
            CHECK_THROWS(e*d);
            CHECK_THROWS(d*e);
            }
        }
    }
    /**
     * @brief Mix check of basic arithmetics 
     * 
     */
    SUBCASE("Mix em all"){
        CHECK_NOTHROW(a+b-c-e);
        CHECK_NOTHROW(num_a*(a+b)-c);
        CHECK_THROWS((b-c)+d);
        CHECK_THROWS(b*=((b-c)+d));
        CHECK_NOTHROW(a*=(b-c-e));
        CHECK_NOTHROW(a-=(b-c-e));
    }
}

/**
 * @brief Checking Postfix & Prefix increment and decrement operators
 * 
 * Cases of the following operators:
 * 
 *          a++
 *          ++a
 *          a--
 *          --a
 *          
 */
TEST_CASE("Increment & Decrement"){
    srand(time(NULL));
    double num_a = WholeNumberGenerator(true);
    double num_b = WholeNumberGenerator(false);
    Matrix a({num_a,num_a,num_b,num_a,num_b,num_a,num_b,num_b,num_a},3,3);
    CHECK_NOTHROW(a--);
    CHECK_NOTHROW(--a);
    CHECK_NOTHROW(--a--);
    CHECK_NOTHROW(a++);
    CHECK_NOTHROW(++a);
    CHECK_NOTHROW(++a++);
}

/**
 * @brief Checking boolean operators.
 * 
 * Cases of the following operators:
 * 
 *      >
 *      <
 *      <=
 *      >=
 *      ==
 *      !=
 * 
 */
TEST_CASE("Boolean cases"){
    double num = WholeNumberGenerator(true);
    Matrix specific_a({1, 0, 0, 0, 1, 0, 0, 0, 1},3,3);
    Matrix specific_d({1, 0, 0, 0, 1, 0, 0, 0, 1},3,3);
    Matrix specific_b({0, 2, 0, 0, 2, 0, 0, 2, 0},3,3);
    Matrix specific_c({0, 0, 3, 0, 0, 3, 0, 0, 3},3,3);
    Matrix d({num, num, num, num, num, num},2,2);


    CHECK_NOTHROW(CHECK_EQ(specific_a <  specific_b, true));
    CHECK_NOTHROW(CHECK_EQ(specific_c > specific_a, true));
    CHECK_NOTHROW(CHECK_EQ(specific_a <= specific_b, true));
    CHECK_NOTHROW(CHECK_EQ(specific_a >= specific_a, true));
    CHECK_NOTHROW(CHECK_EQ(specific_a == specific_d, true));
    CHECK_NOTHROW(CHECK_NE(specific_a == specific_b, true));
    CHECK_NOTHROW(CHECK_EQ(specific_a != specific_b, true));


    // Matrice with different dimensions should throw an error according to README.md
    CHECK_THROWS(CHECK_EQ((specific_a <  d),false));
    CHECK_THROWS(CHECK_EQ((specific_c >  d),true));
    CHECK_THROWS(CHECK_EQ((specific_a <= d),true));
    CHECK_THROWS(CHECK_EQ((specific_a >= d), true));
    CHECK_THROWS(CHECK_EQ((specific_a != d), true));
    CHECK_THROWS(CHECK_EQ((specific_a == d), true));
    
}

/**
 * @brief Mix many operators (most of the ones above)
 * 
 */
TEST_CASE("Mixture of cases"){
    srand(time(NULL));
    double num = WholeNumberGenerator(true);
    Matrix specific_a({1, 0, 0, 0, 1, 0, 0, 0, 1},3,3);
    Matrix specific_d({1, 0, 0, 0, 1, 0, 0, 0, 1},3,3);
    Matrix specific_e({2, 1, 1, 1, 2, 1, 1, 1, 2},3,3);
    Matrix specific_b({0, 2, 0, 0, 2, 0, 0, 2, 0},3,3);
    Matrix specific_c({0, 0, 3, 0, 0, 3, 0, 0, 3},3,3);
    Matrix specific_ans({1, 2, 3, 1, 2, 3, 1, 2, 3},3,3);

 
    CHECK_EQ((specific_a + specific_b + specific_c) == specific_ans, true);
    CHECK_EQ((specific_a * specific_d) == specific_a, true);
    CHECK_EQ((specific_a * 1) == specific_a, true);
    CHECK_EQ((specific_a + specific_d) > specific_a, true);
    CHECK_EQ(((specific_a + specific_d) * 5) > specific_a, true);
    CHECK_EQ((specific_d += specific_a) > specific_a, true);
    CHECK_EQ((specific_a -= specific_a) < specific_a, true);
    CHECK_EQ((specific_a - specific_b) < specific_a, true);
    CHECK_EQ((specific_a * num) != specific_a, true);
    CHECK_NE((2 * specific_a) == specific_a, true);
    CHECK_EQ(specific_a++ == specific_e, true);

}

/**
 * @brief Check for errors when printing the matrices and doing arithmetics on them
 * *cannot do a test case for cin*
 * 
 */
TEST_CASE("Outstream Instream"){
    srand(time(NULL));
    double num_a = WholeNumberGenerator(true);
    double num_b = WholeNumberGenerator(false);
    double num_c = WholeNumberGenerator(true);
    double num_d = WholeNumberGenerator(false);

    Matrix a({num_a, num_b, num_c, num_d, num_a, num_d, num_d, num_d, num_b},3,3);
    Matrix b({num_a, num_c, num_d, num_d, num_b, num_b, num_c, num_a, num_b},3,3);
    Matrix c({num_a, num_a, num_a, num_b, num_b, num_b, num_c, num_c, num_c},3,3);
    Matrix d({num_c, num_c, num_c, num_c, num_c, num_c},2,2);

    CHECK_NOTHROW(std::cout << a);
    CHECK_NOTHROW(std::cout << (a+b));
    CHECK_NOTHROW(std::cout << (c-b));
    // Trying to print matrice with different dimensions
    CHECK_THROWS(std::cout << (a+d));
    CHECK_THROWS(std::cout << (b-d));
    CHECK_THROWS(std::cout << (a*d));

}

/**
 * @brief generates random number between 0 and 100 (is there any need for an higher number?)
 * @param type :
 *               true - positive integer
 *              ,false - negative integer
 * @return int
 */
double WholeNumberGenerator(bool type){
    double num = 0;
    num = rand()%(100+1-0)+0;
    
    return type ? num : -num;
}

/**
 * @brief generates random even number between 0 and 100 (is there any need for an higher number?)
 * @param type :
 *               true - positive integer
 *              ,false - negative integer
 * @return int
 */
double FractionGenerator(bool type){
    double num = 0;
    num = (float) rand()/RAND_MAX;

    return type ? num : -num;
}