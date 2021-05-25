#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define ArraySize 10000000

int UnsortedLinearSearch(int *array,int randomNumber) {   // n�� array size
    for (int i = 0; i < ArraySize; i++) {
        if (randomNumber == array[i])
        {   
            return i;
        }
    }
    return -1;
}
int BinarySearch(int *array,int data) {  // n�� array size
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



void makeArrayData(int* array)//��ü ������ �迭
{
    for (int i = 0;i < ArraySize;i++)
    {
        array[i] = i * 2;
    }
}
int* makeRandomNumber(int RandomArraySize)//Random ���ڹ迭�� ����� �Լ��� ����ϴ�.
{
    int* RandomNumberArray = (int*)malloc(sizeof(int) * RandomArraySize);
    srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����
    
    int random;
    for (int i= 0;i < RandomArraySize;i++)
    {
        random = (rand() % ArraySize) * 2; // 0~ArraySize�� 2�� ũ���� ������ �Ķ���� �� ��ŭ ����
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
    makeArrayData(array);//�迭�� ���� �Ҵ����ݴϴ�.
    RandomArrayforUnsortedLinear = makeRandomNumber(1000);//for UnsortedLinearSearch, Random�� ���� 1000���� ����� �����ϴ�.
    //random�� �����͸� ã�� operation�� 1000�� �����ϱ� ���� ���Դϴ�. 
    RandomArrayforBinary = makeRandomNumber(100000);//for UnsortedLinearSearch, Random�� ���� 100000���� ����� �����ϴ�.
    //random�� �����͸� ã�� operation�� 10���� �����ϱ� ���� ���Դϴ�.

    //�̷��� �� ������, Rand�Լ��� call�� �ҿ�Ǵ� �ð����� �迭���� ���� ������ ���� ���� �ð��� �� ���� ���̱� ������,
    //��Ȯ�� ���Ŀ��� �ҿ�Ǵ� �ð��� ���� �;����ϴ�.


    //printArrayData(RandomArrayforUnsortedLinear,1000);
    //printf("\n");
    //printArrayData(RandomArrayforBinary,100000);
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 1000; i++) { // 10�� �ݺ�
        UnsortedLinearSearch(array, RandomArrayforUnsortedLinear[i]);
    }//1000���� ���ڿ� ���� Unsorted Linear Search, 1000���� UnsortedLinearSearch
    end = clock();
    printf("[UnsortedLinearSearch : %.4lf]\n",(double)(end - start)/1000);


    start = 0;//�ð� �ʱ�ȭ
    end=0;//�ð� �ʱ�ȭ
    start = clock();
    for (int i = 0; i < 100000; i++) { // 10�� �ݺ�
        BinarySearch(array, RandomArrayforBinary[i]);
    }//100000���� ���ڿ� ���� BinarySearch, ���ڰ� ���ĵ� �����̹Ƿ�, BinarySearch ����, �� ���ڴ� 0~200000������ ¦��
    end = clock();
    printf("[BinarySearch : %.4lf]\n", (double)(end - start) / 100000);


    free(array);
    free(RandomArrayforUnsortedLinear);
    free(RandomArrayforBinary);
}