/*3. Create a Book structure containing book_id, title, author name and price.
 Write a C program to pass a structure as a function argument and print the
 book details.*/
#include <stdio.h>
struct book_details
{
    long int book_id;
    char title[50];
    char author_name[20];
    float price;
};
void print_book_details(struct book_details book) 
{
    printf("----------------------------------------------------------\n");
    printf("Book ID: %ld\n", book.book_id);
    printf("Title of the book: %s\n", book.title);
    printf("Author of the book: %s\n", book.author_name);
    printf("Price of the book: %.2f\n", book.price);
    printf("\n");
}
int n;
void main()
{
    printf("Enter the number of book entries you want to do:");
    scanf("%d", &n);
    struct book_details book[n];
    printf("\nEnter the details of book:\n");
    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter book-%d ID no.:\n",i+1);
        scanf("%ld", &book[i].book_id);
        getchar();
        printf("Enter book-%d name:\n",i+1);
        scanf("%[^\n]%*c", book[i].title);
        printf("Enter book-%d author name:\n",i+1);
        scanf("%[^\n]%*c", book[i].author_name);
        printf("Enter book-%d price:\n",i+1);
        scanf("%f", &book[i].price);
    }
    printf("\n");
    printf("\nBook Details:\n");
    for (int i = 0; i < n; i++)
    {
        print_book_details(book[i]);
    }
}
