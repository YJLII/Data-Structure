#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
#define Question_0 30


void Merge(int A[], int temp[], int left, int right, int right_end);

void BubbleSort(int A[], int n) {
    int swapped = 1;
    for (int pass = n-1; pass > 0 && swapped; pass--) {
        swapped = 0;
        for (int i = 0; i < pass; i++) {
            if (A[i] > A[i + 1]) {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}

void InsertionSort(int A[], int n)
{
    int i, j, key;
    for (i = 1;i < n;i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void Mergesort(int A[], int temp[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        Mergesort(A, temp, left, mid);
        Mergesort(A, temp, mid + 1, right);
        Merge(A, temp, left, mid + 1, right);
    }
}

void Merge(int A[], int temp[], int left, int right, int right_end) {
    int i, j, left_end, size, temp_pos;
    left_end = right - 1;
    size = right_end - left + 1;
    i = left;
    j = right;
    temp_pos = left;
    while ((i <= left_end) && (j <= right_end)) {   // left쪽과 right쪽에서 작은 순서대로 temp[]에 copy
        if (A[i] <= A[j]) {
            temp[temp_pos] = A[i];
            temp_pos = temp_pos + 1;
            i = i + 1;
        }
        else {
            temp[temp_pos] = A[j];
            temp_pos = temp_pos + 1;
            j = j + 1;
        }
    }
    while (i <= left_end) {    // left쪽이 남아있다면
        temp[temp_pos] = A[i];
        temp_pos = temp_pos + 1;
        i = i + 1;
    }
    while (j <= right_end) {      // right쪽이 남아있다면
        temp[temp_pos] = A[j];
        temp_pos = temp_pos + 1;
        j = j + 1;
    }
    for (i = left; i <= right_end; i++) // temp[]에서 A[]로 다시 copy
        A[i] = temp[i];
}


void SelectionSort(int list[], int n) {
    int i, j, least, temp;

    // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
    for (i = 0; i < n - 1; i++) {
        least = i;

        // 최솟값을 탐색한다.
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least])
                least = j;
        }

        // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
        if (i != least) {
            SWAP(list[i], list[least], temp);
        }
    }
}

void QuickSort(int arr[], int left, int right) {
    int i = left, j = right;
    //int pivot = arr[(left + right) / 2];
    int pivot = arr[left];

    int temp;
    do
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    /* recursion */
    if (left < j)
        QuickSort(arr, left, j);

    if (i < right)
        QuickSort(arr, i, right);
}
void RandomizedQuickSort(int arr[], int left, int right) {
    int i = left, j = right;

    int randomN = rand() % right;
    //    int temp1 = arr[randomN];
    //    arr[randomN] = temp1;
    //    arr[left] = temp1;
    int temp3 = 0;
    SWAP(arr[randomN], arr[left], temp3);
    int pivot = arr[left];
    int temp;
    do
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    /* recursion */
    if (left < j)
        QuickSort(arr, left, j);

    if (i < right)
        QuickSort(arr, i, right);
}


int* makeArray(int n)
{
    srand((int)time(NULL));
    int* array = (int*)malloc(sizeof(int) * n);
    for (int i = 0;i < n;i++)
        array[i] = rand() % 100;

    return array;
}
void printArray(int* array, int n)
{
    for (int i = 0;i < n;i++)
    {
        printf("%d ", array[i]);
    }printf("\n");
}

void Question1()
{
    printf("(1) array의 크기가 증가함에 따라서, 평균의 경우 (random data) 각 sorting algorithm의 time complexity를 측정해 보자.\n");
    clock_t start;
    clock_t end;

    for (int i = 10000;i <=100000;i = i + 10000)
    {
 
        printf("==========================Size : %d===================\n",i);
        int* A = malloc(sizeof(int) * i);
        int* B = malloc(sizeof(int) * i);
        int* C = malloc(sizeof(int) * i);
        int* D = malloc(sizeof(int) * i);
        int* E = malloc(sizeof(int) * i);
        //int* F = malloc(sizeof(int) * i);
        int* Temp = malloc(sizeof(int) * i);
        int* ForMergeTemp = malloc(sizeof(int) * i);
        int* Array = makeArray(i);
        for (int k = 0;k < i;k++)
        {
            A[k] = Array[k];
            B[k] = Array[k];
            C[k] = Array[k];
            D[k] = Array[k];
            E[k] = Array[k];
            //F[k] = Array[k];
            Temp[k] = Array[k];
        }
        
        start = clock();
        QuickSort(A, 0, i - 1);
        end = clock();//시간 측정 종료
        printf("QuickSort Time: %ld millisec\n\n", end - start);
        
        start = clock();
        SelectionSort(B, i);
        end = clock();//시간 측정 종료
        printf("SelectionSort Time: %ld millisec\n\n", end - start);
        
        start = clock();
        Mergesort(C, ForMergeTemp, 0, i - 1);
        end = clock();//시간 측정 종료
        printf("Mergesort Time: %ld millisec\n\n", end - start);
        
        start = clock();
        BubbleSort(D, i);
        end = clock();//시간 측정 종료
        printf("BubbleSort Time: %ld millisec\n\n", end - start);
        
        start = clock();
        InsertionSort(E, i);//
        end = clock();//시간 측정 종료
        printf("InsertionSort Time: %ld millisec\n\n", end - start);
        
        //start = clock();
        //RandomizedQuickSort(F, 0, i - 1);
        //end = clock();//시간 측정 종료
        //printf("RandomizedQuickSort Time: %ld millisec\n\n", end - start);
        printf("==========================Size : %d===================\n\n",i);
        free(A);
        free(B);
        free(C);
        free(D);
        free(E);
        //free(F);
        free(Temp);
        free(ForMergeTemp);
        free(Array);
    }
}
void Question0() {

    int i = 0;
    //과제 0번
    printf("(0) (1)번 실험을 진행하기 전에, 각자 구현한 sorting algorithm들이 정확히 동작하는지를 보이시오. (n=30 정도)\n");
    int* hw5_0_1 = malloc(sizeof(int) * Question_0);
    int* hw5_0_2 = malloc(sizeof(int) * Question_0);
    int* hw5_0_3 = malloc(sizeof(int) * Question_0);
    int* hw5_0_4 = malloc(sizeof(int) * Question_0);
    int* hw5_0_5 = malloc(sizeof(int) * Question_0);
    int* hw5_0_6 = malloc(sizeof(int) * Question_0);
    int* hw5_0_temp = malloc(sizeof(int) * Question_0);
    int* formergetemp = malloc(sizeof(int) * Question_0);
    int* hw5_0_Array = makeArray(Question_0);
    for (int i = 0;i < Question_0;i++)
    {
        hw5_0_1[i] = hw5_0_Array[i];
        hw5_0_2[i] = hw5_0_Array[i];
        hw5_0_3[i] = hw5_0_Array[i];
        hw5_0_4[i] = hw5_0_Array[i];
        hw5_0_5[i] = hw5_0_Array[i];
        hw5_0_6[i] = hw5_0_Array[i];
        hw5_0_temp[i] = hw5_0_Array[i];
    }

    QuickSort(hw5_0_1, 0, Question_0 - 1);
    SelectionSort(hw5_0_2, Question_0);
    Mergesort(hw5_0_3, formergetemp, 0, Question_0 - 1);
    BubbleSort(hw5_0_4, Question_0);
    InsertionSort(hw5_0_5, Question_0);//
    RandomizedQuickSort(hw5_0_6, 0, Question_0 - 1);
    printArray(hw5_0_temp, Question_0);
    printArray(hw5_0_1, Question_0);
    printArray(hw5_0_2, Question_0);
    printArray(hw5_0_3, Question_0);
    printArray(hw5_0_4, Question_0);
    printArray(hw5_0_5, Question_0);
    printArray(hw5_0_6, Question_0);
    printf("과제 0번 완료\n");
    free(hw5_0_1);
    free(hw5_0_2);
    free(hw5_0_3);
    free(hw5_0_4);
    free(hw5_0_5);
    free(hw5_0_temp);
    free(formergetemp);
    free(hw5_0_Array);
}
void Question2() {

    printf("(1)번 실험은 데이터들이 random하게 섞여 있는 경우를 가정하였다. 그러나, 몇몇 알고리즘들은 데이터의 상태에 따라 알고리즘의 수행속도가 달라질 수 있다.이러한 점을 실험하여 제시하시오.");
    clock_t start;
    clock_t end;
    for (int i = 10000;i <= 100000;i = i + 10000)
    {
        printf("==========================Size : %d===================\n", i);
        int* A = malloc(sizeof(int) * i);
        int* B = malloc(sizeof(int) * i);
        int* C = malloc(sizeof(int) * i);
        
        int* Array = makeArray(i);
        for (int k = 0;k < i;k++)
        {
            A[k] = Array[k];
            B[k] = Array[k];
            C[k] = Array[k];
            
        }

        QuickSort(A, 0, i - 1);
        //BubbleSort를 위한 한번의 초기화
        start = clock();
        BubbleSort(A, i);
        end = clock();//시간 측정 종료
        printf("Sorted Array, BubbleSort Time: %ld millisec\n\n", end - start);

        start = clock();
        InsertionSort(A, i);//
        end = clock();//시간 측정 종료
        printf("Sorted Array, InsertionSort Time: %ld millisec\n\n", end - start);

        start = clock();
        QuickSort(B, 0, i - 1);
        end = clock();//시간 측정 종료
        printf("UnSorted QuickSort Time: %ld millisec\n\n", end - start);

        start = clock();
        QuickSort(B, 0, i - 1);
        end = clock();//시간 측정 종료
        printf("Sorted QuickSort Time: %ld millisec\n\n", end - start);



        start = clock();
        RandomizedQuickSort(C, 0, i - 1);
        end = clock();//시간 측정 종료
        printf("Unsorted RandomizedQuickSort Time: %ld millisec\n\n", end - start);


        start = clock();
        RandomizedQuickSort(C, 0, i - 1);
        end = clock();//시간 측정 종료
        printf("Sorted RandomizedQuickSort Time: %ld millisec\n\n", end - start);
        printf("==========================Size : %d===================\n\n", i);
        free(A);
        free(B);
        free(C);
        free(Array);
    }
}
int main()
{

    Question0();

    ////과제 1번//
    Question1();

    Question2();
}