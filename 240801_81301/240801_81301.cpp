// 240801_81301.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 숫자 문자열과 영단어

/*
문제 설명
네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

1478 → "one4seveneight"
234567 → "23four5six7"
10203 → "1zerotwozero3"

이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다.
s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <map>
#include <regex>

int solution(std::string s)
{
    std::map<std::string, std::string> Numbers;
    Numbers.insert(std::pair<std::string, std::string>("zero", "0"));
    Numbers.insert(std::pair<std::string, std::string>("one", "1"));
    Numbers.insert(std::pair<std::string, std::string>("two", "2"));
    Numbers.insert(std::pair<std::string, std::string>("three", "3"));
    Numbers.insert(std::pair<std::string, std::string>("four", "4"));
    Numbers.insert(std::pair<std::string, std::string>("five", "5"));
    Numbers.insert(std::pair<std::string, std::string>("six", "6"));
    Numbers.insert(std::pair<std::string, std::string>("seven", "7"));
    Numbers.insert(std::pair<std::string, std::string>("eight", "8"));
    Numbers.insert(std::pair<std::string, std::string>("nine", "9"));

    int answer = 0;

    std::string StringAnswer = "";

    std::string CheckString = "";

    const int StringSize = s.size();
    for (int i = 0; i < StringSize; ++i)
    {
        char CheckChar = s[i];

        if ('9' >= CheckChar && '0' <= CheckChar)
        {
            StringAnswer += CheckChar;
            continue;
        }

        CheckString += CheckChar;

        if (3 > CheckString.size())
        {
            continue;
        }

        std::map<std::string, std::string>::iterator FindIter = Numbers.find(CheckString);

        if (Numbers.end() != FindIter)
        {
            StringAnswer += FindIter->second;
            CheckString = "";
        }
    }

    answer = std::stoi(StringAnswer);

    return answer;
}

//int solution(std::string s)
//{
//    s = std::regex_replace(s, std::regex("zero"), "0");
//    s = std::regex_replace(s, std::regex("one"), "1");
//    s = std::regex_replace(s, std::regex("two"), "2");
//    s = std::regex_replace(s, std::regex("three"), "3");
//    s = std::regex_replace(s, std::regex("four"), "4");
//    s = std::regex_replace(s, std::regex("five"), "5");
//    s = std::regex_replace(s, std::regex("six"), "6");
//    s = std::regex_replace(s, std::regex("seven"), "7");
//    s = std::regex_replace(s, std::regex("eight"), "8");
//    s = std::regex_replace(s, std::regex("nine"), "9");
//    return stoi(s);
//}

void PrintResult(const std::string& s)
{
    int Result = solution(s);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::string Ex1 = "one4seveneight";
    PrintResult(Ex1);

    std::string Ex2 = "23four5six7";
    PrintResult(Ex2);

    std::string Ex3 = "2three45sixseven";
    PrintResult(Ex3);

    std::string Ex4 = "123";
    PrintResult(Ex4);
}
