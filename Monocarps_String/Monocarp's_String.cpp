#include<bits/stdc++.h>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int t,n;cin>>t;
    int ans;
    string s;
    while(t--)
    {
    cin>>n;
    cin>>s;
    int cnta=0,cntb=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='b')cntb++;
    }
    cnta=n-cntb;
    bool neither=cnta==0 || cntb ==0;
    int diff= cnta-cntb;
    int len=INT_MAX;
    vector<int> prefix_sum(n);
    prefix_sum[0]= s[0]=='a'? 1:-1;
    for(int i=1;i<n && diff !=0 && !neither;i++)
    {
        int val=s[i]== 'a' ? 1:-1;
        prefix_sum[i]= prefix_sum[i-1] + val;
    }
    map<int,int> mp;
    mp[0]=-1;
    int needed,j,curlen;
    for(int i=0;i<n;i++)
    { 
        needed=prefix_sum[i]-diff;
        if(mp.count(needed))
        {
            j=mp[needed];
            curlen=i-j;
            len=min(curlen,len);
        }
        mp[prefix_sum[i]]=i;
    }
    if(diff == 0)
    ans= 0;
    else if(neither || len==n)
    ans= -1;
    else
    ans=len;
    cout<<ans<<'\n';
    
}
return 0;
}