#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define ArraySize 10000000

int UnsortedLinearSearch(int *array,int randomNumber) {   // n은 array size
    for (int i = 0; i < ArraySize; i++) {
        if (randomNumber == array[i])
        {   
            return i;
        }
    }
    return -1;
}
int BinarySearch(int *array,int data) {  // n은 array size
    int mid;
    int low = 0;
    int high = ArraySize - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == data)
            return mid;
        else if (array[mid] < data)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}



void makeArrayData(int* array)//전체 데이터 배열
{
    for (int i = 0;i < ArraySize;i++)
    {
        array[i] = i * 2;
    }
}
int* makeRandomNumber(int RandomArraySize)//Random 숫자배열을 만드는 함수를 썼습니다.
{
    int* RandomNumberArray = (int*)malloc(sizeof(int) * RandomArraySize);
    srand(time(NULL)); // 매번 다른 시드값 생성
    
    int random;
    for (int i= 0;i < RandomArraySize;i++)
    {
        random = (rand() % ArraySize) * 2; // 0~ArraySize의 2배 크기의 난수를 파라미터 값 만큼 생성
        RandomNumberArray[i] = random;
    }
    return RandomNumberArray;
}
void printArrayData(int *array,int size)
{
    for (int i = 0;i < size;i++) {
        printf("%d, %d\n", i,array[i]);
    }
}

int main(void) {
    int* array = (int*)malloc(sizeof(int) * ArraySize);
    int *RandomArrayforUnsortedLinear;
    int* RandomArrayforBinary;
    printf("[Array Size is %d]\n", ArraySize);
    makeArrayData(array);//배열에 값을 할당해줍니다.
    RandomArrayforUnsortedLinear = makeRandomNumber(1000);//for UnsortedLinearSearch, Random한 숫자 1000개를 만들어 놓습니다.
    //random한 데이터를 찾는 operation을 1000번 수행하기 위한 것입니다. 
    RandomArrayforBinary = makeRandomNumber(100000);//for UnsortedLinearSearch, Random한 숫자 100000개를 만들어 놓습니다.
    //random한 데이터를 찾는 operation을 10만번 수행하기 위한 것입니다.

    //이렇게 한 이유는, Rand함수의 call에 소요되는 시간보다 배열에서 값을 참조해 오는 것이 시간이 더 빠를 것이기 때문에,
    //정확히 정렬에만 소요되는 시간을 보고 싶었습니다.


    //printArrayData(RandomArrayforUnsortedLinear,1000);
    //printf("\n");
    //printArrayData(RandomArrayforBinary,100000);
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 1000; i++) { // 10번 반복
        UnsortedLinearSearch(array, RandomArrayforUnsortedLinear[i]);
    }//1000개의 숫자에 대해 Unsorted Linear Search, 1000번의 UnsortedLinearSearch
    end = clock();
    printf("[UnsortedLinearSearch : %.4lf]\n",(double)(end - start)/1000);


    start = 0;//시간 초기화
    end=0;//시간 초기화
    start = clock();
    for (int i = 0; i < 100000; i++) { // 10번 반복
        BinarySearch(array, RandomArrayforBinary[i]);
    }//100000개의 숫자에 대해 BinarySearch, 숫자가 정렬된 상태이므로, BinarySearch 가능, 각 숫자는 0~200000사이의 짝수
    end = clock();
    printf("[BinarySearch : %.4lf]\n", (double)(end - start) / 100000);


    free(array);
    free(RandomArrayforUnsortedLinear);
    free(RandomArrayforBinary);
}