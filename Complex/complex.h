#include <istream>
#include <ostream>
#include <math.h>
#include <iostream>

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы

    Complex() {};

    Complex(double r) // конструктор по умолчанию
    {
        re = r;
        im = 0;
    };

    explicit Complex(double r, double i) // конструктор по умолчанию
    {
        re = r;
        im = i;
    };

    Complex(const Complex &c)   // конструктор копирования
    {
        re = c.re;
        im = c.im;
    };

    // деструктор
    ~Complex() {
    };

    // остальные функции

    // Модуль комплексного числа
    double abs() {
        return std::sqrt(re * re + im * im);
    };

    // оператор присваивания
    Complex &operator=(Complex &c) {
        re = c.re;
        im = c.im;

        return (*this);
    };


    // оператор +=
    Complex &operator+=(Complex &c) {
        re += c.re;
        im += c.im;
        return *this;
    };

    // оператор сложения
    Complex operator+(const Complex &c) {
        return Complex(re + c.re, im + c.im);
    };

    // оператор вычитания
    Complex operator-(const Complex &c) {
        return Complex(re - c.re, im - c.im);
    };

    // оператор умножения
    Complex operator*(const Complex &c) {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    };

    // оператор деления
    Complex operator/(const Complex &c) {
        Complex temp;
        try {
            double r = c.re * c.re + c.im * c.im;
            if (r==0) throw 20;
            temp.re = (re * c.re + im * c.im) / r;
            temp.im = (im * c.re - re * c.im) / r;
        }
        catch (int e){
            std::cout << " An exception division by 0";
        }
        return temp;
    };

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend std::ostream &operator << (std::ostream &out, const Complex &c){
        out << "(" << c.re << ", " << c.im << ")";
        return out;
    };

    friend std::istream &operator>>(std::istream &in, Complex &c){
        in >> c.re >> c.im;
        return in;
    };


// перегрузка оператора <<
// перегрузка оператора >>



    double getReal() const {
        return re;
    };

    double getImag() const {
        return im;
    };

    void setReal(double r) {
        re = r;
    };

    void setImag(double i) {
        im = i;
    };

    //перезагрузки
    bool operator==(Complex &right) const {


        if (getReal() == right.getReal() &&
            getImag() == right.getImag())
            return true;
        else
            return false;
    };

    bool operator!=(Complex &right) const {


        if (getReal() != right.getReal() &&
            getImag() != right.getImag())
            return true;
        else
            return false;
    };

};


