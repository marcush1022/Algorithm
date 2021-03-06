/********************************************************************************************/
Given n pairs of parentheses, write a function to generate all combinations of well-formed 
parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

"在当前局面下，你有若干种选择。那么尝试每一种选择。如果已经发现某种选择肯定不行（因为违反了某些限定条
件），就返回；如果某种选择试到最后发现是正确解，就将其加入解集"

至于要输出所有括号的正确组合形式，可以采用递归。用两个变量l和r记录剩余左括号和右括号的数量，当且仅当左
右括号数量都为0时，正常结束。当然还有一点限制，就是剩余的右括号数量比左括号多时才能添加右括号。
/********************************************************************************************/

class Solution {
public:
    void generate(vector<string> &ret, string path, int leftNum, int rightNum)
    {
        if(leftNum==0 && rightNum==0)  //当且仅当左右括号数量都为0时，正常结束
            ret.push_back(path);
        
        if(leftNum>0)
            generate(ret, path+'(', leftNum-1, rightNum);
        if(rightNum>0 && leftNum<rightNum)  //剩余的右括号数量比左括号多时才能添加右括号
            generate(ret, path+')', leftNum, rightNum-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(ret, "", n, n);
        return ret;
    }
};


Update:
class Solution {
public:
    void dfs(string tmp, vector<string> &ret, int nLeft, int nRight)
    {
        if(nLeft==0 && nRight==0)
            ret.push_back(tmp);
        if(nLeft>0)
        {
		tmp+='(';
		dfs(tmp, ret, nLeft-1, nRight);
            	tmp.pop_back();
	}
	if(nRight>nLeft && nRight>0)
	{
		tmp+=')';
		dfs(tmp, ret, nLeft, nRight-1);
            	tmp.pop_back();
	}
    }
    vector<string> generateParenthesis(int n) {
        	vector<string> ret;
		string tmp="";
		dfs(tmp, ret, n, n);
		return ret;
    }
};
