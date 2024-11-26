#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

struct Node* insertPos(struct Node* head, int pos, int newdata) {
    struct Node* curr = head;
    struct Node* newnode = createNode(newdata);
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return head;
    }
    for(int i = 1; i < pos-1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position is out of bounds.\n");
        free(newnode);
        return head;
    }

    newnode->next = curr->next;
    curr->next= newnode;
    return head;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main () {

    struct Node* head = createNode(3);
    head->next = createNode(5);
    head->next->next = createNode(8);
    head->next->next->next = createNode(10);

    int newdata = 12, pos = 2;
    head = insertPos(head, pos, newdata);
 
    printList(head);


    return 0;
}