//
//  arraySolutions.cpp
//  C++Practice
//
//  Created by Alam Figueroa Aguilar on 4/18/21.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

#include "ArraySolutions.h"

using namespace std;

int ArraySolutions::lengthOfLongestSubstring(string s){
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
