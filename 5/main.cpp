/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

#include <iostream>
#include<string>
using namespace std;

bool ishuiWen(string temp){
    int length = temp.length();
    for(int i = 0,k=length-1;i<k;i++,k--){
        if(temp[i]!=temp[k])
            return false;
    }
    return true;
}
string longestPalindrome(string s){
    int length = s.length();
    string sn(s.rbegin(),s.rend());
    string temp;
    for(int i=length;i>0;i--){
        for(int k=0;k+i<=length;k++){
            temp = s.substr(k,i);
            if(sn.find(temp)!=string::npos&&ishuiWen(temp)){
                return temp;
            }
        }
    }
    return "";
}

