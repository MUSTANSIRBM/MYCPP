#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
//// space trading game
//// Planet structure to store market data for each location
//struct Planet {
//	std::string Name;
//	int FuelPrice;
//	int CarbonPrice;
//	// constructor to initialize planet data
//	Planet(std::string name, int fuel_price, int Carbon_Price) {
//		Name = name;
//		FuelPrice = fuel_price;
//		CarbonPrice = Carbon_Price;
//
//	}
//
//};
//class Ship {
//public:
//	std::string Name;
//	int fuel = 0;
//	int credits = 0;
//	int cargo = 0;
//	Planet* currentPlanet;// pointer to track which planet the ship is at
//	//constructor :sets initial values for ship
//	Ship(std::string name, int f_level, int credit, int Cargo) {
//		Name = name;
//		fuel = f_level;
//		credits = credit;
//		cargo = Cargo;
//		currentPlanet = nullptr;
//	}
//	//Display current status of the ship
//	void Showstates() {
//		std::cout << "====================================" << std::endl;
//		std::cout << "Ship: " << Name << std::endl;
//		std::cout << "current fuel level: " << fuel << " credits: " << credits << std::endl;
//		std::cout << "current Cargo: "<<cargo<<std::endl;
//		std::cout << "====================================" << std::endl;
//	}
//	// update ship's location and fuel after traveling to a new planet
//	void TravelTo(Planet& Destination) {
//		if (fuel >= 20) {
//			fuel -= 20;
//			currentPlanet = &Destination;
//			std::cout << "welcome to: " << Destination.Name << std::endl;
//		}
//		else {
//			std::cout << "Not enough fuel to reach " << Destination.Name << std::endl;
//		}
//	}
//	// Trade functions for buying and selling resources
//	void buyFuel(){
//		int amount;
//		std::cout << "How many units of fuel?" << std::endl;
//		std::cin >> amount;
//		int totalcost = amount * currentPlanet->FuelPrice;
//		if (credits >= totalcost) {
//			credits -= totalcost;
//			fuel += amount;
//		}
//		else {
//			std::cout << "You're too poor for that much fuel!" << std::endl;
//		}
//
//	}
//	// Buy carbon function
//	void buycarbon() {
//		int amount;
//		std::cout << "How many units of carbon?" << std::endl;
//		std::cin >> amount;
//		int totalcost = amount * currentPlanet->CarbonPrice;
//		if (credits >= totalcost) {
//			credits -= totalcost;
//			cargo += amount;
//		}
//		else {
//			std::cout << "You're too poor for that much fuel!" << std::endl;
//		}
//
//	}
//	// Sell carbon function
//	void sellCarbon() {
//		int amount;
//		std::cout << "How many units of carbon you want to sell?" << std::endl;
//		std::cin >> amount;
//		int totalcost = amount * currentPlanet->CarbonPrice;
//		if (cargo >= amount) {
//			credits += totalcost;
//			cargo -= amount;
//		}
//		else {
//			std::cout << "You dont have that amount!" << std::endl;
//		}
//	}
//	//Loss condition function
//	void LOSS() {
//		
//			if (currentPlanet == nullptr || credits < currentPlanet->FuelPrice) {
//				std::cout << "\nSTRANDED! You have no fuel and no way to buy more." << std::endl;
//				std::cout << "Your ship drifts into the void forever..." << std::endl;
//			}
//			else {
//				// If we have money, we aren't dead yet, but we MUST buy fuel.
//				std::cout << "\n[!] WARNING: Fuel is empty! Go to TRADE to refuel now!" << std::endl;
//			}
//		}
//	//Win condition function
//	void WIN() {
//		std::cout << "\nCONGRATULATIONS! You have amassed 2000 credits and won the game!" << std::endl;
//	}
//	
//
//};
//
//// Main function to run the game loop
//int main() {
//	// Welcome message and instructions of the game
//	std::cout << "Welcome Captain "<< " to the Space Trading Game!" << std::endl;
//	std::cout << "Your mission is to travel between planets, trade resources, and reach 2000 credits to win!" << std::endl;
//	std::cout << "Good luck!\n" << std::endl;
//	// Initialize ship and planets
//	Ship nova("None", 100, 500, 0);
//	std::cout << "enter the name of Your Ship: " << std::endl;
//	std::cin >> nova.Name;
//
//	bool isRunning = true;
//	
//	// Envoirmental setup
//	Planet earth("Earth", 10, 50);
//	Planet mars("Mars", 20, 100);
//
//
//	
//	// Main Game loop
//	while (isRunning) {
//		// Conditional Checks for Win/Loss
//		if (nova.credits >= 2000) {
//			nova.WIN();
//			isRunning = false;
//			break;
//		}
//		if (nova.fuel <= 0) {
//			if (nova.currentPlanet != nullptr && nova.credits >= nova.currentPlanet->FuelPrice) {
//				std::cout << "\n[!] OUT OF FUEL! You must trade for fuel immediately!" << std::endl;
//			}
//		}else {nova.LOSS();
//			isRunning = false;
//			break;
//		}
//		
//		nova.Showstates();
//		int choice;
//		std::cout << "-----------MENU-----------\n1.To Travel.\n2.To Trade\n3.To see Status\n4.Quit\n--------------------------" << std::endl;
//		std::cin >> choice;
//
//
//
//		// Handle user choices
//		switch (choice) {
//		case 1: {
//			int choice;
//			std::cout << "Where Do you want to Travel:\n1.Earth\n2.Mars" << std::endl;
//			std::cin >> choice;
//			if (choice == 1) {
//				nova.TravelTo(earth);
//				nova.Showstates();
//			}
//
//			 else if (choice == 2) {
//				nova.TravelTo(mars);
//				nova.Showstates();
//			}
//			 else {
//				std::cout << "Invalid Planet!" << std::endl;
//			}
//		}
//			  break;
//
//
//		case 2: {
//			if (nova.currentPlanet == nullptr) {
//				std::cout << "You need to land First!\n" << std::endl;
//				break;
//			}
//			int Trade;
//			std::cout << "1.buy\n2.sell" << std::endl;
//			std::cin >> Trade;
//			if (Trade == 1) {
//				int trade_choice;
//				std::cout << "What do you want to Buy:\n1.Fuel\n2.Carbon" << std::endl;
//				std::cin >> trade_choice;
//
//				if (trade_choice == 1) {
//					nova.buyFuel();
//					std::cout << "now you have fuel level:" << nova.fuel << std::endl;
//				}
//
//				else if (trade_choice == 2) {
//					nova.buycarbon();
//					std::cout << "now you have  cargo:" << nova.cargo << std::endl;
//				}
//				else {
//					std::cout << "Invalid Choice!" << std::endl;
//				}
//				
//			}
//			if (Trade == 2) {
//				int trade_choice;
//				std::cout << "What do you want to sell:\nCarbon(1-yes/2-no)" << std::endl;
//				std::cin >> trade_choice;
//
//				if (trade_choice == 1) {
//					nova.sellCarbon();
//					std::cout << "you sold Cargo and now have:" <<nova.credits << std::endl;
//				}
//				else {
//					std::cout << "Invalid Choice!" << std::endl;
//				}
//				
//			}
//			break;
//	}
//
//
//		case 3: {
//			nova.Showstates();
//			std::cout << "" << std::endl;
//
//			break;
//		}
//
//
//		case 4: {
//			std::string answer;
//			std::cout << "you sure you want to quit? (yes/no)" << std::endl;
//			std::cin >> answer;
//			if (answer == "yes" || answer == "YES") {
//				std::cout << "Thanks for Playing!" << std::endl;
//				isRunning = false;
//				break;
//			}
//			if (answer == "no" || answer == "NO") {
//				std::cout << "\nback to Menu!" << std::endl;
//			}
//
//		break;
//		}
//
//
//		default:
//			std::cout << "Invalid Choice!" << std::endl;
//			break;
//		}
//	}
//	return 0;
//}




