#include<iostream>
#include<stack>
#include<algorithm>
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

string InfixToPrefixConv(string s)
{
    string res="";
    reverse(s.begin(),s.end());
    for(int i=0; i<s.length();i++)
    {
        if(s[i]=='(')
            s[i]=')';
        else if(s[i]==')')
            s[i]='(';
    }
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
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    string s="(a-b/c)*(a/k-l)";
    string res_prefix_exp= InfixToPrefixConv(s);
    cout<<"The resultant postfix expresssion: "<< res_prefix_exp <<endl;
    // Output: The resultant postfix expresssion: *-a/bc-/akl
}