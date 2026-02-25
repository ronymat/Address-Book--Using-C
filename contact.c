#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

//function for contact validation 
int evaluatephone(AddressBook *addressBook, char mob[])
{
  int i;
  int flag=0;
  if(strlen(mob)!=10)
  {
    printf("Enter a 10 Digit Mobile number\n");
    printf("\n---------------------------------------------------------------------------------------\n");
   return 0;
  }

    for(i=0;i<10;i++)
    {
    if(!(mob[i]>= '0' && mob[i]<= '9'))
    {
       printf("Enter a valid Mobile number");
       printf("\n---------------------------------------------------------------------------------------\n");
       return 0;
    }
    }
    

    for(i=0;i<addressBook->contactCount;i++)
    {
         if(strcmp(addressBook->contacts[i].phone,mob)==0)
         {
        printf("Mobile number exist \nEnter a new mobile number\n");
        printf("\n---------------------------------------------------------------------------------------\n");
        return 0;
        }
    }
    return 1;
  }

 //function for email validation
 int evaluateemail(AddressBook *addressBook,char mail[])
 {
 char st[]={".com"};
 int c,i,count=0;
 if(strstr(mail,"@")==NULL)
 {
     printf("\n---------------------------------------------------------------------------------------\n");
     printf("Enter a valid email id \n");
    return 0;
 }

   c=strlen(mail);
   c=c-4;
   for(i=0;i<4;i++)
   {
       if(mail[c+i]==st[i])
       {
         count++;
       }
   }if(count!=4)
   {
       printf("\n---------------------------------------------------------------------------------------\n");
     printf("Enter a valid email id \n");
    return 0;
   }

   if(mail[c-1]=='@')
   {
       printf("\n---------------------------------------------------------------------------------------\n");
     printf("Enter a valid email id \n");
    return 0;
   }

   for(i=0;i<strlen(mail);i++)
   {
    if(!(mail[i]>='a' && mail[i]<='z' || mail[i]=='.' || mail[i]>='0'&& mail[i]<='9' || mail[i]=='@' || mail[i]=='-' || mail[i]=='_'))
    {
        printf("\n---------------------------------------------------------------------------------------\n");
         printf("Enter a valid email id \n");
    return 0;
    }
   }
  for(i=0;i<addressBook->contactCount;i++)
    {
         if(strcmp(addressBook->contacts[i].email,mail)==0)
         {
             printf("\n---------------------------------------------------------------------------------------\n");
        printf("Email exist \nEnter a new Email id\n");
        return 0;
        }
    }
    return 1;

 }

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    int i,m=1;
   printf("\n==============================================================================================\n");
    printf(" \n\033[1m                                      CONTACT LIST        \033[0m     \n");
   printf("\n==============================================================================================\n");
    printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
    for(i=0;i<addressBook->contactCount;i++)
    {
    printf("\n----------------------------------------------------------------------------------------------\n");
        printf("| %-10d| %-25s| %-25s| %-25s|",m,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        m++;
    }
       printf("\n----------------------------------------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    //Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char ch[25];
    int i=0,valid;
    valid=0;
    while(valid==0)
    {
     getchar();
     printf("Enter the contact name:");
    scanf("%[^\n]",ch);
    valid=1;
    for(i=0;ch[i]!='\0';i++)
    {
      if(!(ch[i]==' ' || (ch[i]>='A'&&ch[i]<='z') || (ch[i]>='a'&&ch[i]<='z')))
      {
        printf("Enter a valid Name\n");
        valid=0;
        break;
      } 
    }
}
strcpy(addressBook->contacts[addressBook->contactCount].name,ch);
addressBook->contactCount++;

char p[20];
valid=0;
while(valid==0)
{
    getchar();
    printf("Enter the Mobile number:");
    scanf("%[^\n]",p);
  if(evaluatephone(addressBook,p)!=0)
  {
      strcpy(addressBook->contacts[addressBook->contactCount-1].phone,p);
      valid=1;
  }
}

char em[50];
valid=0;
while(valid==0)
{
    getchar();
    printf("Enter the Email id :");
    scanf("%[^\n]",em);
    if(evaluateemail(addressBook,em)!=0)
    {
    strcpy(addressBook->contacts[addressBook->contactCount-1].email,em);
      valid=1;
    }
}
}


void searchContact(AddressBook *addressBook)  //Search contact
{
    //Search contact
    int i,j,ch,flag=0,k=0;
    printf("Enter the search choice :\n1.Name\n2.phone\n3.Email\n");
    scanf("%d",&ch);
    getchar();
    switch(ch)
    {
        case 1:
               char n[20]; 
               printf("Enter name :");
               scanf("%[^\n]",n); 
               getchar();
               printf("\n==============================================================================================\n");
                printf(" \n\033[1m                                     SEARCH LIST        \033[0m     \n");
              printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
               for(i=0;i<addressBook->contactCount;i++)
               {
               if(strstr(addressBook->contacts[i].name,n)!=NULL)
                {
                    flag=1;
                    k++;
               printf("\n----------------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s|",k,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }
              printf("\n----------------------------------------------------------------------------------------------\n");

                if(flag==0)
                {
                    printf("\nContact not found");
                }
               
               break;
        case 2:
               char p[20]; 
               printf("Enter phone number :");
               scanf("%[^\n]",p); 
               getchar();
              printf("\n==============================================================================================\n");
               printf(" \n\033[1m                                     SEARCH LIST        \033[0m     \n");
               printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
               for(i=0;i<addressBook->contactCount;i++)
               {
                if(strstr(addressBook->contacts[i].phone,p)!=NULL)
                {
                    flag=1;
                     k++;
              printf("\n----------------------------------------------------------------------------------------------\n");
                     printf("| %-10d| %-25s| %-25s| %-25s|",k,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }
               printf("\n----------------------------------------------------------------------------------------------\n");
                if(flag==0)
                {
                    printf("Contact not found");
                }
               
               break;
        case 3:
               char em[20]; 
               printf("Enter email :");
               scanf("%[^\n]",em); 
               getchar();
             printf("\n==============================================================================================\n");
               printf(" \n\033[1m                                     SEARCH LIST        \033[0m     \n");
             printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");                
               for(i=0;i<addressBook->contactCount;i++)
               {
               if(strstr(addressBook->contacts[i].email,em)!=NULL)
                {
                    flag=1;
                    k++;
               printf("\n----------------------------------------------------------------------------------------------\n");
                     printf("| %-10d| %-25s| %-25s| %-25s",k,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
            }
            printf("\n----------------------------------------------------------------------------------------------\n");
                if(flag==0)
                {
                    printf("Contact not found");
                }
               
               break;
        default :
                 printf("Enter a valid input 1,2 or 3");
                 break;
    }
}

void editContact(AddressBook *addressBook)  //Edit contact
{
     int i,j,ch,flag=0,k=0;
     int a[100];
    printf("\n----------------------------------------------------------------------------------------------\n");
     printf("Enter any of the below for searching the contact to be edited :\n1.Name\n2.Phone\n3.Email\n");
     scanf("%d",&ch);
      printf("\n----------------------------------------------------------------------------------------------\n");
    getchar();
    switch(ch)
    {
        case 1:
               char n[20]; 
               printf("Enter search name :");
               scanf("%[^\n]",n); 
               getchar();
                 printf("\n==============================================================================================\n");
                  printf(" \n\033[1m                                       SEARCH LIST        \033[0m     \n");
                 printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
               for(i=0;i<addressBook->contactCount;i++)
               {
               if(strstr(addressBook->contacts[i].name,n)!=NULL)
                {
                    flag=1;
              printf("\n----------------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s|",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                   a[k]=i;
                    k++;
                }
            }
              printf("\n----------------------------------------------------------------------------------------------\n");

                if(flag==0)
                {
                    printf("\nContact not found");
                }
               
               break;
        case 2:
               char p[20]; 
               printf("Enter phone number :");
               scanf("%[^\n]",p); 
               getchar();
              printf("\n==============================================================================================\n");
               printf(" \n\033[1m                                       SEARCH LIST        \033[0m     \n");
              printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
               for(i=0;i<addressBook->contactCount;i++)
               {
                if(strstr(addressBook->contacts[i].phone,p)!=NULL)
                {
                    flag=1;
                 printf("\n----------------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s|",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    a[k]=i;
                    k++;
                }
            }
                printf("\n----------------------------------------------------------------------------------------------\n");
                if(flag==0)
                {
                    printf("Contact not found");
                }
               
               break;
        case 3:
               char em[20]; 
               printf("Enter email :");
               scanf("%[^\n]",em); 
               getchar();
               printf("\n==============================================================================================\n");
                printf(" \n\033[1m                                       SEARCH LIST        \033[0m     \n");
             printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");                
               for(i=0;i<addressBook->contactCount;i++)
               {
               if(strstr(addressBook->contacts[i].email,em)!=NULL)
                {
                    flag=1;
              printf("\n----------------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s|",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    a[k]=i;
                    k++;
                }
            }
              printf("\n----------------------------------------------------------------------------------------------\n");
                if(flag==0)
                {
                    printf("Contact not found");
                }
               
               break;
        default :
                 printf("Enter a valid input 1,2 or 3");
                 break;
    }
    int choice;
    int contindex;
    do
    {
    printf("\nEnter the Si number corresponding to the name to edit from 1-%d : ",k);
    scanf("%d",&choice);
    printf("\n----------------------------------------------------------------------------------------------\n");
    if(choice<1 || choice>k)
    {
      printf("\nInvalid choice! Please enter between 1 and %d \n",k);
      printf("\n----------------------------------------------------------------------------------------------\n");
    }
    } while(choice<1 || choice>k);
    contindex=a[choice-1];
    printf("\nEditing contact is: %s\n", addressBook->contacts[contindex].name);
     int ed;
    printf("\n----------------------------------------------------------------------------------------------\n");
    printf("\nEnter the edit option :\n1.Name\n2.Phone\n3.Email\n");
    scanf("%d",&ed);
    printf("\n----------------------------------------------------------------------------------------------\n");
    getchar();
    switch(ed)
    {
        case 1:
               char n[20]; 
               printf("Enter new name :");
               scanf("%[^\n]",n);
             printf("\n==============================================================================================\n");
                  printf(" \n\033[1m                                       AFTER EDITING        \033[0m     \n");
              printf("\n==============================================================================================\n");
               getchar();
               strcpy(addressBook->contacts[contindex].name,n);
               printf("%-25s| %-25s| %-25s|","Name","Phone","Email");
               printf("\n---------------------------------------------------------------------------------------\n");
               printf("%-25s| %-25s| %-25s|",addressBook->contacts[contindex].name,addressBook->contacts[contindex].phone,addressBook->contacts[contindex].email);
              printf("\n----------------------------------------------------------------------------------------------\n");
               break;
        case 2:
               char p[20]; 
              int valid=0;
              while(valid==0)
              {
               printf("Enter new phone number :");
               scanf("%[^\n]",p);
               getchar();
            if(evaluatephone(addressBook,p)!=0)
            {
              printf("\n==============================================================================================\n");
                  printf(" \n\033[1m                                       AFTER EDITING        \033[0m     \n");
               printf("\n==============================================================================================\n");
               strcpy(addressBook->contacts[contindex].phone,p);
                printf("%-25s| %-25s| %-25s|","Name","Phone","Email");
                 printf("\n----------------------------------------------------------------------------------------------\n");
               printf("%-25s| %-25s| %-25s|",addressBook->contacts[contindex].name,addressBook->contacts[contindex].phone,addressBook->contacts[contindex].email);
             printf("\n----------------------------------------------------------------------------------------------\n");
             valid=1;
            }
        }  
             break;
        case 3:
               char em[20]; 
               valid=0;
              while(valid==0)
              {
               printf("Enter new Email :");
               scanf("%[^\n]",em);
               getchar();
               if(evaluateemail(addressBook,em)!=0)
               {
               printf("\n==============================================================================================\n");
                  printf(" \n\033[1m                                       AFTER EDITING        \033[0m     \n");
               printf("\n==============================================================================================\n");
               strcpy(addressBook->contacts[contindex].email,em);
               printf("%-25s| %-25s| %-25s|","Name","Phone","Email");
              printf("\n----------------------------------------------------------------------------------------------\n");
               printf("%-25s| %-25s| %-25s|",addressBook->contacts[contindex].name,addressBook->contacts[contindex].phone,addressBook->contacts[contindex].email);
            printf("\n----------------------------------------------------------------------------------------------\n");
            valid=1;
               }
            }  
            break;
        default :
                 printf("Enter a valid input for edit");
                 break;
    }
}


void deleteContact(AddressBook *addressBook)/* Define the logic for deletecontact */
{	
     int i,j,ch,flag=0,k=0;
     int a[100];
    printf("Enter the search choice :\n1.Name\n2.phone\n3.emil\n");
    scanf("%d",&ch);
    getchar();
    switch(ch)
    {
        case 1:
               char n[20]; 
               printf("Enter name :");
               scanf("%[^\n]",n); 
               getchar();
              printf("\n==============================================================================================\n");
                printf(" \n\033[1m                                       SEARCH LIST        \033[0m     \n");
              printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
               for(i=0;i<addressBook->contactCount;i++)
               {
               if(strstr(addressBook->contacts[i].name,n)!=NULL)
                {
                    flag=1;
                printf("\n----------------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                 a[k]=i;
                 k++;
                }
            }
                 printf("\n----------------------------------------------------------------------------------------------\n");

                if(flag==0)
                {
                    printf("\nContact not found");
                }
               
               break;
        case 2:
               char p[20]; 
               printf("Enter phone number :");
               scanf("%[^\n]",p); 
               getchar();
              printf("\n==============================================================================================\n");
                printf(" \n\033[1m                                       SEARCH LIST        \033[0m     \n");
             printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
               for(i=0;i<addressBook->contactCount;i++)
               {
                if(strstr(addressBook->contacts[i].phone,p)!=NULL)
                {
                    flag=1;
                    printf("\n---------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s|",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    a[k]=i;
                    k++;
                }
            }
               printf("\n---------------------------------------------------------------------------------------\n");
                if(flag==0)
                {
                    printf("Contact not found");
                }
               
               break;
        case 3:
               char em[20]; 
               printf("Enter email :");
               scanf("%[^\n]",em); 
               getchar();
               printf("\n==============================================================================================\n");
                printf(" \n\033[1m                                       SEARCH LIST        \033[0m     \n");
              printf("\n==============================================================================================\n");
               printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");                
               for(i=0;i<addressBook->contactCount;i++)
               {
               if(strstr(addressBook->contacts[i].email,em)!=NULL)
                {
                    flag=1;
                    printf("\n----------------------------------------------------------------------------------------------\n");
                    printf("| %-10d| %-25s| %-25s| %-25s|",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    a[k]=i;
                    k++;
                }
            }
               printf("\n----------------------------------------------------------------------------------------------\n");
                if(flag==0)
                {
                    printf("Contact not found");
                }
               
               break;
        default :
                 printf("Enter a valid input 1,2 or 3");
                 break;
    }
    int choice;
    int contindex;
    do
    {
    printf("\nEnter the Si number corresponding to the name to delete from 1-%d : ",k);
    scanf("%d",&choice);
    printf("\n----------------------------------------------------------------------------------------------\n");
    if(choice<1 || choice>k)
    {
      printf("\nInvalid choice! Please enter between 1 and %d \n",k);
       printf("\n----------------------------------------------------------------------------------------------\n");
    }
    } while(choice<1 || choice>k);
contindex=a[choice-1];
printf("\nThe contact to be deleted is: %s\n", addressBook->contacts[contindex].name);
    for(i=contindex;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;
     printf("\n==============================================================================================\n");
     printf("\n                                     After deleting \n");
    int m=1;
    printf("\n==============================================================================================\n");
    printf("| %-10s| %-25s| %-25s| %-25s|","Si.NO","Name","Phone","Email");
    for(i=0;i<addressBook->contactCount;i++)
    {
    printf("\n----------------------------------------------------------------------------------------------\n");
        printf("| %-10d| %-25s| %-25s| %-25s|\n",m,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        m++;
    }
       printf("\n----------------------------------------------------------------------------------------------\n");
}
