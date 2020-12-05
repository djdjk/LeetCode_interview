#include<iostream>
#include<string>
// #include<algorithm>
using namespace std;

bool isFlipedString(string s1, string s2) 
{
    int l1 = s1.length(),l2 = s2.length();
    if(l1 != l2) return false;
    if(s1 == s2) return true;
    int flag = 0;
    for(int i = 0; i <l1;i++)
    {     
        if(s1[i] == s2[0])
        {
            if(s1.substr(i) == s2.substr(0,(l1-i)))
                flag++;
            if(s1.substr(0,i) == s2.substr((l1-i) , i))
                flag++;
        }
        if(flag == 2) return true;
        else flag = 0;
        
    }
    return false;

}

bool isFlipedString2(string s1, string s2) //题解
{
    if(s1.length() != s2.length()) return false;
    if(s1.length() == 0) return true;
    string ss = s2 + s2;
    return(ss.find(s1) != string::npos ? true:false);
}

int main()
{
    string s1 = "waterbottle", s2 = "erbottlewat",s3 = "aba",s4 = "aa";
    bool a = isFlipedString(s1,s2);
    cout << a << endl;
}
