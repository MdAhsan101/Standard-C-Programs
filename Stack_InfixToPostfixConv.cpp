#include<iostream>
#include<stack>
using namespace std;

int precedence(char c)
{
    if(c=='+' || c=='-')
    {return 1;}
    else if(c=='*' || c=='/')
    {return 2;}
    else if(c=='^')
    {return 3;}
    else // c=='(' || c==')'
    {
        return -1;
    }
}

string InfixToPostfixConv(string s)
{
    string res="";
    stack<char> stk;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='a' && s[i]<='z')
        { res+=s[i]; }
        else if(s[i]=='(')
        { stk.push(s[i]); }
        else if(s[i]==')')
        { 
            while(!stk.empty() && stk.top()!='(')
            {
                res+=stk.top(); stk.pop();
            }                        
            if(!stk.empty())
            { stk.pop(); } // removing '(' bracket 
        }
        else
        {
            while(!stk.empty() && (precedence(stk.top())>=precedence(s[i])))
            {
                res+=stk.top(); stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty())
    {
        res+=stk.top(); stk.pop();
    }
    return res;
}

int main()
{
    string s="(a-b/c)*(a/k-l)";
    string res_postfix_exp= InfixToPostfixConv(s);
    cout<<"The resultant postfix expresssion: "<< res_postfix_exp <<endl;
}

// Output: The resultant postfix expresssion: abc/-ak/l-*