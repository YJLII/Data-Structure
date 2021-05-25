//201811281 ������ Windows ȯ��
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>

#define COUNT 1//�ʱⰪ
#define HowManyTimeLoop 10000000//��� �ݺ�����
struct DynArrayStack {
    int top;
    int capacity;
    int* array;
};
struct DynArrayStack* CreateStack(int cap) {
    struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
    if (!S)   return NULL;
    S->capacity = cap;  // parameter�� �Է¹޾Ƽ� �ʱ� ���� ����
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if (!S->array) {
        return NULL;
    }
    return S;
}

int DynArrayStackIsFullStack(struct DynArrayStack* S) {
    return (S->top == S->capacity - 1);
}
void DynArrayStackDoubleStack(struct DynArrayStack* S) {
    S->capacity *= 2;
    S->array = (int*)realloc(S->array, S->capacity * sizeof(int));
}
void DynArrayStackPush(struct DynArrayStack* S, int x) {
    //�� ���� ��� ������ �����÷ο찡 �߻����� ����
    if (DynArrayStackIsFullStack(S))
        DynArrayStackDoubleStack(S);
    S->array[++S->top] = x;
}
int DynArrayStackIsEmptyStack(struct DynArrayStack* S) {
    return (S->top == -1);
}
int DynArrayStackTop(struct DynArrayStack* S) {
    if (DynArrayStackIsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top];
}
int DynArrayStackPop(struct DynArrayStack* S) {
    if (DynArrayStackIsEmptyStack(S))
        return INT_MIN;
    return (S->array[S->top--]);
}
void DynArrayStackDeleteStack(struct DynArrayStack* S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}
////////////////////////////////////////////////////////////////////////////////////////
struct ListNode {
    int data;
    struct ListNode* next;
};

struct Stack {
    struct ListNode* top;
};

struct Stack* LinkedListCreateStack() {
    struct Stack* stk;
    stk = (struct Stack*)malloc(sizeof(struct Stack));
    stk->top = NULL;
    return stk;
}
void LinkedListPush(struct Stack* stk, int data) {
    struct ListNode* temp;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!temp)
        return;
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}
int LinkedListIsEmptyStack(struct Stack* stk) {
    return (stk->top == NULL);
}
int LinkedListPop(struct Stack* stk) {
    int data;
    struct ListNode* temp;
    if (LinkedListIsEmptyStack(stk))
        return INT_MIN;
    temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free(temp);
    return data;
}

int LinkedListTop(struct Stack* stk) {
    if (LinkedListIsEmptyStack(stk))
        return INT_MIN;
    return stk->top->data;
}
void LinkedListDeleteStack(struct Stack* stk) {
    struct ListNode* temp, * p;
    p = stk->top;
    while (p) {
        temp = p->next;
        free(p);
        p = temp;
    }
    free(stk);
}
int main()
{
    clock_t start;
    clock_t end;


    struct DynArrayStack* DynamicArraystack = CreateStack(COUNT);//�ʱ� 1 ũ���� ���� ����
    printf("[%d�� ����]\n", HowManyTimeLoop);// ��� ������ �� print

    printf("[DynamicArray push %d��, pop %d�� ����]\n\n", HowManyTimeLoop, HowManyTimeLoop);
    start = clock();//������� ���� ����
    //push�� 100����
    for (int i = 0; i < HowManyTimeLoop;i++)
    {
        if (DynArrayStackIsFullStack(DynamicArraystack))
        {
            DynArrayStackDoubleStack(DynamicArraystack);
        }

        DynArrayStackPush(DynamicArraystack, i);
    }
    //pop�� 100����
    for (int i = 0;i < HowManyTimeLoop;i++)
    {
        if (DynArrayStackIsEmptyStack(DynamicArraystack))
        {
            break;
        }
        DynArrayStackPop(DynamicArraystack);
    }

    end = clock();//�ð� ���� ����
    printf("Time: %d millisec\n\n", end - start);
    printf("[DynamicArray push %d����, pop %d���� ���� �Ϸ�]\n\n", HowManyTimeLoop / 10000, HowManyTimeLoop / 10000);

    printf("[LinkedList push %d����, pop %d���� ����]\n\n", HowManyTimeLoop / 10000, HowManyTimeLoop / 10000);
    struct Stack* LinkedListstack = LinkedListCreateStack();
    start = clock();
    for (int i = 0; i < HowManyTimeLoop;i++)
    {
        LinkedListPush(LinkedListstack, i);
    }
    for (int i = 0;i < HowManyTimeLoop;i++)
    {

        if (LinkedListIsEmptyStack(LinkedListstack))
        {
            break;
        }
        LinkedListPop(LinkedListstack);
    }
    end = clock();
    printf("Time: %d millisec\n\n", end - start);
    printf("[LinkedList push %d����, pop %d���� ���� �Ϸ�]", HowManyTimeLoop / 10000, HowManyTimeLoop / 10000);

    DynArrayStackDeleteStack(DynamicArraystack);
    LinkedListDeleteStack(LinkedListstack);
    return 0;

}