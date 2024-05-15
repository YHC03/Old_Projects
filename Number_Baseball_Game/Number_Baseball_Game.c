#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
	// inputData: 입력 값, dataTmp100/10/1: 100의 자리수, 10의 자리수, 1의 자리수 임시 저장
	int inputData = 123, dataTmp100 = 1, dataTmp10 = 2, dataTmp1 = 3;
	
	// strikeCount: strike 개수, ballCount: ball 개수, dataTarget: 맞출 값, count: 시도 횟수
	int strikeCount = 0, ballCount = 0, dataTarget = 123, count = 0;

	while (1)
	{
		printf("로딩 중. . . ");

		// random 초기화
		srand(time(NULL));

		// 맞출 값의 백의 자릿수 설정
		dataTmp100 = (rand() % 8) + 1;

		// 맞출 값의 십의 자릿수 설정
		do{
			dataTmp10 = (rand() % 8) + 1;
		} while (dataTmp10 == dataTmp100); // 백의 자릿수와 십의 자릿수가 달라질때까지 반복

		// 맞출 값의 일의 자릿수 설정
		do {
			dataTmp1 = (rand() % 8) + 1;
		} while (dataTmp1 == dataTmp10 || dataTmp1 == dataTmp100); // 백의 자릿수와 일의 자릿수, 그리고 십의 자릿수와 일의 자릿수가 달라질때까지 반복
		
		// 맞출 값 설정
		dataTarget = 100 * dataTmp100 + 10 * dataTmp10 + dataTmp1;

		system("cls");

		// 시도 횟수 초기화
		count=0;

		// 정답시 까지 반복
		while(1)
		{
			// 시도 횟수 증가
			count++;

			// 입력값 받기
			while (1)
			{
				inputData = 0;
				printf("예측할 숫자 입력 : ");
				scanf("%d", &inputData);

				// 입력값이 범위를 넘어가거나, 3자리 숫자 중 같은 숫자가 있는 경우, 재시도
				if (inputData < 123 || inputData>987)
				{
					printf("다시 입력\n");
				}else if ((inputData / 100) == ((inputData % 100) / 10) || (inputData / 100) == (inputData % 10) || ((inputData % 100) / 10) == (inputData % 10) || (inputData / 100) == 0 || ((inputData % 100) / 10) == 0 || (inputData % 10) == 0){
					printf("다시 입력\n");
				}else{
					// 계산 단계로 넘어감
					break;
				}
			}

			// 결괏값 계산
			// strike의 수: 숫자의 위치를 맞춘 개수, ball의 수: 숫자는 맞췄으나 위치를 맞추지는 못한 개수
			strikeCount = ((inputData / 100) == (dataTarget / 100)) + (((inputData % 100) / 10) == ((dataTarget % 100) / 10)) + ((inputData % 10) == (dataTarget % 10));
			ballCount = ((inputData / 100) == ((dataTarget % 100) / 10)) + ((inputData / 100) == (dataTarget % 10)) + (((inputData % 100) / 10) == (dataTarget % 10)) + (((inputData % 100) / 10) == (dataTarget / 100)) + ((inputData % 10) == (dataTarget / 100)) + ((inputData % 10) == ((dataTarget % 100) / 10));
			
			// 결괏값 출력
			printf("%d Strike(s) %d Ball(s)\n", strikeCount, ballCount);

			// 모든 숫자의 위치를 맞춘 경우, 게임 종료
			if(strikeCount == 3)
			{
				break;
			}
		}

		// 시도 횟수 출력
		printf("%d번만에 성공하셨습니다.\n", count);
		system("PAUSE");

		// 화면 초기화
		system("cls");
	}

	return 0;
}
