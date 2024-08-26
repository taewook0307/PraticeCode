// 240711_133502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 햄버거 만들기

/*
문제 설명
햄버거 가게에서 일을 하는 상수는 햄버거를 포장하는 일을 합니다.
함께 일을 하는 다른 직원들이 햄버거에 들어갈 재료를 조리해 주면 조리된 순서대로 상수의 앞에 아래서부터 위로 쌓이게 되고,
상수는 순서에 맞게 쌓여서 완성된 햄버거를 따로 옮겨 포장을 하게 됩니다.
상수가 일하는 가게는 정해진 순서(아래서부터, 빵 – 야채 – 고기 - 빵)로 쌓인 햄버거만 포장을 합니다.
상수는 손이 굉장히 빠르기 때문에 상수가 포장하는 동안 속 재료가 추가적으로 들어오는 일은 없으며,
재료의 높이는 무시하여 재료가 높이 쌓여서 일이 힘들어지는 경우는 없습니다.

예를 들어, 상수의 앞에 쌓이는 재료의 순서가 [야채, 빵, 빵, 야채, 고기, 빵, 야채, 고기, 빵]일 때,
상수는 여섯 번째 재료가 쌓였을 때, 세 번째 재료부터 여섯 번째 재료를 이용하여 햄버거를 포장하고,
아홉 번째 재료가 쌓였을 때, 두 번째 재료와 일곱 번째 재료부터 아홉 번째 재료를 이용하여 햄버거를 포장합니다.
즉, 2개의 햄버거를 포장하게 됩니다.

상수에게 전해지는 재료의 정보를 나타내는 정수 배열 ingredient가 주어졌을 때,
상수가 포장하는 햄버거의 개수를 return 하도록 solution 함수를 완성하시오.
*/

#include <iostream>
#include <string>
#include <vector>

// 시간 초과 -----------------------------------------------------------------------------------------------------------------------
//#include <algorithm>

//int solution(std::vector<int> ingredient) {
//    int answer = 0;
//
//    std::vector<int> HamburgerSequence = { 1, 2, 3, 1 };
//
//    int ingredientSize = ingredient.size();
//
//    bool MakeHamburger = true;
//
//    while (MakeHamburger)
//    {
//        for (int i = 3; i < ingredientSize; ++i)
//        {
//            int SliceStart = i - 3;
//            int SliceEnd = i;
//
// if ------------------------------------------------------------------------------------------------------------------------------
//            if (HamburgerSequence[0] == ingredient[SliceStart])
//            {
//                if (HamburgerSequence[1] == ingredient[SliceStart + 1])
//                {
//                    if (HamburgerSequence[2] == ingredient[SliceStart + 2])
//                    {
//                        if (HamburgerSequence[3] == ingredient[SliceEnd])
//                        {
//                            answer += 1;
//
//                            ingredient.erase(ingredient.begin() + SliceStart, ingredient.begin() + SliceEnd + 1);
//
//                            if (ingredientSize - 1 == SliceEnd)
//                            {
//                                ingredient.pop_back();
//                            }
//
//                            break;
//                        }
//                    }
//                }
//            }
//---------------------------------------------------------------------------------------------------------------------------------
// slice 이용 ---------------------------------------------------------------------------------------------------------------------
//            std::vector<int> slice(ingredient.begin() + SliceStart, ingredient.begin() + SliceEnd + 1);
//            
//            if (slice == HamburgerSequence)
//            {
//                answer += 1;
//            
//                ingredient.erase(ingredient.begin() + SliceStart, ingredient.begin() + SliceEnd + 1);
//            
//                if (ingredientSize - 1 == SliceEnd)
//                {
//                    ingredient.pop_back();
//                }
//            
//                break;
//            }
//---------------------------------------------------------------------------------------------------------------------------------
//
//            if (ingredientSize - 1 == SliceEnd)
//            {
//                MakeHamburger = false;
//            }
//        }
//
//        ingredientSize = ingredient.size();
//
//        if (4 > ingredientSize)
//        {
//            MakeHamburger = false;
//        }
//    }
//
//    return answer;
//}

#include <stack>

void MoveStackData(std::stack<int>* ReqStack, std::stack<int>* ResStack)
{
    ResStack->push(ReqStack->top());
    ReqStack->pop();
}

int solution(std::vector<int> ingredient)
{
    int answer = 0;

    std::vector<int> HamburgerRecipe = { 1, 2, 3, 1 };
    std::stack<int> ingredientStack;
    std::stack<int> CheckIngredientStack;

    for (const int CurIngredient : ingredient)
    {
        ingredientStack.push(CurIngredient);

        if (4 <= ingredientStack.size())
        {
            if (HamburgerRecipe[3] == ingredientStack.top())
            {
                MoveStackData(&ingredientStack, &CheckIngredientStack);

                if (HamburgerRecipe[2] == ingredientStack.top())
                {
                    MoveStackData(&ingredientStack, &CheckIngredientStack);

                    if (HamburgerRecipe[1] == ingredientStack.top())
                    {
                        MoveStackData(&ingredientStack, &CheckIngredientStack);

                        if (HamburgerRecipe[0] == ingredientStack.top())
                        {
                            MoveStackData(&ingredientStack, &CheckIngredientStack);

                            answer += 1;

                            while (false == CheckIngredientStack.empty())
                            {
                                CheckIngredientStack.pop();
                            }
                        }
                        else
                        {
                            while (false == CheckIngredientStack.empty())
                            {
                                MoveStackData(&CheckIngredientStack, &ingredientStack);
                            }
                        }
                    }
                    else
                    {
                        while (false == CheckIngredientStack.empty())
                        {
                            MoveStackData(&CheckIngredientStack, &ingredientStack);
                        }
                    }
                }
                else
                {
                    while (false == CheckIngredientStack.empty())
                    {
                        MoveStackData(&CheckIngredientStack, &ingredientStack);
                    }
                }
            }
        }
    }

    return answer;
}

void PrintResult(const std::vector<int>& ingredient)
{
    int Result = solution(ingredient);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> ingredient = { 2, 1, 1, 2, 3, 1, 2, 3, 1 };
    PrintResult(ingredient);

    std::vector<int> ingredient0 = { 1, 3, 2, 1, 2, 1, 3, 1, 2 };
    PrintResult(ingredient0);

    std::vector<int> ingredient1 = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3 };
    PrintResult(ingredient1);

    std::vector<int> ingredient2 = { 1, 2, 1, 2, 3, 1, 3, 1, 1, 2, 3, 1, 1, 2, 1, 2, 3, 1, 3, 1, 1, 2, 3, 1 };
    PrintResult(ingredient2);
}
