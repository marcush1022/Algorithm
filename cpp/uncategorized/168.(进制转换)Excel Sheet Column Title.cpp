/*
Given a positive integer, return its corresponding column title as appear in an
Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 
 即10进制转为26进制。
 
 同理10进制转2进制:
 while(n) {ret+=(n%2+'0'); n=n/2;}
 reverse
 
 注意：由于下标从1开始而不是从0开始，因此要减一
*/

class Solution {
public:
    string convertToTitle(int n) {
        string ret="";
        while(n)
        {
            ret+=char('A'+(n-1)%26);
            n=(n-1)/26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
