#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;
    printf("New node with vlaue %d created.\n", value);
    return newnode;

}

int main(){ 
    struct node* tail = NULL;
    struct node* temp = NULL;

    int n, value;

    printf("How many nodes you wnat to creare: ");
    scanf("%d", &n);

    for(int i = 0; i <n; i++){
            printf("Enter the value for node %d: ", i+1);
            scanf("%d", &value);
        

        struct node* newnode = createnode(value);

        if(tail == NULL){
            tail = newnode;
            tail->next = tail;
            printf("Head node assigned.\n");
        }else{
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
    }
    temp = tail->next;
    printf("Circular Linked list: ");
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != tail->next);
    printf("Back to head.\n");

    return 0;
}