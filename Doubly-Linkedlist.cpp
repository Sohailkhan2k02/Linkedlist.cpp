#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data){
        this->data = data;
        this->next=NULL;
        this->back=NULL;
    }
};

Node* deleteHead(Node* head){
    if(head==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    head->back=NULL;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL) return NULL;
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    Node* prev=temp->back;
    prev->next=NULL;
    temp->back=NULL;
    delete temp;
    
    return head;
}

Node* deleteAtK(Node* head, int k){
    int cnt=0;
    Node* temp=head;
    while(temp && cnt<k){
        cnt++;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* next=temp->next;
    if(prev==NULL && next==NULL){
        delete(temp);
        return head;
    }
    else if(prev==NULL){
        deleteHead(temp);
        return head;
    }
    else if(next==NULL){
        deleteTail(temp);
        return head;
    }
    else{
        prev->next=next;
        temp->next=NULL;
        temp->back=NULL;
        delete(temp);
        return head;
    }
    return head;
}

Node* reverse(Node* head){
    if(head==NULL) return NULL;
    Node* curr=head;
    Node* temp=NULL;
    while(curr){
        temp=curr->back;
        curr->back=curr->next;
        curr->next=temp;
        curr=curr->back;
    }
    return temp->back;
}


int main(){
    vector<int>arr={1,2,3,4};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1; i<arr.size(); i++){
        temp->next=new Node(arr[i]);
        temp->next->back=temp;
        temp=temp->next;
    }
    temp=head;
    temp=reverse(temp);
    temp=deleteHead(temp);
    temp=deleteTail(temp);
    temp=deleteAtK(temp,2);
    
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
