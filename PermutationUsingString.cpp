#include<iostream>
using namespace std;

void StringPermutation(string s, string ans)
{
    if(s.length()==0)
        {
            cout<<ans<<endl;
            return;
        }
    for(int i=0; i<s.length(); i++)
    {
        char c=s[i];
        string ros= s.substr(0,i) + s.substr(i+1);
        StringPermutation(ros,ans+c);
    }
}

int main()
{
    string s= "ABCD";
    StringPermutation(s,"");
}

/*
Output:

ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BACD
BADC
BCAD
BCDA
BDAC
BDCA
CABD
CADB
CBAD
CBDA
CDAB
CDBA
DABC
DACB
DBAC
DBCA
DCAB
DCBA
*/