// The following code will execute the insertion operations in the linked list:

#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};
// Function to display the linked list

void display(struct Node* ptr){
    cout<<"....Here is your Linked List....\n";
    while (ptr!=NULL)
    {
        cout<<ptr->data ;
        ptr=ptr->next;
    }
    cout<<"\n";
}

// Function to insert a node at the first of a linked list
struct Node* insert_first(struct Node* head,int data){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    cout<<"Inserted the element successfully\n" ;
    return ptr;
    
}

// function to add node b/w two nodes in a linked list

struct Node* insert_between(struct Node* head,int data,int index){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;

    int i=0;
    while(i!= index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    cout<<"Inserted the element successfully\n";
    return head;
   
    
}

// Function to insert a node at the end of a linked list
struct Node* insert_end(struct Node* head,int data){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    struct Node* p=head;  
    while(p->next!=NULL){
        p=p->next;
        
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    cout<<"Inserted the element successfully\n";
    return head;
    
    
}
// To delete an  element from the linked list there are basically 4cases:

/*Delete element at the first position
Delete element at a specific index
Delete a specific item from the linked list
Delete the last element from the linked list
The following code will execute the deletion operations in the linked list:*/

// Function to delete the first element from the linked list
struct Node * delete_first(struct Node*head){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;


}

// Function to delete  element from  specific index of  the linked list
struct Node* delete_index(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head->next;
    
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    cout<<"Deleted the element at index"<< index<< "successfully\n";
    return head;

}
// Function to delete specific  element from   the linked list

struct Node* delete_data(struct Node* head,int value){
    struct Node* p=head;
    struct Node* q=head->next;

    while(q->data!=value && q->next!= NULL  ){
        p=p->next;
        q=q->next;

    }
    if(q->data==value){
        p->next=q->next;
        free(q);

    }
    cout<<"Deleted the element"<< value  << "successfully\n";
    return head;

}

// Function to delete the last element from the linked list
struct Node* delete_last(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;

    while(q->next!= NULL  ){
        p=p->next;
        q=q->next;

    }
    p->next=NULL;
    free(q);
    cout<<"Deleted the last element successfully\n" ;
    return head;

}
/*When the element does not exist in the list NULL is returned with an error message as " The element you are trying to delete doesn't exits in the list"
To delete the first and only element we have to dynamically allocate a new pointer and point it to the head and point the head pointer to head -> next and free the allocated pointer. The code for the same is already provided above.
For sorting we are going to use the Quicksort Algorithm which has the Best Time complexity Big O(nlogn).*//

#<include iostream>//Quick Sort Algorithm
using namespace std; 


void printarray(int*arr,int n){  //function to print the elments of the array
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<"\n";
}



int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;


    do
    {
        while(arr[i]<=pivot){
            i++;
        }

        while (arr[j]>pivot)
        {
            j--;
        }

        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp ;
        }
        
    } while (i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;

    
}

void quicksort(int arr[],int low, int high){

    int index;

    if(low<high){
        index=partition(arr,low,high);
        quicksort(arr,low,index-1);
        quicksort(arr,index+1,high);

    }
}
int main(){
    int arr[10]={22,99,1,55,7,98,1,2,3,4};
    int n=10;

    printarray(arr,n);
    quicksort(arr,0,n-1);
    printarray(arr,n);

return 0;
}
// The code below is just for testing the insertion and deletion operations of the linked list:

#<include iostream>
using namespace std;

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // pointer to the first node of the linked list
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));
    
    head->data=11;
    head->next=second;
    
    second->data=22;
    second->next=third;

    third->data=33;
    third->next=fourth;

    fourth->data=44;
    fourth->next= NULL;

    display(head); // calling the display function using the head pointer

    //INSERTION OPERATIONS

    //head =insert_first(head,77);
    //head=insert_between(head,999,2);
    //head=delete_index(head,1);
    // head=insert_end(head,55);

    //DELETION OPERATIONS
    
    // head= delete_first(head);
    // head=delete_index(head,2);
    //delete_data(head,22);
    head=delete_last(head);

    
    display(head);

return 0;
}
