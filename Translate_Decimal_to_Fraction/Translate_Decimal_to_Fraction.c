#include<stdio.h>
#include<math.h>


// 입력받은 정수 input이 10의 몇승 자리까지 올라가는지 반환
int countDec(int input)
{
	double targ = input;
	int result = 1;

	while(targ >= 10)
	{
		result++;
		targ /= 10;
	}
	return result;
} 


// 입력받은 실수 input이 정수인지의 여부를 반환
int isint(long double input)
{
	long double result = input;

	// 0부터 input값보다 작은 최대의 자연수까지 반복하여, result의 값을 1씩 줄이기
	for(int i = 0; i < input; i++)
	{
		result -= 1;
	}

	// result가 0인 경우, input은 정수이다.
	return !result;
}


// 입력된 소수 input이 소수 몇째 자리인지 반환
int countV(int prev, long double input)
{
	return isint(input) ? prev : countV(prev + 1, input * 10);
}


// 분자와 분모값이 서로소가 되도록 한 후, 해당 분자와 분모의 값을 분수 형식으로 출력
void processAndPrintResult(int upper, int under)
{
	int flag = 1;
	int sizeofUpper = 0, sizeofUnder = 0;

	// 입력된 분모와 분자가 서로소가 아닌 경우, 이를 처리함. 소수는 2와 5로만 해당 식을 처리하면 된다.
	do{
		flag = 0; // 반복 여부 확인
		if(upper % 5 == 0 && under % 5 == 0) // 분모, 분자가 모두 5로 나누어떨어지는 경우
		{
			flag = 1; // 다음 반복을 예약한다.

			// 분모와 분자를 모두 5로 나누어준다.
			upper /= 5;
			under /= 5;
		}
		if(upper %2 == 0 && under % 2 == 0){ // 분모, 분자가 모두 2로 나누어떨어지는 경우
			flag = 1; // 다음 반복을 예약한다.

			// 분모와 분자를 모두 2로 나누어준다.
			upper /= 2;
			under /= 2;
		}
	}while(flag);

	// 분자의 값 출력
	printf("%d\n", upper);

	// 분모, 분자의 값 중, 10의 몇승 자리까지 올라가는지를 계산
	sizeofUpper = countDec(upper);
	sizeofUpper = countDec(upper);
	sizeofUnder = countDec(under);

	// sizeofUpper, sizeofUnder의 값 중, 더 큰 값만큼 '-'를 출력
	for(int i = 0; i < (sizeofUpper > sizeofUnder ? sizeofUpper : sizeofUnder); i++)
	{
		printf("-");
	}

	// 개행 후, 분모의 값 출력
	printf("\n%d\n", under);

	return;
}

int main()
{
	long double inputNum = 0; // 입력 값
	int decimalLength, upperValue, underValue; // decimalLength: 입력받은 소수의 자릿수, upperValue: 분자의 값, underValue: 분모의 값

	while(1)
	{
		printf("Enter a decimal number : ");
		scanf("%lf", &inputNum);

		// 0.001 = 1/1000인것과 같이, 분모는 10의 소수의 자릿수로 표현할 수 있음
		decimalLength = countV(0, inputNum);
		underValue = pow(10, decimalLength);

		// 분자는 입력받은 수와 10^(입력받은 소수의 자릿수)의 곱이다. 예를 들어, 3.14 = 314/100에서, 3.14 * 100 = 314 
		upperValue = inputNum * underValue;

		// 분자와 분모의 값이 모두 2와 5의 배수가 아닐때까지 각각 2와 5로 나누고, 그 값을 출력한다.
		processAndPrintResult(upperValue, underValue);
	}
	return 0;
}
