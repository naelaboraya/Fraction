#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel {
    
}
		
class Fraction {
	
	private :
	//members:
	int _numerator;
	int _denominator;
	
	
	public :
	//constructors:
	Fraction (int numerator , int denominator);
	Fraction (const Fraction& other);
	

	//getters:
	int getNumerator(){
		return this->_numerator;
	}

	int getDenominator(){
		return this->_denominator;
	}

	//functions:
	friend Fraction operator+ (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator+ (const Fraction& frac , const int& num);
	friend Fraction operator+ (const  int& num , Fraction& frac);
	friend Fraction operator+ (const Fraction& frac , const float& num);
	friend Fraction operator+ (const  float& num , Fraction& frac);
	friend Fraction operator- (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator- (const Fraction& frac , const int& num);
	friend Fraction operator- (const  int& num , Fraction& frac);
	friend Fraction operator- (const Fraction& frac , const float& num);
	friend Fraction operator- (const  float& num , Fraction& frac);
	friend Fraction operator* (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator* (const Fraction& frac , const int& num);
	friend Fraction operator* (const  int& num , Fraction& frac);
	friend Fraction operator* (const Fraction& frac , const float& num);
	friend Fraction operator* (const  float& num , Fraction& frac);
	friend Fraction operator/ (const Fraction& frac1 , const Fraction& frac2);
	friend Fraction operator/(const Fraction& frac, int num);
	friend Fraction operator/(int num , const Fraction& frac);
	friend Fraction operator/(const Fraction& frac, float num);
	friend Fraction operator/(float num , const Fraction& frac);  
	friend bool operator== (const Fraction& frac1 , const Fraction& frac2);
	friend bool operator== (const Fraction& frac, int num);
	friend bool operator== (int num, const Fraction& frac);
	friend bool operator== (const Fraction& frac, double num);
	friend bool operator== (double num, const Fraction& frac);
	friend bool operator!= (const Fraction& frac1 , const Fraction& frac2);
	friend bool operator!= (const Fraction& frac, int num);
	friend bool operator!= (int num, const Fraction& frac);
	friend bool operator!= (const Fraction& frac, double num);
	friend bool operator!= (double num, const Fraction& frac);
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);
	friend bool operator>(const Fraction& frac, int num);
	friend bool operator>(int num, const Fraction& frac);
	friend bool operator>(const Fraction& frac, double num);
	friend bool operator>(double num, const Fraction& frac);
   	friend bool operator<(const Fraction& frac1, const Fraction& frac2);
	friend bool operator<(const Fraction& frac, int num);
	friend bool operator<(int num, const Fraction& frac);
	friend bool operator<(const Fraction& frac, double num);
	friend bool operator<(double num, const Fraction& frac);
   	friend bool operator>=(const Fraction& frac1, const Fraction& frac2);
	friend bool operator>=(const Fraction& frac, int num);
	friend bool operator>=(int num, const Fraction& frac);
	friend bool operator>=(const Fraction& frac, double num);
	friend bool operator>=(double num, const Fraction& frac);
   	friend bool operator<=(const Fraction& frac1, const Fraction& frac2);
	friend bool operator<=(const Fraction& frac, int num);
	friend bool operator<=(int num, const Fraction& frac);
	friend bool operator<=(const Fraction& frac, double num);
	friend bool operator<=(double num, const Fraction& frac);
   	friend Fraction& operator++(Fraction& frac);
   	friend Fraction operator++(Fraction& frac , int dummy_flag_for_postfix_increment);
   	friend Fraction& operator--(Fraction& frac);
   	friend Fraction operator--(Fraction& frac , int dummy_flag_for_postfix_increment);
   	friend std::ostream& operator<< (std::ostream& output, const Fraction& frac);
    friend std::istream& operator>> (std::istream& input , Fraction& frac);

	std::string toString();
   	
};


int LCM(int num1 , int num2);
Fraction reduce(int numerator , int denominator);
Fraction floatToFraction(float num);


#endif
