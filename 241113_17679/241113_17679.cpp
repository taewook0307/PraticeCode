// 241113_17679.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [1차] 프렌즈4블록

/*
문제설명
블라인드 공채를 통과한 신입 사원 라이언은 신규 게임 개발 업무를 맡게 되었다. 이번에 출시할 게임 제목은 "프렌즈4블록".
같은 모양의 카카오프렌즈 블록이 2×2 형태로 4개가 붙어있을 경우 사라지면서 점수를 얻는 게임이다.

2×2로 배치된 4개 블록이 지워진다.
같은 블록은 여러 2×2에 포함될 수 있으며, 지워지는 조건에 만족하는 2×2 모양이 여러 개 있다면 한꺼번에 지워진다.
블록이 지워진 후에 위에 있는 블록이 아래로 떨어져 빈 공간을 채우게 된다.
만약 빈 공간을 채운 후에 다시 2×2 형태로 같은 모양의 블록이 모이면 다시 지워지고 떨어지고를 반복하게 된다.

입력으로 블록의 첫 배치가 주어졌을 때, 지워지는 블록은 모두 몇 개인지 판단하는 프로그램을 제작하라.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

int solution(int m, int n, std::vector<std::string> board)
{
    int answer = 0;

    std::vector<std::vector<char>> CopyBoard(m, std::vector<char>(n, ' '));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            CopyBoard[i][j] = board[i][j];
        }
    }
    
    while(1)
    {
        std::set<std::pair<int, int>> EraseIndex;
        std::vector<std::vector<bool>> BoardState(m, std::vector<bool>(n, false));

        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (CopyBoard[i][j] == '.')
                {
                    continue;
                }

                if (CopyBoard[i][j] == CopyBoard[i + 1][j]
                    && CopyBoard[i][j] == CopyBoard[i][j + 1]
                    && CopyBoard[i][j] == CopyBoard[i + 1][j + 1])
                {
                    EraseIndex.insert(std::make_pair(i, j));
                    EraseIndex.insert(std::make_pair(i + 1, j));
                    EraseIndex.insert(std::make_pair(i, j + 1));
                    EraseIndex.insert(std::make_pair(i + 1, j + 1));

                    BoardState[i][j] = true;
                    BoardState[i + 1][j] = true;
                    BoardState[i][j + 1] = true;
                    BoardState[i + 1][j + 1] = true;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (BoardState[i][j] == true)
                {
                    CopyBoard[i][j] = '.';
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0)
                {
                    continue;
                }

                if (CopyBoard[i][j] == '.')
                {
                    int StartX = i;

                    while (StartX > -1)
                    {
                        int CheckX = StartX - 1;

                        if (CheckX < 0)
                        {
                            break;
                        }

                        if (CopyBoard[CheckX][j] == '.')
                        {
                            break;
                        }

                        std::swap(CopyBoard[StartX][j], CopyBoard[CheckX][j]);
                        --StartX;
                    }
                }
            }
        }

        if (EraseIndex.size() == 0)
        {
            break;
        }

        answer += EraseIndex.size();
    }

    return answer;
}

int main()
{
    std::cout << solution(4, 5, { "CCBDE", "AAADE", "AAABF", "CCBBF" }) << std::endl;
    std::cout << solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" }) << std::endl;
    std::cout << solution(2, 2, { "AA", "AA" }) << std::endl;                                                       // 4
    std::cout << solution(2, 2, { "AA", "AB" }) << std::endl;                                                       // 0
    std::cout << solution(3, 2, { "AA", "AA", "AB" }) << std::endl;                                                 // 4
    std::cout << solution(4, 2, { "CC", "AA", "AA", "CC" }) << std::endl;                                           // 8
    std::cout << solution(6, 2, { "DD", "CC", "AA", "AA", "CC", "DD" }) << std::endl;                               // 12
    std::cout << solution(8, 2, { "FF", "AA", "CC", "AA", "AA", "CC", "DD", "FF" }) << std::endl;                   // 8
    std::cout << solution(6, 2, { "AA", "AA", "CC", "AA", "AA", "DD" }) << std::endl;                               // 8
    std::cout << solution(10, 10, { "DDABBAABBA", "AAAAAABBBA", "DDACCBBBAA", "DDABBBBBAA", "AAABBABBBA", "CCADDAABBB", "CCADDAABBB", "BBACCABBBA", "BBAAABBBAA", "DDABBBBAAA" }) << std::endl; // 86                              // 8
}
