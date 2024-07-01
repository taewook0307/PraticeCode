// 240701.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 소수 만들기

/*
문제 설명
주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다.
숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.
*/


#include <vector>
#include <algorithm>
#include <iostream>

// 소수 인지 확인
bool IsPrimeNumber(int num)
{
    for (int i = 1; i <= num; ++i)
    {
        int RemainValue = num % i;

        if (0 == RemainValue)
        {
            if (1 != i && num != i)
            {
                return false;
            }
        }
    }

    return true;
}

int solution(std::vector<int> nums) {
    int answer = 0;

    sort(nums.begin(), nums.end());

    const int numsSize = nums.size();

    for (int i = 0; i < numsSize - 2; ++i)
    {
        for (int j = i + 1; j < numsSize - 1; ++j)
        {
            for (int k = j + 1; k < numsSize; ++k)
            {
                const int firstNum = nums[i];
                const int secondNum = nums[j];
                const int thirdNum = nums[k];

                const int CheckNum = firstNum + secondNum + thirdNum;

                bool IsPrime = IsPrimeNumber(CheckNum);

                if (true == IsPrime)
                {
                    ++answer;
                    printf_s("[%d,%d,%d]를 이용해서 %d을 만들 수 있습니다.\n", firstNum, secondNum, thirdNum, CheckNum);
                }
            }
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    std::cout << "answer : " << answer << std::endl;

    return answer;
}

//using namespace std;
//
//int solution(vector<int> nums) {
//    int answer = -1;
//
//    const int numsSize = nums.size();
//
//    for (int i = 0; i < numsSize - 2; ++i)
//    {
//        for (int j = i + 1; j < numsSize - 1; ++j)
//        {
//            for (int k = j + 1; k < numsSize; ++k)
//            {
//                const int firstNum = nums[i];
//                const int secondNum = nums[j];
//                const int thirdNum = nums[k];
//
//                const int sumNum = firstNum + secondNum + thirdNum;
//
//                for (int a = 1; a <= sumNum; ++a)
//                {
//                    int RemainValue = sumNum % a;
//
//                    if (0 == RemainValue)
//                    {
//                        if (1 != a && sumNum != a)
//                        {
//                            break;
//                        }
//                    }
//
//                    if (sumNum == a)
//                    {
//                        ++answer;
//                    }
//                }
//            }
//        }
//    }
//
//    cout << answer << endl;
//    return answer;
//}
//
//int main()
//{
//    std::vector<int> Example1 = { 1,2,3,4 };
//
//    solution(Example1);
//
//    std::vector<int> Example2 = { 1,2,7,6,4 };
//
//    solution(Example2);
//}

// 실패 -------------------------------------------------------------------------------------------
//int solution(std::vector<int> nums) {
//    int answer = -1;
//
//    //소수 + 합성수 + 합성수 = 소수
//    //소수 + 소수 + 합성수 = 소수
//
//    std::vector<int> PrimeNums;
//    std::vector<int> CompositeNums;
//
//    const int numsSize = nums.size();
//
//    // 소수와 합성수 분류
//    for (int i = 0; i < numsSize; ++i)
//    {
//        const int CheckNum = nums[i];
//
//        bool IsPrime = IsPrimeNumber(CheckNum);
//
//        if (true == IsPrime)
//        {
//            PrimeNums.push_back(CheckNum);
//        }
//        else
//        {
//            CompositeNums.push_back(CheckNum);
//        }
//    }
//
//    // 2배열의 크기
//    const int PrimeNumsSize = PrimeNums.size();
//    const int CompositeNumsSize = CompositeNums.size();
//
//    // 합성수 2개를 뽑는 숫자
//    const int SelectTwoCompositeNums = (CompositeNumsSize * (CompositeNumsSize - 1)) / 2;
//
//    // 소수 + 합성수 + 합성수
//    const int OnePrimeTwoComposite = SelectTwoCompositeNums * PrimeNumsSize;
//
//    // 소수 2개를 뽑는 숫자
//    const int SelectTwoPrimeNums = (PrimeNumsSize * (PrimeNumsSize - 1)) / 2;
//
//    // 소수 + 소수 + 합성수
//    const int TwoPrimeOneComposite = SelectTwoPrimeNums * CompositeNumsSize;
//
//    answer = OnePrimeTwoComposite + TwoPrimeOneComposite;
//
//    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
//    std::cout << "answer : " << answer << std::endl;
//
//    return answer;
//}