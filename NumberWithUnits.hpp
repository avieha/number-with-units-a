//#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

namespace ariel
{
    class NumberWithUnits
    {

    private:
    double number;
    string unit;

    public:
        // constructor and distructor
        NumberWithUnits(double number, const string& unit);
        ~NumberWithUnits();

        // placement operator
        const NumberWithUnits& operator=(const NumberWithUnits &num) const;

        // function for reading the units from a given file
        static void read_units(ifstream &file);

        /*** arithmetic operators ***/
        /****************************/

        // unary addition
        const NumberWithUnits operator+();

        // binary addition
        const NumberWithUnits operator+(const NumberWithUnits &num1);

        // binary addition and save
        const NumberWithUnits& operator+=(const NumberWithUnits& num2) const;

        // unary substraction
        const NumberWithUnits operator-();

        // binary substraction
        const NumberWithUnits operator-(const NumberWithUnits &num1) const;

        // binary substraction and save
        const NumberWithUnits& operator-=(const NumberWithUnits &num1);

        /*** comparison operators ***/
        /****************************/

        // greater than operator
        const bool operator>(const NumberWithUnits &num1) const;
        
        // greater than/equal operator
        bool operator>=(const NumberWithUnits &num1) const;
        
        // smaller than operator
        bool operator<(const NumberWithUnits &num1) const;
        
        // smaller than/equal operator
        bool operator<=(const NumberWithUnits &num1) const;
        
        // equal operator
        bool operator==(const NumberWithUnits &num1) const;
        
        // not equal operator
        bool operator!=(const NumberWithUnits &num1) const;
        

        /*** increasing and dicreasing operators ***/
        /*******************************************/

        // prefix addition
        const NumberWithUnits& operator++();
        
        // prefix substraction
        const NumberWithUnits& operator--();
        
        // postfix addition
        const NumberWithUnits& operator++(int);

        // postfix substraction
        const NumberWithUnits& operator--(const int n);

        /***  multiplication operator ***/
        /********************************/

        friend const NumberWithUnits& operator*(const NumberWithUnits& obj1, const double d);

        friend const NumberWithUnits& operator*(const double d, const NumberWithUnits& obj1);

        /*** input and output operators ***/
        /**********************************/

        // input operator
        friend istream &operator>>(istream& is,NumberWithUnits &num);

        // output operator
        friend ostream &operator<<(ostream& os, const NumberWithUnits &num);
    };

}