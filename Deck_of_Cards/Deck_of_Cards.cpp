#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        const int size=n;
        string rem;
        rem.reserve(k);
        string ans(size,'+');
        int l=0,r=size-1;
        cin>>rem;
        for(int i=0;i<k && l<n && r>=0;i++)
        {
            if(rem[i]=='0')
            {
                if(l>0 && ans[l-1]=='?')
                {
                    int temp=l-1;
                    while(ans[temp--]== '?'&& temp>0)
                    {}
                    ans[l]='?';
                    ans[temp+1]='-';
                }
                else
                ans[l]='-';
                l++;
            }
             else if(rem[i] == '1')
            {
                if(r<n-1 && ans[r+1]=='?')
                {
                    int temp=r+1;
                    while(ans[temp++]== '?'&& temp<n-1)
                    {}
                    ans[r]='?';
                    ans[temp-1]='-';


                }
                else
                ans[r]='-';
                r--;

            }
             else if(rem[i]=='2')
            {
                if (l==r && r<n-1 && ans[r+1]!='?' && l>0 && ans[l-1]!= '?' || n==1)
                {
                    ans[l]='-';

                }
                else{
                ans[l++]='?';
                ans[r--]='?';
                }
            }

        }
        cout<<ans<<'\n';
    }
    return 0;
}