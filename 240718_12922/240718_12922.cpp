// 240718_12922.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 수박수박수

/*
문제 설명
길이가 n이고, "수박수박수박수...."와 같은 패턴을 유지하는 문자열을 리턴하는 함수, solution을 완성하세요.
예를들어 n이 4이면 "수박수박"을 리턴하고 3이라면 "수박수"를 리턴하면 됩니다.
*/

#include <iostream>
#include <string>

std::string solution(int n)
{
    std::string answer = "";

    answer.reserve(n);

    if (0 == n % 2)
    {
        for (int i = 0; i < n; i += 2)
        {
            answer += "수박";
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            answer += "수박";
        }
        answer += "수";
    }
    
    return answer;
}

void PrintResult(int n)
{
    std::string Result = solution(n);

    std::cout << Result << std::endl;
}

int main()
{
    PrintResult(3);
    PrintResult(4);
    PrintResult(10);
}
