//#include <iostream>
//#include <string>
//int main() {
//	std::string Hero_name = "Mustansir";
//	int e_health = 125;
//	int e_armor = 100;
//	int stamina =250;
//	int round = 0;
//	int money = 0;
//	std::string E_name = "A";
//	std::cout << "========================RULES========================"<<std::endl;
//	std::cout << "* Enemy has Health of " << e_health << std::endl;
//	std::cout << "* Enemy has Armor of " << e_armor << std::endl;
//	std::cout << "* You have 10 Rounds to Defeat " << e_health << std::endl;
//	std::cout << "* If you defeat him in under 3 rounds your get reward of 1,000$ " << std::endl;
//	std::cout << "* If you defeat him in under 5-7 rounds your get reward of 500$ " << std::endl;
//	std::cout << "* If you defeat him in under 7-10 rounds your get reward of 250$ " << std::endl;
//	std::cout << "* If you Can't defeat him in under 10 rounds you'll be Defeated!" << std::endl;
//	std::cout << "* You have 250 Stamina!" << std::endl;
//	std::cout << "* You'll lose 45 stamina if you attack between 75-100 to the Enemy!" << std::endl;
//	std::cout << "* You'll lose 25 stamina if you attack between 50-75  to the Enemy!"<< std::endl;
//	std::cout << "* You'll lose 15 stamina if you attack between 25-50  to the Enemy!" << std::endl;
//	std::cout << "* You'll lose 5 stamina if  you attack between 0-25   to the Enemy!" << std::endl;
//	std::cout << "* You'll recover 2 stamina if  you use range between 1-10 scale of Attacks to the Enemy!" << std::endl;
//	std::cout << "================================================" << std::endl;
//	while (e_armor > 0) {
//		round += 1;
//		int dmg;
//		std::cout << "\nRound: " << round << " (Attacking Armor)" << std::endl;
//		std::cout << "enter your damage:" << std::endl;
//		std::cin >> dmg;
//		if (dmg > 0 && dmg <= 10) {
//			std::cout << "Try Again!" << std::endl;
//			stamina += 2;
//		}
//		else if (dmg > 10 && dmg <= 25) {
//			std::cout << "Not a good Hit!" << std::endl;
//			stamina -= 5;
//		}
//		else if (dmg <= 50 && dmg >=25) {
//			std::cout << "Decent hit!" << std::endl;
//			stamina -= 15;
//		}else if (dmg <= 75 && dmg >=50) {
//			std::cout << "Good hit!" << std::endl;
//			stamina -= 25;
//		}else {
//			std::cout << "Critical Hit!" << std::endl;
//			stamina -= 45;
//		}
//		if (dmg > e_armor) {
//			int remain = dmg - e_armor;
//			e_armor = 0;
//			e_health -= remain;
//			if (remain > 0)std::cout << remain << " damage hit health!" << std::endl;
//		}
//		else {
//			e_armor -= dmg;
//			std::cout << "Armor health: " << e_armor << std::endl;
//			std::cout << "stamina Left: " << stamina<< std::endl;
//
//		}
//	}
//	while (e_health > 0) {
//		round +=1;
//		int dmg;
//		std::cout << "\nRound: " << round << " (Attacking Health)" << std::endl;
//		std::cout << "Enter your dmg:" << std::endl;
//		std::cin >> dmg;
//
//		e_health -= dmg;
//		if (dmg > 0 && dmg <= 10) {
//			std::cout << "Try Again!" << std::endl;
//			stamina += 2;
//		}
//		else if (dmg > 10 && dmg <=25) {
//			std::cout << "Not a good Hit!" << std::endl;
//			stamina -= 5;
//		}
//		else if (dmg <= 50 && dmg >= 25) {
//			std::cout << "Decent hit!" << std::endl;
//			stamina -= 15;
//		}
//		else if (dmg <= 75 && dmg >= 50) {
//			std::cout << "Good hit!" << std::endl;
//			stamina -= 25;
//		}
//		else {
//			std::cout << "Critical Hit!" << std::endl;
//			stamina -= 45;
//		}
//		if (e_health <= 0) {
//			std::cout << "Enemy Health: 0" << std::endl;
//		}
//		else {
//			std::cout << "Enemy Health: \n" << e_health << std::endl;
//			std::cout << "stamina Left: " << stamina << std::endl;
//
//		}
//	}
//	std::cout << "\nVICTORY! " << Hero_name << " defeated " << E_name << " in " << round << " rounds." << std::endl;
//
//	if (round <= 3) money = 1000;
//	else if (round >= 4 and round < 6) money = 500;
//	else if (round >= 7) money = 250;
//
//	if (money > 0) {
//		std::cout << "Here is your reward: " << money << " coins!" << std::endl;
//	}
//	else {
//		std::cout << "No reward for taking so long!" << std::endl;
//	}
//}
//#include <iostream>
//#include <string>
//class Weapon {
//public:
//	std::string type;
//	int dmg;
//	Weapon(std::string t, int d) {
//		type = t;
//		dmg = d;
//
//	}
//};
//int main() {
//		Weapon sword("Sword", 50);
//		std::cout << "You have a " << sword.type << "!" << std::endl;
//		std::cout << "It Does " << sword.dmg << " damage." << std::endl;
//}
//#include <iostream>
//#include <string>
//int main() {
//	std::string Hero_name = "Mustansir";
//	int e_health = 125;
//	int e_armor = 100;
//	int stamina = 250;
//	int round = 0;
//	int money = 0;
//	std::string E_name = "A";
//	std::cout << "========================RULES========================" << std::endl;
//	std::cout << "* Enemy has Health of " << e_health << std::endl;
//	std::cout << "* Enemy has Armor of " << e_armor << std::endl;
//	std::cout << "* You have 10 Rounds to Defeat " << e_health << std::endl;
//	std::cout << "* If you defeat him in under 3 rounds your get reward of 1,000$ " << std::endl;
//	std::cout << "* If you defeat him in under 5-7 rounds your get reward of 500$ " << std::endl;
//	std::cout << "* If you defeat him in under 7-10 rounds your get reward of 250$ " << std::endl;
//	std::cout << "* If you Can't defeat him in under 10 rounds you'll be Defeated!" << std::endl;
//	std::cout << "* You have 250 Stamina!" << std::endl;
//	std::cout << "* You'll lose 45 stamina if you attack between 75-100 to the Enemy!" << std::endl;
//	std::cout << "* You'll lose 25 stamina if you attack between 50-75  to the Enemy!" << std::endl;
//	std::cout << "* You'll lose 15 stamina if you attack between 25-50  to the Enemy!" << std::endl;
//	std::cout << "* You'll lose 5 stamina if  you attack between 0-25   to the Enemy!" << std::endl;
//	std::cout << "* You'll recover 2 stamina if  you use range between 1-10 scale of Attacks to the Enemy!" << std::endl;
//	std::cout << "================================================" << std::endl;
//	while (e_armor > 0) {
//		round++;
//		int dmg;
//		std::cout << "\nRound: " << round << " (Attacking Armor)" << std::endl;
//		std::cout << "enter your damage:" << std::endl;
//		std::cin >> dmg;
//		if (dmg > 0 && dmg <= 10) {
//			std::cout << "Try Again!" << std::endl;
//			stamina += 2;
//		}
//		else if (dmg > 10 && dmg <= 25) {
//			std::cout << "Not a good Hit!" << std::endl;
//			stamina -= 5;
//		}
//		else if (dmg <= 50 && dmg >= 25) {
//			std::cout << "Decent hit!" << std::endl;
//			stamina -= 15;
//		}
//		else if (dmg <= 75 && dmg >= 50) {
//			std::cout << "Good hit!" << std::endl;
//			stamina -= 25;
//		}
//		else {
//			std::cout << "Critical Hit!" << std::endl;
//			stamina -= 45;
//		}	
//		if (dmg > e_armor) {
//			int remain = dmg - e_armor;
//			e_armor = 0;
//			e_health -= remain;
//			if (remain > 0)std::cout << remain << " damage hit health!" << std::endl;
//		}
//		else {
//			e_armor -= dmg;
//			std::cout << "Armor health: " << e_armor << std::endl;
//			std::cout << "stamina Left: " << stamina<< std::endl;
//		}
//	}
//	while (e_health > 0){
//		round++;
//		int dmg;
//		std::cout << "\nRound: " << round << " (Attacking Armor)" << std::endl;
//		std::cout << "enter your damage:" << std::endl;
//		std::cin >> dmg;
//
//
//		if (dmg > 0 && dmg <= 10) {
//			std::cout << "Try Again!" << std::endl;
//			stamina += 2;
//		}
//		else if (dmg > 10 && dmg <= 25) {
//			std::cout << "Not a good Hit!" << std::endl;
//			stamina -= 5;
//		}
//		else if (dmg <= 50 && dmg >= 25) {
//			std::cout << "Decent hit!" << std::endl;
//			stamina -= 15;
//		}
//		else if (dmg <= 75 && dmg >= 50) {
//			std::cout << "Good hit!" << std::endl;
//			stamina -= 25;
//		}
//		else {
//			std::cout << "Critical Hit!" << std::endl;
//			stamina -= 45;
//		}
//		if (e_health <= 0) {
//			std::cout << "Enemy Health: 0" << std::endl;
//		}
//		else {
//			std::cout << "Enemy Health: \n" << e_health << std::endl;
//			std::cout << "stamina Left: " << stamina << std::endl;
//			
//		}
//	}
//	std::cout << "\nVICTORY! " << Hero_name << " defeated " << E_name << " in " << round << " rounds." << std::endl;
//	
//	if (round <= 3) money = 1000;
//	else if (round >= 4 && round <=7) money = 500;
//	if (round <= 10 && round >=8) money = 250;
//
//	if (money > 0) {
//		std::cout << "Here is your reward: " << money << " coins!" << std::endl;
//	}
//	else {
//		std::cout << "No reward for taking so long!" << std::endl;
//	}
//}