//empire builder game
//struct Building
//{
//	std::string name;
//	int cost;
//	int production;
//};
//class Empire {
//	private:
//		std::string Name;
//		int gold = 500;
//		std::vector<Building> Mycity;
//public:
//		Empire(std::string name) {
//			Name = name;
//		}
//
//	void Buildsomthing(std::string type){
//		if (type == "Farm") {
//			int cost = 100;
//			if (gold >= cost) {
//				gold -= cost;
//				Mycity.push_back({ "Farm", 100, 10 });
//				std::cout << "Built a Farm!" << std::endl;
//			}
//			else {
//				std::cout << "that's Invaild!" << std::endl;
//			}
//		}
//		else if (type == "Mine") {
//			int cost = 200;
//			if (gold >= cost) {
//				gold -= cost;
//				Mycity.push_back({ "Mine",200,25 });
//				std::cout << "Built a Mine!" << std::endl;
//			}
//			else {
//				std::cout << "that's Invaild!" << std::endl;
//			}
//		}
//
//	}
//	void endTurn() {
//		int turnIncome = 0;
//		for (int i = 0; i < Mycity.size(); i++) {
//			turnIncome += Mycity[i].production;
//		}
//		gold += turnIncome;
//		std::cout << "Turn Ended! You earned " << turnIncome << " gold." << std::endl;
//		std::cout << "Current Bank: " << gold << std::endl;
//	}
//};
//int main() {
//	Empire myEmpire("Roman");
//	myEmpire.Buildsomthing("Farm");
//
//	myEmpire.endTurn();
//}



