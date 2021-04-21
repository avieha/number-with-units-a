#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
using namespace ariel;

// distance units

ariel::NumberWithUnits meter{3, "m"};
ariel::NumberWithUnits cm{10, "cm"};

// time units

ariel::NumberWithUnits hour{4, "hour"};
ariel::NumberWithUnits mi{30, "min"};

// currency units

ariel::NumberWithUnits usd{1, "USD"};
ariel::NumberWithUnits ils{1, "ILS"};

TEST_CASE("First - check the operator =="){
    ariel::NumberWithUnits meter1 = {5,"m"};
    CHECK_FALSE(meter==meter1);
    meter1 = {3,"m"};
    CHECK(meter==meter1);
}

TEST_CASE("Good unary addition & subtraction")
{
    meter = {7, "m"};
    hour = {7, "hour"};

    CHECK((-meter) == NumberWithUnits{-7.00, "m"});
    CHECK((+meter) == NumberWithUnits{7.00, "m"});
    CHECK((-hour) == NumberWithUnits{-7.00, "hour"});
    CHECK((+hour) == NumberWithUnits{7.00, "hour"});
}

TEST_CASE("Good binary addition & subtraction")
{
    CHECK((meter + cm) == NumberWithUnits{3.1, "m"});
    CHECK((hour + mi) == NumberWithUnits{4.5, "hour"});
    CHECK((ils + usd) == NumberWithUnits{4.33, "ILS"});
    CHECK((meter - cm) == NumberWithUnits{2.9, "m"});
    CHECK((hour - mi) == NumberWithUnits{3.5, "hour"});
    CHECK((usd - usd) == NumberWithUnits{0, "ILS"});

    CHECK((meter += cm) == NumberWithUnits{3.1, "m"});
    CHECK((hour += mi) == NumberWithUnits{4.5, "hour"});
    CHECK((ils += ils) == NumberWithUnits{2, "ILS"});
    CHECK((meter -= cm) == NumberWithUnits{2.9, "m"});
    CHECK((hour -= mi) == NumberWithUnits{3.5, "hour"});
    CHECK((ils -= ils) == NumberWithUnits{0, "ILS"});
}


TEST_CASE("Good prefix addition and subtraction")
{
    CHECK((--meter) == NumberWithUnits{2.00, "m"});
    CHECK((--hour) == NumberWithUnits{3.00, "hour"});

    CHECK((++meter) == NumberWithUnits{4.00, "m"});
    CHECK((++hour) == NumberWithUnits{5.00, "hour"});
}

TEST_CASE("Good postfix addition & subtraction")
{
    CHECK((meter--) == NumberWithUnits{3.00, "m"});
    CHECK((meter++) == NumberWithUnits{2.00, "m"});
    
    CHECK((hour--) == NumberWithUnits{4.00, "ton"});
    CHECK((hour++) == NumberWithUnits{3.00, "ton"});
}

TEST_CASE("add & sub diff kinds of units")
{
    CHECK_THROWS((meter + hour));
    CHECK_THROWS((meter - hour));
    
    CHECK_THROWS((hour + ils));
    CHECK_THROWS((hour - ils));

    CHECK_THROWS((meter += usd));
    CHECK_THROWS((meter -= usd));
    
    CHECK_THROWS((hour += cm));
    CHECK_THROWS((hour -= cm));
}

TEST_CASE("Multiplication operator check")
{
    CHECK((meter * 2) == NumberWithUnits{4, "km"});
    CHECK((hour * 2) == NumberWithUnits{4, "ton"});
    CHECK((ils * 2) == NumberWithUnits{2, "ILS"});
    CHECK((2 * meter) == NumberWithUnits{4, "km"});
    CHECK((2 * hour) == NumberWithUnits{4, "ton"});
    CHECK((2 * ils) == NumberWithUnits{2, "ILS"});
}


TEST_CASE("Good comparison operators")
{
    meter = {10, "m"};
    hour = {10, "hour"};
    usd = {10, "USD"};

    CHECK((meter) > NumberWithUnits{1, "m"});
    CHECK((hour) > NumberWithUnits{1, "hour"});
    CHECK((usd) > NumberWithUnits{1, "USD"});
    
    CHECK((meter) < NumberWithUnits{20, "m"});
    CHECK((hour) < NumberWithUnits{20, "hour"});
    CHECK((usd) < NumberWithUnits{20, "USD"});
    
    CHECK((meter) != NumberWithUnits{10.1, "m"});
    CHECK((hour) != NumberWithUnits{10.1, "hour"});
    CHECK((usd) != NumberWithUnits{10.1, "USD"});

    CHECK((meter) >= NumberWithUnits{9, "m"});
    CHECK((hour) >= NumberWithUnits{10, "hour"});
    CHECK((usd) >= NumberWithUnits{8, "USD"});
    
    CHECK((meter) <= NumberWithUnits{11, "m"});
    CHECK((hour) <= NumberWithUnits{10, "hour"});
    CHECK((usd) <= NumberWithUnits{12, "USD"});
}


TEST_CASE("wrong comparison operators")
{

    bool b;
    cm = {3, "cm"};
    mi = {3, "min"};
    usd = {3, "USD"};

    CHECK_THROWS(b = (cm < hour));
    
    CHECK_THROWS(b = (meter >= ils));

    CHECK_THROWS(b = (meter == ils));
    
    CHECK_THROWS(b = (meter <= ils));
}