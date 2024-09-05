// 240905_12939.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 최댓값과 최솟값

/*
문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다.
str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.

예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string solution(std::string s) {
    std::string answer = "";

    std::vector<int> IntVector;
    std::stringstream MinStream(s);
    int Temp = 0;

    while (MinStream >> Temp)
    {
        IntVector.push_back(Temp);
    }

    int MinValue = IntVector[0];
    int MaxValue = IntVector[0];

    for (int Num : IntVector)
    {
        MinValue = MinValue < Num ? MinValue : Num;
        MaxValue = MaxValue > Num ? MaxValue : Num;
    }

    answer = std::to_string(MinValue) + " " + std::to_string(MaxValue);

    return answer;
}

void PrintResult(const std::string& _s)
{
    std::string Result = solution(_s);

    std::cout << "Result = " << Result << std::endl;
}

int main()
{
    PrintResult("1 2 3 4");
    PrintResult("-1 -2 -3 -4");
    PrintResult("-1 -1");
}
