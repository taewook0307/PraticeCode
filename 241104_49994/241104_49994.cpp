// 241104_49994.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 방문 길이

/*
문제 설명
게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

    U: 위쪽으로 한 칸 가기
    D: 아래쪽으로 한 칸 가기
    R: 오른쪽으로 한 칸 가기
    L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.
우리는 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하려고 합니다.
단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.

명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <set>

int solution(std::string dirs)
{
    int answer = 0;

    std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> Pathes;

    std::pair<int, int> CurPos = std::make_pair(0, 0);

    for (char MoveDir : dirs)
    {
        switch (MoveDir)
        {
        case 'U':
        {
            std::pair<int, int> MovePos = std::make_pair(CurPos.first, CurPos.second + 1);
            if (MovePos.second < 6)
            {
                Pathes.insert(std::make_pair(MovePos, CurPos));
                CurPos = MovePos;
            }
            break;
        }
        case 'D':
        {
            std::pair<int, int> MovePos = std::make_pair(CurPos.first, CurPos.second - 1);
            if (MovePos.second > -6)
            {
                Pathes.insert(std::make_pair(CurPos, MovePos));
                CurPos = MovePos;
            }
            break;
        }
        case 'R':
        {
            std::pair<int, int> MovePos = std::make_pair(CurPos.first + 1, CurPos.second);
            if (MovePos.first < 6)
            {
                Pathes.insert(std::make_pair(CurPos, MovePos));
                CurPos = MovePos;
            }
            break;
        }
        case 'L':
        {
            std::pair<int, int> MovePos = std::make_pair(CurPos.first - 1, CurPos.second);
            if (MovePos.first > -6)
            {
                Pathes.insert(std::make_pair(MovePos, CurPos));
                CurPos = MovePos;
            }
            break;
        }
        default:
            break;
        }
    }

    answer = static_cast<int>(Pathes.size());

    return answer;
}

int main()
{
    std::cout << solution("ULURRDLLU") << std::endl;
}
