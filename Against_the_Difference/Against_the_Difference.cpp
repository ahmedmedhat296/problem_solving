#include<bits\stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t,n,loci,maxneat;
    cin>>t;
    while(t--)
    {
        maxneat=INT_MIN;
        cin>>n;
        vector<int> a(n);
        map<int,int>dp;
        map<int,map<int,int>>loc;
        map<int,int>cnt;
        dp[-1]=0;
        for(int i=0;i<n;i++)
        {cin>>a[i];
        if(cnt.count(a[i]))
        cnt[a[i]]++;
        else
        cnt[a[i]]=1;
        loc[a[i]][cnt[a[i]]]=i; 

            if(cnt[a[i]]>=a[i])
            {
                loci = loc[a[i]][cnt[a[i]]-a[i]+1]-1;
                dp[i]=max(a[i]+dp[loci],dp[i-1]);
                if(dp[i]>maxneat)
                maxneat=dp[i];
            }
            else
            dp[i]=dp[i-1];
        }
        if(maxneat==INT_MIN)
        maxneat=0;
        cout<<maxneat<<'\n';

    }
    return 0;
}