#include<iostream>
using namespace std;
const int DEF_SIZE=1000000;
class BST
{
    private:
    int* Arr;
    bool empty;
    public:
    class POS
    {
        private:
        int index;
        BST* bst;
        public:
        POS(int in, BST* T):index(in),bst(T){}
        POS():index(0),bst(nullptr){}
        const int& operator*(){return bst->Arr[index];}
        void operator++()
        {
           if(bst->Arr[index*2+1]!=-1)
           {
                index=2*index+1;
                while(bst->Arr[index]!=-1&&index<DEF_SIZE)
                  index*=2;
                  index/=2;
           }
           else
           {
             bool rightson=index%2;
             index/=2;
               while (rightson)
               {
                rightson=index%2;
                index/=2;
               }
           }
        }
    };
    BST():Arr(new int[DEF_SIZE+1]),empty(true){for(int i=0;i<=DEF_SIZE;i++){Arr[i]=-1;}}
    void Add(int e)
    {   
        int i=1;
          while (Arr[i]!=-1)
          {
            if(e>Arr[i])
               i=i*2+1;
               else
               i*=2;
          }
        Arr[i]=e;
        empty=false;
    }
    POS BEGAN()
    {
        if(!empty)
        {
           int i=2;
           while(Arr[i]!=-1&&i<DEF_SIZE)
           {
              i*=2;
           }
           return POS(i/2,this);
        
        }
        else 
        return POS();
    }
    POS End()
    {
      if(!empty)
        {
           int i=3;
           while(Arr[i]!=-1&&i<DEF_SIZE)
           {
              i=i*2+1;
           }
           return POS(i/2,this);
        
        }
        else 
        return POS();


    }

};
int main()
{
    BST bst;
    bst.Add(10);
    bst.Add(5);
    bst.Add(15);
    bst.Add(18);
    bst.Add(7);
    bst.Add(29);

    BST::POS X = bst.BEGAN();
    cout<<*X<<endl;
    ++X;
    cout<<*X<<endl;
    BST::POS Y = bst.End();
    cout<<*Y<<endl;

    cout<<"SECOND TREE TEST " <<endl;
    BST bst2;
    bst2.Add(11);
    bst2.Add(6);
    bst2.Add(116);
    bst2.Add(119);
    bst2.Add(4);
    bst2.Add(23);
    BST::POS Z = bst2.BEGAN();
    cout<<*Z<<endl;
    ++Z;
    cout<<*Z<<endl;
    BST::POS U = bst2.End();
    cout<<*U<<endl;

    return 0;
}