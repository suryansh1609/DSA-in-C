#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = value;
    newnode->next = NULL;
    printf("New node with value %d created.\n", value);
    return newnode;
}

void insertAtIndex(struct node** head, int value, int index){
    struct node* newnode = createNode(value);

    if (index == 0){
        newnode->next = *head;
        if(*head == NULL){
            (*head)->prev = newnode;
        }
        *head = newnode;
        return;
    }   
    
    struct node* temp = *head;
    int count = 0;

    while(temp != NULL && count < index - 1){
        temp = temp->next;
        count++;
    }

    if(temp == NULL){
        printf("Index out of bounds.\n");
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

int main(){

    struct node* head = NULL;
    struct node* temp = NULL;
    int n, value;

    printf("How many nodes you want to create: ", n);
    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Invalid input.\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("enter the value of node %d: ", i+1);
        if(scanf("%d", &value) != 1){
            printf("invalid input'\n");
            return 1;
        }

        struct node* newnode = createNode(value);

        if(head == NULL){
            head = newnode;
        }else{
            temp = head;
            while(temp->next != NULL){
                
                temp = temp->next;
                
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    temp = createNode(5);
    head->prev = temp;
    temp->next = head;
    head = temp;
    
    insertAtIndex(&head,30,4);

    printf("\nDoubly linkedlist forward: ");
    temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Doubly linkedlist backward: ");
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL");


    return 0;
}