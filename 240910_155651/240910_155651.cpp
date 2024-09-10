// 240910_155651.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 호텔 대실

/*
문제 설명
호텔을 운영 중인 코니는 최소한의 객실만을 사용하여 예약 손님들을 받으려고 합니다.
한 번 사용한 객실은 퇴실 시간을 기준으로 10분간 청소를 하고 다음 손님들이 사용할 수 있습니다.

예약 시각이 문자열 형태로 담긴 2차원 배열 book_time이 매개변수로 주어질 때,
코니에게 필요한 최소 객실의 수를 return 하는 solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Time
{
public:
    Time(int _Hour = 0, int _Second = 0)
        : Hour(_Hour), Second(_Second)
    {

    }

    Time(const std::string& _Time)
    {
        std::string HourString = _Time.substr(0, 2);
        std::string SecondString = _Time.substr(3, 2);

        Hour = std::stoi(HourString);
        Second = std::stoi(SecondString);
    }

    Time operator+(int _PlusSecond)
    {
        this->Second += _PlusSecond;

        if (60 <= this->Second)
        {
            int PlusHour = this->Second / 60;
            this->Second %= 60;
            this->Hour += PlusHour;
        }

        return *this;
    }

    std::string ToString() const
    {
        std::string HourString = std::to_string(Hour);
        std::string SecondString = std::to_string(Second);

        if (9 >= Hour)
        {
            HourString = "0" + std::to_string(Hour);
        }
        if (9 >= Second)
        {
            SecondString = "0" + std::to_string(Second);
        }

        std::string Result = HourString + ":" + SecondString;
        return Result;
    }

private:
    int Hour;
    int Second;
};

int solution(std::vector<std::vector<std::string>> book_time)
{
    int answer = 0;

    const int BookingCount = static_cast<int>(book_time.size());
    sort(book_time.begin(), book_time.end());

    std::vector<std::string> Rooms;
    Rooms.reserve(BookingCount);

    for (int i = 0; i < BookingCount; ++i)
    {
        std::vector<std::string> CheckBooking = book_time[i];

        bool CheckIn = false;

        const int RoomCount = static_cast<int>(Rooms.size());
        for (int i = 0; i < RoomCount; ++i)
        {
            if (Rooms[i] <= CheckBooking[0])
            {
                Time CleanEndTime = (Time(CheckBooking[1]) + 10);
                Rooms[i] = CleanEndTime.ToString();
                CheckIn = true;
                break;
            }
        }

        if (false == CheckIn)
        {
            Time CleanEndTime = (Time(CheckBooking[1]) + 10);
            Rooms.push_back(CleanEndTime.ToString());
        }
    }

    answer = Rooms.size();

    return answer;
}

int main()
{
    std::vector<std::vector<std::string>> book_time0 = { { "15:00", "17:00" },{ "16:40", "18:20" },{ "14:20", "15:20" },{ "14:10", "19:20" },{ "18:20", "21:20" } };

    std::cout << solution(book_time0) << std::endl;

    std::vector<std::vector<std::string>> book_time1 = { { "17:00", "23:55" },{ "18:40", "18:50" },{ "17:00", "23:50" } };

    std::cout << solution(book_time1) << std::endl;

    std::vector<std::vector<std::string>> book_time2 = { { "15:00", "16:50" },{ "15:00", "16:30" },{ "16:40", "23:00" } };

    std::cout << solution(book_time2) << std::endl;
}
