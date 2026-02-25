#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    int sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
         printf("\n==============================================================================================\n");
                printf(" \n\033[1m                                      ADDRESS BOOK        \033[0m     \n");
          printf("\n==============================================================================================\n");
        printf("\n    Address Book Menu\n");
        printf("  1. Create contact\n");
        printf("  2. Search contact\n");
        printf("  3. Edit contact\n");
        printf("  4. Delete contact\n");
        printf("  5. List all contacts\n");
    	printf("  6. Save contacts\n");		
        printf("  7. Exit\n");
        printf("Enter your choice: ");
       if (scanf("%d", &choice) != 1)   // Check if scanf successfully read an integer
        {
            printf("Invalid Input\n");
            while (getchar() != '\n');   // clear invalid input from buffer
            continue;                    // restart the loop
        }
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("Saving ...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}
