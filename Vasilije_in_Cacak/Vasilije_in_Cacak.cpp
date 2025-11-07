#include<iostream>
using namespace std;
int main()
{
   int t;
    long long x,max,min,k,n;
   cin>>t;
   while(t--)
   {
    cin>>n>>k>>x;
    min=(k*(k+1)/2);
    max=(k*(2*n-k+1)/2);
    if(x>=min && x<=max)
    cout<<"YES\n";
    else
    cout<<"NO\n";
   }

    return 0;
}