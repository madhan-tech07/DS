#include <stdio.h>

#define MAX_SIZE 100

void create(int a[], int *n);
void insert(int a[], int *n);
void search(int a[], int n);
void delete(int a[], int *n);
void display(int a[], int n);

int main()
{
    int a[MAX_SIZE], n = 0;
    int choice;

    while (1)
    {
        printf("\n--- ARRAY MENU ---\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create(a, &n);
                break;

            case 2:
                insert(a, &n);
                break;

            case 3:
                search(a, n);
                break;

            case 4:
                delete(a, &n);
                break;

            case 5:
                display(a, n);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

void create(int a[], int *n)
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", n);

    if (*n > MAX_SIZE)
    {
        printf("Array size is too large\n");
        *n = 0;
        return;
    }

    printf("Enter elements:\n");

    for (i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Array created\n");
}

void insert(int a[], int *n)
{
    int element, position, i;

    if (*n == MAX_SIZE)
    {
        printf("Array is full\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &element);

    printf("Enter position: ");
    scanf("%d", &position);

    if (position < 0 || position > *n)
    {
        printf("Invalid position\n");
        return;
    }

    for (i = *n; i > position; i--)
    {
        a[i] = a[i - 1];
    }

    a[position] = element;
    (*n)++;

    printf("Element inserted\n");
}

void search(int a[], int n)
{
    int element, i;

    printf("Enter element to search: ");
    scanf("%d", &element);

    for (i = 0; i < n; i++)
    {
        if (a[i] == element)
        {
            printf("Element found at position %d\n", i);
            return;
        }
    }

    printf("Element not found\n");
}

void delete(int a[], int *n)
{
    int position, i;

    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 0 || position >= *n)
    {
        printf("Invalid position\n");
        return;
    }

    for (i = position; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    (*n)--;

    printf("Element deleted\n");
}

void display(int a[], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}