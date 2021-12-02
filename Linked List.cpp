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
    Node *ptr =head;
    head=head->next;
    free(ptr);
    return head;
}

//delete the last Node 
void deleteLastNode(Node *head){
    //grabing the previous node with
    //the help of Null of last node
    Node *preNode=head;
    head=head->next;
    while (head->next!=NULL){
        head=head->next;
        preNode=preNode->next;
    }
    preNode->next=NULL;
    free(head);
}

// deleting the Node with given data
void deleteNodeWithValue(Node *head, int data){
    Node *preNode=head;
    head=head->next;
    while (head!=NULL){
       if(head->data==data){
           preNode->next=head->next;
           free(head);
           break;
       }
       head=head->next;
       preNode=preNode->next;
    }
}




// deleting at a given index
void deleteAtIndex(Node *head,int index){
    int myindex=1;
    Node *preNode;
    Node *ptr;
    
    
    while(head!=NULL){
        
        //grabing the previous node 
        if (myindex==index-1){
            preNode=head;
        }
        
        //updating next of previous node with the next of current node 
        if(myindex==index){
            preNode->next=head->next;
            ptr=head;
            free(ptr);
        }
        head=head->next;
        myindex=myindex+1;
    }
    
}


//updating first
void UpdateFirst(Node *head,int data){
    head->data=data;
}


// updating at any given index
void updateAtIndex(Node *head,int index,int newData){
    int myindex=1;
    while(myindex<=index){
        if (myindex==index){
            head->data=newData;
        }
        myindex++;
        head=head->next;
    }
}

// Update data by giving data 
void updateAtValue(Node *head,int dataToUpdate, int data){
    while(head!=NULL){
        if (head->data== dataToUpdate){
            head->data=data;
        }
        head=head->next;
    }
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
    // insertAtIndex(head,7000,3);         //insert at a given index (cannot insert in the beginning)
    // insertAfterNode(head,head,700);     //insert after desired node 
    
    // head=deleteFromBegin(head);         //detele first Node 
    // deleteAtIndex(head,1);              //delete at a given index (cannot delete the starting node)
    // deleteLastNode(head);               //delete the last node
    // deleteNodeWithValue(head,4);        //delete by giving data (cannot delete the starting node)
    
    // UpdateFirst(head,88);               //update first Node 
    // updateAtIndex(head,1,400);          //update any value by giving index of node;
    // updateAtValue(head,1,400);          //update any Value by giving data 
    
    Traverse(head);

    return 0;
}