//#include <iostream>
//#include <string>
//#include <ctime>
//class Weapon {
//public:
//	std::string name;
//	int dmg;
//	int health;
//	Weapon p1(std::string n, int d, int h) {
//		name = n;
//		dmg = d;
//		health = h;
//	}
//};
//int main() {
//	Weapon details("Sword", 125, 110);
//	std::cout << details.name << " has " << details.health << " health and does " << details.dmg << "damage!" << std::endl;
//}
//class student {
//public:
//
////};
//class Entity {
//public:
//	std::string name;
//	int health = 100;
//
//
//	void takedmg() {
//		int dmg;
//		std::cout << "enter the dmg taken:";
//		std::cin >> dmg;
//		health -= dmg;
//		std::cout << name << " has " << health << " HP left." << std::endl;
//	}
//};
//class player :public Entity {
//public:
//	int stamina = 50;
//	void sprint() { std::cout << name << " is sprinting!" << std::endl; }
//
//};
//
//int main() {
//	player myhero;
//	myhero.name = "Mustasnir";
//	myhero.takedmg();
//	myhero.sprint();
//
//	return 0;
//}
//
//class Enemy {
//public:
//	int health =100; 
//};
//int main() {
//	Enemy arr[3] ;
//	for (int i = 0; i < 3; i++) {
//		std::cout << "Enemy " << i << " health is: " << arr[i].health << std::endl;
//	}
//}

