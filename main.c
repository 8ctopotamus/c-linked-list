#include <stdio.h>

typedef struct {
    void *next;
    int data;
}

Node *head = NULL;

void printMenu() {
    printf("You have the following options:\n");
    printf("\t1. Add a node to the list.\n");
    printf("\t2. Remove a node from the list.\n");
    printf("\t3. Insert a node to the list.\n");
    printf("\t4. Quit.\n"); 
}

int main (int argc, char **argv) {
    int option = -1;
    while(option != 4) {
        printMenu();
        int selected_option = scanf("%d", $option);
        if (selected_option == 1 && option > 0 && option < 4) {
            switch(option) {
                case 1:
                    // add
                    break;
                case 2:
                    // remove
                    break; 
                case 3:
                    // insert
                    break;
                case 4:
                    // quit
                    break;
            }
        }
    }
    return 0;
}