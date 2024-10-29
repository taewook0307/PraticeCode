// 241029_42577.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 전화번호 목록

/*
문제 설명
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421

전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때,
어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool solution(std::vector<std::string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());

    const size_t PhoneNumCount = phone_book.size();

    for (size_t i = 0; i < PhoneNumCount - 1; ++i)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::cout << solution({ "119", "97674223", "1195524421" }) << std::endl;
    std::cout << solution({ "123","456","789" }) << std::endl;
    std::cout << solution({ "12","123","1235","567","88" }) << std::endl;
}
