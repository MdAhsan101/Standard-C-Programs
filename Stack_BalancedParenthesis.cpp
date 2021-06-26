#include<iostream>
#include<stack>
using namespace std;

bool IsBalanced(string s)
{
    stack<char> stk;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='{' ||  s[i]=='[' || s[i]=='(')
        {
            stk.push(s[i]);
        }
        else if(s[i]=='}')
        {
            if(stk.top()=='{')
            {
                stk.pop();
            }   
            else
            {
                return false;
            }         
        }
        else if(s[i]==']')
        {
            if(stk.top()=='[')
            {
                stk.pop();
            }   
            else
            {
                return false;
            }         
        }
        else if(s[i]==')')
        {
            if(stk.top()=='(')
            {
                stk.pop();
            }   
            else
            {
                return false;
            }         
        }
    }
    return true;
}


int main()
{
    string s1="{[()]}";
    cout<<"Is the parenthesis is balanced: "<<IsBalanced(s1)<<endl;

    string s2="{[(])}";
    cout<<"Is the parenthesis is balanced: "<<IsBalanced(s2)<<endl;
}

/*
Output:

Is the parenthesis is balanced: 1
Is the parenthesis is balanced: 0
*/