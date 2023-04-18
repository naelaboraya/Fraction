#include "Fraction.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//constructors:
Fraction::Fraction (int numerator , int denominator){
    this->_numerator = numerator;
    this->_denominator = denominator;
}

Fraction::Fraction (const Fraction& other){
    this->_numerator = other._numerator;
    this->_denominator = other._denominator;
}


//functions:

/*A function that calculates the lowest common multiple*/
int LCM (int num1 , int num2){
    int max = (num1 > num2) ? num1 : num2;
     do
    {
        if (max % num1 == 0 && max % num2 == 0)
        {
            break;
        }
        else
            ++max;
    } while (true);
    return max;
} 

 /*A function that simplifies the fraction*/
Fraction reduce(int numerator , int denominator){
    int gcd = std::__gcd(numerator,denominator);
    int reduced_numerator = numerator/gcd;
    int reduced_denominator = denominator/gcd;
    return Fraction(reduced_numerator,reduced_denominator);
}

/*A function that converts a float into a fraction*/
Fraction floatToFraction(float num){
    int sign = (num < 0) ? -1 : 1;
    num *= sign;
    int wholePart = floor(num);
    num -= wholePart;
    int maxDenominator = 1000000;
    int numerator = round(num * maxDenominator);
    int denominator = maxDenominator;
    numerator += wholePart * denominator;
    numerator *= sign;
    return reduce(numerator, denominator);
}

//--------------------adding----------------------------

Fraction operator+ (const Fraction& frac1 , const Fraction& frac2){
    //1.make a common denominator (LCM)
    //2.add the numerators
    //3.simplify the fraction
    int common_denominator = LCM(frac1._denominator , frac2._denominator);
    int sum_numerator = ((common_denominator/frac1._denominator)*frac1._numerator) + ((common_denominator/frac2._denominator)*frac2._numerator);
    return reduce(sum_numerator , common_denominator);
}

Fraction operator+ (const Fraction& frac , const int& num){
    Fraction frac2(num,1);
    return frac+frac2;//calling frac+frac function
}

Fraction operator+ (const  int& num , Fraction& frac){
    Fraction frac1(num,1);
    return frac1 + frac;//calling frac+frac function
}

Fraction operator+ (const Fraction& frac , const float& num){
    Fraction frac2 = floatToFraction(num);
    return frac + frac2;//calling frac+frac function
}

Fraction operator+ (const  float& num , Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 + frac;
}

 //--------------------substraction----------------------------

Fraction operator- (const Fraction& frac1 , const Fraction& frac2){
    //1.make a common denominator (LCM)
    //2.add the numerators
    //3.simplify the fraction
    int common_denominator = LCM(frac1._denominator , frac2._denominator);
    int sum_numerator = ((common_denominator/frac1._denominator)*frac1._numerator) - ((common_denominator/frac2._denominator)*frac2._numerator);
    return reduce(sum_numerator , common_denominator);
}

Fraction operator- (const Fraction& frac , const int& num){
    Fraction frac2(num,1);
    return frac-frac2;//calling frac+frac function
}

Fraction operator- (const  int& num , Fraction& frac){
    Fraction frac1(num,1);
    return frac1 - frac;//calling frac+frac function
}

Fraction operator- (const Fraction& frac , const float& num){
    Fraction frac2 = floatToFraction(num);
    return frac - frac2;//calling frac+frac function
}

Fraction operator- (const  float& num , Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 - frac;
}


//--------------------multiplication----------------------------

Fraction operator* (const Fraction& frac1 , const Fraction& frac2){
    //1.multiply the numerators and make them one numerator 
    //2.multiply the denominators and make them one common denominator
    int new_numerator = frac1._numerator * frac2._numerator;
    int new_denominator = frac1._denominator * frac2._denominator;
    return reduce(new_numerator,new_denominator);
}

Fraction operator* (const Fraction& frac , const int& num){
    Fraction frac2(num,1);
    return frac*frac2;
}

Fraction operator* (const  int& num , Fraction& frac){
    Fraction frac1(num,1);
    return frac1 * frac;
}

Fraction operator* (const Fraction& frac , const float& num){
    Fraction frac2 = floatToFraction(num);
    return frac * frac2;
}

Fraction operator* (const  float& num , Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 * frac;
}

//--------------------division----------------------------

Fraction operator/ (const Fraction& frac1 , const Fraction& frac2){
    //1.multiply the numerator of the first fraction with the denominator of the second , and make the result numerator
    //2.multiply the denomirator of the first fraction with the numerator of the second . and make the result the denominator
    int new_numerator = frac1._numerator * frac2._denominator;
    int new_denominator = frac1._denominator * frac2._numerator;
    return reduce(new_numerator,new_denominator);
}

Fraction operator/(const Fraction& frac, int num){
    Fraction frac2(num,1);
    return frac / frac2;
}

Fraction operator/ (int num , const Fraction& frac){
    Fraction frac1(num,1);
    return frac1 / frac;
}


Fraction operator/ (const Fraction& frac , float num){
    Fraction frac2 = floatToFraction(num);
    return frac / frac2;
}

Fraction operator/ (float num , const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 / frac;
}





std::string Fraction::toString(){
    std::string info = "";
    if(this->_numerator == this->_denominator){
        return "1";
    }
    if(this->_denominator == 1){
        return std::to_string(this->_numerator);
    }
    info+= std::to_string(this->_numerator);
    info+="/";
    info+= std::to_string(this->_denominator);
    return  info;
}