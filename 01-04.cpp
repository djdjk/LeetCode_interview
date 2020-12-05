#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <bitset>

using namespace std;
bool canPermutePalindrome(string s);
bool canPermutePalindrome1(string s);
bool canPermutePalindrome2(string s);

int main()
{
    string s = "tactcoa", s1 = "a///";
    bitset<20> test;
    for(char c : s)
       {
            test.flip(c);
            cout << test << endl;
       } 
    // bool a = canPermutePalindrome2(s);
    // cout<<a<<endl;

    return 0;
}
bool canPermutePalindrome1(string s)//错误的解法，只考虑了小写字母，但是测试样例包含其他字符
{
    int a[26],len = s.length();
    memset(a,0,sizeof(a));
    for(int i = 0; i < len;i++)
    {
        a[s[i]-'a']++;
    }
    int j = 0,count = 0;
    for(int i = 0; i < 26;i++)
    {
        if(a[i]%2 == 1) {
            count++;
            a[i] = 0;
        }
        if(count>1) return false;

    }
    return true;
}
bool canPermutePalindrome(string s)
{
    unordered_map<char, int> mp;
    for(auto c : s)
        mp[c]++;
    int count = 0;
    for(auto c : s)
    {
        if(mp[c]%2 == 1)
        {
            count++;
            mp[c] = 0;
        }
        if(count>1) return false;
    }
    return true;
}
bool canPermutePalindrome2(string s) //题解，c为s中字符的ASCII码码值，以此为bits中的下标，所以bits要开的足够长
{
    bitset<128> bits;
    for (char c : s) 
        {
            bits.flip(c);
        }
    return bits.none() || bits.count() == 1;
}
