// 241125_12916.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문자열 내 p와 y의 개수

/*
문제설명
대문자와 소문자가 섞여있는 문자열 s가 주어집니다.
s에 'p'의 개수와 'y'의 개수를 비교해 같으면 True, 다르면 False를 return 하는 solution를 완성하세요.
'p', 'y' 모두 하나도 없는 경우는 항상 True를 리턴합니다. 단, 개수를 비교할 때 대문자와 소문자는 구별하지 않습니다.

예를 들어 s가 "pPoooyY"면 true를 return하고 "Pyy"라면 false를 return합니다.
*/

#include <iostream>
#include <string>

bool solution(std::string s)
{
    std::string CopyS = "";

    for (char C : s)
    {
        char LowC = std::tolower(C);
        CopyS += LowC;
    }

    int pCount = std::count(CopyS.begin(), CopyS.end(), 'p');
    int yCount = std::count(CopyS.begin(), CopyS.end(), 'y');

    if (pCount == 0 && yCount == 0)
    {
        return true;
    }

    return pCount == yCount;
}

//bool solution(std::string s)
//{
//    int pCount = 0;
//    int yCount = 0;
//
//    for (char C : s)
//    {
//        if (C == 'P' || C == 'p')
//        {
//            ++pCount;
//        }
//
//        if (C == 'Y' || C == 'y')
//        {
//            ++pCount;
//        }
//    }
//
//    if (pCount == 0 && yCount == 0)
//    {
//        return true;
//    }
//
//    return pCount == yCount;
//}

int main()
{
    std::cout << "Hello World!\n";
}
