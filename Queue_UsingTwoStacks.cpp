#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    public:
        stack<int> s1;
        stack<int> s2;

        void push(int x)
        {
            s1.push(x);
        }

        int pop()
        {
            if(s1.empty() && s2.empty())
            {
                cout<<"Queue is empty."<<endl;
                return -1;
            }
            else if(s2.empty())
            {
                while(!s1.empty())
                {
                    int x= s1.top();
                    s1.pop();
                    s2.push(x);
                }
                int val=s2.top();
                s2.pop();
                return val;
            }
            else
            {
                int val=s2.top();
                s2.pop();
                return val; 
            }
        }

        bool empty()
        {
            if(s1.empty() && s2.empty())
            {
                return true;
            }
            return false;
        }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
}

/*
Output:

1
2
3
4
Queue is empty.
-1
*/