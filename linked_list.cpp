#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
};

class Linked_List{
    Node *head, *temp, *cur, *prev;
    int length = 0;
    public:
        Linked_List(){
            head = NULL;
            temp = NULL;
            cur = NULL;
            prev = NULL;
            length = 0;
        }
        void addNode(int data){
            // If empty List 
            if (head == NULL){
                head = new Node();
                head->data = data;
                length++;
                cout<<"Linked List Created\n"<<data<<" Inserted at Head\n";
            }
            else{
                temp = new Node();
                temp->data = data;
                // Normal Insertion
                // At the End 
                cur = head;
                while (cur->next!=NULL){
                    cur = cur->next;
                }
                cur->next = temp;
                length++;
                cout<<data<<" Appended\n";

                

            }
        }

        void addNode(int data, int prev_data){
            // Insert after node with data==prev_data
            temp = new Node();
            temp->data = data;
            cur = head;
            while (cur->data!=prev_data){
                cur = cur->next;
            }
            temp->next = cur->next;
            cur->next = temp;
            length++;
            cout<<data<<" Inserted\n";
        }
        void display(){
            cur = head;
            cout<<"\nLINKED LIST:\n";
            while (cur!=NULL){
                cout<<cur->data<<"\t";
                cur = cur->next;
            }
            cout<<"\n";
        }

        void deleteNode(int data){
            prev = head;
            // Find Previous of Node to Delete
            while (prev->next->data != data){
                prev = prev->next;
            }
            temp = prev->next;
            prev->next = temp->next;
            delete (temp);
            cout<<"\nNode Deleted\n";
        }
        
        void sort(){
            prev = head;
            int tmp;
            for(int i = 0; i<length; i++){
                cur = prev->next;
                for(int j = 0; j<length;j++){
                    if (prev ->next==NULL || cur == NULL){
                        break;
                    }
                    if(prev->data>cur->data){
                        tmp = prev->data;
                        prev->data = cur->data;
                        cur->data = tmp;
                    }
                    cur = cur->next;
                }
                prev = prev->next;
            }
            cout<<"\nList Sorted\n";
        }

        void reverse(){
            Node *nxt = NULL;
            prev = NULL;
            cur = head;
            while (cur!=NULL){
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            head = prev;
        }
};

int main(){
    Linked_List l;
    l.addNode(4);
    l.addNode(6);
    l.addNode(2);
    l.addNode(1);
    l.addNode(5);
    // Insert Data After Node with data==2
    l.addNode(3,2);
    //Display
    l.display();
    // Sort
    l.sort();
    //Display
    l.display();
    // Delete
    l.deleteNode(3);
    //Display
    l.display();
    // Reverse
    l.reverse();
    //Display
    l.display();
    
    return 0;
}
