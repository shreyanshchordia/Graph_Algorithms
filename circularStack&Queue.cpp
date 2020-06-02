#include <iostream>
#include <cstring>
using namespace std;

class List{
    struct Node{
        Node* next;
        int data;
    };
    Node* first;

    public:
    List(int d){
        Node* newnode = new Node;
        first = newnode;
        first->next = newnode;
        first->data = d;
    }

    List(){
        this->first = NULL;
    }

    int push_back(int x){
        Node* temp = this->first;
        if(temp == NULL){
            Node* newnode = new Node;
            newnode->data = x;
            newnode->next = newnode;
            this->first = newnode;
            return newnode->data;
        }
        while(temp->next!= this->first){
            temp = temp->next;
        }
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = this->first;
        temp->next = newnode;
        return newnode->data;
    }

    int pop_back(){
        if(this->first == NULL){
            return -1;
        }
        else if(this->first->next == this->first){
            int x = this->first->data;
            this->first = NULL;
            return x;
        }
        Node* temp = this->first;
        while(temp->next->next != this->first){
            temp = temp->next;
        }
        int x = temp->next->data;
        temp->next = this->first;
        return x;
    }

    int push_front(int x){
        Node* newnode = new Node;
        newnode->data = x;
        if(this->first == NULL){
            this->first = newnode;
            newnode->next = newnode;
            return x;
        }

        else{
            Node* temp = this->first;
            this->first = newnode;
            this->first->next = temp;
            Node* t = temp;
            while(t->next != temp){
                t = t->next;
            }
            t->next = this->first;
            return x;
        }
    }

    int pop_front(){
        if(this->first == NULL){
            return -1;
        }
        else if(this->first->next == this->first){
            int x = this->first->data;
            this->first = NULL;
            return x;
        }
        else{
            int x = this->first->data;
            Node* t = this->first;
            this->first = this->first->next;
            Node* iter = t;
            while(iter->next != t){
                iter = iter->next;
            }
            iter->next = this->first;
            return x;
        }
    }

    void print(){
        Node* temp = this->first;
        if(temp == NULL){
            cout<<"-1\n";
            return;
        }
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp !=this->first);
        cout<<"\n";
    }
};
