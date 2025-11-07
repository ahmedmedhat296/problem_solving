#include<bits\stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    int x,y,z;
    int a,b,c;
    while(t--)
    {
        cin>>x>>y>>z;
        a= x|y;
        b= y|z;
        c=z|x;
        if ((a&b) == y && (b&c) == z && (c&a) ==x)
        cout<<"yes\n";
        else
        cout<<"no\n";

    }
}