struct Building {
	std::string name;
	int cost;
	int	production;
	int xp;
};

class Empire {

private:
	std::string Name;
	int gold = 500;
	std::vector<Building> Mycity;

public:
	int Xp = 0;
	Empire(std::string name) {
		Name = name;
	}

	
	void Build(std::string type) {
		
		if (type == "Farm") {
			int cost = 100;
			if (gold >= cost) {
				gold -= cost;
				Mycity.push_back({ "Farm",100,10,5});
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "Builded a Farm!" << std::endl;
				Xp += 5;
			}
			else {
				std::cout << "You Don't have money to build this!" << std::endl;

			}
		}

		else if (type == "House") {
			int cost = 250;
			if (gold >= cost) {
				gold -= cost;
				Mycity.push_back({ "House",250,30,10});
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Builded a House!" << std::endl;
				Xp += 10;
			}
			else {
				std::cout << "You Don't have money to build this!" << std::endl;
			}
		}

		else if (type == "Small-Cottage") {
			int cost = 350;
			if (gold >= cost) {
				gold -= cost;
				Mycity.push_back({ "Small-Cottage",350,70,25});
				std::this_thread::sleep_for(std::chrono::seconds(5));
				std::cout << "Builded a Small-Cottage!" << std::endl;
				Xp += 25;
			}
			else {
				std::cout << "You Don't have money to build this!" << std::endl;

			}
		}

		else if (type == "Building") {
			int cost = 550;
			if (gold >= cost) {
				gold -= cost;
				Mycity.push_back({ "Building",550,120,50});
				std::this_thread::sleep_for(std::chrono::seconds(7));
				std::cout << "Builded a Building!" << std::endl;
				Xp += 50;
			}
			else {
				std::cout << "You Don't have money to build this!" << std::endl;

			}
		}

		else if (type == "SkyScraper") {
			int cost = 750;
			if (gold >= cost) {
				gold -= cost;
				Mycity.push_back({ "SkyScraper",750,170,100});
				std::this_thread::sleep_for(std::chrono::seconds(10));
				std::cout << "Builded a SkyScraper!" << std::endl;
				Xp += 100;
			}
			
		}


		else if (type == "Monument") {
			int cost = 1000;
			if (gold >= cost) {
				gold -= cost;
				Mycity.push_back({ "Monument",1000,250,175});
				std::this_thread::sleep_for(std::chrono::seconds(12));
				std::cout << "Builded a Monument!" << std::endl;
				Xp += 175;
			}
			
		}
	}
		
	
	void endTurn() {
		int turnIncome = 0;
		int currentXp = 0;

		int event = rand() % 10;
		if (event == 1) {
			std::cout << "\nDisaster struck! A building has been destroyed!" << std::endl;
			Mycity.pop_back();
		}
		if (event == 2) {
			int bonus = 150;
			gold += bonus;
			std::cout << "\nLucky day! You found a hidden treasure and earned " << bonus << " gold!" << std::endl;
		}
		if (event == 3) {
			int bonus = 150;
			Xp += bonus;
			std::cout << "\nInspiration struck! You gained " << bonus << " extra experience points!" << std::endl;
		}
		if (event == 4) {
			int bonus = 150;
			gold -= bonus;
			std::cout << "\nUnWanted Tax! You lost " << bonus << " gold!" << std::endl;
		}

		for (int i = 0; i < Mycity.size(); i++) {
			turnIncome += Mycity[i].production;
		}
				gold += turnIncome;
				Xp += currentXp;
				std::cout << "\nTurn Ended! You earned " << turnIncome << " gold." << std::endl;
				std::cout << "Current Bank: " << gold << std::endl;
				std::cout << "Current Xp: " << Xp << std::endl;
			}
	