//int main() {
//	int waves[5];
//	for (int i = 0; i < 5; i++) {
//		waves[i] = i * 100;
//		std::cout << waves[i] << std::endl;
//
//	}
//}

//int main() {
//	int ammoClip[6];
//	for (int i = 0; i < 6; i++) {
//		ammoClip[i] = 50;
//		std::cout << "Loading bullet" << i << std::endl;
//	}
//	std::cout << "reloading complete!\n" << std::endl;
//	for (int i = 0; i < 6; i++) {
//		std::cout << "Firing Bullet!" << i << "! Damage:" <<ammoClip[i]<<std::endl;
//
//	}
//int main() {
//	int waves[5];
//	for (int i = 0; i < 5; i++) {
//		waves[i] = i * 100;
//		std::cout << "wave: " << i <<" strength: " <<waves[i]<< std::endl;
//	}
//}

//int main() {
//	int targets[3] = { 20,50,100 };
//	int totalscore = 0;
//	for (int i = 0; i < 3; i++) {
//		int accuracy;
//		std::cout << "Target " << targets[i] << " appearing! Enter your accuracy (0 to 100):" << std::endl;
//		std::cin >> accuracy;
//		if (accuracy >= 60) {
//			totalscore += targets[i];
//		}
//		else {
//			std::cout << "Miss!" <<std::endl;
//		}
//	}
//	std::cout << "the total score is: " << totalscore << std::endl;
//}

