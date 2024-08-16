#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    Node(int data, Node* next){
        this->data=data;
        this->next=next;
    }
};

Node* delathead(Node* head){
    if(head==NULL) return NULL;
    Node* t=head;
    head=head->next;
    delete(t);
    return head;
}
Node* delatpos(Node* head,int pos){
    if(head==NULL) return NULL;
    Node* curr=head,*prev=NULL;
    int cnt=0;
    while(curr){
        if(pos==0){
            Node* temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        else{
            if(cnt==pos){
                Node* temp=curr;
                curr=curr->next;
                prev->next=curr;
                delete(temp);
                break;
            }
            cnt++;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

Node* delattail(Node* head){
    if(head==NULL) return NULL;
    Node* temp=head,*prev=NULL;
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    while(temp->next){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    return head;
}

Node* delWithVal(Node* head, int val){
    if(head==NULL) return NULL;
    Node* curr=head,*prev=NULL;
    while(curr){
        if(curr->data==val){
            Node* temp=curr;
            curr=curr->next;
            prev->next=curr;
            delete(temp);
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
}

Node* insertAtHead(Node* head, int val){
    Node* temp=new Node(val);
    temp->next=head;
    head=temp;
    return head;
}

Node* insertAtTail(Node* head, int val){
    Node* temp=new Node(val),*curr=head,*prev=NULL;
    while(curr){
        prev=curr;
        curr=curr->next;
    }
    prev->next=temp;
    return head;
}

Node* insertAtKPos(Node* head, int val, int k){
    Node* temp=new Node(val),*curr=head,*prev=NULL;
    int cnt=0;
    if(k==0){
        temp->next=head;
        head=temp;
        return head;
    }
    while(curr){
        if(cnt==k){
            prev->next=temp;
            temp->next=curr;
            return head;
        }
        cnt++;
        prev=curr;
        curr=curr->next;
    }
  if(cnt==k){
    prev->next=temp;
  }
    return head;
}
int main(){
    int arr[4]={1,2,3,4};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    int i=1;
    while(i<4){
        temp->next=new Node(arr[i]);
        temp=temp->next;
        i++;
    }
    temp=head;
    temp=delathead(temp);
    temp=delatpos(temp,3);
    temp=delattail(temp);
    temp=delWithVal(temp,2);
    temp=insertAtHead(temp,2);
    temp=insertAtTail(temp,5);
    temp=insertAtKPos(temp,10,2);
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
