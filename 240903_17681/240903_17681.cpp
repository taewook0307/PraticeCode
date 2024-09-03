// 240903_17681.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// (1차)비밀지도

/*
문제 설명
네오는 평소 프로도가 비상금을 숨겨놓는 장소를 알려줄 비밀지도를 손에 넣었다.
그런데 이 비밀지도는 숫자로 암호화되어 있어 위치를 확인하기 위해서는 암호를 해독해야 한다.
다행히 지도 암호를 해독할 방법을 적어놓은 메모도 함께 발견했다.

    1. 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.
    2. 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 "지도 1"과 "지도 2"라고 하자. 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다.
       지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
    3. "지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.
    4. 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열이다.

네오가 프로도의 비상금을 손에 넣을 수 있도록, 비밀지도의 암호를 해독하는 작업을 도와줄 프로그램을 작성하라.
*/

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <regex>

//std::string DecimalToBinary(int _Value, int _Size)
//{
//    std::string ReturnValue;
//    ReturnValue.reserve(_Size);
//
//    int ChangeValue = _Value;
//    std::string ChangeValueString;
//    while (ChangeValue > 0)
//    {
//        int RemainValue = ChangeValue % 2;
//        if (0 == RemainValue)
//        {
//            ChangeValueString.push_back(' ');
//        }
//        else
//        {
//            ChangeValueString.push_back('#');
//        }
//        
//        ChangeValue /= 2;
//    }
//
//    const int ChangeValueSize = static_cast<int>(ChangeValueString.size());
//
//    if (ChangeValueSize < _Size)
//    {
//        int PushCount = _Size - ChangeValueSize;
//        for (int i = 0; i < PushCount; ++i)
//        {
//            ReturnValue.push_back(' ');
//        }
//    }
//
//    for (int i = (ChangeValueSize - 1); i >= 0; --i)
//    {
//        ReturnValue.push_back(ChangeValueString[i]);
//    }
//
//    return ReturnValue;
//}

// bitset 사용 ------------------------------------------------------------------------------
std::string DecimalToBinary(int _Value, int _Size)
{
    std::string BinaryValue = std::bitset<16>(_Value).to_string();

    const int SliceIndex = 16 - _Size;

    std::string ReturnValue = BinaryValue.substr(SliceIndex, _Size);

    return ReturnValue;
}
// ------------------------------------------------------------------------------------------

//std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2)
//{
//    const int Arr1Size = arr1.size();
//
//    std::vector<std::string> answer;
//    answer.reserve(Arr1Size);
//
//    std::vector<std::string> AnalysisArr1;
//    AnalysisArr1.reserve(Arr1Size);
//
//    for (int Num : arr1)
//    {
//        AnalysisArr1.push_back(DecimalToBinary(Num, n));
//    }
//
//    std::vector<std::string> AnalysisArr2;
//    AnalysisArr2.reserve(Arr1Size);
//
//    for (int Num : arr2)
//    {
//        AnalysisArr2.push_back(DecimalToBinary(Num, n));
//    }
//
//    for (int i = 0; i < Arr1Size; ++i)
//    {
//        std::string PushString;
//        PushString.reserve(n);
//
//        for (int j = 0; j < n; ++j)
//        {
//            char Arr1Value = AnalysisArr1[i][j];
//            char Arr2Value = AnalysisArr2[i][j];
//
//            if (' ' == Arr1Value && ' ' == Arr2Value)
//            {
//                PushString.push_back(' ');
//            }
//            else
//            {
//                PushString.push_back('#');
//            }
//        }
//
//        answer.push_back(PushString);
//    }
//
//    return answer;
//}

// regex 사용 : 근데 매우 느림 --------------------------------------------------------------
std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2)
{
    std::vector<std::string> answer;
    answer.reserve(arr1.size());

    for (int i = 0; i < n; ++i)
    {
        arr1[i] = arr1[i] | arr2[i];
    }

    std::vector<std::string> ChangeBinary;

    for (int i = 0; i < n; ++i)
    {
        std::string BinaryNum = DecimalToBinary(arr1[i], n);
        
        BinaryNum = std::regex_replace(BinaryNum, std::regex("1"), "#");
        BinaryNum = std::regex_replace(BinaryNum, std::regex("0"), " ");

        answer.push_back(BinaryNum);
    }

    return answer;
}
// ------------------------------------------------------------------------------------------

void PrintResult(int n, const std::vector<int>& arr1, const std::vector<int>& arr2)
{
    std::vector<std::string> Result = solution(n, arr1, arr2);

    for (const std::string& CurString : Result)
    {
        std::cout << CurString << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr0 = { 9, 20, 28, 18, 11 };
    std::vector<int> arr1 = { 30, 1, 21, 17, 28 };

    PrintResult(5, arr0, arr1);
}
