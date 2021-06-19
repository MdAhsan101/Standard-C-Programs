#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &st, int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int temp= st.top();
    st.pop();
    InsertAtBottom(st,ele);
    st.push(temp);
}

void Reverse_Stack(stack<int> &st)
{
    if(st.size()==1)
        return;
    int ele= st.top();
    st.pop();
    Reverse_Stack(st);
    InsertAtBottom(st,ele);    
}

void Print_Stack(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<"<-";
        st.pop();        
    }
    cout<<endl;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    cout<<"My original stack: ";
    Print_Stack(stk);

    Reverse_Stack(stk);
    cout<<"My stack after reverse: ";
    Print_Stack(stk);
}