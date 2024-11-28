// 241128_133499.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 옹알이(2)

/*
문제설명
머쓱이는 태어난 지 11개월 된 조카를 돌보고 있습니다.
조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음과 네 가지 발음을 조합해서 만들 수 있는 발음밖에 하지 못하고 연속해서 같은 발음을 하는 것을 어려워합니다.
문자열 배열 babbling이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

int solution(std::vector<std::string> babbling)
{
    int answer = 0;

    std::map<std::string, std::string> Words;
    Words.insert(std::make_pair("aya", "1"));
    Words.insert(std::make_pair("ye", "2"));
    Words.insert(std::make_pair("woo", "3"));
    Words.insert(std::make_pair("ma", "4"));

    for (const std::string& CurBabbling : babbling)
    {
        std::string ChangeValue = CurBabbling;

        std::map<std::string, std::string>::iterator BeginIter = Words.begin();
        std::map<std::string, std::string>::iterator EndIter = Words.end();

        for (;BeginIter != EndIter; ++BeginIter)
        {
            while (ChangeValue.find(BeginIter->first) != std::string::npos)
            {
                size_t FindNum = ChangeValue.find(BeginIter->first);
                ChangeValue.replace(FindNum, BeginIter->first.length(), BeginIter->second);
            }
        }

        bool Flag = true;

        for (char C : ChangeValue)
        {
            if (false == isdigit(C))
            {
                Flag = false;
                break;
            }
        }

        if (Flag == false)
        {
            continue;
        }

        int Num = atoi(ChangeValue.c_str());

        int PrevNum = -1;
        while (Num != 0)
        {
            int CurNum = Num % 10;

            if (CurNum == PrevNum)
            {
                Flag = false;
                break;
            }

            PrevNum = CurNum;
            Num /= 10;
        }

        if (true == Flag)
        {
            ++answer;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution({ "aya", "yee", "u", "maa" }) << std::endl;
}
