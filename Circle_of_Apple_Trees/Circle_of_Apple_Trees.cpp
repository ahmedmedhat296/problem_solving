#include<bits\stdc++.h>
using namespace std;
int main()
{
    int t,n,ans=0;cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        vector<int>b(n);
        map<int,bool> mp;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(mp.count(b[i])==0)
            {ans++;mp[b[i]]=true;}
    
        }
        cout<<ans<<'\n';
    }
}
