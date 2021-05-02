//
//  Arrays.cpp
//  C++Practice
//
//  Created by Alam Figueroa Aguilar on 4/18/21.
//

#include <iostream>
#include <string>
#include <unordered_map>

#include <stdio.h>

#include "Arrays.h"

using namespace std;

int Arrays::lengthOfLongestSubstring(string s){
    unordered_map<char,int> letters;
    int lPos = 0, max = 0, len = 0;
    
    for(int i = 0; i < s.length();i++){
        if(letters.find(s[i]) != letters.end()){
            if(letters[s[i]] >= lPos){//Inside substring then its a repeat
                if(s.length()-s.find(s[i],lPos)-1 > max)
                    lPos = (int)s.find(s[i],lPos) + 1;
                else
                    break;
            }
            letters[s[i]] = i;
        } else//Never seen this letteer
            letters[s[i]] = i;
        len = i-lPos+1;
        max = (len > max) ? len : max;
    }
    return max;
}


    //Runtime: 12 ms -- beats
    //Memory Usage: 5.8 MB
    string Arrays::intToRomanSubtract(int num) {
        int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"} ;
        string roman = "";
        
        for(int i=0;num;i++) {
            while(num>=value[i]) {
                roman += s[i];
                num -= value[i];
            }
        }
        return roman;
    }
    
    //Runtime: 0 ms -- beats 100%
    //Memory Usage: 6 MB -- beats 60%
    string Arrays::intToRomanSimpleMinded(int num) {
        string roman = "";
        int lead;
        
        lead = num/1000;
        num %=1000;
        while(lead){
            roman+="M";
            lead--;
        }
        
        lead = num/100;
        num %=100;
        if (lead == 9){
            roman += "CM";
            lead -=9;
        } else if (lead >= 5){
            roman += "D";
            lead -= 5;
            while(lead){
                roman += "C";
                lead--;
            }
        } else if(lead == 4){
            roman += "CD";
            lead -= 4;
        } else {
            while(lead){
                roman += "C";
                lead--;
            }
        }
            
        lead = num/10;
        num %=10;
        if (lead == 9){
            roman += "XC";
            lead -= 9;
        } else if(lead >= 5){
            roman += "L";
            lead -= 5;
            while(lead){
                roman += "X";
                lead--;
            }
        } else if(lead == 4){
            roman += "XL";
            lead -= 4;
        } else {
            while(lead){
                roman += "X";
                lead--;
            }
        }
        
        lead = num;
        if (lead == 9){
            roman += "IX";
            lead -= 9;
        } else if(lead >= 5){
            roman += "V";
            lead -= 5;
            while(lead){
                roman += "I";
                lead--;
            }
        } else if(lead == 4){
            roman += "IV";
            lead -= 4;
        } else {
            while(lead){
                roman += "I";
                lead--;
            }
        }

        return roman;
    }
    
    
    //Runtime: 4 ms -- beats 84%
    //Memory Usage: 6 MB -- beats 60%
    string Arrays::intToRomanSimpleMinded2(int num) {
        string roman = "";
        int lead;
        
        lead = num/1000;
        num %=1000;
        while(lead){
            roman+="M";
            lead--;
        }
        
        lead = num/100;
        num %=100;
        while(lead){
            if (lead == 9){
                roman += "CM";
                lead -=9;
            } else if (lead >= 5){
                roman += "D";
                lead -= 5;
            } else if(lead == 4){
                roman += "CD";
                lead -= 4;
            } else {
                roman += "C";
                lead--;
            }
        }
            
        lead = num/10;
        num %=10;
        while(lead){
            if (lead == 9){
                roman += "XC";
                lead -= 9;
            } else if(lead >= 5){
                roman += "L";
                lead -= 5;
            } else if(lead == 4){
                roman += "XL";
                lead -= 4;
            } else {
                roman += "X";
                lead--;
            }
        }
        
        lead = num;
        while(lead){
            if (lead == 9){
                roman += "IX";
                lead -= 9;
            } else if(lead >= 5){
                roman += "V";
                lead -= 5;
            } else if(lead == 4){
                roman += "IV";
                lead -= 4;
            } else {
                roman += "I";
                lead--;
            }
        }
        
        return roman;
    }
    
    //Runtime: 20 ms -- beats 12%
    //Memory Usage: 13.1 MB -- beats 0%
