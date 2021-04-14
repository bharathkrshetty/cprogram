#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice=0,i;

    printf("\n\t\t---Library Management System---\n");
    do{
    printf("\n\t--MENU--\n \n 1. Add A New Book\n 2. Search a book \n 3. Display Complete Information\n 4. Display All Books of An Author\n 5. List Titles of a Book\n 6.Exit the program\n\n\t Enter your choice <1-10>: ");
    scanf("%i",&choice);

    switch (choice)
    {
        case 1:
            Addbook();
            break;
        case 2:
            Searchbook();
            break;
        case 3:
            Displaybook();
            break;
        case 4:
            Author();
            break;
        case 5:
            Titlelist();
            break;
        case 6:
            Exit();
        default:
            printf(" ! Invalid Input...\n");
    }
}while(choice!=10);
 return (0);
}

void Exit()
{
  exit(0);
}