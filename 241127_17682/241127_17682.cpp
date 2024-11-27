// 241127_17682.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [1차] 다트게임

/*
문제설명
카카오톡 게임별의 하반기 신규 서비스로 다트 게임을 출시하기로 했다.
다트 게임은 다트판에 다트를 세 차례 던져 그 점수의 합계로 실력을 겨루는 게임으로, 모두가 간단히 즐길 수 있다.
갓 입사한 무지는 코딩 실력을 인정받아 게임의 핵심 부분인 점수 계산 로직을 맡게 되었다. 다트 게임의 점수 계산 로직은 아래와 같다.

    1. 다트 게임은 총 3번의 기회로 구성된다.
    2. 각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.
    3. 점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱 (점수1 , 점수2 , 점수3 )으로 계산된다.
    4. 옵션으로 스타상(*) , 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 아차상(#) 당첨 시 해당 점수는 마이너스된다.
    5. 스타상(*)은 첫 번째 기회에서도 나올 수 있다. 이 경우 첫 번째 스타상(*)의 점수만 2배가 된다. (예제 4번 참고)
    6. 스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상(*) 점수는 4배가 된다. (예제 4번 참고)
    7. 스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다. 이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. (예제 5번 참고)
    8. Single(S), Double(D), Triple(T)은 점수마다 하나씩 존재한다.
    9. 스타상(*), 아차상(#)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.

0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열이 입력될 시 총점수를 반환하는 함수를 작성하라.
*/

#include <iostream>
#include <string>
#include <cmath>

int solution(std::string dartResult)
{
    const size_t Len = dartResult.length();

    int answer = 0;

    std::string HitScore = "";
    int PowValue = 0;
    int Option = 0;

    int PrevScore = 0;

    for (size_t i = 0; i < Len; ++i)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if (HitScore == "")
            {
                HitScore += dartResult[i];
                continue;
            }

            if (PowValue == 0)
            {
                HitScore += dartResult[i];
                continue;
            }

            int Score = std::stoi(HitScore);
            if (PowValue != 0)
            {
                Score = std::pow(Score, PowValue);
            }
            if (Option != 0)
            {
                Score *= Option;
                if (Option == 2)
                {
                    answer += PrevScore;
                }
            }

            answer += Score;
            PrevScore = Score;
            HitScore = "";
            HitScore += dartResult[i];
            PowValue = 0;
            Option = 0;
            continue;
        }

        if (dartResult[i] == 'S')
        {
            PowValue = 1;
            continue;
        }
        else if (dartResult[i] == 'D')
        {
            PowValue = 2;
            continue;
        }
        else if (dartResult[i] == 'T')
        {
            PowValue = 3;
            continue;
        }

        if (dartResult[i] == '*')
        {
            Option = 2;
            continue;
        }
        else if (dartResult[i] == '#')
        {
            Option = -1;
            continue;
        }
    }

    if (HitScore != "")
    {
        int Score = std::stoi(HitScore);
        if (PowValue != 0)
        {
            Score = std::pow(Score, PowValue);
        }
        if (Option != 0)
        {
            Score *= Option;
            if (Option == 2)
            {
                answer += PrevScore;
            }
        }

        answer += Score;
    }

    return answer;
}

int main()
{
    std::cout << solution("1S2D*3T") << std::endl;
    std::cout << solution("1D2S#10S") << std::endl;
    std::cout << solution("1D2S0T") << std::endl;
    std::cout << solution("1S*2T*3S") << std::endl;
    std::cout << solution("1D#2S*3S") << std::endl;
    std::cout << solution("1T2D3D#") << std::endl;
    std::cout << solution("1D2S3T*") << std::endl;
}
