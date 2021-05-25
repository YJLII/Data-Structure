//201811281 ������ Windows ȯ��
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define COUNT 1//�ʱⰪ
#define HowManyTimeLoop (int)pow(2, 23)+ 30//��� �ݺ�����
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
int main()
{
    clock_t start;
    clock_t end;


    struct DynArrayStack* DynamicArraystack = CreateStack(COUNT);
    //printf("[ũ�Ⱑ %d�� ��]\n", HowManyTimeLoop);

    //printf("[DynamicArray push %d��]\n\n", HowManyTimeLoop);
    //start = clock();
    clock_t start2;
    clock_t end2;
    for (int i = 0; i < HowManyTimeLoop;i++)//��� �� ������ ���ϱ�
    {
        if (pow(2, 23) - 10 < i && i < pow(2, 23) + 10)//�� ���� �ȿ� ���� ����غ����� �߽��ϴ�.
        {
            start2 = clock();
        }
        if (DynArrayStackIsFullStack(DynamicArraystack))
        {
            DynArrayStackDoubleStack(DynamicArraystack);
        }

        DynArrayStackPush(DynamicArraystack, i);
        if (pow(2, 23) - 10 < i && i < pow(2, 23) + 10)
        {
            end2 = clock();
            printf("ũ�Ⱑ %d�϶� push �ϴµ� �ɸ� �ð�(��ǻ�� ����) %lf\n", i,(double) end2-start2/10000);
        }
    }

    //end = clock();
    //printf("Time: %d millisec\n\n", end - start);
    printf("[DynamicArray push %d�� ���� �Ϸ�]\n\n", HowManyTimeLoop);


    DynArrayStackDeleteStack(DynamicArraystack);
    return 0;

}