#include<stdio.h>
//201811281 컴퓨터공학과 이유준입니다.
//Windows 환경에서 작성하였습니다.
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
	int one = 1, two = 1, result = -1;  // one은 n-2, two는n-1 값 
	if (num == 1 || num == 2)  // 1 또는 2면 1을 돌려줌
		return 1;
	else {
		for (int i = 3; i <= num; i++) {
			result = one + two;   // 직전(n-1)과 직직전(n-2) 값을 더해서 돌려줌 
			one = two;      // 직직전(n-2) = 직전(n-1)
			two = result;     // 직전(n-1) = 현재값(now)  
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
		inputNum *= i;//iteration을 이용한 순차적 반복
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
		
		printf("%lld! = ",inputNum + i);//그 후 증가 값에 대한 팩토리얼 값
		IterationVersion(inputNum + i);
	}
	printf("iteration 수행 완료\n");
	/////////////////////////////
	printf("\n2. Recursion_Result\n");
	for(unsigned long long int i=0;i<10;i++)	
		printf("%lld! = %lld\n",inputNum+i,RecursionVersion(inputNum+i));


	/////////////////////////////
	printf("recursion 수행 완료\n\n");
	inputNum = 1;

	printf("\n3. Fibonacci_Result\n");
	for (int i = 0;i < 10;i++)
		printf("Fibonacci(%lld) 재귀 함수를 통한 출력 : %lld, 반복 함수를 통한 출력 : %lld\n", inputNum + i, recurfib(inputNum + i), iterfib(inputNum + i));


	printf("\n값이 4000일때 팩토리얼의 iteration연산과 Recursive연산\n");
	printf("%lld", RecursionVersion(4000));
	IterationVersion(4000);
	printf("결과값은 중요하지 않으므로 정상 종료 유무 판별, 연산 정상 종료\n");
	
	printf("값을 5000을 넣었을 때, iteration\n");
	IterationVersion(5000);
	printf("연산 정상 종료\n");
	printf("값을 5000을 넣었을 때, Recursion\n");
	printf("%lld", RecursionVersion(5000));
	//밑의 구문이 실행되지 않음으로 Recursion Version은 정상 종료가 되지 않았습니다.
	printf("연산 정상 종료\n");
	return 0;

}