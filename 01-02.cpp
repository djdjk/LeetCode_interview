#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <map>//map和unordered_map区别：map和set会自动在建立的时候排序，unordered_map不排序，可能会节省时间，也
//可能会满足某些特殊需求
using namespace std;
int a1[26], a2[26];

bool CheckPermutation(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    for(int i = 0; i < len1; i++)
        a1[s1[i] - 'a']++;
    for(int i = 0; i < len2; i++)
        a2[s2[i] - 'a']++;
    int j = 0;
    while(j < 26 && a1[j] == a2[j])
        j++;
    return (j == 26) ? true : false;
}

bool CheckPermutation2(string s1, string s2) {
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1==s2;
}

bool CheckPermutation3(string s1, string s2) {
    unordered_map<char, int> mp;//map 相当于Python里面的字典
    for(auto c1 : s1)//遍历s1里面的元素 如果不知道s1里的元素是啥类型 可以用 auto 
        mp[c1]++;
    for(char c2 : s2)
        mp[c2]--;
    for(int i = 0; i < 26; i++)
        if(mp['a' + i])
            return false;
    return true;
}

int main(){
    string s1 = "abc";
    string s2 = "bad";
    printf("%s", CheckPermutation(s1, s2) ? "true" : "false");
    return 0;
}