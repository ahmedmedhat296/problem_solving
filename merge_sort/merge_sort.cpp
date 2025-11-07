#include<iostream>
using namespace std;
void merge(int** A,int p,int q ,int r)
{
    int* Arr=*A;
int* ret = new int[r - p + 1];
    int i = p, j = q + 1, k = 0;
    while (i <= q && j <= r) { 
        ret[k++] = (Arr[i] <= Arr[j]) ? Arr[i++] : Arr[j++];
    }
    while (i <= q) ret[k++] = Arr[i++]; 
    while (j <= r) ret[k++] = Arr[j++];
    for (int m = 0; m < k; m++) {
    Arr[p + m] = ret[m];
}
delete ret;
}
void mergesort(int* Arr,int p,int r)
{
    int q=(p+r)/2;
    if(p<r)
    {
        mergesort(Arr,p,q);
        mergesort(Arr,q+1,r);
    }
    merge(&Arr,p,q,r);
}
int main()
{
    int Arr[8]={6,5,3,1,2,18,9,0};
    mergesort(Arr,5,7);
    for(int i=0;i<8;i++)
cout<<Arr[i]<<" ";
    return 0;
}