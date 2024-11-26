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

struct Node* reverseList(struct Node* head) {
    if (head == NULL || head->next == NULL) 
        return head;

    struct Node* rest = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return rest;
    
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while(curr != NULL) {
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

    printf("Given Linked List:");
    printList(head);

    head = reverseList(head);

    printf("Reversed Linked List:");
    printList(head);


    return 0;
}