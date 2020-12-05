// #include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;
string compressString(string S) {
    int len = S.length();
    string a = "";
    int count = 1;
    for(int i = 1; i< len; i++){
            if(S[i] == S[i-1]) 
                count += 1;
            else{
                a += S[i-1];a += to_string(count);
                count = 1;
            }      
        }
    a += S[len-1];a += to_string(count);
    int len2 = a.length();
    return (len>len2) ? a : S;
    }
int main()
{
    string s1 = "aabcccccaaa", s2 = "abbccd";
    string aa = compressString(s2);
    cout << aa <<endl;
}
    
