/**
 * @file Matrix.cpp
 * @author Ohad Maday (maday.ohad.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Matrix.hpp"
/**
 * @brief Documentation is written in the header file ("Matrix.hpp")
 * 
 */
namespace zich{
    Matrix::Matrix(std::vector<double> v, int row, int col ){}

    Matrix& Matrix::operator+ (const Matrix& mat){
        return *this;
    }

    Matrix& Matrix::operator+= (const Matrix& mat){
        return *this;
    }

    Matrix& Matrix::operator+(){
        return *this;
    }

    Matrix& Matrix::operator-(const Matrix& mat){
        return *this;
    }

    Matrix& Matrix::operator-= (const Matrix& mat){
        return *this;
    }

    Matrix& Matrix::operator- (){
        return *this;
    }


    bool Matrix::operator< (const Matrix& mat) const{
        return true;
    }

    bool Matrix::operator<= (const Matrix& mat) const{
        return true;
    }

    bool Matrix::operator> (const Matrix& mat) const{
        return true;
    }

    bool Matrix::operator>= (const Matrix& mat) const{
        return true;
    }

    bool Matrix::operator== (const Matrix &mat) const{
        return true;
    }

    bool Matrix::operator!= (const Matrix& mat) const{
        return true;
    }


    Matrix& Matrix::operator++ (){
        return *this;
    }

    Matrix& Matrix::operator-- (){
        return *this;
    }


    Matrix& Matrix::operator++ (int){
        return *this;
    }

    Matrix& Matrix::operator-- (int){
        return *this;
    }


    Matrix& Matrix::operator* (const Matrix &mat){
        return *this;
    }
    Matrix& Matrix::operator* (double num1){
        return *this;
    }

    Matrix& Matrix::operator*= (double num1){
        return *this;
    }
        Matrix& Matrix::operator*= (const Matrix &mat){
        return *this;
    }

    Matrix operator*(double number, const Matrix &mat){
        return mat;
    }


    std::ostream &operator<<(std::ostream &os, const Matrix &mat) {
    return os;
    }

    std::istream &operator>>(std::istream &is, Matrix &mat) {
    return is;
    }
}
