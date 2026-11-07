
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];
int isOccupied[SIZE] = {0};

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    int start = index;

    do
    {
        if(isOccupied[index] == 0)
        {
            hashTable[index] = key;
            isOccupied[index] = 1;

            printf("Key %d inserted at index %d\n", key, index);
            return;
        }

        if(hashTable[index] == key)
        {
            printf("Key already exists!\n");
            return;
        }

        index = (index + 1) % SIZE;

    } while(index != start);

    printf("Hash table is full!\n");
}

void search(int key)
{
    int index = hashFunction(key);
    int start = index;

    do
    {
        if(isOccupied[index] == 0)
        {
            printf("Key not found!\n");
            return;
        }

        if(hashTable[index] == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

    } while(index != start);

    printf("Key not found!\n");
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++)
    {
        if(isOccupied[i])
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : Empty\n", i);
    }
}

int main()
{
    int choice, key;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
