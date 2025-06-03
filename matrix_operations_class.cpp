#include<iostream>
using namespace std;
class Array2d
{
    private:
    int** Arr;
    int* rowsum; // to store rows sums
    int row;
    int col;
    public:
    Array2d(int x,int y)
    {
        row=x;
        col=y;
        const int sizerow=row;
        const int sizecol=col;
        Arr=new int*[sizerow];
        for(int i=0;i<sizerow;i++)
        {
            Arr[i]=new int[sizecol];
            for(int j=0;j<sizecol;j++)
                 Arr[i][j]=0;
        }
        rowsum = new int[sizerow];
          for(int i=0;i<sizerow;i++)
          {
            rowsum[i]=0;
          }
    }
     int getset(int x,int y,  int val = INT_MIN )
     {
        if(val == INT_MIN)
        {
            return Arr[x][y];
        }
        else{
            rowsum[x]-= Arr[x][y];
            rowsum[x]+=val;
            Arr[x][y]=val;
            return val;

        }
     }
     void resize(int x,int y)
     {
        const int oldx=row;
        const int oldy=col;
        row=x;
        col=y;
        const int newx=x;
        const int newy=y;
        int** temp=new int*[newx]; 
        for(int i=0;i<x;i++)
        {
            temp[i]=new int[newy];
            for(int j=0;j<y;j++)
            {     
                if(i<oldx&&j<oldy)
                 temp[i][j]=Arr[i][j];
                 else
                 temp[i][j]=0;
            }
        }
        delete[] Arr;
        Arr=temp;
        int* temp1=new int[newx];
        for(int i=0;i<newx;i++)
        {
            if(i<oldx)
            temp1[i]=rowsum[i];
            else
            temp1[i]=0;
        }
        delete[] rowsum;
        rowsum=temp1;
        
     }
    
    int* getraw(int x)
    {
        const int sizey=col;
       int *temp=new int[sizey];
       for(int i=0;i<sizey;i++)
       {
        temp[i]=Arr[x][i];
       }
       return temp;
    }
    int getmax()
    {
        int maxrow=rowsum[0];
        int maxindex=0;
        for(int i=1;i<row;i++)
        {
           if(rowsum[i]>maxrow)
           {
            maxindex=i;
            maxrow=rowsum[i];
           }
        }
        return maxindex;
    }
    Array2d operator+(Array2d op) // u can't sum or subtract matrices with different dimensions
    {
       Array2d temp (row,col);
       for(int i=0;i<row;i++)
       {
        for(int j=0;j<col;j++)
        {
            temp.Arr[i][j]=op.Arr[i][j]+Arr[i][j];
        }
       }
       return temp;

    }
};
int main()
{
    int count = 0;
    Array2d matrix(3,4);
    for (int i = 0 ; i< 3 ; i ++)
    {
       for (int j = 0 ; j<4 ; j++)
       {
         matrix.getset(i,j,count);
         count++;
       }
    }
    Array2d matrix2(3,4);
    for (int i = 0 ; i< 3 ; i ++)
    {
       for (int j = 0 ; j<4 ; j++)
       {
         matrix2.getset(i,j,count);
         count++;
       }
    }
    for (int i = 0 ; i< 3 ; i ++)
    {
       for (int j = 0 ; j<4 ; j++)
       {
           cout<<matrix.getset(i,j)<<"-";
       }
    }
    int* ptr = matrix.getraw(1);
    cout<<endl;
    for (int i = 0 ; i<4 ; i ++)
    {
        cout<<ptr[i]<<"-";
    }
    cout<<endl<<matrix.getmax()<<endl;
   matrix.resize(3,5);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<matrix.getset(i,j)<<"_";
        }
    }
    matrix.getset(1,4,500);
    cout<<endl<<matrix.getmax()<<endl;
    Array2d matrixres(3,4);
    matrixres=matrix+matrix2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<matrixres.getset(i,j)<<"_";
        }
    }
    return 0;
}