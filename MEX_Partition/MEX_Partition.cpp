#include<bits\stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t,n,min,ans;cin>>t;
    
    while(t--)
    {
        bool exist[101]={0};
        min=INT_MAX;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
        {
        cin>>A[i];
        exist[A[i]]=true;
        }
        for(int i=0;i<102;i++)
        {
            if(!exist[i])
           {min=i;break;}
        }
        ans= min==INT_MAX? 101:min;
        cout<<ans<<'\n';
    }

}