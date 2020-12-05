#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;
string replaceSpaces(string S, int length);
int main()
{
    string s1 = "Mr John Smith    ";
    string s2 = "               ";
    string s3 = "ds sdfs afs sdfa dfssf asdf             ";
    int l1 = 13;
    int l3 = 27;    
    string ss = replaceSpaces(s3,l3);
    cout << ss << endl;
    // string s2 = "bad";
    // printf("%s", CheckPermutation(s1, s2) ? "true" : "false");
    return 0;
}

string replaceSpaces(string S, int length) 
{
    int l2 = S.length();
    // cout << l2 << endl;
    char s2[l2+1];
    // printf("%d", l2);
    int j = 0;
    for(int i = 0; i< length && j<l2;i++)
    {
        
            if(S[i] != ' ')
            {
                s2[j] = S[i];
                j++;
            }
            else
            {
                s2[j] = '%';j++;
                s2[j] = '2';j++;
                s2[j] = '0';j++;

            }
            
        
    }
    // printf("%d %d", j, l2);
    s2[j] = '\0';
    string a(s2);
    return a;
}