#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int do_operation(int op1, int op2, char c)
{
    int res;
    switch(c)
    {
        case '+':
            res= op1+op2;
            break;
        case '-':
            res= op1-op2;
            break;
        case '*':
            res= op1*op2;
            break;
        case '/':
            res= op1/op2;
            break;
        case '^':
            res= pow(op1,op2);
            break;
    }
    return res;
}

int PostfixToInfixEval(string s)
{
    stack<char> stk;
    int res;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            stk.push(s[i]-'0');
        }
        else
        {
            char c= s[i];
            int oprand2= stk.top(); stk.pop();
            int oprand1= stk.top(); stk.pop();
            res= do_operation(oprand1,oprand2,c);
            stk.push(res);
        }
    }
    return stk.top();
}


int main()
{
    string s="46+2/5*7+";
    int result= PostfixToInfixEval(s);
    cout<<"The evaluated result is "<<result<<endl;
    // Output: The evaluated result is 32
}