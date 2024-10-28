// 241028_17680.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// [1차]캐시

/*
문제 설명
지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와 관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.
이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전 각 로직에 대한 성능 측정을 수행하였는데,
제이지가 작성한 부분 중 데이터베이스에서 게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.
어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고, 제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야 효율적인지 몰라 난감한 상황이다.

어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오.

입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

- 캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
- cache hit일 경우 실행시간은 1이다.
- cache miss일 경우 실행시간은 5이다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Cache
{
public:
    Cache(int _MaxSize)
        : MaxSize(_MaxSize)
    {

    }

    bool Check(const std::string& _SearchData)
    {
        return CacheMemory.end() != find_if(CacheMemory.begin(), CacheMemory.end(), [&](const std::pair<std::string, int> _Data)
            {
                return _Data.first == _SearchData;
            }
        );
    }

    void Hit(const std::string& _HitData)
    {
        std::vector<std::pair<std::string, int>>::iterator HitIter =  find_if(CacheMemory.begin(), CacheMemory.end(), [&](const std::pair<std::string, int> _Data)
            {
                return _Data.first == _HitData;
            }
        );

        HitIter->second = 0;
    }

    int GetCacheMemorySize() const
    {
        return static_cast<int>(CacheMemory.size());
    }

    void PlusTime()
    {
        const size_t CacheSize = CacheMemory.size();

        for (size_t i = 0; i < CacheSize; ++i)
        {
            ++CacheMemory[i].second;
        }
    }

    void ChangeData(const std::string& _Data)
    {
        if (true == Check(_Data))
        {
            return;
        }

        if (CacheMemory.size() < MaxSize)
        {
            PlusTime();
            CacheMemory.push_back(std::make_pair(_Data, 0));
            return;
        }

        size_t Index = std::min_element(CacheMemory.begin(), CacheMemory.end(), [&](const std::pair<std::string, int>& _Left, const std::pair<std::string, int>& _Right)
            {
                return _Left.second > _Right.second;
            }
        ) - CacheMemory.begin();

        PlusTime();
        CacheMemory[Index] = std::make_pair(_Data, 0);
    }

private:
    std::vector<std::pair<std::string, int>> CacheMemory;
    int MaxSize = -1;
};

int solution(int cacheSize, std::vector<std::string> cities)
{
    int answer = 0;

    if (cacheSize == 0)
    {
        return 5 * static_cast<int>(cities.size());
    }

    Cache CityCache = Cache(cacheSize);

    const size_t CityCount = cities.size();

    for (size_t i = 0; i < CityCount; ++i)
    {
        std::string CurCity = cities[i];

        std::transform(CurCity.begin(), CurCity.end(), CurCity.begin(), [](char _Char)
            {
                return std::tolower(_Char);
            }
        );

        if (true == CityCache.Check(CurCity))
        {
            CityCache.PlusTime();
            CityCache.Hit(CurCity);
            ++answer;
        }
        else
        {
            CityCache.ChangeData(CurCity);
            answer += 5;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << std::endl;
    std::cout << solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" }) << std::endl;
    std::cout << solution(2, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << std::endl;
    std::cout << solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" }) << std::endl;
    std::cout << solution(2, { "Jeju", "Pangyo", "NewYork", "newyork" }) << std::endl;
    std::cout << solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }) << std::endl;
    std::cout << solution(5, { "Jeju", "Jeju", "Jeju", "Jeju" }) << std::endl;
}