//struct Item
//{
//	std::string name;
//	int goldValue;
//};
//int main() {
//	Item Inventory[3];
//	Inventory[0].name = "Sword";
//	Inventory[0].goldValue = 100;
//	Inventory[1].name = "Shield";
//	Inventory[1].goldValue = 150;
//	Inventory[2].name = "Potion";
//	Inventory[2].goldValue = 50;
//
//	int total = 0;
//	for (int i = 0; i < 3; i++) {
//		total += Inventory[i].goldValue;
//	}
//	std::cout << "The total Value is: " << total << std::endl;
//}





#include <iostream>
#include <string>
#include <ctime>
const int MAX_HP = 100;
const int POTION_HEAL= 30;
const int POTION_COST = 50;
const int SWORD_COST = 150;
const int ATTACK_POWER= 20;

class Player {
public:
	std::string name;
	int hp = 100;
	int gold = 0;
    int bonusDamage = 0;
    int kill_count = 0;

	void showstats() {
		std::cout << "\n--- " << name << "'s Stats ---" << std::endl;
        std::cout << "HP: " << hp << " | Gold: " << gold << std::endl;
        std::cout << "Kills: " << kill_count<< std::endl;
		std::cout << "--------------------" << std::endl;
	}

    void levelUp() {
        level += 1;
        hp = 100;
    }

    bool takeDamage(int amount) {
        hp -= amount;
        std::cout << name << " took " << amount << " damage!" << std::endl;
        if (hp <= 0) {
            return true;
        }
        return false;
    }

private:
    int level=1;
};
class Monster {

public:
    std::string type;
    int health;
    int damage;
    int gold;

    Monster(std::string t, int h, int d, int minGold, int maxGold) {
        type = t;
        health = h;
        damage = d;
        gold = minGold + rand() % (maxGold - minGold + 1);
    }
}; 

void restAtCamp(Player& p) {
    std::cout << "You sit by the campfire and rest.." << std::endl;
    p.hp = std::min(p.hp + 5, 100);
}

