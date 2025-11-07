#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    int ans=1;
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n==0 || n==1)
    {
        cout<<ans<<'\n';
        continue;
    }
    int l=0,r=1;
    while(r<n)
    {
        if(a[r]-a[l]>1)
        {
            ans++;
            l=r;
            r++;
        }
        else{
            r++;
        }
    }
    cout<<ans<<'\n';
}
    return 0;
}