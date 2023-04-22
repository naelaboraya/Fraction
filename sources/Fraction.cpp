#include "Fraction.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//constructors:
Fraction::Fraction() : _numerator(0), _denominator(1) {
    //default constructor , init values are : 0/1
}


Fraction::Fraction (int numerator , int denominator){
    if(denominator == 0){//checking if denominator = 0 , dont initialize the fraction and throw an error
        throw std::invalid_argument("denominator can't be 0");
    }
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



Fraction operator/ (const Fraction& frac , float num){
    Fraction frac2 = floatToFraction(num);
    return frac / frac2;
}

Fraction operator/ (float num , const Fraction& frac){
    Fraction frac1 = floatToFraction(num);
    return frac1 / frac;
}

//--------------------equals----------------------------

bool operator== (const Fraction& frac1 , const Fraction& frac2){
    Fraction left = reduce(frac1._numerator,frac1._denominator);
    Fraction right = reduce(frac2._numerator,frac2._denominator);
    return left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator();
}


bool operator== (const Fraction& frac, float num){
    Fraction left = reduce(frac._numerator,frac._denominator);
    Fraction right = floatToFraction(num);
    return left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator();
}

bool operator== (float num, const Fraction& frac){
    Fraction left = floatToFraction(num);
    Fraction right = reduce(frac._numerator,frac._denominator);
    return left.getNumerator()==right.getNumerator() && left.getDenominator()==right.getDenominator();
}

//--------------------not equals----------------------------

bool operator!= (const Fraction& frac1 , const Fraction& frac2){
    return (!(frac1 == frac2));
}


bool operator!= (const Fraction& frac, float num){
    return (!(frac == num));
}

bool operator!= (float num, const Fraction& frac){
     return (!(num == frac));
}

//--------------------greater than----------------------------

bool operator>(const Fraction& frac1, const Fraction& frac2){
    //determining by cross multiplication
    int left = frac1._numerator*frac2._denominator;
    int right = frac2._numerator*frac1._denominator;
    return left>right? true:false;
}


bool operator>(const Fraction& frac, float num){
    int left = frac._numerator * 1;
    float right = num * frac._denominator;
    return left>right? true:false;
}

bool operator>(float num, const Fraction& frac){
    float left = num * frac._denominator;
    int right = frac._numerator * 1;
    return left>right? true:false;
}


//--------------------less than----------------------------

bool operator<(const Fraction& frac1, const Fraction& frac2){
    //determining by cross multiplication
    int left = frac1._numerator*frac2._denominator;
    int right = frac2._numerator*frac1._denominator;
    return left<right? true:false;
}


bool operator<(const Fraction& frac, float num){
    int left = frac._numerator * 1;
    float right = num * frac._denominator;
    return left<right? true:false;
}

bool operator<(float num, const Fraction& frac){
    float left = num * frac._denominator;
    int right = frac._numerator * 1;
    return left<right? true:false;
}

//--------------------greater than / equals----------------------------

bool operator>=(const Fraction& frac1, const Fraction& frac2){
    return ((frac1>frac2)||(frac1==frac2))? true:false;
}


bool operator>=(const Fraction& frac, float num){
    return ((frac>num)||(frac==num))? true:false;
}

bool operator>=(float num, const Fraction& frac){
    return ((num>frac)||(num==frac))? true:false;
}

//--------------------less than / equals----------------------------

bool operator<=(const Fraction& frac1, const Fraction& frac2){
    return ((frac1<frac2)||(frac1==frac2))? true:false;
}

bool operator<=(const Fraction& frac, float num){
    return ((frac<num)||(frac==num))? true:false;
}

bool operator<=(float num, const Fraction& frac){
    return ((num<frac)||(num==frac))? true:false;
}

//--------------------increment----------------------------

Fraction& operator++(Fraction& frac){
    //changes (increments) the fraction itself (reference) and then returns it
    frac = frac + 1;
    return frac;
}

Fraction operator++(Fraction& frac , int dummy_flag_for_postfix_increment){
    //creates a copy of the original fraction, increments it, and returns the copy
    Fraction result(frac);
    frac = frac +1;
    return result;
}

//--------------------decrement----------------------------

Fraction& operator--(Fraction& frac){
    //changes (decrements) the fraction itself (reference) and then returns it
    frac = frac - 1;
    return frac;
}

Fraction operator--(Fraction& frac , int dummy_flag_for_postfix_increment){
    //creates a copy of the original fraction, decrements it, and returns the copy
    Fraction result(frac);
    frac = frac - 1;
    return result;
}

//--------------------IO----------------------------

std::ostream& operator<< (std::ostream& output, const Fraction& frac){//doesnt modify the object
    output << frac._numerator << "/" << frac._denominator;
    return output;
}

std::istream& operator>> (std::istream& input , Fraction& frac){//modifies the object !
    int numerator, denominator;
    input >> numerator >> denominator;
    frac.setNumerator(numerator);
    frac.setDenominator(denominator);
    return input;
}


//------------------------toString----------------------------------

/*A toString function that describes the fracton*/
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