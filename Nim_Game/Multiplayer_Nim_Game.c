#include<stdio.h>
#include<stdlib.h> //rand() 사용을 위함
#include<time.h>  //rand() 초기화(srand() 사용)를 위함


// 플레이어의 수를 입력받는다.
int getPlayerNo()
{
	int players; // 입력받은 플레이어의 수를 저장하는 변수

	printf("플레이어 수를 입력하십시오.(2~50) : ");
	do{
		scanf("%d", &players);
		if(players >= 2 && players <= 50)
			break;
		
		printf("플레이어 수를 다시 입력하십시오.(2~50) : ");
	} while (players < 2 || players>50);

	return players;
}


// 탈락 숫자를 입력받는다.
int getFailNum()
{
	int tmp, MAX; // tmp: 임시 변수, MAX: 실제 탈락 숫자를 저장하는 변수

	srand(time(NULL));

	do{
		printf("탈락 숫자를 랜덤 입력하시겠습니까?\n1-예\n0-아니오\n: ");
		scanf("%d", &tmp);

		if(tmp == 1) // 랜덤 입력받는 경우
		{
			// 랜덤 최댓값을 입력받는다.
			printf("가능한 탈락 숫자의 최댓값을 입력하십시오(3~3000) : ");

			do{
				scanf("%d", &tmp);
				if(tmp >= 3 && tmp <= 3000)
					break;
		
				printf("다시 입력하십시오(3~3000) : ");
			} while (tmp < 3 || tmp>3000);

			// 실제 아웃 숫자를 결정한다.
			MAX = (int)(rand() % (tmp - 2)) + 2;
			break;

		}else if(!tmp){ // 직접 입력받는 경우
			// 실제 탈락 숫자를 입력받는다.
			printf("탈락 숫자를 입력하십시오(2~3000) : ");

			do{
				scanf("%d", &tmp);
				if(tmp >= 2 && tmp <= 3000)
					break;
			
				printf("다시 입력하십시오(2~3000) : ");
			} while (tmp < 2 || tmp>3000);

			MAX = tmp;
			break;
		}else{
			printf("다시 입력하십시오.\n");
		}
	}while(tmp != 0 && tmp != 1);

	// 탈락 숫자 정보를 출력한다.
	printf("탈락 숫자는 %d입니다.\n", MAX); 

	return MAX;
}


// 한번에 증가시킬 수 있는 수를 입력받는다.
int getMaxIn(int MAX)
{
	int maxin; // 최대 입력 가능 수를 저장하는 변수

	printf("1회에 최대로 증가시킬 수 있는 수를 입력하십시오(1~%d, 추천 수 : ", MAX - 1);

	do{
		// 추천하는 수 출력, 탈락 숫자가 2이면 1, 30 미만의 숫자이면 2, 그 외의 경우 탈락 숫자의 1/10 값이다. 
		printf("%d) : ", MAX < 30 ? (MAX == 2 ? 1 : 2) : (int)(MAX / 10));

		scanf("%d", &maxin);

		if(maxin >= (MAX == 2 ? 1 : 2) && maxin < MAX)
			break;
	
		printf("다시 입력하십시오(1~%d, 추천 수 : ", MAX - 1);
	} while (maxin < (MAX == 2 ? 1 : 2) || maxin >= MAX);

	return maxin;
}


// 시작 플레이어의 번호를 부여
int playerStartSettings(int players)
{
	int tmp; // 입력받은 랜덤 설정의 여부를 저장하는 변수

	do{
		// 랜덤 설정 여부
		printf("시작 플레이어를 랜덤 설정하시겠습니까?\n1-예\n0-아니오(플레이어 No.1부터 시작)\n: ");
		scanf("%d", &tmp);

		if(tmp == 1) // 랜덤 설정 시
		{
			return (int)(rand() % players) + 1;
		}else if(!tmp){ // 1번부터 시작 시
			return 1;
		}else{ // 잘못 입력한 경우
			printf("다시 입력해주십시오.\n");
		}

	}while(tmp != 0 && tmp != 1);

	// 오류로 인해 이 위치에 도달한 경우, 1번부터 시작하는 것으로 가정한다.
	return 1;
}


