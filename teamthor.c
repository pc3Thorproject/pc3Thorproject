#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct todo_item {
    char name[50];
    int done;
};

int main() {
    struct todo_item items[MAX_ITEMS];
    int num_items = 0;
    int cont;

    do {
        // print the current list of items
        printf("Current items:\n");
        for(int i = 0; i < num_items; i++) {
            printf("%d. [%c] %s\n", i+1, items[i].done ? 'X' : ' ', items[i].name);
        }

        // prompt the user for an action
        printf("\nWhat do you want to do?\n");
        printf("1. Add an item\n");
        printf("2. Mark an item as done\n");
        printf("3. Remove an item\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: // add an item
                if(num_items == MAX_ITEMS) {
                    printf("Error: List is full.\n");
                } else {
                    printf("Enter the name of the item: ");
                    scanf(" %[^\n]", items[num_items].name);
                    items[num_items].done = 0;
                    num_items++;
                }
                break;
            case 2: // mark an item as done
                printf("Enter the number of the item to mark as done: ");
                int index;
                scanf("%d", &index);
                if(index < 1 || index > num_items) {
                    printf("Error: Invalid index.\n");
                } else {
                    items[index-1].done = 1;
                }
                break;
            case 3: // remove an item
                printf("Enter the number of the item to remove: ");
                int remove_index;
                scanf("%d", &remove_index);
                if(remove_index < 1 || remove_index > num_items) {
                    printf("Error: Invalid index.\n");
                } else {
                    for(int i = remove_index; i < num_items; i++) {
                        strcpy(items[i-1].name, items[i].name);
                        items[i-1].done = items[i].done;
                    }
                    num_items--;
                }
                break;
            case 4: // exit
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &cont);

        getchar(); // clear the input buffer
    } while(cont == 1);

    printf("Goodbye!\n");
    return 0;
}