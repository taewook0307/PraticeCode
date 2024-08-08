// 240808_64061.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

// 크레인 인형뽑기 게임

/*
문제 설명
게임 화면은 "1 x 1" 크기의 칸들로 이루어진 "N x N" 크기의 정사각 격자이며 위쪽에는 크레인이 있고 오른쪽에는 바구니가 있습니다.
각 격자 칸에는 다양한 인형이 들어 있으며 인형이 없는 칸은 빈칸입니다.
모든 인형은 "1 x 1" 크기의 격자 한 칸을 차지하며 격자의 가장 아래 칸부터 차곡차곡 쌓여 있습니다.
게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을 집어 올릴 수 있습니다.
집어 올린 인형은 바구니에 쌓이게 되는 데, 이때 바구니의 가장 아래 칸부터 인형이 순서대로 쌓이게 됩니다.

만약 같은 모양의 인형 두 개가 바구니에 연속해서 쌓이게 되면 두 인형은 터뜨려지면서 바구니에서 사라지게 됩니다.
위 상태에서 이어서 [5번] 위치에서 인형을 집어 바구니에 쌓으면 같은 모양 인형 두 개가 없어집니다.

게임 화면의 격자의 상태가 담긴 2차원 배열 board와
인형을 집기 위해 크레인을 작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때,
크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.
*/

int solution(std::vector<std::vector<int>> board, std::vector<int> moves) {
    int answer = 0;

    std::stack<int> PickResult;

    const int BoardColumnCount = board.size();
    const int BoardRowCount = board[0].size();

    for (int PickLine : moves)
    {
        int SelectLine = PickLine - 1;

        for (int i = 0; i < BoardRowCount; ++i)
        {
            int PickDoll = board[i][SelectLine];

            if (0 != PickDoll)
            {
                if (false == PickResult.empty())
                {
                    if (PickDoll != PickResult.top())
                    {
                        // 인형 뽑기
                        PickResult.push(PickDoll);
                    }
                    else
                    {
                        PickResult.pop();
                        answer += 2;
                    }
                }
                else
                {
                    // 인형 뽑기
                    PickResult.push(PickDoll);
                }

                // 뽑은 위치 0으로 변경
                board[i][SelectLine] = 0;
                break;
            }
        }
    }

    return answer;
}

void PrintResult(std::vector<std::vector<int>> board, std::vector<int> moves)
{
    int Result = solution(board, moves);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<std::vector<int>> board0 = { { 0,0,0,0,0 }, { 0,0,1,0,3 }, { 0,2,5,0,1 }, { 4,2,4,4,2 }, { 3,5,1,3,1 } };
    std::vector<int> moves0 = { 1,5,3,5,1,2,1,4 };

    PrintResult(board0, moves0);
}
