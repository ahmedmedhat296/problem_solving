#include <iostream>
using namespace std;
 void split(int arr[],const int size, int k)
 {
     int sum1=0,sum2=0;
     bool alice =true;
     for (int i=0;i<size;i++)   // while sorting the array ,give the next max value to alice or bob
     {
         for (int j=0;j<size-i-1;j++)
         {
             if (arr[j]>arr[j+1])
             {
                 int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;

             }
         }
         if (alice)
         {
             sum1+=arr[size-i-1];
             alice=false;
         }
         else
         {
            int absinc = arr[size-i]-arr[size-i-1];
            if (absinc>=k&&k>0)
            {
                arr[size-i-1]+=k;
                k=0;
            }
            else if(k>0){arr[size-i-1]+=absinc;k-=absinc;}
            sum2+=arr[size-i-1];
             alice=true;
         }
     }
     int diff=sum1-sum2;
     cout<<diff<< '\n' ;
 }
int main()
{
   int t,n,k;

  cin>>t;
  for (int i=0;i<t;i++)
  {
    cin>>n>>k;
    const int size=n;
   int arr[size];
    for(int j=0;j<size;j++)
    cin>>arr[j];
      split(arr,size,k);
  }
    return 0;
}
