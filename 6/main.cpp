/*将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/

#include <iostream>

using namespace std;

string convert(string s, int numRows) {
    if(numRows<2){
        return s;
    }
    string * strings = new string[numRows];
    int length = s.length();
    int i1,i2 = 0;
    for(int i=0;i<length;i++){
        i1 = i%(2*numRows-2);
        if(i1<=numRows-1){
            strings[i1]=strings[i1]+s[i];
        }else{
            i2 = (numRows-1)*2-i1;
            strings[i2]=strings[i2]+s[i];
        }
    }
    string result;
    for(int i=0;i<numRows;i++){
        result = result+strings[i];
    }
    delete []strings;
    return result;
}
