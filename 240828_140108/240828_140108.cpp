// 240828_140108.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 문자열 나누기

/*
문제 설명
문자열 s가 입력되었을 때 다음 규칙을 따라서 이 문자열을 여러 문자열로 분해하려고 합니다.

    - 먼저 첫 글자를 읽습니다. 이 글자를 x라고 합시다.
    - 이제 이 문자열을 왼쪽에서 오른쪽으로 읽어나가면서, x와 x가 아닌 다른 글자들이 나온 횟수를 각각 셉니다.
      처음으로 두 횟수가 같아지는 순간 멈추고, 지금까지 읽은 문자열을 분리합니다.
    - s에서 분리한 문자열을 빼고 남은 부분에 대해서 이 과정을 반복합니다. 남은 부분이 없다면 종료합니다.
    - 만약 두 횟수가 다른 상태에서 더 이상 읽을 글자가 없다면, 역시 지금까지 읽은 문자열을 분리하고, 종료합니다.

문자열 s가 매개변수로 주어질 때, 위 과정과 같이 문자열들로 분해하고,
분해한 문자열의 개수를 return 하는 함수 solution을 완성하세요.
*/

#include <iostream>
#include <string>
#include <vector>

int solution(std::string s)
{
    int answer = 0;

    int Length = static_cast<int>(s.size());

    // 초기값
    char x = s[0];
    int Same = 1;               // 문자가 같을 경우의 갯수
    int NotSame = 0;            // 문자가 같지 않을 경우의 갯수

    for (int i = 1; i < Length; ++i)
    {
        // 체크하는 문자가 x와 같을 경우
        if (s[i] == x)
        {
            ++Same;
        }
        // 체크하는 문자가 x와 다를 경우
        else
        {
            ++NotSame;
        }

        // 같은 문자와 같지 않는 문자 수가 서로 같을 경우
        if (Same == NotSame)
        {
            ++answer;
            Same = 0;
            NotSame = 0;
            
            // 오버플로우 방지
            if (Length > i + 1)
            {
                x = s[i + 1];
            }
        }
    }

    if (Same != NotSame)
    {
        ++answer;
    }

    return answer;
}

void PrintResult(const std::string& _Value)
{
    int Result = solution(_Value);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    PrintResult("banana");

    PrintResult("abracadabra");

    PrintResult("aaabbaccccabba");

    PrintResult("a");
}
