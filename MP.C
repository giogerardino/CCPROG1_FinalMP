#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define STARTMONEY 1500
#define STARTLOAN 4000


void DisplayDivider () {
	printf ("%s%s%s%s", "----------", "----------", "----------", "----------\n");
}
// STARTING MENU
void DisplayMain ()		{
	DisplayDivider();
	printf ("Good day! Welcome to Oil-bularyo!\n");
	printf ("Main Menu:\n");
	printf ("(1) Start a Sales Trip\n");
	printf ("(2) Change Settings\n");
	printf ("(3) Exit the Game\n");
}
//START MONEY FUNCTION
int money(int nChangeMoney) {
	int money;
	// checks if user input is same as STARMONEY 
	if (nChangeMoney != STARTMONEY && nChangeMoney > 1) 
		money = nChangeMoney;
	else if (nChangeMoney == STARTMONEY) 
		money = STARTMONEY;
	else if (nChangeMoney <= 0) 
		money = 1500;
	return money;
}
// START LOAN FUNCTION
int loan(int nChangeLoan) {
	int loan;
	// checks if user input is same as STARTLOAN 
	if (nChangeLoan != STARTLOAN && nChangeLoan > 1) 
		loan = nChangeLoan;
	else if (nChangeLoan == STARTLOAN)
		loan = STARTLOAN; 
	
	else if (nChangeLoan <= 0)
		loan = 4000;
	return loan;
}
int MaxDiffuserClearmindsBottles (int lemonCount, int rosemaryCount, int mintCount){
	int max = 0;
	while (lemonCount >= 3 && rosemaryCount >= 2 && mintCount >= 2) {
		lemonCount -= 3;
		rosemaryCount -= 2;
		mintCount -= 2;
		max++;
	}
	return max; // returns max bottles user can buy
}
int MaxEnergyBoosterBottles (int rosemaryCount, int mintCount, int lemonCount) {
	int max = 0;
	while (rosemaryCount >= 1 && mintCount >= 1 && lemonCount >= 1) {
		rosemaryCount -= 1;
		mintCount -= 1;
		lemonCount -= 1;
		max++;
	}
	return max;
}
int MaxCalmingBottles (int lavenderCount, int rosemaryCount, int lemonCount) {
	int max = 0;
	while (lavenderCount >= 3 && rosemaryCount >= 2 && lemonCount >= 1) {
		lavenderCount -= 3;
		rosemaryCount -= 2;
		lemonCount -= 1;
		max++;
	}
	return max;
}
// PlAYER CHOOSES WHAT TO MAKE
void MakeOption(int clearmindsbottles, int energyboosterbottles, int calmingbottles) {	
	printf ("What would you like to make?\n\n");
	printf ("(1)Clear Minds = 3 drops of Lemon, 2 drops of Rosemary, and 2 drops of Mint\n");
	printf ("Can make %d bottle(s)\n\n", clearmindsbottles);
	
	printf ("(2)Energy Booster = 1 drop of Rosemary, 1 drop of Mint, 1 drop of Lemon\n");
	printf ("Can make %d bottle(s)\n\n", energyboosterbottles);
	
	printf ("(3)Calming = 3 drops of Lavender, 2 drops of Rosemary, 1 drop of Lemon\n");
	printf("Can make %d bottle(s)\n\n", calmingbottles);
	DisplayDivider();
	printf ("Enter the number to select: ");
}
// DISPLAY PLAYER MOVE
void DisplayPlayerMove() { 
	printf("(1)Buy\n\n (2)Sell\n\n (3)Make\n\n (4)Pay Debt\n\n (5)Loan\n\n (6)Travel\n\n (7)Exit Game\n\n");
}
// PLAYER TRAVELS
void CurrentCity(int city, int* currentcity) {
	if (city == 1) {
		printf("You're in Manila!\n");
		*currentcity = city;
	}
	else if (city == 2) {
		printf("You're in Makati!\n");
		*currentcity = city;
	}
	else if (city == 3) {
		printf("You're in Alabang!\n");
		*currentcity = city;
	}
	else if (city == 4) {
		printf("You're in Quezon City!\n");
		*currentcity = city;
	}
	else {
		printf("Invalid input\n\n");
	}
}
// GENERATES RANDOM VALUE
int GenerateValue(int min, int max) {
	int price;
	price = (rand() % (max - min) + 1) + min;
	return price;
}	
// DISPLAYS LEMONS ON HAND 
void DisplayLemon (int* lemonCount) {
	printf("Lemon = %d drops\n", *lemonCount);
	DisplayDivider();
}
// DISPLAYS ROSEMARY ON HAND 
void DisplayRosemary (int* rosemaryCount) {
	printf("Rosemary = %d drops\n", *rosemaryCount);
	DisplayDivider();

}
// DISPLAYS LAVENDER ON HAND
void DisplayLavender (int* lavenderCount) {
	printf("Lavender = %d drops\n", *lavenderCount);
	DisplayDivider();
}
// DISPLAYS MINT ON HAND
void DisplayMint (int* mintCount) {
	printf("Mint = %d drops\n", *mintCount);
	DisplayDivider();
}
void DisplayEssentialOils (int lemonCount, int rosemaryCount, int lavenderCount, int mintCount) {
	printf("Lemon = %d\n", lemonCount);
	DisplayDivider();
	printf("Rosemary = %d\n", rosemaryCount);
	DisplayDivider();
	printf("Lavender = %d\n", lavenderCount);
	DisplayDivider();
	printf("Mint = %d\n", mintCount);
}
// DISPLAYS DIFFUSER ON HAND 
void DisplayDiffuser (int* clearminds, int* energybooster, int* calming, int BottlesDiffuser, int nMakeDiffuser) {
	switch (nMakeDiffuser) {
		case 1: 
			*clearminds += BottlesDiffuser;
			printf("Clearminds: %d\n\n", *clearminds);
			 break;
		case 2:
			*energybooster += BottlesDiffuser;
			printf("Energy Booster: %d\n\n", *energybooster);
			break;
		case 3:
			*calming += BottlesDiffuser;
			printf("Calming: %d\n\n", *calming);
			 break;
	}
}
// DISPLAYS TRAVEL OPTIONS
void TravelOptions() {
	printf("(1)Manila\n(2)Makati\n(3)Alabang\n(4)Quezon City\n");
}
int UpdatedPrice (int nPrice, int RNG, int factor) {
	if (RNG >= 1 && RNG <= 35) {
		nPrice += factor;
	}
	else if (RNG >= 36 && RNG <= 70) {
		if (factor < nPrice)
			nPrice -= factor;	
		else
			nPrice = 0;
		
	}
	else if (RNG >= 71 && RNG <= 90)
		nPrice *= factor;
	return nPrice;
}
//displays price list
void DisplayEssentialOilPrice (int nLemonPrice, int nLavenderPrice, int  nRosemaryPrice, int nMintPrice, int nStartMoney) {
	if (nLemonPrice > 0) {
		printf("(1) Lemon per bottle = %d\n", nLemonPrice);
		printf("Can buy %d bottle(s)\n\n", nStartMoney / nLemonPrice);
	}
	else  {
		printf("No available Lemon\n\n");
	}
	if (nLavenderPrice > 0) {
		printf("(2) Lavender per bottle = %d\n", nLavenderPrice);
		printf("Can buy %d bottle(s)\n\n", nStartMoney / nLavenderPrice);
	}
	else {
		printf("No available Lavender\n\n");
	}
	if (nRosemaryPrice > 0) {
		printf("(3) Rosemary  per bottle = %d\n", nRosemaryPrice);
		printf("Can buy %d bottle(s)\n\n", nStartMoney / nRosemaryPrice);
	}
	else {
		printf("No available Rosemary\n\n");
	}
	if (nMintPrice > 0) {
		printf("(4) Mint per bottle = %d\n", nMintPrice);
		printf("Can buy %d bottle(s)\n\n", nStartMoney / nMintPrice);
	}
	else  {
		printf("No available Mint\n\n");
	}
	printf("(0) To cancel transaction\n");
	DisplayDivider();
}
void DisplayDiffuserOilPrice (int lemonprice, int lavenderprice, int  rosemaryprice, int mintprice, int clearminds, int energybooster, int calming) {
	int clearmindsbottle;
	int energyboosterbottle;
	int calmingbottle;
	clearmindsbottle = 3 * lemonprice + 2 * rosemaryprice + 2 * mintprice;
	energyboosterbottle = rosemaryprice + mintprice + lemonprice;
	calmingbottle = 3 * lavenderprice + 2 * rosemaryprice + 1* lemonprice;
	
	if (clearminds > 0) {
		printf("(1)Clearminds: %d\n", clearminds);
		printf("per Bottle in the city = %d\n\n", clearmindsbottle);
	}
	else {
		printf("No Clearminds Diffuser on hand\n\n");
	}
	if (energybooster > 0) {
		printf("(2)Energy Booster: %d\n", energybooster);
		printf("per Bottle in the city = %d\n\n", energyboosterbottle);
	}
	else {
		printf("No Energy Booster on hand\n\n");
	}
	if (calming > 0) {
		printf("(3)Calming: %d\n", calming);
		printf("per Bottle in the city = %d\n\n", calmingbottle);
	}
	else {
		printf("No Calming Diffuser on hand\n\n");
	}	
}
void DisplayGameSummary (int clearminds, int energybooster, int calming, int nMoney, int nDebt) {
	printf("Remaining Diffuser Oils:\n\n");
	printf("Clearminds: %d\n\n", clearminds);
	printf("Energy Booster: %d\n\n", energybooster);
	printf("Calming: %d\n\n", calming);
	DisplayDivider();
	printf("Remaining Money: %d\n\n", nMoney);
	printf("Remaining Debt: %d\n\n", nDebt);
	DisplayDivider();
}
int main ()
{
	srand(time(NULL)); // generates random number every run
	
	int nChoose; 
	int nStartMoney;
	int nChangeMoney; // variable for changing startmoney
	int nStartLoan;
	int nMoney;
	int nChangeLoan; // variable for changing startloan
	
	int nLemonPrice, nLavenderPrice, nRosemaryPrice, nMintPrice;
	// initial value for essential oils on stock
	int lemonCount = 0; int rosemaryCount = 0; int lavenderCount = 0; int mintCount = 0;
	
	//initial value for diffuser oil on stock
	int clearminds = 0; int energybooster = 0; int calming = 0;
	
	//initial value of city = 1 = Manila
	int city = 1;
	// checks what current city is
	int currentcity = 1;
	
	// default values of cash, loan, and debt
	nChangeMoney = 1500; 
	nChangeLoan = 4000;
	int nDebt = 4000;
	
	nStartMoney = money(nChangeMoney);
	nStartLoan = loan(nChangeLoan);
	
	// generates prices of essential oil
	nLemonPrice = GenerateValue(100, 150);  
	nLavenderPrice = GenerateValue(20, 60);
	nRosemaryPrice = GenerateValue(70, 100);
	nMintPrice = GenerateValue(130, 200);
	
	// used to generate chance %
	int RNG = GenerateValue(1, 100);
	// used to generate factor value 
	int factor = GenerateValue(102, 199);
	//updated prices of essential oils
	nLemonPrice = UpdatedPrice(nLemonPrice, RNG, factor);
	nLavenderPrice = UpdatedPrice(nLavenderPrice, RNG, factor);
	nRosemaryPrice = UpdatedPrice(nRosemaryPrice, RNG, factor);
	nMintPrice = UpdatedPrice(nMintPrice, RNG, factor);

	int nCharge; // variable for charging when making a diffuser
	nChoose = 0;
	
	int nDay;
	nDay = 1;
	
	int nItemsEssential;
	while (nChoose != 3) {	
		if (nChoose != 1) {  
			DisplayMain();	//displays starting menu
			DisplayDivider();
			printf ("Enter the number to select: "); 
			scanf ("%d", &nChoose);
			DisplayDivider();
		}
		//start game 		
		if (nChoose == 1) {	
			int nOption;
			CurrentCity(city, &currentcity);
			printf ("Your money is %d\n", nStartMoney);
			printf ("Your loan %d\n", nStartLoan);
			printf ("Debt is %d\n", nDebt);
			printf ("Day %d\n", nDay);
			DisplayDivider();
			
			// Displays essential oil stock on hand 
			DisplayEssentialOils(lemonCount, lavenderCount, rosemaryCount, mintCount);
			
			printf ("what would you like to do?\n ");
			DisplayPlayerMove(); // shows player move
			DisplayDivider();
			printf ("Enter the number to select: ");	//makes player choose what move to make
			scanf ("%d", &nOption);
			system("cls");
			
			if (nOption == 1)	// buy option 
			{	
				int nBuyEssential;
				int nFinalPrice;
				int nItemsEssential;
				int inventory;
				printf("\nEssential Oils\n");
				DisplayDivider();
				DisplayEssentialOilPrice(nLemonPrice, nLavenderPrice, nRosemaryPrice, nMintPrice, nStartMoney);
				printf ("Enter the number of your option: ");
				scanf ("%d", &nBuyEssential);
				printf ("How many bottles would you like to buy?: ");
				scanf ("%d", &nItemsEssential);
				system("cls");	
					
				if (nBuyEssential == 1) // BUYS LEMON OIL
				{	
					if (nLemonPrice > 0)
					{
						nStartMoney -= nLemonPrice * nItemsEssential;	
						lemonCount += 10 * nItemsEssential;
					}
					else
						{
							printf("You cannot buy this!\n");
							DisplayDivider();
						}
				}		
				else if (nBuyEssential == 2) // if user buys lavender
				{
					if (nLavenderPrice > 0)
					{		
						nStartMoney -= nLavenderPrice * nItemsEssential;
						lavenderCount += 10 * nItemsEssential;
					}
					else
					{
						printf("You cannot buy this!\n");
						DisplayDivider();
					}
				}
				else if (nBuyEssential == 3)
				{
					if (nRosemaryPrice > 0)// if user buys rosemary
					{
						nStartMoney -= nRosemaryPrice * nItemsEssential;
						rosemaryCount += 10 * nItemsEssential;
					}	
					else
					{
						printf("You cannot buy this!\n");
						DisplayDivider();
					}
				
				}
				else if (nBuyEssential == 4)
				{
					if (nMintPrice > 0)
					{
						nStartMoney -= nMintPrice * nItemsEssential;
						mintCount += 10 * nItemsEssential;
					}	
					else 
					{
						printf("You cannot buy this!\n");
						DisplayDivider();
					}
				}
				else if (nBuyEssential == 0)
				{
					nItemsEssential = 0;
					printf("Transaction cancelled\n");
					DisplayDivider();
				}	
				else
				{
					printf("Enter a valid option!\n");
					DisplayDivider();
				}
			}		
			else if (nOption == 2)	//SELL OPTION
			{
				int selloption;	
				printf("What would you like to sell?\n");
				printf("(1)Essential Oil\n(2)Diffuser Oil\n");
				DisplayDivider();
				printf("Enter number to select: ");
				scanf("%d", &selloption);
				if (selloption == 1) // sells essential oils
				{
					int sellessential;
					int drops;
					//displays lemon essential oils on stock
					DisplayDivider();
					printf("(1)Lemon: %d\n", lemonCount); 
					printf("Average price in the city: %d\n", nLemonPrice / 10);
					DisplayLemon(&lemonCount);
					printf("\n\n");
					
					//displays rosemary essential oils on stock
					printf("(2)Rosemary: %d\n", rosemaryCount);
					printf("Average price in the city: %d\n", nRosemaryPrice / 10);
					DisplayRosemary(&rosemaryCount);
					printf("\n\n");
					
					//displays lavender essential oils on stock
					printf("(3)Lavender: %d\n", lavenderCount);
					printf("Average price in the city: %d\n", nLavenderPrice / 10);
					DisplayLavender(&lavenderCount);
					printf("\n\n");
					
					//displays mint essential oils on stock
					printf("(4)Mint: %d\n", mintCount);
					printf("Average price in the city: %d\n", nMintPrice / 10);
					DisplayMint(&mintCount);
					printf("Enter number to select: ");
					scanf("%d", &sellessential);
					printf("How many drops? ");
					scanf("%d", &drops);
					
					// if user sells lemon
					if (sellessential == 1 && drops <= lemonCount)
					{
						nStartMoney += nLemonPrice / 10 * drops;
					}
					// if user sells rosemary
					else if (sellessential == 2 && drops <= rosemaryCount)
					{
						nStartMoney += nRosemaryPrice / 10 * drops;
					}
					// if user sells lavnder
					else if (sellessential == 3 && drops <= lavenderCount)
					{
						nStartMoney += nLavenderPrice / 10 * drops;
					}
					// if user sells mint
					else if (sellessential == 4 && drops <= mintCount)
					{
						nStartMoney += nMintPrice / 10 * drops;
					}
					// if user doesnt have enough drops
					else 
					{
						printf("Insufficient drops!\n\n");
						DisplayDivider();
					}
				}
				else if (selloption == 2) // sells diffuser oils
				{
					int selldiffuser;
					int bottle;
					DisplayDiffuserOilPrice(nLemonPrice, nRosemaryPrice, nLavenderPrice, nMintPrice, clearminds, energybooster, calming);
					DisplayDivider();
					printf("Enter number to select: ");
					scanf("%d", &selldiffuser);
					printf("How many bottles? ");
					scanf("%d", &bottle);
					DisplayDivider();
					
					// sells clearminds diffuser oil and checks if number of bottle is same as stock
					if (selldiffuser == 1 && bottle <= clearminds)
					{
						clearminds -= bottle;
						nStartMoney += bottle * (3 * nLemonPrice + 2 * nRosemaryPrice + 2 * nMintPrice ) * 1.15 ; 
						lemonCount -= bottle * 3;
						rosemaryCount -= bottle * 2;
						mintCount -= bottle * 2;
					}
					// sells energybooster diffuser oil and checks if number of bottle is same as stock
					else if (selldiffuser == 2 && bottle <= energybooster)
					{
						energybooster -= bottle;
						nStartMoney += bottle * (nRosemaryPrice + nMintPrice + nLemonPrice) * 1.15;
						// i still mutiply it by 1 just to remember what happens here
						rosemaryCount -= bottle * 1; 
						mintCount -= bottle * 1;
						lemonCount -= bottle * 1;
					}
					// sells calming diffuser oil and checks if number of bottle is same as stock
					else if (selldiffuser == 3 && bottle <= calming)
					{
						calming -= bottle;
						nStartMoney += bottle * (3 * nLavenderPrice + 2 * nRosemaryPrice + nLemonPrice) * 1.15; 
						lavenderCount -= bottle * 3;
						rosemaryCount -= bottle * 2;
						lemonCount -= bottle * 1;
					}
					else
					{
						printf("Insufficient bottles!\n");
					}
				}
				else
				{
					printf("\nInvalid Input!");
					DisplayDivider();
				}
			}
			else if (nOption == 3)	//MAKE DIFFUSER OPTION
				{
					int nMakeDiffuser;
					int BottlesDiffuser;
					int clearmindsbottles = MaxDiffuserClearmindsBottles(lemonCount, rosemaryCount, mintCount);
					int energyboosterbottles = MaxEnergyBoosterBottles(rosemaryCount, mintCount, lemonCount);
					int calmingbottles = MaxCalmingBottles(lavenderCount, rosemaryCount, lemonCount);
					
					DisplayEssentialOils(lemonCount, lavenderCount, rosemaryCount, mintCount);
					
					MakeOption(clearmindsbottles, energyboosterbottles, calmingbottles);
					scanf ("%d", &nMakeDiffuser);
					printf("How many Bottles? ");
					scanf("%d", &BottlesDiffuser);
					system("cls");
					switch (nMakeDiffuser)
					{
						case 1: // make clearminds
							if (lemonCount <= 2 && rosemaryCount <= 1 && mintCount <= 1)
							{
								printf("Missing essential oils!\n");
								DisplayDivider();
							}
							else
							{
								if (city == 1)
								{
									nCharge = GenerateValue(20, 30);
									nStartMoney -= nCharge;
									lemonCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									mintCount -= 2 * BottlesDiffuser;
									
									printf("Succesfully made Clear Minds\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 2)
								{
									nCharge = GenerateValue(80, 100);
									nStartMoney -= nCharge;
									lemonCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									mintCount -= 2 * BottlesDiffuser; 
									
									printf("Successfully made Clear Minds\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 3)
								{
									nCharge = GenerateValue(70, 90);
									nStartMoney -= nCharge;
									lemonCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									mintCount -= 2 * BottlesDiffuser;
									
									printf("Successfully made Clear Minds\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 4)
								{
									nCharge = GenerateValue(40, 60);
									nStartMoney -= nCharge;
									lemonCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									mintCount -= 2 * BottlesDiffuser;
									
									printf("Successfully made Clear Minds\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}	
							}
							break;
						case 2: // make energybooster
							if (rosemaryCount <=1  && mintCount <=1  && lemonCount <= 1)
							{
								printf("Missing essential oils!\n");
								DisplayDivider();
								DisplayDivider();
							}
							else
							{
								if (city == 1)
								{
									nCharge = GenerateValue(20, 30);
									nStartMoney -= nCharge;
									rosemaryCount -= 1 * BottlesDiffuser;
									mintCount -= 1 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Succesfully made Energy Booster\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 2)
								{
									nCharge = GenerateValue(80, 100);
									nStartMoney -= nCharge;
									rosemaryCount -= 1 * BottlesDiffuser;
									mintCount -= 1 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Successfully made Energy Booster\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 3)
								{
									nCharge = GenerateValue(70, 90);
									nStartMoney -= nCharge;
									rosemaryCount -= 1 * BottlesDiffuser;
									mintCount -= 1 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Successfully made Energy Booster\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 4)
								{
									nCharge = GenerateValue(40, 60);
									nStartMoney -= nCharge;
									rosemaryCount -= 1 * BottlesDiffuser;
									mintCount -= 1 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Successfully made Energy Booster\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}	
							}	
							break;
						
						case 3: // make calming
							if (lavenderCount <= 2 && rosemaryCount <= 1 && lemonCount <= 1)
							{
								printf("Missing essential oils!\n");
							}
							else
							{
								if (city == 1)
								{
									nCharge = GenerateValue(20, 30);
									nStartMoney -= nCharge;
									lavenderCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Succesfully made Calming\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 2)
								{
									nCharge = GenerateValue(80, 100);
									nStartMoney -= nCharge;
									lavenderCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Successfully made Calming\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 3)
								{
									nCharge = GenerateValue(70, 90);
									nStartMoney -= nCharge;
									lavenderCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Successfully made Calming\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}
								else if (city == 4)
								{
									nCharge = GenerateValue(40, 60);
									nStartMoney -= nCharge;
									lavenderCount -= 3 * BottlesDiffuser;
									rosemaryCount -= 2 * BottlesDiffuser;
									lemonCount -= 1 * BottlesDiffuser;
									printf("Successfully made Calming\n");
									printf("Charged a total of %d\n", nCharge);
									DisplayDiffuser(&clearminds, &energybooster, &calming, BottlesDiffuser, nMakeDiffuser);
									DisplayDivider();
								}	
							}
							break;
						default:
							printf("Invalid Input!\n");
							DisplayDivider();
							break;
					}		
				}
			else if (nOption == 4)	//pay debt option
			{
				int paydebt;
				printf("Enter amount: "); // enter debt
				scanf("%d", &paydebt);
				system("cls");
				if (nDebt >= paydebt)
				{
					nStartMoney -= paydebt;
					nDebt -= paydebt;
					nStartLoan -= paydebt;
					printf("Successfully paid amount: %d\n\n", paydebt);
				}
				else
				{
					printf("Invalid transaction! No debt balance!\n");
				}
				DisplayDivider();
			}
			else if (nOption == 5)	//make loan option
			{
				int makeloan;
				printf("Enter amount: ");
				scanf("%d", &makeloan);
				system("cls");
				nStartMoney += makeloan; // adds the loan to cash
				nStartLoan += makeloan; // adds to loan
				nDebt += makeloan; // adds to debt
				printf("Loaned amount: %d\n", makeloan);
				DisplayDivider;
			}
			else if (nOption == 6)	//choose where to travel
			{
				
				int freebiechance;
				TravelOptions();
				DisplayDivider();
				printf("Enter number to select: ");
				scanf("%d", &city);
				system("cls");
				if (currentcity == city || city >= 5 || city <= 0)
				{
					DisplayDivider();
					printf("Invalid Input!\n");
					printf("You might be choosing the same city\n");
					DisplayDivider();
				}
				else 
				{
					currentcity = city;
					nDay += 1;
					nDebt += nStartLoan * 0.10;
					
					// generates different price of essential oil per city
					nLemonPrice = GenerateValue(100, 150);  
					nLavenderPrice = GenerateValue(20, 60);
					nRosemaryPrice = GenerateValue(70, 100);
					nMintPrice = GenerateValue(130, 200);
						
					// freebie chance generator
					freebiechance = GenerateValue(1, 100);
					if (freebiechance >= 1 && freebiechance <= 35)
					{
						if (freebiechance > 1 && freebiechance < 11)
						{
							clearminds += 1;
							printf("You got free Clearminds diffuser!\n\n");
							lemonCount += 3;
							rosemaryCount += 2;
							mintCount += 2;
							DisplayDivider();
						}
						else if (freebiechance > 11 && freebiechance < 22)
						{
							energybooster += 1;
							rosemaryCount += 1;
							mintCount += 1;
							lemonCount += 1;
							printf("You got free Energy Booster diffuser!\n\n");
							DisplayDivider();
						}
						else if (freebiechance > 22 && freebiechance < 33)
						{
							calming += 1;
							lavenderCount += 3;
							rosemaryCount += 2;
							lemonCount += 1;
							printf("You got free Calming Diffuser!\n\n");
							DisplayDivider();
						}
						else;
					}	
					// checks if day is = 15 
					if (nDay == 15)
					{
						printf("Game is Finished!\n");
						printf("Game summary:\n ");
						DisplayDivider();
						printf("Remaining Essential Oils:\n\n");
						// displays remaining essential oils
						DisplayEssentialOils(lemonCount, lavenderCount, rosemaryCount, mintCount);
						DisplayDivider();
						// displays game summary
						DisplayGameSummary(clearminds, energybooster, calming, nMoney, nDebt);
						nChoose = 3;
					}
					else;
				}	
			}
			else if (nOption == 7) // exits game while in progress
			{
				nChoose = 3;
				printf("Game exited!\n");
				printf("Thank you for playing!\n\n");
			}
			else
			{
				printf("Invalid input!\n");
				DisplayDivider();
			}
		}
		else if (nChoose == 2)	//change game settings
		{ 
			printf ("Settings\n\n");
			printf ("Note: if you input 0 in money and loan, it will automatically set it to the default money\n");
			printf ("Change starting money and loan\n");
			DisplayDivider();
			printf ("Enter starting Money: ");
			scanf ("%d", &nChangeMoney);
			nStartMoney = money(nChangeMoney);
			printf ("Enter starting Loan: ");
			scanf ("%d", &nChangeLoan);
			system("cls");
			nStartLoan = loan(nChangeLoan);

		}
		else if (nChoose > 3) { 
			printf("Enter a valid input!\n");
		}
		else  {
			printf("Game exited!\n");
			printf("Thank you for playing!\n\n");
		}
	}
	return 0;
}
