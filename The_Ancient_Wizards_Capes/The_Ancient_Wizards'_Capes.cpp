#include<bits/stdc++.h>
using namespace std;
int solve(int n,int m[])
{   
    if(n==1 )
    {if(m[0]==1)return 2;
    else return 0;
    }

    int diff[n-1];
    int ans=2;
    bool see_n=false;
    for(int i=0;i<n-1;i++)
    { 
        if(m[i]==n)
        see_n=true;
        diff[i]=m[i+1]-m[i];
    }
    if(m[n-1]==n)
        see_n=true;
    bool one=false;
    for(int i =0;i<n-1;i++)
    {
        if(diff[i]==0 && n%2==1)
        {
            ans=min(ans,2);
            if(diff[i]==0 && see_n)
            {
                if (one || m[i+1]!=n)return 0;
                else one = true;
            }
            continue;
        }
         if( (diff[i]==1||diff[i]==-1) || (diff[i]==0 && n%2==0 ) )
        {
            if(i>0 && diff[i]-diff[i-1]>1)
            return 0;
            ans=min(ans,1);
            if(diff[i]==0 && see_n)
            {
                if (one || m[i+1]!=n)return 0;
                else one = true;
            }

        }
        else 
        {ans=0;break;}
    }
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n;cin>>t;
    int ans;
    while(t--)
    { 
        cin>>n;
        int m[n];
        for(int i =0;i<n;i++)cin>>m[i];
        ans=solve(n,m);
        cout<<ans<<'\n';
    }
}