// 241128_150370.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 개인정보 수집 유효기간

/*
문제설명
고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있습니다.
약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다.
당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다.
수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.

예를 들어, A라는 약관의 유효기간이 12 달이고,
2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면
해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.
당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.

모든 달은 28일까지 있다고 가정합니다.

다음은 오늘 날짜가 2022.05.19일 때의 예시입니다.

약관 종류       유효기간
    A	          6 달
    B	          12 달
    C	          3 달

번호	    개인정보 수집 일자	        약관 종류
  1	            2021.05.02	                A
  2	            2021.07.01	                B
  3	            2022.02.19	                C
  4	            2022.02.20	                C

    - 첫 번째 개인정보는 A약관에 의해 2021년 11월 1일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
    - 두 번째 개인정보는 B약관에 의해 2022년 6월 28일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
    - 세 번째 개인정보는 C약관에 의해 2022년 5월 18일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
    - 네 번째 개인정보는 C약관에 의해 2022년 5월 19일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.

따라서 파기해야 할 개인정보 번호는 [1, 3]입니다.

오늘 날짜를 의미하는 문자열 today, 약관의 유효기간을 담은 1차원 문자열 배열 terms와 수집된 개인정보의 정보를 담은 1차원 문자열 배열 privacies가 매개변수로 주어집니다.
이때 파기해야 할 개인정보의 번호를 오름차순으로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> solution(std::string today, std::vector<std::string> terms, std::vector<std::string> privacies)
{
    std::vector<int> answer;

    const size_t PrivacieCount = privacies.size();

    answer.reserve(PrivacieCount);

    std::map<char, int> TermMap;

    for (const std::string& Term : terms)
    {
        int Mouth = std::stoi(Term.substr(2));

        TermMap.insert(std::make_pair(Term[0], Mouth));
    }

    for (int i = 0; i < PrivacieCount; ++i)
    {
        std::string Date = privacies[i].substr(0, 10);
        int PlusMouth = TermMap[privacies[i][privacies[i].length() - 1]];

        int Year = std::stoi(Date.substr(0, 4));
        int Month = std::stoi(Date.substr(5, 2));
        int Day = std::stoi(Date.substr(8));

        Month += PlusMouth;

        while (Month > 12)
        {
            Month -= 12;
            ++Year;
        }

        int TodayYear = std::stoi(today.substr(0, 4));
        int TodayMonth = std::stoi(today.substr(5, 2));
        int TodayDay = std::stoi(today.substr(8));

        if (TodayYear < Year)
        {
            continue;
        }
        else if (TodayYear == Year)
        {
            if (TodayMonth < Month)
            {
                continue;
            }
            else if (TodayMonth == Month)
            {
                if (TodayDay < Day)
                {
                    continue;
                }
                else
                {
                    answer.push_back(i + 1);
                }
            }
            else
            {
                answer.push_back(i + 1);
            }
        }
        else
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main()
{
    std::vector<int> Result = solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
    std::vector<int> Result1 = solution("2020.01.01", { "Z 3", "D 5" }, { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" });
    std::vector<int> Result2 = solution("2022.02.28", { "A 23" }, { "2020.01.28 A" });
    std::vector<int> Result3 = solution("2019.01.01", { "B 12" }, { "2017.12.21 B" });

    int a = 0;
}
