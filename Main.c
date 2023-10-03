#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct _node
{
    unsigned int value;
    struct _node *next;
} Node;

void *printLinkedList(Node *head)
{
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
        printf("Prime=%d\n", current->value);
        //printf("Value=%d, Next=%p\n", current->value, current->next);
    }
}

bool isPrime(Node *head, int num)
{
    if (num < 2)
        return false;
    unsigned int half_num = num / 2;

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
        if (num % current->value == 0)
            return false;
        if (current->value > half_num)
            break;
    }

    return true;
}

int main()
{
    long max_value;
    printf("Find primes up to: ");
    scanf("%lu", &max_value);
    
    time_t clock_start = clock();

    Node head = {.value = -1, .next = NULL};

    // Use tail to prevent going through entire linked list to add new value at end 
    Node *tail = &head;

    for (unsigned int i = 0; i < max_value; i++)
    {
        if (isPrime(&head, i))
        {

            Node *nodeNew = (Node *)malloc(sizeof(Node));
            nodeNew->value = i;
            nodeNew->next = NULL;

            tail->next = nodeNew;
            tail = tail->next;
        }
    }

    time_t clock_end = clock();
    double time_taken = (double)(clock_end - clock_start) / CLOCKS_PER_SEC;

    printLinkedList(&head);

    printf("Program took %fs to find prime numbers", time_taken);

    return 0;
}