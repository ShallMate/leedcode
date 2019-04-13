/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
*/

#include <iostream>
#include <vector>
#include <exception>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int length = strs.size();
        if(length==0){
            return result;
        }else if(length==1){
            return strs[0];
        }
        int num = 0;
        char s,s1;
        while(true){
            try{
                s = strs[0][num];
                if(s=='\0'){
                    return result;
                }
            }catch(exception & e){
                return result;
            }
            for(int i=1;i<length;i++){
                if(strs[i]==""){
                    return result;
                }
                try{
                    s1 = strs[i][num];
                    if(s=='\0')
                        return result;
                }catch(exception & e){
                    return result;
                }
                if(s1!=s){
                    return result;
                }
            }
            result = result+s;
            num++;
        }
        return result;
    }
};
