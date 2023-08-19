/**
 *  the simplest way is to keep track of the open brackets in a stack, and whenever
 * a closed bracket is encountered, check that the top contains the open bracket or not.
 * If it does pop it, else return false 
 * 
**/

class Solution {
public:

    bool isPair(char a, char b)
    {
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
        {
            return true;
        }

        return false;
    }
    bool isValid(string s) {
        stack<char> open;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                open.push(s[i]);
            }else
            {
                if(open.empty())
                {
                    return false;
                }
                char top = open.top();
                if(isPair(top, s[i]))
                {
                    open.pop();
                }else
                {
                    return false;
                }
            }
        }
        return (open.size()==0);
    }
    
    
};