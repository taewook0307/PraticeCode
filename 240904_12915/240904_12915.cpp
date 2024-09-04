// 240904_12915.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// 문자열 내 마음대로 정렬하기

/*
문제 설명
문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다.
예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//std::vector<std::string> solution(std::vector<std::string> strings, int n)
//{
//    sort(strings.begin(), strings.end(),
//        [&](const std::string& _Left, const std::string& _Right)
//        {
//            if (_Left[n] == _Right[n])
//            {
//                return _Left < _Right;
//            }
//            return _Left[n] < _Right[n];
//        }
//    );
//
//    return strings;
//}

static int CompareIndex = 0;

bool Compare(const std::string& _Left, const std::string& _Right)
{
    //if (_Left[CompareIndex] == _Right[CompareIndex])
    //{
    //    return _Left < _Right;
    //}

    //return _Left[CompareIndex] < _Right[CompareIndex];

    return _Left[CompareIndex] == _Right[CompareIndex] ? _Left < _Right : _Left[CompareIndex] < _Right[CompareIndex];
}

std::vector<std::string> solution(std::vector<std::string> strings, int n)
{
    CompareIndex = n;

    sort(strings.begin(), strings.end(), Compare);

    return strings;
}

void PrintResult(const std::vector<std::string>& strings, int n)
{
    std::vector<std::string> Result = solution(strings, n);

    printf_s("--------------------------------------\n");
    for (const std::string& CurString : Result)
    {
        printf_s("%s ", CurString.c_str());
    }
    printf_s("\n--------------------------------------\n");
}

int main()
{
    std::vector<std::string> strings0 = { "sun", "bed", "car" };
    PrintResult(strings0, 1);

    std::vector<std::string> strings1 = { "abce", "abcd", "cdx" };
    PrintResult(strings1, 2);
}
