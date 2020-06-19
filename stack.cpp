#include <iostream>
using namespace std;
#define MAX 1000 
class Stack{
    int array[MAX],top;
    public:
        Stack(){
            top = -1;
        }
        bool isEmpty(){
            return(top<0);
        }
        void push(int data){
            if (top >= (MAX - 1)) { 
                cout << "Stack Overflow"; 
            }
            else{
                top++;
                array[top] = data;
                cout<<data<<" Pushed\n";
            }
        }
        int pop(){
            if (!isEmpty()){
                int data = array[top];
                top--;
                return data;
            }
            else{
                cout<<"Stack Empty";
                return -1;
            }
        }
        void peek(){
            if(isEmpty())
                cout<<"Stack Empty\n";
            else
                cout<<"Top: "<<array[top]<<"\n";
        }
};
int main(){
    Stack s;
    s.push(1);
    s.push(9);
    s.push(4);
    s.push(3);
    s.push(7);
    s.push(5);
    s.peek();
    cout << s.pop() << " Popped from stack\n"; 
    cout << s.pop() << " Popped from stack\n"; 
    cout << s.pop() << " Popped from stack\n"; 
    cout << s.pop() << " Popped from stack\n"; 
    cout << s.pop() << " Popped from stack\n"; 
    cout << s.pop() << " Popped from stack\n";
    s.peek(); 
    return 0;
}