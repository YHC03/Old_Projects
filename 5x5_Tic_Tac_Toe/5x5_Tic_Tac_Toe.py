board=[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]


def init():                 #초기화 구문
    for i in range(5):
        for j in range(5):
            board[i][j]=0


def printBoard():                   #출력 구문
    print('  | 1 2 3 4 5')
    print('-------------')
    for i in range(5):
        print(str(i+1)+' |',end=' ')
        for j in range(5):
            print(str(board[i][j]),end=' ')
        print('')
    print('')
    for j in range(20):
        print('-',end='')
    print('')
    print('')


def inputData(code):                    #입력 구문
    gx=0
    gy=0
    while True:
        print('플레이어 #'+str(code), end=' ')
        gx=int(input('가로 좌표 입력 : '))
        print('플레이어 #'+str(code), end=' ')
        gy=int(input('세로 좌표 입력 : '))
        if 1<=gx<=5 and 1<=gy<=5:
            if board[gy-1][gx-1]==0:
                board[gy-1][gx-1]=code
                print('')
                return
            else:
                print('지정한 좌표는 이미 사용됨. 다시 입력 필요')
        else:
            print('존재하지 않는 좌표. 다시 입력 필요')


def check():                    #승/패 판단 구문
    for i in range(5):
        if board[i][0]==board[i][1]==board[i][2]==board[i][3]==board[i][4]!=0:
            return board[i][0]
        if board[0][i]==board[1][i]==board[2][i]==board[3][i]==board[4][i]!=0:
            return board[0][i]
    if board[0][0]==board[1][1]==board[2][2]==board[3][3]==board[4][4]!=0:
        return board[0][0]
    if board[0][4]==board[1][3]==board[2][2]==board[3][1]==board[4][0]!=0:
        return board[0][4]
    return 0


def isEnd():                    #무승부 판단 구문
    for i in range(5):
        for j in range(5):
            if board[i][j]==0:
                return False
    return True


p_num=1
print()
print('틱택토 게임 시작')
print()
while True:
    init()
    while True:
        printBoard()
        inputData(p_num)
        result=check()
        if result!=0:
            printBoard()
            print('플레이어 #'+str(result)+' 승리')
            print('')
            for j in range(20):
                print('-',end='')
            print('')
            break
        if isEnd()==True:
            printBoard()
            print('무승부')
            print('')
            for j in range(20):
                print('-',end='')
            print('')
            break
        p_num=3-p_num
    p_num=3-p_num
    print()
    print('새로운 틱택토 게임 시작')
    print()
