#include <iostream>
#include <string>
using namespace std;
  int main()
  {
      int t;cin>>t;
      while(t--)
      {
          bool meet= false;
          int a,b,n;
          int x,y;
          x=0;y=0;
          cin>>n>>a>>b;
          string route;
          cin>>route;
          int size=route.size();
          for(int i=0;i<1000;i++)
          {
              if(route[i%size]=='E')
              {
                  x++;
                  if (x==a&&y==b)
                  {
                      meet=true;
                      break;
                  }
              }
               if(route[i%size]=='W')
              {
                  x--;
                  if (x==a&&y==b)
                  {
                      meet=true;
                      break;
                  }
              }
               if(route[i%size]=='S')
              {
                  y--;
                  if (x==a&&y==b)
                  {
                      meet=true;
                      break;
                  }
              }
               if(route[i%size]=='N')
              {
                  y++;
                  if (x==a&&y==b)
                  {
                      meet=true;
                      break;
                  }
              }
          }
          if (meet)
            cout<< "YES"<<endl;
          else
            cout<< "NO"<<endl;
      }




      return 0;
  }
