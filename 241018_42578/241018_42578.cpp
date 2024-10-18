// 241018_42578.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 의상

/*
문제 설명
코니는 매일 다른 옷을 조합하여 입는것을 좋아합니다.

예를 들어 코니가 가진 옷이 아래와 같고, 오늘 코니가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야합니다.

종류	이름
얼굴	동그란 안경, 검정 선글라스
상의	파란색 티셔츠
하의	청바지
겉옷	긴 코트

- 코니는 각 종류별로 최대 1가지 의상만 착용할 수 있습니다. 예를 들어 위 예시의 경우 동그란 안경과 검정 선글라스를 동시에 착용할 수는 없습니다.
- 착용한 의상의 일부가 겹치더라도, 다른 의상이 겹치지 않거나, 혹은 의상을 추가로 더 착용한 경우에는 서로 다른 방법으로 옷을 착용한 것으로 계산합니다.
- 코니는 하루에 최소 한 개의 의상은 입습니다.

코니가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int solution(std::vector<std::vector<std::string>> clothes)
{
    int answer = 0;

    // 옷의 타입별 인덱스
    std::unordered_map<std::string, int> TypeToIndex;
    // 옷의 타입별 개수
    std::vector<int> TypeToClotheCount(clothes.size(), 0);

    int Index = 0;

    for (const std::vector<std::string>& CurClothe : clothes)
    {
        std::string Type = CurClothe[1];

        if (TypeToIndex.end() != TypeToIndex.find(Type))
        {
            ++TypeToClotheCount[TypeToIndex[Type]];
        }
        else
        {
            TypeToIndex.insert(std::make_pair(Type, Index));
            ++Index;

            ++TypeToClotheCount[TypeToIndex[Type]];
        }
    }
    
    // 조합론
    const size_t TypeCount = TypeToIndex.size();

    answer = TypeToClotheCount[0] + 1;

    for (size_t i = 1; i < TypeCount; ++i)
    {
        answer *= (TypeToClotheCount[i] + 1);
    }

    answer -= 1;

    return answer;
}

int main()
{
    std::cout << solution({ {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} }) << std::endl;
    std::cout << solution({ {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} }) << std::endl;
}

/*


의상 종류가 1개(a개)

a개

의상 종류가 2개(a개, b개)

a + b
ab

a + b + ab

의상 종류가 3개(a개, b개, c개)

a + b + c

ab + ac + bc

abc


의상이 1개

a + 1 - 1개

의상이 2개

(a + 1)(b + 1) - 1 = ab + a + b + 1 - 1

의상이 3개
(a + 1)(b + 1)(c + 1) - 1
= (ab + a + b + 1)(c + 1) - 1
= abc + ac + bc + c + ab + a + b + 1 - 1

*/
