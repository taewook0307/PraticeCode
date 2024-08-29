// 240829_250137.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 붕대감기

/*
문제 설명
어떤 게임에는 붕대 감기라는 기술이 있습니다.

붕대 감기는 t초 동안 붕대를 감으면서 1초마다 x만큼의 체력을 회복합니다.
t초 연속으로 붕대를 감는 데 성공한다면 y만큼의 체력을 추가로 회복합니다.
게임 캐릭터에는 최대 체력이 존재해 현재 체력이 최대 체력보다 커지는 것은 불가능합니다.

기술을 쓰는 도중 몬스터에게 공격을 당하면 기술이 취소되고, 공격을 당하는 순간에는 체력을 회복할 수 없습니다.
몬스터에게 공격당해 기술이 취소당하거나 기술이 끝나면 그 즉시 붕대 감기를 다시 사용하며, 연속 성공 시간이 0으로 초기화됩니다.

몬스터의 공격을 받으면 정해진 피해량만큼 현재 체력이 줄어듭니다.
이때, 현재 체력이 0 이하가 되면 캐릭터가 죽으며 더 이상 체력을 회복할 수 없습니다.

당신은 붕대감기 기술의 정보, 캐릭터가 가진 최대 체력과 몬스터의 공격 패턴이 주어질 때 캐릭터가 끝까지 생존할 수 있는지 궁금합니다.

붕대 감기 기술의 시전 시간, 1초당 회복량, 추가 회복량을 담은 1차원 정수 배열 bandage와
최대 체력을 의미하는 정수 health,
몬스터의 공격 시간과 피해량을 담은 2차원 정수 배열 attacks가 매개변수로 주어집니다.

모든 공격이 끝난 직후 남은 체력을 return 하도록 solution 함수를 완성해 주세요.
만약 몬스터의 공격을 받고 캐릭터의 체력이 0 이하가 되어 죽는다면 -1을 return 해주세요.
*/

#include <iostream>
#include <string>
#include <vector>

class Health
{
public:
    Health(int _InitHp = 0, int _ConditionHealCount = 0, int _PlusHeal = 0)
        : Hp(_InitHp), MaxHp(_InitHp), ConditionHealCount(_ConditionHealCount), PlusHeal(_PlusHeal)
    {

    }

    void TakeDamage(int _DamageValue)
    {
        // 데미지 후 지금까지 힐한 횟수 초기화
        Hp -= _DamageValue;
        SuccessContinueHealCount = 0;
    }

    void Heal(int _HealValue)
    {
        // Hp가 0이면 무시
        if (Hp <= 0)
        {
            return;
        }

        ++SuccessContinueHealCount;

        // 일반 힐
        if (SuccessContinueHealCount != ConditionHealCount)
        {
            Hp += _HealValue;
        }
        // 추가 힐
        else
        {
            Hp += _HealValue;
            Hp += PlusHeal;
            SuccessContinueHealCount = 0;
        }

        // Max 값 초과 시
        if (Hp > MaxHp)
        {
            Hp = MaxHp;
        }
    }

    int GetHp() const
    {
        return Hp <= 0 ? -1 : Hp;
    }

private:
    int Hp = 0;                             // 현재 Hp
    int MaxHp = 0;                          // 최대 Hp

    int SuccessContinueHealCount = 0;       // 힐은 연속한 횟수
    int ConditionHealCount = 0;             // 추가 힐 조건 횟수
    int PlusHeal = 0;                       // 추가 힐 량
};

int solution(std::vector<int> bandage, int health, std::vector<std::vector<int>> attacks)
{
    Health Stat = Health(health, bandage[0], bandage[2]);

    // 공격 횟수
    const int AttackCount = static_cast<int>(attacks.size());
    // 마지막 공격 시간
    const int LastAttackTime = attacks[AttackCount - 1][0];

    // 진행예정된 공격의 인덱스 값
    int CheckAttackIndex = 0;

    for (int i = 1; i <= LastAttackTime; ++i)
    {
        // 진행되야하는 공격 시간
        int CurAttackTime = attacks[CheckAttackIndex][0];

        if (CurAttackTime == i)
        {
            int CurAttackDamage = attacks[CheckAttackIndex][1];

            // Damage
            Stat.TakeDamage(CurAttackDamage);
            ++CheckAttackIndex;
        }
        else
        {
            // Heal
            Stat.Heal(bandage[1]);
        }   
    }

    return Stat.GetHp();
}

void PrintResult(const std::vector<int>& bandage, int health, const std::vector<std::vector<int>>& attacks)
{
    int Result = solution(bandage, health, attacks);

    std::cout << "Result : " << Result << std::endl;
}

int main()
{
    std::vector<int> bandage0 = { 5, 1, 5 };
    std::vector<std::vector<int>> attacks0 = { { 2, 10 },{ 9, 15 }, { 10, 5 }, { 11, 5 } };
    PrintResult(bandage0, 30, attacks0);

    std::vector<int> bandage1 = { 3, 2, 7 };
    std::vector<std::vector<int>> attacks1 = { { 1, 15 },{ 5, 16 }, { 8, 6 } };
    PrintResult(bandage1, 20, attacks1);

    std::vector<int> bandage2 = { 4, 2, 7 };
    std::vector<std::vector<int>> attacks2 = { { 1, 15 },{ 5, 16 }, { 8, 6 } };
    PrintResult(bandage2, 20, attacks2);

    std::vector<int> bandage3 = { 1, 1, 1 };
    std::vector<std::vector<int>> attacks3 = { { 1, 2 },{ 3, 2 } };
    PrintResult(bandage3, 5, attacks3);
}
