// 241025_Question04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

/*
65 ~ 90 : A ~ Z
97 ~ 122 : a ~ z

*/

std::string caesarCipher(std::string s, int k)
{
    std::string Result = "";

    for (char CurChar : s)
    {
        if (CurChar >= 'A' && CurChar <= 'Z')
        {
            int MoveRange = k % 26;

            for (int i = 0; i < MoveRange; ++i)
            {
                if (CurChar == 'Z')
                {
                    CurChar = 'A';
                    continue;
                }

                ++CurChar;
            }
        }
        else if (CurChar >= 'a' && CurChar <= 'z')
        {
            int MoveRange = k % 26;

            for (int i = 0; i < MoveRange; ++i)
            {
                if (CurChar == 'z')
                {
                    CurChar = 'a';
                    continue;
                }

                ++CurChar;
            }
        }

        Result += CurChar;
    }

    return Result;
}

int main()
{
    std::cout << caesarCipher("Ciphering.", 26) << std::endl;
    std::cout << caesarCipher("www.abc.xy.", 87) << std::endl;
}