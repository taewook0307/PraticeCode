// MakeBracelet.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 팔찌 만들기

// 각 구슬의 가격과 매듭(*)이 나열된 문자열이 주어짐
// input 1. 매듭의 길이
// input 2. 매듭 
// input 3. 자를 인덱스 쌍의 개수
// input 4. 자를 인덱스 쌍
//   S : 왼쪽 자를 인덱스 2
//   E : 뒤쪽 자를 인덱스 8
// 
//      0 2     8           
//      111*213*22*3*132**12
//        1*213*2
//     매듭으로 묶여있지 않으면 없으면 구슬이 빠져버림.
//         *213*
//     이 팔찌 뭐시기의 가격은 6이 됨.
/////////////////////////////////////////////////////////////////

/*
<input 1>
20
111*213*22*3*132**12
4
3 8
10 18
0 11
4 9

<output>
6
9
10
0
*/


/*
<input 2>
300
323*3*22*113**3221*32*3*323323132*3*1**211122*311*11121**32*223313213*1133*23221322112212*12*1*2*3112*21122**2221112321123*221*13***12**32***31***231312213133*33312322*1*212*12122**3*1*112*12133332322111****1*331312*13211*2331113222*2*1111111*22311*1233122*3*13212*1121*213321**1*32121*33**3**2*11*12
20
53 166
218 238
92 136
59 235
12 103
23 220
0 255
187 221
71 215
89 231
177 191
199 284
90 237
126 133
170 277
71 133
177 229
205 282
47 247
24 269

<output>
149
22
53
257
134
278
352
50
199
181
8
104
200
4
147
79
58
104
275
333
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<int> MakeBracelet(int _KnotLength, const std::string& _Knot, int _CutCount, const std::vector<std::vector<int>>& _Cut)
{
	std::vector<int> Result;
	Result.reserve(_CutCount);
	std::vector<std::vector<int>> KnotPrice;

	int StartIndex = -1;
	int EndIndex = -1;
	int Price = 0;

	for (int i = 0; i < _KnotLength; ++i)
	{
		if (-1 == StartIndex)
		{
			StartIndex = i;

			if ('*' != _Knot[i])
			{
				int Value = _Knot[i] - '0';
				Price += Value;
			}

			continue;
		}

		if ('*' == _Knot[i] && -1 != StartIndex && -1 == EndIndex)
		{
			EndIndex = i;
			std::vector<int> PushVector = { StartIndex, EndIndex, Price };
			KnotPrice.push_back(PushVector);

			StartIndex = -1;
			EndIndex = -1;
			Price = 0;
			continue;
		}

		if('*' != _Knot[i])
		{
			int Value = _Knot[i] - '0';
			Price += Value;
		}

		if (i == _KnotLength - 1)
		{
			EndIndex = i;
			std::vector<int> PushVector = { StartIndex, EndIndex, Price };
			KnotPrice.push_back(PushVector);
		}
	}

	for (int i = 0; i < _CutCount; ++i)
	{
		std::vector<int> CurCut = _Cut[i];

		int CutStartIndex = CurCut[0];
		int CutEndIndex = CurCut[1];

		int Price = 0;

		const int KnotPriceCount = static_cast<int>(KnotPrice.size());
		for (int i = 0; i < KnotPriceCount; ++i)
		{
			if (CutStartIndex >= KnotPrice[i][0])
			{
				continue;
			}
			else
			{
				if (CutEndIndex >= KnotPrice[i][1])
				{
					Price += KnotPrice[i][2];
				}
				else
				{
					continue;
				}
			}
		}

		Result.push_back(Price);
	}

	return Result;
}

int main()
{
	std::string Knot0 = "111*213*22*3*132**12";
	const int Knot0Count = static_cast<int>(Knot0.size());

	std::vector<std::vector<int>> Cut0 = { { 3, 8 }, { 10, 18 }, { 0, 11 }, { 4, 9 } };
	const int Cut0Count = static_cast<int>(Cut0.size());

	MakeBracelet(Knot0Count, Knot0, Cut0Count, Cut0);
}
