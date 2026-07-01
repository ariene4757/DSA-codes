#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
struct Node{

    public:
      int Data{0};
      Node *Next = nullptr;
      Node(int Data): Data (Data){}

};

class Linked_List{
    private:
    Node * head = nullptr;
    Node * tail = nullptr;
    int length{0};
    
    public:
   
    void Push_back(int data){
      
      
        Node* newnode = new Node(data);
        if (!head){
            head = tail = newnode;
        }
        else {
            tail->Next = newnode;
            tail = newnode;

        }
        length++;
    }
    void Print(){
        for (Node* f = head; f; f = f->Next){
            cout <<f->Data<<" ";
        }
        cout <<endl;
    }
    void Print_Rec(Node* x){
        if (x == nullptr){
            cout <<endl;
            return ;
        }
        cout << x->Data<<" ";
        Print_Rec(x->Next);

    }
    Node* Get_Nth(int n){
       
        if (n >= length){
            return nullptr;
        }
        Node* temp = head;
        for (int i = 1; i <n; i++){
            temp = temp->Next;

        }
        return temp;
    }
    void Print_Nth(int n){
        
        Node*  temp = Get_Nth(n);
        cout << temp->Data<<endl;
     }
    
     int search(int goal){
        int idx = 0;
        for (auto temp = head; temp; temp = temp-> Next){
            if (temp->Data == goal){
                return idx;
            } 
        }
    
               return -1;
     }

    int Improved_search(int goal){
        int n = 0;
        if (head -> Data == goal ){
            return n;
        }
        for (auto prv = head; prv; prv = prv ->Next ){
            if (prv->Next-> Data == goal){
                n++; 
                int temp = prv ->Data;
                prv->Data = prv->Next->Data;
                prv->Next->Data = temp;
                return n;


            }
        }
        return -1;
    }
    void push_front(int data){
        insert(data,0);
        
    }
    void insert(int data, int idx){
        Node* newnode = new Node(data);
        Node* prv = Get_Nth(idx);
        Node* next = Get_Nth(idx+1);
        if (prv == nullptr && next == nullptr){
            head = tail = newnode;
        }
        else if (prv == nullptr){
            head = newnode;
            newnode->Next = next;
        }else if (next == nullptr){
            prv->Next = newnode;
        }else{
            prv->Next = newnode;
            newnode->Next = next;
        }
        length++;
    }
     void delete_Node(Node* node){
        length--;
        delete node;

    }
    
    void pop_front(){
        assert(head);
        Node* temp ;
        if (head == tail){
            temp = head;
            head = tail= nullptr;
            
            
        }else {
            Node* next = head->Next;
            temp = head;
            head = next;
            

        }
        delete_Node(temp);
        

    }
   
     void pop_back(){
          Node* temp;
        
        if (head == tail ){
            temp = tail;
            head = tail= nullptr;
            
            
        }else {
            Node* prv = Get_Nth(length - 2);
            temp = tail;
            tail = prv;
            

        }
        
      delete_Node(temp);
       
        
    }
    void erase(int idx){
        assert(idx >= 0 && idx < length);
        Node* prv = Get_Nth(idx-1);
        Node* next = Get_Nth(idx+1);
        Node * temp;
        if (prv == nullptr){
           pop_front();
            

        }else if (next == nullptr){
           
           pop_back();
        }
        else{
            temp = prv ->Next;
            prv ->Next = next;
            delete_Node(temp);


        }

    }


};
int main(){
    Linked_List st;
    st.insert(1,0);
    st.insert(2,1);
    st.Print();
   

}