// 240905_76501.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 음양 더하기

/*
문제 설명
어떤 정수들이 있습니다. 이 정수들의 절댓값을 차례대로 담은 정수 배열 absolutes와
이 정수들의 부호를 차례대로 담은 불리언 배열 signs가 매개변수로 주어집니다.

실제 정수들의 합을 구하여 return 하도록 solution 함수를 완성해주세요.
    signs[i] 가 참이면 absolutes[i] 의 실제 정수가 양수임을, 그렇지 않으면 음수임을 의미합니다.
*/

#include <iostream>
#include <string>
#include <vector>

int solution(std::vector<int> absolutes, std::vector<bool> signs)
{
    int answer = 0;

    const int VectorSize = static_cast<int>(absolutes.size());

    for (int i = 0; i < VectorSize; ++i)
    {
        int Value = true == signs[i] ? absolutes[i] : -absolutes[i];

        answer += Value;
    }

    return answer;
}

void PrintResult(const std::vector<int>& absolutes, const std::vector<bool>& signs)
{
    int Result = solution(absolutes, signs);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> Absolutes0 = { 4,7,12 };
    std::vector<bool> Signs0 = { true,false,true };
    PrintResult(Absolutes0, Signs0);
}
