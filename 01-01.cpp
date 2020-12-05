#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
bool isUnique(string astr) ;
bool isUnique1(string astr) ;
bool isUnique2(string astr) ;
// #include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "acd";
    
    // bool jg = isUnique("");
    cout << isUnique1(s) << endl;
    // cout << jg << endl;
    // cout << s[0] <<endl;
    // cout << s.size() <<endl;
    // cout << s.length() <<endl;

}

bool isUnique(string astr) 
{
    int len = astr.length();
    if(len == 0) return true;
    int copy[len];
    for(int i = 0; i < len; i++)
        {
            copy[i] = astr[i];
        }
    for(int i = 0; i < len; i++)
    {
        for(int j = (i+1) ; j< len;j++)
        {
            if(copy[i] == astr[j]) 
            {
                return false;
            }          
        }
    }
    return true;
}
bool isUnique1(string astr) 
{
    int a[26];
    memset(a, 0, sizeof(a));

    int len = astr.length();
    for(int i =0;i<len;i++)
    {
        a[astr[i] - 'a']++;
        if(a[astr[i] - 'a'] > 1)
            return false;
    }
    return true;
}
bool isUnique2(string astr) {
    // 位运算，不使用其他数据结构
    int b = 0;
    int len = astr.size();
    for(int i = 0; i < len; i++){
        if(b & (1 << (astr[i] - 'a')))
            return false;
        b |= 1 << (astr[i] - 'a');
    }
    return true;
}


