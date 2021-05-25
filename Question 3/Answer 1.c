//201811281 이유준 Windows 환경
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>

#define COUNT 1//초기값
#define HowManyTimeLoop 10000000//몇번 반복할지
struct DynArrayStack {
    int top;
    int capacity;
    int* array;
};
struct DynArrayStack* CreateStack(int cap) {
    struct DynArrayStack* S = (struct DynArrayStack*)malloc(sizeof(struct DynArrayStack));
    if (!S)   return NULL;
    S->capacity = cap;  // parameter로 입력받아서 초기 값을 조절
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
    //이 구현 방식 에서는 오버플로우가 발생하지 않음
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


    struct DynArrayStack* DynamicArraystack = CreateStack(COUNT);//초기 1 크기의 스택 생성
    printf("[%d번 수행]\n", HowManyTimeLoop);// 몇번 수행할 지 print

    printf("[DynamicArray push %d번, pop %d번 수행]\n\n", HowManyTimeLoop, HowManyTimeLoop);
    start = clock();//수행시작 측정 시작
    //push를 100만번
    for (int i = 0; i < HowManyTimeLoop;i++)
    {
        if (DynArrayStackIsFullStack(DynamicArraystack))
        {
            DynArrayStackDoubleStack(DynamicArraystack);
        }

        DynArrayStackPush(DynamicArraystack, i);
    }
    //pop을 100만번
    for (int i = 0;i < HowManyTimeLoop;i++)
    {
        if (DynArrayStackIsEmptyStack(DynamicArraystack))
        {
            break;
        }
        DynArrayStackPop(DynamicArraystack);
    }

    end = clock();//시간 측정 종료
    printf("Time: %d millisec\n\n", end - start);
    printf("[DynamicArray push %d만번, pop %d만번 수행 완료]\n\n", HowManyTimeLoop / 10000, HowManyTimeLoop / 10000);

    printf("[LinkedList push %d만번, pop %d만번 수행]\n\n", HowManyTimeLoop / 10000, HowManyTimeLoop / 10000);
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
    printf("[LinkedList push %d만번, pop %d만번 수행 완료]", HowManyTimeLoop / 10000, HowManyTimeLoop / 10000);

    DynArrayStackDeleteStack(DynamicArraystack);
    LinkedListDeleteStack(LinkedListstack);
    return 0;

}