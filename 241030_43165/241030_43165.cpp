// 241030_43165.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 타겟넘버

/*
문제 설명
n개의 음이 아닌 정수들이 있습니다.
이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다.
예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때
숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <vector>

int Recursive(const std::vector<int>& _Vector, int _Index, int _Current_Sum, int _Target, bool _IsPlus)
{
    int Count = 0;

    int PlusValue = _IsPlus == true ? _Vector[_Index] : -_Vector[_Index];

    _Current_Sum += PlusValue;

    if (_Index == _Vector.size() - 1 && _Current_Sum == _Target)
    {
        return 1;
    }
    else if (_Index == _Vector.size() - 1 && _Current_Sum != _Target)
    {
        return 0;
    }

    Count += Recursive(_Vector, _Index + 1, _Current_Sum, _Target, true);
    Count += Recursive(_Vector, _Index + 1, _Current_Sum, _Target, false);

    return Count;
}

int solution(std::vector<int> numbers, int target)
{
    int answer = 0;

    answer += Recursive(numbers, 0, 0, target, true);
    answer += Recursive(numbers, 0, 0, target, false);

    return answer;
}

int main()
{
    std::cout << solution({ 1, 1, 1, 1, 1 }, 3) << std::endl;
    std::cout << solution({ 4, 1, 2, 1 }, 4) << std::endl;
}
