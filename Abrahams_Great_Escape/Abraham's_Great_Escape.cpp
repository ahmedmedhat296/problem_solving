#include<bits\stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        if(k!=(n*n)-1)
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i*n+j<k)
                    cout<<'U';
                    else if(i*n<n*(n-1))
                    cout<<'D';
                    else if (j==n-1)
                    cout<<'L';
                    else
                    cout<<'R';
                }
                cout<<'\n';
            }
        
        }
        else
        cout<<"NO\n";
    }
}