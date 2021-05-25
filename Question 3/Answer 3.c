//201811281 이유준 Windows 환경
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define COUNT 1//초기값
#define HowManyTimeLoop (int)pow(2, 23)+ 30//몇번 반복할지
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
int main()
{
    clock_t start;
    clock_t end;


    struct DynArrayStack* DynamicArraystack = CreateStack(COUNT);
    //printf("[크기가 %d일 때]\n", HowManyTimeLoop);

    //printf("[DynamicArray push %d번]\n\n", HowManyTimeLoop);
    //start = clock();
    clock_t start2;
    clock_t end2;
    for (int i = 0; i < HowManyTimeLoop;i++)//몇번 할 것인지 정하기
    {
        if (pow(2, 23) - 10 < i && i < pow(2, 23) + 10)//이 범위 안에 값만 출력해보려고 했습니다.
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
            printf("크기가 %d일때 push 하는데 걸린 시간(컴퓨터 기준) %lf\n", i,(double) end2-start2/10000);
        }
    }

    //end = clock();
    //printf("Time: %d millisec\n\n", end - start);
    printf("[DynamicArray push %d번 수행 완료]\n\n", HowManyTimeLoop);


    DynArrayStackDeleteStack(DynamicArraystack);
    return 0;

}