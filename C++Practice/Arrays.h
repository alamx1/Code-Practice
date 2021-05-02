//
//  Arrays.h
//  Code Practice
//
//  Created by Alam Figueroa Aguilar on 4/18/21.
//

#ifndef Arrays_h
#define Arrays_h

#include <string>

using namespace std;

class Arrays {
public:
    //Given a string s, find the length of the longest substring without repeating characters.
    int lengthOfLongestSubstring(string s);
    
    //Given an integer, convert it to a roman numeral.
    string intToRomanSubtract(int num);//lest memory usage
    string intToRomanSimpleMinded(int num);//fastest
    string intToRomanSimpleMinded2(int num);//second fastest
    string intToRomanDynamic2DArrays(int num);//Dynamic Memory Allocation 2D Arrays
    string intToRoman2DArrays(int num);//2D Arrays
    string intToRomanArrays(int num);//Arrays
    string intToRomanArraysEnum(int num);//Using enumeration
    string intToRomanArraysEnum2(int num);//Faster using enumeration
private:
    
};

#endif /* Arrays_h */