int main() {
    srand(time(0));
    std::cout << "WELCOME TO THE C++ DUNGEON" << std::endl;

    Player hero;
    std::cout << "Enter your name, traveler: ";
    std::cin >> hero.name;

    bool isRunning = true;
    while (isRunning) {
        hero.showstats();

        std::cout << "1. Go North (Woods)\n2. Go South (Market)\n3. set camp-Fire and rest\n4.Quit game\n" << std::endl;
        std::cout << "Choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            if (hero.kill_count >= 5) {
                std::cout << "The dragon has Appeared!\n" << std::endl;
                int answer;
                std::cout << "Do you Wish to fight it 1.now 2.later?\n" << std::endl;
                std::cin >> answer;
                if (answer == 1) {
                    Monster Dragon("Dragon",150,35,250,500);
                    std::cout << "You are now in Dragon Arena!\n" << std::endl;
                    while (Dragon.health > 0 && hero.hp > 0) {
                        int damageDealt = (rand() % 25) + 1 + hero.bonusDamage;
                        if (damageDealt > 20) {
                            std::cout << "CRITICAL HIT" << std::endl;
                            damageDealt *= 2;
                        }
                        Dragon.health -= damageDealt;
                        std::cout << "You strike the Dragon for " << damageDealt << "!" << std::endl;
                        if (Dragon.health <= 0) {
                            std::cout << "\nVICTORY! You have slain the Dragon and won the game!" << std::endl;
                            isRunning = false;
                            break;
                        }


                        int montereHit = (rand() % Dragon.damage) + 1;
                        if (hero.takeDamage(montereHit)) {
                            std::cout << "The Dragon incinerated you..." << std::endl;
                            isRunning = false;
                            break;
                        }
                        std::cout << "Your HP: " << hero.hp << " | " << Dragon.type << " HP: " << Dragon.health << std::endl;
                        system("pause");
                    }
                    break;
                }
                else {
                    std::cout << "You flee to safety!" << std::endl;
                    break;
                }
                
            }
            Monster enemy("None", 0, 0, 0, 0);
            int encounter = rand() % 2;
            if (encounter == 0) {
                enemy = Monster("Goblin", 80, 10, 20, 50);
            }
            else {
                enemy = Monster("Orge", 100, 20, 100, 200);
            }

            std::cout << "A wild " << enemy.type << " jumps out!" << std::endl;

            while (enemy.health > 0 && hero.hp > 0) {
                std::cout << "\nYou attack the " << enemy.type << "!" << std::endl;
                int damageDealt = (rand() % 25) + 1 + hero.bonusDamage;
                if (damageDealt > 20) {
                    std::cout << "CRITICAL HIT" << std::endl;
                    damageDealt *= 2;
                }
                enemy.health -= damageDealt;

                if (enemy.health <= 0) {
                    std::cout << "You killed it! Time to level up!" << std::endl;
                    std::cout << "Loot Got:" << enemy.gold << std::endl;
                    hero.gold += enemy.gold;
                    hero.kill_count += 1;
                    hero.levelUp();

                    break;
                }
                

                int montereHit = (rand() % enemy.damage) + 1;
                if (hero.takeDamage(montereHit)) {
                    std::cout << "GAME OVER" << std::endl;
                    isRunning = false;
                    break;
                }
                std::cout << "Your HP: " << hero.hp << " | " << enemy.type << " HP: " << enemy.health << std::endl;
                system("pause");
            }
            break;
        }


        case 2:
            std::cout << "Welcome to the Market!" << std::endl;
            std::cout << "Buy Health Potion (50 Gold)? Restores 30 HP." << std::endl;
            std::cout << "Buy Iron Sword (150 Gold)." << std::endl;
            std::cout << "1. Buy Potion\n2.Buy Sword\n3. Leave\n4. rest at camp\n5. quit" << std::endl;
            int answer;
            std::cout << "Do you Wish to buy? \n" << std::endl;
            std::cin >> answer;
            switch (answer) {
            case 1:
                if (hero.gold >= POTION_COST) {
                    hero.gold -= POTION_COST;
                    hero.hp = std::min(hero.hp + 30, 100);
                    std::cout << "You chug the potion!" << std::endl;
                    hero.showstats();
                }
                else {
                    std::cout << "Merchant: 'Get out of here! You don't have enough gold!'" << std::endl;
                }
                break;
            case 2:
                    if (hero.bonusDamage > 0) {
                        std::cout << "you already have a Sword!" << std::endl;
                    }
                else if (hero.gold >= SWORD_COST) {
                    hero.gold -= SWORD_COST;
                    hero.bonusDamage += 10;
                    std::cout << "You bought the Iron Sword! You feel powerful." << std::endl;
                }
                else {
                        std::cout << "Merchant: 'Get out of here! You don't have enough gold!'" << std::endl;
                    }
                 break;

            case 3:
                std::cout << "You leave the market." << std::endl;
                break;

            default:
                std::cout << "Invalid choice." << std::endl;
                break;
            }

            system("pause");
            break;
        
        case 4:
            restAtCamp(hero);
            break;

        case 5:
            std::cout << "Thanks for playing!" << std::endl;
            isRunning = false;
            break;
        
        default:
            std::cout << "Invalid choice, Hero!" << std::endl;
            break;
        }
    }

    return 0;
}