//
//  Recursion.cpp
//  C++Practice
//
//  Created by Alam Figueroa Aguilar on 5/1/21.
//
#include <set>
#include <string>
#include <vector>

using namespace std;

#include "Recursion.hpp"

vector<string> Recursion::generateParenthesis(int n){
    set<string> par;

    if(n==0){
        return vector<string>();
    } else if (n == 1){
        string newPar = "()";
        par.insert(newPar);
    } else {
        int i,j;
        vector<string> inner = generateParenthesis(n-1);
        for(i = 0; i < inner.size(); i++){
            par.insert("("+inner[i]+")");
        }
        for(i = 0; i < inner.size(); i++){
            par.insert(inner[i]+"()");
            for(j=0; j < inner[i].length();j++){
                par.insert(inner[i].substr(0,j) + "()" + inner[i].substr(j,inner[i].length()-j));
            }
        }

    }
    
    return vector<string>(par.begin(),par.end());
}