int main()
{
	// MAX: 탈락 숫자, maxin: 최대 입력 가능 숫자
	int MAX = 20, maxin = 3;

	// players: 총 플레이어 수, playerNo: 현재 플레이어의 번호, curr: 현재 진행 위치
	int players = 0, playerNo = 0, curr = 0;

	// tmp: 입력값을 임시 저장하는 변수, loserNum: 패자의 플레이어 번호, winnerNum, 승자의 플레이어 번호
	int tmp = 0, loserNum = 0, winnerNum = 0;

	srand(time(NULL)); // Random 초기화
	printf("님 게임\n");
	
	// 초기 설정 진행
	players = getPlayerNo(); // 플레이어 수 입력
	MAX = getFailNum(); // 탈락 숫자 가져오기
	maxin = getMaxIn(MAX); // 1회에 최대로 증가시킬 수 있는 수 가져오기
	playerNo = playerStartSettings(players); // 시작 플레이어 설정

	// 무한 반복
	while(1)
	{
		printf("시작 플레이어 : No.%d\n", playerNo);

		while(curr < MAX) // 게임 진행
		{
			printf("현재 값 : %d\n남은 수 : %d\n", curr, MAX - curr);

			// 현재의 플레이어 번호가 플레이어의 수보다 많은 경우, 1번 플레이어부터 다시 시작
			if(playerNo > players)
				playerNo = 1;
			
			// 해당 플레이어의 값을 받는다.
			printf("No.%d", playerNo);
			do{
				printf(" 입력(1~%d) : ", maxin);
				scanf("%d", &tmp);
				if(tmp <= maxin && tmp >= 1)
					break;
				
				printf("다시");
			} while (tmp > maxin || tmp < 1);

			// 입력받은 값을 현재값에 추가한다.
			curr += tmp;

			// 다음 플레이어로 이동한다.
			playerNo++;
		}

		// 승자와 패자 계산
		loserNum = playerNo - 1;
		winnerNum = playerNo - 2;
		if(loserNum < 1) // 패자의 번호가 1 미만인 경우(Underflow). 즉 패자의 번호가 0인 경우.
		{
			loserNum = players; // 패자의 번호는 플레이어의 수, 승자의 번호는 패자의 번호 - 1
			winnerNum = players - 1;
		}else if(winnerNum < 1){ // 승자의 번호가 0인 경우
			winnerNum = players; // 승자의 번호는 플레이어의 수
		}
		// 결과 출력
		printf("패배 : No.%d, 승리 : No.%d\n", loserNum, winnerNum);

		// 현재값 초기화
		curr = 0;

		// 재설정 완료시까지 무한 반복
		while(1)
		{
			printf("다음 게임 시작 시 현재 설정을 유지하시겠습니까?\n1-예\n0-아니오\n: ");
			scanf("%d", &tmp);

			if(tmp == 1) // 기존 설정 유지 시
			{
				system("cls");
				
				// 기존 설정값 출력
				printf("---기존 설정---\n플레이어 수 : %d\n탈락 숫자 : %d\n1회 최대 입력 가능 수 : %d\n", players, MAX, maxin);

				// 시작 플레이어 설정
				playerNo = playerStartSettings(players);

				// 재시작
				break;

			}else if(tmp == 0){ // 설정 초기화 시
				// 초기 설정 진행
				players = getPlayerNo(); // 플레이어 수 입력
				MAX = getFailNum(); // 탈락 숫자 가져오기
				maxin = getMaxIn(MAX); // 1회에 최대로 증가시킬 수 있는 수 가져오기
				playerNo = playerStartSettings(players); // 시작 플레이어 설정

				// 재시작
				break;

			}else{ // 잘못된 값이 입력된 경우
				printf("다시 입력해주십시오\n");
			}
		}

		system("cls");
	}
	return 0;
}