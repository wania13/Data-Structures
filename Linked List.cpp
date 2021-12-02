#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node *next;
};

//traversing
void Traverse(Node *myNode){
    while(myNode!=NULL){
        cout<<"data element is "<<myNode->data<<endl;
        myNode=myNode->next;
    }
}

// insertion at begin
Node* insertAtBegin(Node *head,int data){
    Node *newNode=new Node;
    newNode->data=data;
    newNode->next=head;
    return newNode;
}

//insertion at the end
void insertAtEnd(Node *head,int data){
    
    Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    
    while(head->next!=NULL){
        head=head->next;
    }
    
    head->next=newNode;
    
}

// insert at giver location
void insertAtIndex(Node *head, int data,int index){
    
    int myindex=1;
   
    Node *newNode=new Node;
    newNode->data=data;
   
    //grab the previous node
    while(head!=NULL){
        if (myindex==index-1){
            newNode->next=head->next;
            head->next=newNode;
        }
       
        head=head->next;
        myindex++;
    } 
}

//insert after a desired Node
void insertAfterNode(Node *head,Node *desiredNode,int data){
    Node *newNode=new Node;
    newNode->data=data;
    newNode->next=desiredNode->next;
    desiredNode->next=newNode;
}




// delete from begin
Node* deleteFromBegin(Node *head){
     head=head->next;
     return head;
}

// deleting at a given index
void deleteAtIndex(Node *head,int index){
    int myindex=1;
    Node *preNode;
    
    while(head!=NULL){
        
        //grabing the previous node 
        if (myindex==index-1){
            preNode=head;
        }
        
        //updating next of previous node with the next of current node 
        if(myindex==index){
            preNode->next=head->next;
        }
        head=head->next;
        myindex=myindex+1;
    }
}


//updating first
void UpdateFirst(Node *head,int data){
    head->data=data;
}


int main()
{
    
    Node *head,*second,*third, *fourth;
    
    head=new Node;
    second=new Node;
    third=new Node;
    fourth=new Node;
    
    head->data=1;
    head->next=second;
    
    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next=fourth;
    
    fourth->data=4;
    fourth->next=NULL;
    
 
    // head=insertAtBegin(head,0);         //insert First Node
    // insertAtEnd(head,69);               //insert at the end 
    // insertAtIndex(head,70,4);           //insert at a given index
    // insertAfterNode(head,fourth,700);   //insert after desired node 
    
    // head=DeleteFromBegin(head);   //detele first Node 
    // deleteAtIndex(head,4);        //delete at a given index
    // UpdateFirst(head,88);        //update first Node 
   
   
 
    
    Traverse(head);

    return 0;
}