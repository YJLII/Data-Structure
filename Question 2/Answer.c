//201811281 이유준, windows
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#define N 100000

struct ListNode {
    int data;
    struct ListNode* next;
};//구조체 선언

void insertion(int* array, int i)
{
    array[i] = i;
}
//1-1 Array Insertion

void InsertInLinkedList(struct ListNode** h, int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    struct ListNode* current;
    current = *h;
    newNode->next = current->next;
    current->next = newNode;
}
//1-1 Linked List Insertion

int LinkedListRandomSum(struct ListNode** h, int index)
{
    struct ListNode* current = *h;
    current = current->next;
    while (index > 0)
    {
        current = current->next;
        index--;
    }
    return current->data;
}
//1-2 LinkedListRandomSum

int* ArrayRandomDeletion(int* array, int index, int size)
{
    int* array2 = malloc(sizeof(int) * size);
    int j = 0;
    for (int i = 0;i < size;i++)
    {
        if (i == index)
        {
            j++;
        }
        array2[i] = array[j];
        j++;
    }
    free(array);
    return array2;

}
//1-3 ArrayDeletion

/*
void printLinkedList(struct ListNode** h)
{
    struct ListNode* current = *h;
    current = current->next;
    while (current->next!=NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}*/
void LinkedListRandomDeletion(struct ListNode** h, int index)
{
    struct ListNode* current = *h;
    current = current->next;
    struct ListNode* previous = *h;
    while (index > 0)
    {
        current = current->next;
        previous = previous->next;
        index--;
    }
    previous->next = current->next;
    free(current);
}
//1-3 LinkedList Deletion
int main(void) {
    printf("[N : %d]\n", N);
    clock_t start;
    clock_t end;


    printf("[Array Insertion]\n\n");
    int start2 = 0;//중간중간 시간 분할 측정을 위해 선언
    /* 시간을 측정하고자 하는 코드 시작 */
    //Insertion
    int size = N;
    int* array = malloc(sizeof(int) * size);

    for (int i = 0;i < N;i++)
    {
        if (i == 0)
        {
            start = clock();
            start2 = start;
        }
        if (i % 10000 == 0 && i > 0)
        {
            end = clock();
            printf("[Array Insertion ~%d]\n", i - 1);
            printf("Time: %d millisec\n", end - start2);
            start2 = end;
        }
        insertion(array, i);
    }
    end = clock();
    printf("[Array Insertion ~%d]\n", N - 1);
    printf("Time: %d millisec\n", end - start2);
    /* 시간을 측정하고자 하는 코드 끝 */
    printf("\n[Time:0~%d : %d millisec]\n\n\n", N - 1, end - start);








    printf("[LinkedListArray Insertion]\n\n");
    struct ListNode* LinkedListArray = (struct ListNode*)malloc(sizeof(struct ListNode));
    LinkedListArray->next = NULL;
    for (int i = 0;i < N;i++)
    {
        if (i == 0)
        {
            start = clock();
            start2 = start;
        }
        if (i % 10000 == 0 && i > 0)
        {
            end = clock();
            printf("[LinkedList Insertion ~%d]\n", i - 1);
            printf("Time: %d millisec\n", end - start2);
            start2 = end;
        }
        InsertInLinkedList(&LinkedListArray, i);

    }
    end = clock();
    printf("[LinkedList Insertion ~%d]\n", N - 1);
    printf("Time: %d millisec\n", end - start2);
    /* 시간을 측정하고자 하는 코드 끝 */

    printf("\n[Time:0~%d : %d millisec]\n\n\n", N-1, end - start);














    printf("[Random access for read Array]\n");
    start = clock();
    srand(time(NULL));
    long long int sum1 = 0;
    for (int i = 0;i < N;i++)
    {
        sum1 += array[(rand() * 10) % N];//1-2 Array random read *********************************
    }
    end = clock();
    printf("Time: %d millisec\n", end - start);



    start = clock();
    /* 시간을 측정하고자 하는 코드 시작 */
    printf("[Random access for read LinkedList]\n");
    long long int sum2 = 0;
    srand(time(NULL));
    for (int i = 0;i < N;i++)
    {
        sum2 += LinkedListRandomSum(&LinkedListArray, (rand() * 10) % N);
    }
    /* 시간을 측정하고자 하는 코드 끝 */
    end = clock();
    printf("Time: %d millisec\n\n", end - start);






    /* 시간을 측정하고자 하는 코드 시작 */
    printf("[Random access for deletion array]\n");
    srand(time(NULL));
    for (int i = N - 1;i > 0;i--)
    {
        if (i == 99999) {
            start = clock();
            start2 = start;
        }
        if (i % 10000 == 0)
        {
            end = clock();
            printf("[Array deletion ~%d]\n", i);
            printf("Time: %d millisec\n", end - start2);
            start2 = end;
        }
        array = ArrayRandomDeletion(array, ((rand() * 10) % i), --size);
    }
    ///* 시간을 측정하고자 하는 코드 끝 */
    printf("[Array deletion ~%d]\n", 0);
    end = clock();
    printf("Time: %d millisec\n", end - start2);

    printf("0~99999 Time: %d millisec\n\n", end - start);





    /* 시간을 측정하고자 하는 코드 시작 */
    printf("[Random access for deletion LinkedList]\n");
    srand(time(NULL));
    for (int i = N - 1;i > 0;i--)
    {
        if (i == 99999) {
            start = clock();
            start2 = start;
        }
        if (i % 10000 == 0)
        {
            end = clock();
            printf("[LinkedList deletion ~%d]\n", i);
            printf("Time: %d millisec\n", end - start2);
            start2 = end;
        }


        LinkedListRandomDeletion(&LinkedListArray, (rand() * 3) % i);
    }
    printf("[LinkedList deletion ~%d]\n", 0);
    end = clock();
    printf("Time: %d millisec\n", end - start2);

    printf("0~99999 Time: %d millisec\n", end - start);



    return 0;
}
