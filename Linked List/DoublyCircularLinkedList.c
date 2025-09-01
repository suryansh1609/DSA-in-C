#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createnode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

int main(){
    struct node* tail = NULL;
    struct node* temp = NULL;
    struct node* newnode;
    int n, value;
    
    printf("How many node you want to create: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &value);
        
        newnode = createnode(value);
        
        if(tail == NULL){
            tail = newnode;
            tail->next = tail;
            tail->prev = tail;
        }else{
            newnode->next = tail->next;
            newnode->prev = tail;
            tail->next->prev = newnode;
            tail->next = newnode;
            tail = newnode;
        }
    }

    if(tail != NULL){
        temp = tail->next;
        printf("Doubly circular linled list: ");
        do{
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }while(temp != tail->next);
        printf("Back to head\n");

    }else{
        printf("List is empty.");
    }
    
    //deletion from end
    if(tail == NULL){
        printf("Linkedlist empty.");
    }else if(tail == tail->next){
        tail = NULL;
        
    }else{
        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;
        tail = tail->prev;
    }
    
    if(tail != NULL){
        temp = tail->next;
        printf("Doubly circular linled list: ");
        do{
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }while(temp != tail->next);
        printf("Back to head\n");
    
    }else{
        printf("List is empty.");
    }
    
    //deletion from begginging
    struct node* head = tail->next;
    if(tail == NULL){
        printf("Linkedlist empty.\n");
    }else if(tail == tail->next){
        tail = NULL;
    }else{
        tail->next = head->next;
        head->next->prev = tail;
    }
    
    if(tail != NULL){
        temp = tail->next;
        printf("Doubly circular linled list: ");
        do{
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }while(temp != tail->next);
        printf("Back to head\n");
    
    }else{
        printf("List is empty.");
    }
    
    //deletion from specific position (correction required)
    
    temp = tail->next;
    int pos = 2;
    
    for(int i = 0; i < n; i++){
        temp = temp->next;
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    if(temp == tail){
        tail = temp->prev;
    }
    
    if(tail != NULL){
        temp = tail->next;
        printf("Doubly circular linled list: ");
        do{
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }while(temp != tail->next);
        printf("Back to head\n");
    
    }else{
        printf("List is empty.");
    }
    
    return 0;
}