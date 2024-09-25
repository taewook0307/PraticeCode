// 240925_181188.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 요격 시스템

/*
문제 설명
A 나라가 B 나라를 침공하였습니다.
B 나라의 대부분의 전략 자원은 아이기스 군사 기지에 집중되어 있기 때문에 A 나라는 B 나라의 아이기스 군사 기지에 융단폭격을 가했습니다.

A 나라의 공격에 대항하여 아이기스 군사 기지에서는 무수히 쏟아지는 폭격 미사일들을 요격하려고 합니다.
이곳에는 백발백중을 자랑하는 요격 시스템이 있지만 운용 비용이 상당하기 때문에 미사일을 최소로 사용해서 모든 폭격 미사일을 요격하려 합니다.

A 나라와 B 나라가 싸우고 있는 이 세계는 2 차원 공간으로 이루어져 있습니다.
A 나라가 발사한 폭격 미사일은 x 축에 평행한 직선 형태의 모양이며 개구간을 나타내는 정수 쌍 (s, e) 형태로 표현됩니다.
B 나라는 특정 x 좌표에서 y 축에 수평이 되도록 미사일을 발사하며, 발사된 미사일은 해당 x 좌표에 걸쳐있는 모든 폭격 미사일을 관통하여 한 번에 요격할 수 있습니다.
단, 개구간 (s, e)로 표현되는 폭격 미사일은 s와 e에서 발사하는 요격 미사일로는 요격할 수 없습니다.
요격 미사일은 실수인 x 좌표에서도 발사할 수 있습니다.

각 폭격 미사일의 x 좌표 범위 목록 targets이 매개변수로 주어질 때,
모든 폭격 미사일을 요격하기 위해 필요한 요격 미사일 수의 최솟값을 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Width
{
    Width(int _Left, int _Right)
        : Left(_Left), Right(_Right)
    {

    }

    int GetLength() const
    {
        if (Left > Right)
        {
            return -1;
        }

        return Right - Left;
    }

    int Left = -1;
    int Right = -1;
};

bool IsOverlap(const Width& _X, const Width& _Y)
{
    if (_X.Left >= _Y.Right || _X.Right <= _Y.Left)
    {
        return false;
    }

    return true;
}

//int solution(std::vector<std::vector<int>> targets)
//{
//    int answer = 0;
//
//    const int MissileCount = static_cast<int>(targets.size());
//    int RemainMissile = MissileCount;
//
//    std::vector<std::vector<Width>> InterceptionCount;
//    InterceptionCount.reserve(MissileCount);
//
//    for (int i = 0; i < MissileCount; ++i)
//    {
//        Width CurMissile= Width(targets[i][0], targets[i][1]);
//
//        bool IsIntercept = false;
//
//        std::vector<std::vector<Width>>::iterator BeginIter = InterceptionCount.begin();
//        std::vector<std::vector<Width>>::iterator EndIter = InterceptionCount.end();
//
//        for (;BeginIter != EndIter;++BeginIter)
//        {
//            std::vector<Width>& CurVector = *BeginIter;
//
//            for (const Width& PrevMissile : CurVector)
//            {
//                if (false == IsOverlap(PrevMissile, CurMissile))
//                {
//                    IsIntercept = false;
//                    break;
//                }
//                else
//                {
//                    IsIntercept = true;
//                }
//            }
//
//            if (true == IsIntercept)
//            {
//                CurVector.push_back(CurMissile);
//                --RemainMissile;
//                break;
//            }
//        }
//
//        if (false == IsIntercept)
//        {
//            std::vector<Width> NewVector = { CurMissile };
//            NewVector.reserve(RemainMissile);
//            --RemainMissile;
//            InterceptionCount.push_back(NewVector);
//        }
//    }
//
//    answer = static_cast<int>(InterceptionCount.size());
//
//    return answer;
//}

bool Compare(const std::vector<int>& _Left, const std::vector<int>& _Right)
{
    if (_Left[0] == _Right[0])
    {
        return _Left[1] > _Right[1];
    }

    return _Left[0] > _Right[0];
}

int solution(std::vector<std::vector<int>> targets)
{
    int answer = 1;

    // 오름차순으로 정렬
    sort(targets.begin(), targets.end(), Compare);
    int MissileCount = static_cast<int>(targets.size());

    // 첫번째 미사일을 체크용으로 선언
    Width CheckMissile = Width(targets[0][0], targets[0][1]);

    // 두번째 부터 조사
    for (int i = 1; i < MissileCount; ++i)
    {
        Width CurMissile = Width(targets[i][0], targets[i][1]);

        // 겹칠 경우
        if (true == IsOverlap(CheckMissile, CurMissile))
        {
            CheckMissile = CheckMissile.Left > CurMissile.Left ? CheckMissile : CurMissile;
        }
        // 안 겹칠 경우
        else
        {
            CheckMissile = CurMissile;
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::vector<std::vector<int>> Targets0 = { { 1, 5 }, { 2, 6 }, { 3, 7 }, { 5, 17 } };
    int Result = solution(Targets0);

    std::cout << Result << std::endl;
}
