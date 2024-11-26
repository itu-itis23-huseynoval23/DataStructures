#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

struct  Node* swapNodes(struct Node* head, int x, int y) {
    if (x == y)
        return head;

    struct Node *prevX=NULL, *currX=NULL;
    struct Node *prevY=NULL, *currY=NULL;
    struct Node* curr = head;

    while(curr != NULL) {
        if (curr->data == x) {
            currX = curr;
            break;
        }
        prevX = curr;
        curr = curr->next;
    }
    
    curr = head;

    while(curr != NULL) {
        if(curr->data == y) {
            currY = curr;
            break;
        }
        prevY = curr;
        curr = curr->next;
    }

    if (currX == NULL || currY == NULL) 
        return head;

    if(prevX != NULL) 
        prevX->next = currY;
    else
        head = currY;

    
    if(prevY != NULL)
        prevY->next = currX;
    else
        head = currX;


    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;

}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printList(head);
    head = swapNodes(head, 5, 3);
    printList(head);


    return 0;
}