string Arrays::intToRomanDynamic2DArrays(int num) {
        string roman = "";
        string numChar = to_string(num);//3897
        int mag = (int)numChar.length()-1;
        
        //string *ones = new string[10];
        string *ones{  new string[10]{"","I","II","III","IV","V","VI","VII","VIII","IX"} };
        string *tens{  new string[10]{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"} };
        string *cents{ new string[10]{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"} };
        string *mils{  new string[4] {"","M","MM","MMM"} };
        string **matrix { new string*[4]{ones,tens,cents,mils} };
        
        for(int i = 0; i < numChar.length(); i++){
            cout << numChar[i] << " = ";
            cout << matrix[mag][numChar[i]-48] << endl;
            roman += matrix[mag--][numChar[i]-48];
        }
        
        return roman;
    }
    
    //Runtime: 24 ms -- beats 8%
    //Memory Usage: 5.8 MB -- beats 95%
    string Arrays::intToRoman2DArrays(int num) {
        string roman = "";
        string numChar = to_string(num);//3897
        int mag = (int)numChar.length()-1;
        
        string matrix[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        
        for(int i = 0; i < numChar.length(); i++){
            cout << numChar[i] << " = ";
            cout << matrix[mag][numChar[i]-48] << endl;
            roman += matrix[mag--][numChar[i]-48];
        }
        
        return roman;
    }

    
    //Runtime: 12 ms -- beats 30%
    //Memory Usage: 5.9 MB -- beats 82%
    string Arrays::intToRomanArrays(int num) {
        string roman = "";
        string numChar = to_string(num);//3897
        int mag = (int)numChar.length()-1;
        
        string ones[10]= {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[10]= {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string cents[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string mils[4] = {"","M","MM","MMM"};
        
        
        for(int i = 0; i < numChar.length(); i++){
            cout << numChar[i] << " = ";
            switch(mag){
                case 0:
                    roman += ones[numChar[i]-48];
                    cout << ones[numChar[i]-48] << endl;
                    break;
                case 1:
                    roman += tens[numChar[i]-48];
                    cout << tens[numChar[i]-48] << endl;
                    break;
                case 2:
                    roman += cents[numChar[i]-48];
                    cout << cents[numChar[i]-48] << endl;
                    break;
                case 3:
                    roman += mils[numChar[i]-48];
                    cout << mils[numChar[i]-48] << endl;
                    break;
            }
            mag--;
        }
        
        return roman;
    }

        
    
    //Runtime: 16 ms -- beats 19%
    //Memory Usage: 6.1 MB -- beats 44%
    string Arrays::intToRomanArraysEnum2(int num) {
        enum romanElements{I=1,IV=4,V=5,IX=9,
                           X=10,XL=40,L=50,XC=90,
                           C=100,CD=400,D=500,CM=900,
                           M=1000};
        int mag = 0;
        string roman = "";
        
        while(num){
            cout << "num: " << num << endl;
            mag = log10(num);
            switch(mag){
                case 0:
                    while(num){
                        if (num >= IX){
                            roman += "IX";
                            num -= IX;
                        } else if(num >= V){
                            roman += "V";
                            num -= V;
                        } else if(num >= IV){
                            roman += "IV";
                            num -= IV;
                        } else {
                            roman += "I";
                            num -= I;
                        }
                    }
                    num /= X;
                    break;
                case 1:
                    while(num >= X){
                        if (num >= XC){
                            roman += "XC";
                            num -= XC;
                        } else if(num >= L){
                            roman += "L";
                            num -= L;
                        } else if(num >= XL){
                            roman += "XL";
                            num -= XL;
                        } else {
                            roman += "X";
                            num -= X;
                        }
                    }
                    num %= X;
                    break;
                case 2:
                    while(num >= C){
                        if (num >= CM){
                            roman += "CM";
                            num -= CM;
                        } else if (num >= D){
                            roman += "D";
                            num -= D;
                        } else if(num >= CD){
                            roman += "CD";
                            num -= CD;
                        } else {
                            roman += "C";
                            num -= C;
                        }
                    }
                    num %= C;
                    break;
                case 3:
                    while(num >= M){
                        roman = roman + "M";
                        num -= M;
                    }
                    num %= M;
                    break;
            }
            cout << "mag: " << mag << endl;
            cout << "roman: " << roman << endl;
        }
        
        return roman;
    }
    
    
    //Runtime: 32 ms -- beats 5%
    //Memory Usage: 6.3 MB -- beats 42%
    string Arrays::intToRomanArraysEnum(int num) {
        enum romanElements{I=1,II=2,III=3,V=5,X=10,L=50,C=100,D=500,M=1000};
        int mag = 0, lead = 0;
        string roman = "";
        
        while(num){
            cout << "num: " << num << endl;
            mag = log10(num);
            switch(mag){
                case 0:
                    lead = num;
                    num /= X;
                    while(lead){
                        if (lead == 9){
                            roman += "IX";
                            lead -= 9;
                        } else if(lead >= 5){
                            roman += "V";
                            lead -= 5;
                        } else if(lead == 4){
                            roman += "IV";
                            lead -= 4;
                        } else {
                            roman += "I";
                            lead--;
                        }
                    }
                    break;
                case 1:
                    lead = num/X;//lead = 9
                    num %= lead*X;
                    while(lead){
                        if (lead == 9){
                            roman += "XC";
                            lead -= 9;
                        } else if(lead >= 5){
                            roman += "L";
                            lead -= 5;
                        } else if(lead == 4){
                            roman += "XL";
                            lead -= 4;
                        } else {
                            roman += "X";
                            lead--;
                        }
                    }
                    break;
                case 2:
                    lead = num/C;//lead = 9
                    num %= lead*C;
                    while(lead){
                        if (lead == 9){
                            roman += "CM";
                            lead -= 9;
                        } else if (lead >= 5){
                            roman += "D";
                            lead -= 5;
                        } else if(lead == 4){
                            roman += "CD";
                            lead -= 4;
                        } else {
                            roman += "C";
                            lead--;
                        }
                    }
                    break;
                case 3:
                    lead = num/M;//lead = 3
                    num %= lead*M;
                    while(lead){
                        roman = roman + "M";
                        lead --;
                    }
                    break;
            }
            cout << "mag: " << mag << endl;
            cout << "lead: " << lead << endl;
            cout << "roman: " << roman << endl;
        }
        
        return roman;
    }