	void ShowCity() {
		if (Mycity.empty()) {
			std::cout << "Your city is empty! Build something first." << std::endl;
			return;
		}

		int f = 0, h = 0, sc = 0, b = 0, sk = 0, m = 0;

		
		for (int i = 0; i < Mycity.size(); i++) {
			if (Mycity[i].name == "Farm") f++;
			else if (Mycity[i].name == "House") h++;
			else if (Mycity[i].name == "Small-Cottage") sc++;
			else if (Mycity[i].name == "Building") b++;
			else if (Mycity[i].name == "SkyScraper") sk++;
			else if (Mycity[i].name == "Monument") m++;
		}

		std::cout << "\n--- City Inventory ---" << std::endl;
		if (f > 0) std::cout << "Farms: " << f << std::endl;
		if (h > 0) std::cout << "Houses: " << h << std::endl;
		if (sc > 0) std::cout << "Small-Cottages: " << sc << std::endl;
		if (b > 0) std::cout << "Buildings: " << b << std::endl;
		if (sk > 0) std::cout << "SkyScrapers: " << sk << std::endl;
		if (m > 0) std::cout << "Monuments: " << m << std::endl;
		std::cout << "----------------------" << std::endl;
	}

	
	bool confirmation(int cost) {
		if (gold >= cost) {
			std::string answer;
			std::cout << "Are you Sure? (yes/no):";
			std::cin >> answer;
			if (answer == "yes" || answer == "YES" ||answer == "y") {
				std::cout <<"Building..." << std::endl;

			return true;
			}
			else {
				std::cout << "Back to Main Menu!" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "You Don't have money to build this!" << std::endl;
			return false;
		}
	}
	void ShowLevel() {
		if (Xp >= 0 && Xp <= 1000) {
			std::cout << "Current Level: 1" << std::endl;
		}
		else if (Xp > 1000 && Xp <= 3000) {
			std::cout << "Current Level: 2" << std::endl;
		}
		else if (Xp > 3000 && Xp <= 6000) {
			std::cout << "Current Level: 3" << std::endl;
		}
		else if (Xp > 6000 && Xp <= 9000) {
			std::cout << "Current Level: 4" << std::endl;
		}
		else if (Xp > 9000) {
			std::cout << "Current Level: 5" << std::endl;
		}
	}
	
	void saveGame(){
		std::ofstream saveFile("Progress.txt");
		int FarmCount = 0;
		int houseCount = 0;
		int Small_CottageCount = 0;
		int BuildingCount = 0;
		int SkyScraperCount = 0;
		int MonumentCount =0;
		
		for (int i = 0; i < Mycity.size(); i++) {
			if (Mycity[i].name == "Farm") {
				FarmCount += 1;
			}
			else if (Mycity[i].name == "House") {
				houseCount += 1;
			}
			else if (Mycity[i].name == "Small-Cottage") {
				Small_CottageCount += 1;
			}
			else if (Mycity[i].name == "Building") {
				BuildingCount += 1;
			}
			else if (Mycity[i].name == "SkyScraper") {
				SkyScraperCount += 1;
			}
			else if (Mycity[i].name == "Monument") {
				MonumentCount += 1;
			}
		}
		
		if (saveFile.is_open()) {
			saveFile << gold << ' ' << Xp << ' ' <<FarmCount << ' ' << houseCount << ' ' << Small_CottageCount << ' ' << BuildingCount << ' '<<SkyScraperCount <<' ' << MonumentCount << ' ';
			saveFile.close();
		}

	}

	
	void loadGame() {
		std::ifstream LoadFile("Progress.txt");
		int FarmCount;
		int houseCount;
		int Small_CottageCount;
		int BuildingCount;
		int SkyScraperCount;
		int MonumentCount;
		
		if (LoadFile.is_open()) {
			LoadFile >> gold >> Xp>>FarmCount>>houseCount>>Small_CottageCount>>BuildingCount>>SkyScraperCount>>MonumentCount;
			for (int i = 0; i < FarmCount; i++) { Mycity.push_back({ "Farm", 100, 10, 5 }); }
			for (int i = 0; i < houseCount; i++) { Mycity.push_back({ "House", 250, 30, 10 }); }
			for (int i = 0; i < Small_CottageCount; i++) { Mycity.push_back({ "Small-Cottage",350,70,25 }); }
			for (int i = 0; i < BuildingCount; i++) { Mycity.push_back({ "Building", 550,120,50 }); }
			for (int i = 0; i < SkyScraperCount; i++) { Mycity.push_back({ "SkyScraper", 750,170,100 }); }
			for (int i = 0; i < MonumentCount; i++) { Mycity.push_back({ "Monument", 1000,250,175 }); }
			std::cout << "Progress Loaded!" << std::endl;
			LoadFile.close();
		}
		else {
			std::cout << "save file found. Starting fresh!" << std::endl;
		}
	}

};


int main() {
srand(time(0));
	Empire Mine("Rome");
	bool IsRunning = true;
	
	Mine.loadGame();
		std::cout << "Welcome to city Builder game!\n" << std::endl;
		std::cout << "-------------Rules-------------" << std::endl;
		std::cout << "You need you Build your city to reach experience 10,000" << std::endl;
		std::cout << "Some Money is given to you to start the game" << std::endl;
		std::cout << "The the cost is depended on the structure!" << std::endl;
		std::cout << "Enjoy your game" << std::endl;
		std::cout << "-------------------------------" << std::endl;

while(IsRunning){
		int choice;
		std::cout << "\nenter you choice:\n1.Build\n2.See your Builds\n3.To See the Current Level\n4.To EndTurn\n5.Quit" << std::endl;
		std::cin >> choice;
		
		while (!std::cin >> choice) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "\nInvaild Choice! Please enter a number Not Letter!" << std::endl;
		}
		
	switch (choice) {
		
		case 1: {
			int answer;
			std::cout << "\n--- BUILD MENU ---" << std::endl;
			std::cout << "1. Farm (100) time:1 Second\n2. House (250) time:2 Second\n3. Small-Cottage (350) time:5 Second\n4. Building (550) time:7 Second\n5. SkyScraper (750) time:10 Second\n6. Monument (1000) time:12 Second" << std::endl;
			std::cin >> answer;
			while (!std::cin >> answer) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
			
			switch (answer) {
			case 1:
				if (Mine.confirmation(100)) Mine.Build("Farm");
				break;
			case 2:
				if (Mine.confirmation(250)) Mine.Build("House");
				break;
			case 3:
				if (Mine.confirmation(350)) Mine.Build("Small-Cottage");
				break;
			case 4:
				if (Mine.confirmation(550)) Mine.Build("Building");
				break;
			case 5:
				if (Mine.confirmation(750)) Mine.Build("SkyScraper");
				break;
			case 6:
				if (Mine.confirmation(1000)) Mine.Build("Monument");
				break;
			default:
				std::cout << "Invalid building choice." << std::endl;
			}
			break;
		}
		
		
		
		case 2:{
			Mine.ShowCity();
			break;
		}
			
		
		case 3: {
			Mine.ShowLevel();
			std::cout << "Current Xp:"<<Mine.Xp << std::endl;
			break;
		}
		
		case 4: {
			Mine.endTurn();
			if (Mine.Xp >= 10000) { 
				std::cout << "Congratulations you completed the game!" << std::endl;
				IsRunning = false;
			}
			system("pause");
			break;
		}
		
		case 5: {
			char ans;
			std::cout << "Are you  sure to Quit?(y/n)" << std::endl;
			std::cin >> ans;
			if (ans == 'y') {
				Mine.saveGame();
				std::cout << "Thanks for Playing!" << std::endl;
				IsRunning = false;
			}
			else {
				std::cout << "Great Choice!" << std::endl;
			}
		}
	}	
}
	return 0;
}