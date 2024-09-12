// 240912_340213.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [PCCE 기출문제] 1번/동영상 재생기

/*
문제 설명
당신은 동영상 재생기를 만들고 있습니다.
당신의 동영상 재생기는 10초 전으로 이동, 10초 후로 이동, 오프닝 건너뛰기 3가지 기능을 지원합니다.
각 기능이 수행하는 작업은 다음과 같습니다.

    - 10초 전으로 이동: 사용자가 "prev" 명령을 입력할 경우 동영상의 재생 위치를 현재 위치에서 10초 전으로 이동합니다.
                        현재 위치가 10초 미만인 경우 영상의 처음 위치로 이동합니다. 영상의 처음 위치는 0분 0초입니다.

    - 10초 후로 이동: 사용자가 "next" 명령을 입력할 경우 동영상의 재생 위치를 현재 위치에서 10초 후로 이동합니다.
                      동영상의 남은 시간이 10초 미만일 경우 영상의 마지막 위치로 이동합니다.
                      영상의 마지막 위치는 동영상의 길이와 같습니다.

    - 오프닝 건너뛰기: 현재 재생 위치가 오프닝 구간(op_start ≤ 현재 재생 위치 ≤ op_end)인 경우 자동으로 오프닝이 끝나는 위치로 이동합니다.

동영상의 길이를 나타내는 문자열 video_len,
기능이 수행되기 직전의 재생위치를 나타내는 문자열 pos,
오프닝 시작 시각을 나타내는 문자열 op_start,
오프닝이 끝나는 시각을 나타내는 문자열 op_end,
사용자의 입력을 나타내는 1차원 문자열 배열 commands가 매개변수로 주어집니다.

이때 사용자의 입력이 모두 끝난 후 동영상의 위치를 "mm:ss" 형식으로 return 하도록 solution 함수를 완성해 주세요.
*/

#include <iostream>
#include <string>
#include <vector>

class Time
{
public:
    Time(int _Hour, int _Second)
        : Hour(_Hour), Second(_Second)
    {

    }

    Time(const std::string& _Time)
    {
        Hour = std::stoi(_Time.substr(0, 2));
        Second = std::stoi(_Time.substr(3, 2));
    }

    std::string ToString() const
    {
        std::string Result;

        if (Hour < 10)
        {
            Result += "0";
        }
        Result += std::to_string(Hour);
        Result += ":";
        if (Second < 10)
        {
            Result += "0";
        }
        Result += std::to_string(Second);

        return Result;
    }

    void Prev()
    {
        if (Second < 10)
        {
            if (Hour == 0)
            {
                Second = 0;
            }
            else
            {
                Hour -= 1;
                Second += 60;
                Second -= 10;
            }
        }
        else
        {
            Second -= 10;
        }
    }

    void Next(int _MaxHour = -1, int _MaxSecond = -1)
    {
        Second += 10;

        if (Second >= 60)
        {
            Hour += 1;
            Second -= 60;
        }
    }

    void Set(const std::string& _Time)
    {
        Hour = std::stoi(_Time.substr(0, 2));
        Second = std::stoi(_Time.substr(3, 2));
    }

private:
    int Hour;
    int Second;
};

std::string solution(std::string video_len, std::string pos, std::string op_start, std::string op_end, std::vector<std::string> commands)
{
    std::string answer = pos;

    if (op_start <= answer && op_end >= answer)
    {
        answer = op_end;
    }

    Time CurTime = Time(answer);

    for (const std::string& Command : commands)
    {
        if ("prev" == Command)
        {
            CurTime.Prev();
        }
        else if ("next" == Command)
        {
            CurTime.Next();
        }

        std::string CurTimeString = CurTime.ToString();

        if (video_len < CurTimeString)
        {
            CurTime.Set(video_len);
        }

        if (op_start <= CurTimeString && op_end >= CurTimeString)
        {
            CurTime.Set(op_end);
        }
    }

    answer = CurTime.ToString();

    return answer;
}

int main()
{
    std::string video_len0 = "10:55";
    std::string pos0 = "00:05";
    std::string op_start0 = "00:15";
    std::string op_end0 = "06:55";
    std::vector<std::string> command0 = { "prev", "next", "next" };

    std::cout << solution(video_len0, pos0, op_start0, op_end0, command0) << std::endl;
}
