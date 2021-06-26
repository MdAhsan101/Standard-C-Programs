#include<iostream>
#include<stack>
using namespace std;

class Queue
{
    public:
        stack<int> s;

        void push(int x)
        {
            s.push(x);
        }

        int pop()
        {
            if(s.empty())
            {
                cout<<"Queue is empty."<<endl;
                return -1;
            }
            
            if(s.size()==1)
                { 
                    int val=s.top();
                    s.pop();
                    return val; 
                }
            int x= s.top();
            s.pop();
            int pop_val= pop();
            s.push(x);
            return pop_val;
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