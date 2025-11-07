#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie();
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        long long b[n];
        int a[n];
        int dis=1;a[0]=dis;
        cin>>b[0];
        for(int i=1;i<n;i++)
        {
            cin>>b[i];
            long long diff=b[i]-b[i-1];
            if(diff==i+1)
            a[i]=++dis;
            else
            a[i]=a[i-diff];
        }
        for(int i:a)
        cout<<i<<' ';
        cout<<'\n';

    }
}