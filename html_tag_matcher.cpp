#include<iostream>
#include<cstring>
using namespace std;
typedef char* Elem;
template <typename E>
class ArrayStack {
	enum { DEFCAPACITY = 100 }; // default stack capacity
public:
	ArrayStack(int cap = DEFCAPACITY); // constructor from capacity
	int size() const; // number of items in the stack
	bool empty() const; // is the stack empty?
	const E& top() const ; // get the top element
	void push(const E& e) ; // push element onto stack
	void pop(); // pop the stack
	// . . .housekeeping functions omitted
private:  
// member data
	E* S; // array of stack elements
	int capacity; // stack capacity
	int t; // index of the top of the stack
};

template <typename E> ArrayStack<E>::ArrayStack(int cap)
	: S(new E[cap]), capacity(cap), t(-1) { } // constructor from capacity
template <typename E> int ArrayStack<E>::size() const
{
	return (t + 1);
} // number of items in the stack
template <typename E> bool ArrayStack<E>::empty() const
{
	return (t < 0);
} // is the stack empty?
template <typename E> // return top of stack
const E& ArrayStack<E>::top() const  {
	return S[t];
}
template <typename E> // push element onto the stack
void ArrayStack<E>::push(const E& e) {
	S[++t] = e;
}
template <typename E> // pop the stack
void ArrayStack<E>::pop() {
	--t;
}

char** gettags( const char* text)
{
    char ** tags=new char*[100];
    int i=0;
        int k=0;
    while(text[i]!='\0')
    {
        if(text[i]=='<')
        {
            int j=i+1;
            int count=0;
            while(text[j]!='>')
            {
            count++;
              j++;
            }
             char* tag = new char[count + 1];
                for (int l = 0; l < count; l++) {
                    tag[l] = text[i + 1 + l];
                }
                tag[count] = '\0';
                tags[k++] = tag;
                i = j;
        }
        i++;
    }
    tags[k]=nullptr;
    return tags;
}
bool matchtags(char** tags)
{
    ArrayStack<char*> St;
    for(int i=0; tags[i] != nullptr;i++)
    {
        if(tags[i][0]!='/')
        {
            St.push(tags[i]);
        }
        else if (tags[i][0]=='/')
        {
            if (St.empty())
            return false;
             int COMP=strcmp(St.top(),tags[i]+1);
             if (COMP!=0)
             return false;
        St.pop();
        }
    }
    if(St.empty())
    return true;
    else 
    return false;
}
int main()
{
   
    const char* str="<body><center><h1>TheLittleBoat</h1></center><p>Thestormtossedthelittleboatlikeacheapsneakerinanoldwashingmachine.Thethreedrunkenfishermenwereusedtosuchtreatment,ofcourse,butnotthetreesalesman,whoevenasastowawaynowfeltthathehadoverpaidforthevoyage.</p><ol><li>Willthesalesmandie?</li><li>Whatcoloristheboat?</li><li>AndwhataboutNaomi?</li></ol></body>";
    char** tags=gettags(str);
    cout<<matchtags(tags);
    return 0;
}