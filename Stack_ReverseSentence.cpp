#include<iostream>
#include<stack>
#include<string>
using namespace std;

void Reverse_Sentence(string s,stack<string> &st)
{
    for(int i=0; i<s.length(); i++)
    {
        string word="";
        while(s[i]!=' ' && i<s.length())
        {
            char c= s[i];
            word=word+c;
            i++;
        }
        st.push(word);
    }    
    return ;
}

int main()
{
    string s="Hello! How are you?";
    stack<string> st;
    Reverse_Sentence(s,st);
    
    while(!st.empty())
    {
        string t= st.top();
        cout<<t<<" ";
        st.pop();
    }cout<<endl;
    // Output: you? are How Hello!
}