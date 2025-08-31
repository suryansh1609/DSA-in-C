#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    printf("node with value %d created.\n",value);
    return newnode;
}

int main(){

    struct node* head = NULL;
    struct node* temp = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("\ninvalid input. please enter a positive integer.\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf("\nEnter the value of node %d: ", i+1);
        if (scanf("%d", &value) != 1) {
            printf("\nInvalid input. Please enter an integer.\n");
            return 1;
        }

        struct node* newnode = createNode(value);

        if (head == NULL){
            head = newnode;
            printf("Head node assigned.\n");
        }else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    printf("\nLinked list: ");
    temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}