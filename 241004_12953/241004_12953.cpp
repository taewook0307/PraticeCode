// 241004_12953.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// N개의 최소공배수

/*
문제 설명
두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다.
예를 들어 2와 7의 최소공배수는 14가 됩니다.

정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다.
n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

//int solution(std::vector<int> arr)
//{
//    int answer = 0;
//
//    // 오름차순으로 정렬
//    sort(arr.begin(), arr.end());
//
//    const size_t NumCount = arr.size();
//
//    // 가장 큰 값
//    int LargeValue = arr[NumCount - 1];
//    int CurrentMultiple = 1;
//
//    while (true)
//    {
//        // 1부터 차례대로 가장 큰 수에 곱을 구함
//        int Check = CurrentMultiple * LargeValue;
//        
//        bool AllClear = true;
//
//        for (int i = 0; i < NumCount; ++i)
//        {
//            if (0 != Check % arr[i])
//            {
//                AllClear = false;
//                break;
//            }
//        }
//
//        // arr의 모든 수로 곱한 수가 나누어질 경우 정답
//        if (true == AllClear)
//        {
//            answer = Check;
//            break;
//        }
//
//        ++CurrentMultiple;
//    }
//
//    return answer;
//}

// 다른 사람 풀이 -----------------------------------------------------
/*
유클리드 호제법 이용

유클리드 호제법이란 ?
2개의 자연수의 최대공약수를 구하는 방법

ex)
1071과 1029의 최대공약수 구하기

1071 % 1029 = 42
1029 % 42 = 21
42 % 21 = 0

최대공약수 = 21
*/

int gcd(int x, int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}

int lcm(int x, int y)
{
    int Num = gcd(x, y);
    return x * y / Num;
}

int solution(std::vector<int> arr)
{
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        answer = lcm(answer, arr[i]);
    }

    return answer;
}

int main()
{
    std::cout << solution({ 2,6,8,14 }) << std::endl;
    std::cout << solution({ 1,2,3 }) << std::endl;
}
