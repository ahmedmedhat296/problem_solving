#include<iostream>
#include<chrono>
#include<cstdlib>
using namespace std::chrono;
using namespace std;
int findmaxcross(int* Arr,int low,int high,int* crossleft,int*crossright)
{
  int mid=(high+low)/2;
  int leftsum=INT_MIN;
  int rightsum=INT_MIN;
  int sum=0;
  for(int i=mid;i>=0;i--)
  {
    sum+=Arr[i];
    if(sum>leftsum)
    {
        *crossleft=i;
        leftsum=sum;
    }
  }
  sum=0;
  for(int j=mid+1;j<=high;j++)
  {
    sum+=Arr[j];
    if(sum>rightsum)
    {
        *crossright=j;
        rightsum=sum;
    }
  }
  return leftsum+rightsum;
}
int maxsubarr(int* Arr,int low,int high,int* maxlow, int* maxhigh)
{
    if(low==high)
    {   
      *maxlow=low;
      *maxhigh=high;
      return Arr[low];
    }
   int mid=(low+high)/2;int leftlow,lefthigh,rightlow,righthigh,crosslow,crosshigh;
    int leftsum=maxsubarr(Arr,low,mid,&leftlow,&lefthigh);
    int rightsum=maxsubarr(Arr,mid+1,high,&rightlow,&righthigh);
    int crosssum=findmaxcross(Arr,low,high,&crosslow,&crosshigh);
    int maxi=max(max(leftsum,rightsum),crosssum);
    if(maxi==rightsum)
    {
      *maxlow=rightlow;
      *maxhigh=righthigh;
    }
    else if(maxi==leftsum)
    {
      *maxlow=leftlow;
      *maxhigh=lefthigh;
    }
    else{
    *maxlow=crosslow;
    *maxhigh=crosshigh;
    }
    return max(max(leftsum,rightsum),crosssum);
}
void generateArray(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
      arr[i] = (rand() % 41) - 20; // random number from -20 to 20
  }
}
const int SIZE= 10000;
int main()
{
  auto start = high_resolution_clock::now();
  int low,high;
  int values[SIZE];
  generateArray(values,SIZE);
  int maxarr=maxsubarr(values,0,SIZE-1,&low,&high);
  cout<<maxarr<<low<<high;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}