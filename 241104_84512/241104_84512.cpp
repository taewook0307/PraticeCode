// 241104_84512.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 모음사전

/*
문제 설명
사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다.
사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다.

단어 하나 word가 매개변수로 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

int solution(std::string word)
{
    int answer = 0;

    std::vector<int> Value = { 781, 156, 31, 6, 1 };

    std::map<int, char> Factor;
    Factor.insert(std::make_pair('A', 1));
    Factor.insert(std::make_pair('E', 2));
    Factor.insert(std::make_pair('I', 3));
    Factor.insert(std::make_pair('O', 4));
    Factor.insert(std::make_pair('U', 5));

    const size_t WordLength = word.length();

    for (size_t i = 0; i < WordLength; ++i)
    {
        answer += (Factor[word[i]] - 1) * Value[i] + 1;
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}
