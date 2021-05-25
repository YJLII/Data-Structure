#include<stdio.h>
//201811281 ��ǻ�Ͱ��а� �������Դϴ�.
//Windows ȯ�濡�� �ۼ��Ͽ����ϴ�.
unsigned long long int RecursionVersion(unsigned long long int inputNum)
{
	if (inputNum ==1)
	{
		return 1;
	}
	return inputNum * RecursionVersion(inputNum - 1);
}
unsigned long long int iterfib(unsigned long long int num)
{
	int one = 1, two = 1, result = -1;  // one�� n-2, two��n-1 �� 
	if (num == 1 || num == 2)  // 1 �Ǵ� 2�� 1�� ������
		return 1;
	else {
		for (int i = 3; i <= num; i++) {
			result = one + two;   // ����(n-1)�� ������(n-2) ���� ���ؼ� ������ 
			one = two;      // ������(n-2) = ����(n-1)
			two = result;     // ����(n-1) = ���簪(now)  
		}
	}
	return result;
}
unsigned long long int recurfib(unsigned long long int num)
{
	if (num <= 1)
	{
		return num;
	}
	else
	{
		return recurfib(num - 1) + recurfib(num - 2);
	}
}
void IterationVersion(unsigned long long int inputNum)
{
	for (int i = inputNum - 1;i > 0;i--)
	{
		inputNum *= i;//iteration�� �̿��� ������ �ݺ�
	}
	printf("%lld\n", inputNum);
}


int main(int argc, char* argv[])
{
	unsigned long long int inputNum = 1;
	/////////////////////////////
	printf("1. Iteration_Result\n");
	for (int i = 0;i < 10;i++)
	{
		
		printf("%lld! = ",inputNum + i);//�� �� ���� ���� ���� ���丮�� ��
		IterationVersion(inputNum + i);
	}
	printf("iteration ���� �Ϸ�\n");
	/////////////////////////////
	printf("\n2. Recursion_Result\n");
	for(unsigned long long int i=0;i<10;i++)	
		printf("%lld! = %lld\n",inputNum+i,RecursionVersion(inputNum+i));


	/////////////////////////////
	printf("recursion ���� �Ϸ�\n\n");
	inputNum = 1;

	printf("\n3. Fibonacci_Result\n");
	for (int i = 0;i < 10;i++)
		printf("Fibonacci(%lld) ��� �Լ��� ���� ��� : %lld, �ݺ� �Լ��� ���� ��� : %lld\n", inputNum + i, recurfib(inputNum + i), iterfib(inputNum + i));


	printf("\n���� 4000�϶� ���丮���� iteration����� Recursive����\n");
	printf("%lld", RecursionVersion(4000));
	IterationVersion(4000);
	printf("������� �߿����� �����Ƿ� ���� ���� ���� �Ǻ�, ���� ���� ����\n");
	
	printf("���� 5000�� �־��� ��, iteration\n");
	IterationVersion(5000);
	printf("���� ���� ����\n");
	printf("���� 5000�� �־��� ��, Recursion\n");
	printf("%lld", RecursionVersion(5000));
	//���� ������ ������� �������� Recursion Version�� ���� ���ᰡ ���� �ʾҽ��ϴ�.
	printf("���� ���� ����\n");
	return 0;

}