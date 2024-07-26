// 240723_67256.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 키패드 누르기

/*
문제 설명
맨 처음 왼손 엄지손가락은 * 키패드에 오른손 엄지손가락은 # 키패드 위치에서 시작하며, 엄지손가락을 사용하는 규칙은 다음과 같습니다.

1. 엄지손가락은 상하좌우 4가지 방향으로만 이동할 수 있으며 키패드 이동 한 칸은 거리로 1에 해당합니다.
2. 왼쪽 열의 3개의 숫자 1, 4, 7을 입력할 때는 왼손 엄지손가락을 사용합니다.
3. 오른쪽 열의 3개의 숫자 3, 6, 9를 입력할 때는 오른손 엄지손가락을 사용합니다.
4. 가운데 열의 4개의 숫자 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용합니다.
    4-1. 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용합니다.
*/

#include <iostream>
#include <string>
#include <vector>

class Location
{
public:
    Location(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int CalculateDistance(Location _Destination)
    {
        return abs(_Destination.x - x) + abs(_Destination.y - y);
    }

private:
    int x = -1;
    int y = -1;
};

std::string solution(std::vector<int> numbers, std::string hand) {
    std::string answer = "";

    std::vector<Location> numberLocation;
    numberLocation.reserve(10);
    numberLocation.push_back(Location(3, 1));           // 0번 위치
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            numberLocation.push_back(Location(i, j));   // 1 ~ 9번 위치
        }
    }

    Location LeftHandLocation = Location(3, 0);         // 왼손 시작 위치
    Location RightHandLocation = Location(3, 2);        // 오른손 시작 위치

    for (int number : numbers)
    {
        if (1 == number
            || 4 == number
            || 7 == number)
        {
            answer += "L";
            LeftHandLocation = numberLocation[number];
        }

        else if (3 == number
            || 6 == number
            || 9 == number)
        {
            answer += "R";
            RightHandLocation = numberLocation[number];
        }

        else
        {
            Location Destination = numberLocation[number];

            int LeftHandDistnace = LeftHandLocation.CalculateDistance(Destination);
            int RightHandDistnace = RightHandLocation.CalculateDistance(Destination);

            if (LeftHandDistnace < RightHandDistnace)
            {
                answer += "L";
                LeftHandLocation = numberLocation[number];
            }
            else if (LeftHandDistnace > RightHandDistnace)
            {
                answer += "R";
                RightHandLocation = numberLocation[number];
            }
            else
            {
                if ("left" == hand)
                {
                    answer += "L";
                    LeftHandLocation = numberLocation[number];
                }
                else if ("right" == hand)
                {
                    answer += "R";
                    RightHandLocation = numberLocation[number];
                }
            }
        }
    }

    return answer;
}

void PrintResult(std::vector<int> numbers, std::string hand)
{
    std::string Result = solution(numbers, hand);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> Example0 = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    PrintResult(Example0, "right");

    std::vector<int> Example1 = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    PrintResult(Example1, "left");

    std::vector<int> Example2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    PrintResult(Example2, "right");
}
