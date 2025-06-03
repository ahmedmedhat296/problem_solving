#include <iostream>
using namespace std;
template<typename E>
class ArrayStack
{
    enum {DEFCAPACITY=100}; //default stackcapacity
public:
    ArrayStack(int cap=DEFCAPACITY); //constructor fromcapacity
    int size()const; //numberof items inthe stack
    bool empty()const; // is the stackempty?
    const E& top()const; //get the topelement
    void push(const E& e) ;
    void pop() ; //popthe stack
// ...housekeepingfunctionsomitted
private: //memberdata
    E* S; //arrayof stackelements
    int capacity; //stackcapacity
    int t; // indexof the topof thestack
};
template<typename E>ArrayStack<E>::ArrayStack(int cap): S(new E[cap]), capacity(cap),t(−1){ }
template <typename E> int ArrayStack<E>::size() const
{
    return (t + 1);
}
// number of items in the stack
template <typename E> bool ArrayStack<E>::empty() const
{
    return (t < 0);
}
// is the stack empty?
template <typename E>
// return top of stack
const E& ArrayStack<E>::top() const
{

    return S[t];
}
template <typename E>
// push element onto the stack
void ArrayStack<E>::push(const E& e)
{
    if (size() == capacity) ;
    S[++t] = e;
}
template <typename E>
// pop the stack
void ArrayStack<E>::pop()
{

    −−t;
}



void max_to_top(ArrayStack &s)
{
    static int maxi=s.top();
    static ArrayStack temp;
    if(s.size()>0)
    {
        if(maxi<s.top())
            maxi = s.top();
        temp.push(s.top());
        s.pop();
        max_to_top(s);
    }
    else
    {
        for(int i=0; i<temp.size(); i++)
        {
            s.push(temp.top());
            temp.pop();
        }
        s.push(maxi);
            
    }
}
int main()
{
    ArrayStack st;
    st.push(13);
    st.push(14);
    st.push(19);
    st.push(0);
    st.push(3);
    st.push(17);
    st.push(12);
    max_to_top(st);
    cout<<st.top();
    return 0;
}
