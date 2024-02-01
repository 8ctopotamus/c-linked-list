#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *next;
    int data;
}

Node *head = NULL;

Node *addNode(int data) {
    Node *new = NULL;
    // if list is empty
    if (head == NULL) {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        new->next = NULL;
        head = new;
    } else {
        new = malloc(sizeof(Node));
        if (new == NULL)
            return NULL;
        new->data = data;
        new->next = head;
        head = new;
    }
    return new;
}

int removeNode(int data) {
    Node *prev = head;
    Node *current = head;
    while(current != NULL) {
        if (current->data == data) {
            // if current node is list head
            if (current == head) {
                head = current->next;
            } else {
                prev->next = current->next;
                free(current);
                current = NULL;
            }
            return 1;
        } 
        prev = current;
        current = current->next;
    }
    return 0;
}

Node *insertNode(int data, int position) {
    Node *current = head;
    while (current != NULL && position != 0) {
        position--;
    }
    if (position != 0) {
        print("Requested position too far into list\n");
        return NULL;
    }
    Node *new = malloc(sizeof(Node));
    if (new == NULL)
        return NULL;
    new->data = data;
    new->next = current->next;
    current->next = new;
    return new;
}

void printList() {
    Node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

void printMenu() {
    printf("You have the following options:\n");
    printf("\t1. Add a node to the list.\n");
    printf("\t2. Remove a node from the list.\n");
    printf("\t3. Insert a node to the list.\n");
    printf("\t4. Print the list.\n");
    printf("\t5. Quit.\n"); 
    return;
}

int main (int argc, char **argv) {
    int option = -1;
    int arg1 = 0;
    int arg2 = 0;
    while(option != 5) {
        printMenu();
        int selected_option = scanf("%d", &option);
        if (selected_option == 1 && option > 0 && option < 5) {
            switch(option) {
                case 1: // add
                    printf("What data should I add?\n");
                    scanf("%d", &option);
                    Node *new = addNode(option);
                    break;
                case 2: // remove
                    printf("What data should I remove?\n");
                    scanf("%d", &arg1);
                    int success = removeNode(arg1);
                    if (!success)
                        printf("Element not found");
                    break; 
                case 3: // insert
                    printf("What data should I insert?\n");
                    scanf("%d", &arg1);
                    printf("What position?\n");
                    scanf("%d", &arg2);
                    new = insertNode(arg1, arg2);
                    if (new == NULL)
                        printf("Failed to insert into list\n");
                    break;
                case 4: // print
                    printList();
                    break;
                case 5: // quit
                    break;
            }
        }
    }
    return 0;
}