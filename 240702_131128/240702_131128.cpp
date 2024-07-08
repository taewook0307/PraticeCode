// 240702_131128.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 숫자 짝꿍

/*
문제 설명
두 정수 X, Y의 임의의 자리에서 공통으로 나타나는 정수 k(0 ≤ k ≤ 9)들을 이용하여 만들 수 있는 가장 큰 정수를 두 수의 짝꿍이라 합니다
(단, 공통으로 나타나는 정수 중 서로 짝지을 수 있는 숫자만 사용합니다).

X, Y의 짝꿍이 존재하지 않으면, 짝꿍은 -1입니다.
X, Y의 짝꿍이 0으로만 구성되어 있다면, 짝꿍은 0입니다.

예를 들어, X = 3403이고 Y = 13203이라면, X와 Y의 짝꿍은 X와 Y에서 공통으로 나타나는 3, 0, 3으로 만들 수 있는 가장 큰 정수인 330입니다.
다른 예시로 X = 5525이고 Y = 1255이면 X와 Y의 짝꿍은 X와 Y에서 공통으로 나타나는 2, 5, 5로 만들 수 있는 가장 큰 정수인 552입니다
(X에는 5가 3개, Y에는 5가 2개 나타나므로 남는 5 한 개는 짝 지을 수 없습니다.)
*/


#include <iostream>
#include <string>
#include <vector>

// 시간 초과 풀이 ------------------------------------------------------------------------------
//bool Find(std::vector<int> CheckVector, int FindValue)
//{
//    if (CheckVector.size() == 0)
//    {
//        return false;
//    }
//
//    for (int CurValue : CheckVector)
//    {
//        if (CurValue == FindValue)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//std::string solution(std::string X, std::string Y) {
//    std::string answer = "";
//
//    const int XSize = X.size();
//    const int YSize = Y.size();
//
//    std::vector<int> ExceptXIndex;
//    ExceptXIndex.reserve(XSize);
//
//    std::vector<int> ExceptYIndex;
//    ExceptYIndex.reserve(YSize);
//
//    for (int i = 0; i < XSize; ++i)
//    {
//        for (int j = 0; j < YSize; ++j)
//        {
//            if (true == Find(ExceptXIndex, i))
//            {
//                continue;
//            }
//
//            if (true == Find(ExceptYIndex, j))
//            {
//                continue;
//            }
//
//            if (X[i] == Y[j])
//            {
//                answer.push_back(X[i]);
//                ExceptXIndex.push_back(i);
//                ExceptYIndex.push_back(j);
//            }
//        }
//    }
//
//    if (0 == answer.size())
//    {
//        answer = "-1";
//    }
//    else
//    {
//        sort(answer.begin(), answer.end(), std::greater<char>());
//
//        if ('0' == answer[0])
//        {
//            answer = "0";
//        }
//    }
//
//    return answer;
//}
// --------------------------------------------------------------------------------------------------------

//std::string solution(std::string X, std::string Y) {
//    std::string answer = "";
//
//    std::set<int> ResultXIndex;
//    std::set<int> ResultYIndex;
//
//    const int XSize = X.size();
//    const int YSize = Y.size();
//
//    for (int i = 0; i < XSize; ++i)
//    {
//        for (int j = 0; j < YSize; ++j)
//        {
//            if (X[i] == Y[j])
//            {
//                ResultXIndex.insert(i);
//                ResultYIndex.insert(j);
//            }
//        }
//    }
//
//    if (true == ResultXIndex.empty() && true == ResultYIndex.empty())
//    {
//        return "-1";
//    }
//
//    const int ResultXSize = ResultXIndex.size();
//    const int ResultYSize = ResultYIndex.size();
//
//    if (ResultXSize < ResultYSize)
//    {
//        answer.reserve(ResultXSize);
//
//        for (int CurIndex : ResultXIndex)
//        {
//            answer.push_back(X[CurIndex]);
//        }
//    }
//    else
//    {
//        answer.reserve(ResultYSize);
//
//        for (int CurIndex : ResultYIndex)
//        {
//            answer.push_back(Y[CurIndex]);
//        }
//    }
//
//    sort(answer.begin(), answer.end(), std::greater<char>());
//
//    if (answer[0] == '0')
//    {
//        return "0";
//    }
//    
//    return answer;
//}

std::string solution(std::string X, std::string Y) {
    std::string answer = "";

    std::vector<int> XNumberCount;
    XNumberCount.resize(10);
    std::vector<int> YNumberCount;
    YNumberCount.resize(10);

    const int XSize = X.size();
    const int YSize = Y.size();

    for (int i = 0; i < XSize; ++i)
    {
        char CurData = X[i] - '0';
        int IndexNum = CurData;

        int PrevValue = XNumberCount[IndexNum];
        XNumberCount[IndexNum] = PrevValue + 1;
    }

    for (int i = 0; i < YSize; ++i)
    {
        char CurData = Y[i] - '0';
        int IndexNum = CurData;

        int PrevValue = YNumberCount[IndexNum];
        YNumberCount[IndexNum] = PrevValue + 1;
    }

    for (int i = 9; i >= 0; --i)
    {
        int Count = XNumberCount[i] < YNumberCount[i] ? XNumberCount[i] : YNumberCount[i];

        for (int j = 0; j < Count; ++j)
        {
            answer += std::to_string(i);
        }
    }

    if (0 == answer.size())
    {
        return "-1";
    }

    if ('0' == answer[0])
    {
        return "0";
    }

    return answer;
}

void PrintResult(std::string X, std::string Y)
{
    std::string Result = solution(X, Y);
    std::cout << Result << std::endl;
}

int main()
{
    PrintResult("10034", "1342");

    PrintResult("55302", "550928");

    PrintResult("77730", "7729");

    PrintResult("1234", "5678");

    PrintResult("5525", "1255");
}
