/**
 * Demo file for the exercise on numbers with units
 *
 * @author Aviem Hadar
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

namespace ariel
{

    // constructor
    ariel::NumberWithUnits::NumberWithUnits(double number, const string& unit)
    {
        this->number = number;
        this->unit = unit;
    }

    // placement operator
    const NumberWithUnits& NumberWithUnits::operator=(const NumberWithUnits &num) const 
    { 
        return num; 
    }

    // function for reading units from a file
    void NumberWithUnits::read_units(ifstream &file) {};

    /*** arithmetic operators ***/
    /****************************/

    // unary addition
    const NumberWithUnits NumberWithUnits::operator+()
    {
        return *this;
    }

    // binary addition
    const NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num)
    {
        return *this;
    }

    // binary addition and save
    const NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& num2) const
    {
        return num2;
    }

    // unary substraction
    const NumberWithUnits NumberWithUnits::operator-() { return NumberWithUnits(0, "km"); }

    // binary substraction
    const NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &num1) const{ return NumberWithUnits(0, "km"); }

    // binary substraction and save
    const NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &num1)
    {
        return num1;
    }

    /*** comparison operators ***/
    /****************************/

    // greater than operator
    const bool NumberWithUnits::operator>(const NumberWithUnits &num1) const
    {
        return true;
    }

    // greater than/equal operator
    bool NumberWithUnits::operator>=(const NumberWithUnits &num1) const
    {
        return true;
    }

    // smaller than operator
    bool NumberWithUnits::operator<(const NumberWithUnits &num1) const
    {
        return true;
    }

    // smaller than/equal operator
    bool ariel::NumberWithUnits::operator<=(const NumberWithUnits &num1) const
    {
        return true;
    }

    // equal operator
    bool ariel::NumberWithUnits::operator==(const NumberWithUnits &num1) const
    {
        return true;
    }

    // not equal operator
    bool NumberWithUnits::operator!=(const NumberWithUnits &num1) const
    {
        return true;
    }

    /*** increasing and dicreasing operators ***/
    /*******************************************/

    // prefix addition
    const NumberWithUnits& NumberWithUnits::operator++()
    {
        return *this;
    }

    // prefix substraction
    const NumberWithUnits& NumberWithUnits::operator--()
    {
        return *this;
    }

    // postfix addition
    const NumberWithUnits& NumberWithUnits::operator++(int)
    {
        return *this;
    }

    // postfix substraction
    const NumberWithUnits& NumberWithUnits::operator--(const int n)
    {
        return *this;
    }

    /***  multiplication operator ***/
    /********************************/

    const NumberWithUnits& operator*(const NumberWithUnits &obj1,const double d)
    {
        return obj1;
    }

    const NumberWithUnits& operator*(const double d, const NumberWithUnits& obj1)
    {
        return obj1;
    }

    /*** input and output operators ***/
    /**********************************/

    // input operator
    istream &operator>>(istream &is,NumberWithUnits &num)
    {
        string s = "right";
        is >> s;
        return is;
    }

    // output operator
    ostream &operator<<(ostream &os, const NumberWithUnits &num)
    {
        string s = "right";
        os << s;
        return os;
    }

    NumberWithUnits::~NumberWithUnits(){};

}