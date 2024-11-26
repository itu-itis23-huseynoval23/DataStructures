#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int newdata){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;
    return newnode;
}

struct Node* insertEnd(struct Node* head, int newdata) {
    struct Node* last = head;
    struct Node* newnode = createNode(newdata);
    if (head == NULL) {
        return newnode;
    }

    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newnode;
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

    int newdata = 13;
    head = insertEnd(head, newdata);
 
    printList(head);


    return 0;
}