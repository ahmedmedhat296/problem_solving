#include<iostream>
const int MAX = 1e9;
struct segment{
int l;
int r;
};
int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        int n;
        int minr=MAX,maxl=1;
        std::cin>>n;
        segment* x=new segment[n];
        for(int i=0;i<n;i++)
        {
            std::cin>>x[i].l>>x[i].r;
            if(x[i].r<minr){minr=x[i].r;}
            if(x[i].l>maxl){maxl=x[i].l;}
        }
        if(n==1 || maxl-minr < 0){std::cout<<0<<'\n';}
        else
std::cout<<maxl-minr<<'\n';
    }
    return 0;
}
