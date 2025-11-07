#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    int n,ans;
    while(t--)
    {
        cin>>n;
        ans = n%3 ? 3-n%3:0;
        cout<<ans<<'\n';
    }
    return 0;
}