#include <bits/stdc++.h>
using namespace std;

class CharacterActions
{
public:
    virtual int attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() = 0;
};

class BaseCharacter : public CharacterActions
{
protected:
    string name, specialAbility;
    int health, mana, attackPower, specialAbilityPower;

public:
    BaseCharacter(string n, int h, int a, string sa, int sap, int m = 0) : name(n), health(h), attackPower(a), specialAbility(sa), specialAbilityPower(sap), mana(m) {}

    int attack()
    {
        cout << name << " attacks with power " << attackPower << " !" << endl;
        mana += 50;
        if (mana >= 100)
        {
            useSpecialAbility();
            mana = 0;
            return attackPower + specialAbilityPower;
        }
        return attackPower;
    }

    void defend()
    {
        cout << name << " defends the attack !" << endl;
    }

    void useSpecialAbility()
    {
        cout << name << " uses " << specialAbility << " with power " << specialAbilityPower << " !" << endl;
    }

    void displayStats()
    {
        cout << name << " - Health: " << health << " - Mana: " << mana << endl;
    }

    string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getAttackPower()
    {
        return attackPower;
    }

    int getSpecialAbilityPower()
    {
        return specialAbilityPower;
    }

    void takeDamage(int damage)
    {
        health -= damage;
    }

    bool alive()
    {
        return health;
    }
};

class Warrior : public BaseCharacter
{
public:
    Warrior() : BaseCharacter("Warrior", 100, 25, "Berserk Rage", 35) {}
};

class Mage : public BaseCharacter
{
public:
    Mage() : BaseCharacter("Mage", 120, 20, "Arcane Blast", 30) {}
};

class Archer : public BaseCharacter
{
public:
    Archer() : BaseCharacter("Archer", 90, 20, "Fire Arrow", 35) {}
};

class BossEnemy
{
protected:
    int health, attack;

public:
    BossEnemy(int h = 150, int a = 30) : health(h), attack(a) {}

    int getHealth()
    {
        return health;
    }

    void takeDamage(int damage)
    {
        health -= damage;
    }

    bool alive()
    {
        if (health > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getAttackPower()
    {
        return attack;
    }
};

class GameEngine
{
    bool playerAlive(BaseCharacter *players[], int count)
    {
        for (int i = 0; i < count; i++)
        {
            if (!players[i]->alive())
                return false;
        }
        return true;
    }

public:
    void gameStarts(BaseCharacter *players[], int plNo, BossEnemy &boss)
    {
        cout << "Game begins! Player vs. Boss" << endl;
        while (boss.alive() && playerAlive(players, plNo))
        {
            for (int i = 0; i < plNo; i++)
            {
                int damage = players[i]->attack();
                boss.takeDamage(damage);
                cout << "Boss takes " << damage << " damage! Health now: " << boss.getHealth() << endl;
                if (!boss.alive())
                {
                    break;
                }
            }
            if (boss.alive())
            {
                for (int i = 0; i < plNo; i++)
                {
                    cout << "Boss attacks " << players[i]->getName() << " with power " << boss.getAttackPower() << " !" << endl;
                    players[i]->takeDamage(boss.getAttackPower());
                    cout << players[i]->getName() << " takes " << boss.getAttackPower() << " damage! Health now: " << players[i]->getHealth() << endl;
                }
            }
            else
            {
                break;
            }
        }
        if (boss.alive())
        {
            cout << "Boss wins! Players defeated!" << endl;
        }
        else
        {
            cout << "Boss defeated! Players win!" << endl;
        }
    }
};

int main()
{
    BaseCharacter *players[3];
    players[0] = new Warrior();
    players[1] = new Mage();
    players[2] = new Archer();

    BossEnemy Boss;

    GameEngine engine;
    engine.gameStarts(players, 3, Boss);

    return 0;
}