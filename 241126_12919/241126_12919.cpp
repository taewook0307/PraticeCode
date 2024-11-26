// 241126_12919.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 서울에서 김서방 찾기

/*
문제설명
String형 배열 seoul의 element중 "Kim"의 위치 x를 찾아, "김서방은 x에 있다"는 String을 반환하는 함수, solution을 완성하세요.
seoul에 "Kim"은 오직 한 번만 나타나며 잘못된 값이 입력되는 경우는 없습니다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string solution(std::vector<std::string> seoul)
{
    int Index = std::find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();

    std::string answer = "김서방은 " + std::to_string(Index) + "에 있다";

    return answer;
}

int main()
{
    std::cout << solution({ "Jane", "Kim" }) << std::endl;
}
