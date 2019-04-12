/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
*/

#include <iostream>
#include <sstream>
using namespace std;

int reverse(int x){
    if(x==0)
        return 0;
    int x1 = x;
    if(x<0){
        if(x>=-2147483647)
            x = -x;
        else
            return 0;
    }
    string strx;
    char xs;
    while(x){
        xs = x%10+'0';
        x = x/10;
        strx = strx+xs;
    }
    long long n;
    istringstream is(strx);
    is >> n;
    if(n>2147483647)
        return 0;
    if(x1>0)
        return n;
    else
        return -n;
}