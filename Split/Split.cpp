#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>k;
        vector<int>a(n);
        unordered_map<int,int> totcounts,subcounts;
        for(int i=0;i<n;i++)
        {
        cin>>a[i];
        subcounts[a[i]]=0;
        if (totcounts.count(a[i])==0)
        {
            totcounts[a[i]]=1;

        }
        else
        totcounts[a[i]]++;
        }
        int l=0,r=0;
        bool div=true;
        for(auto it = totcounts.begin();it!=totcounts.end();it++)
        {
            if(it->second % k != 0)
            {
                div = false;
                break;
            }
        }

        while(r<n && div)
        {  
            subcounts[a[r]]++;
            if(subcounts[a[r]]>totcounts[a[r]]/k)
            {
                while(subcounts[a[r]]>totcounts[a[r]]/k)
                {
                    subcounts[a[l]]--;
                    l++;
                }
            }
            ans += (r-l+1);
            r++;
               
        }
            
        cout<<ans<<'\n';
        }

        return 0;
    }
