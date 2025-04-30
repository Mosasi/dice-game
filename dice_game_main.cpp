// Dice Game  
// Author: Mosa Assi  (github.com/Mosasi)  
// First version: April-2025  
// License: Apache License 2.0
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <limits> 

using namespace std;

#define N ((515485684+123456789)%6)
#define SEED ((515485684+123456789)%60)

bool CheckSum(int sum, int amount);
int Calculate(int sum, int c_3, int amount, char op);

/// <summary>
/// Validates that the requested bet is legal.
/// </summary>
/// <param name="bet"> 
/// The amount the player want to wager.
/// </param>
/// <param name="balance">
/// The player's current balance.
/// </param>
/// <returns>
/// true - the bet is illegal
/// false - the bet is legal
/// </returns>
bool CheckSum(int bet, int balance)
{
	if (bet <= 0)
	{
		cout << "You must choose a positive sum to play with" << endl;
		return true;
	}
	else if (bet > balance)
	{
		cout << "You don't have enough money, you only have " << balance << " left" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Function updates the player's balance after a single dice roll,
/// according to the amount bet and the player's guess.
/// </summary>
/// <param name="bet"> The bet of the player's. </param>
/// <param name="dice_sum"> The sum of the two dice rolled. </param>
/// <param name="amount"> The amount that the player began with. </param>
/// <param name="guess"> The player's guess. </param>
/// <returns> The player's updated balancea. </returns>
int Calculate(int bet, int dice_sum, int amount, char guess)
{

	if (dice_sum == 7 && guess == 'E')
	{
		cout << "You guessed right and x5 your bet" << endl;
		amount = amount + (bet * 5);
		return amount;
	}
	else if (dice_sum < 7 && guess == 'S' || dice_sum > 7 && guess == 'L')
	{
		cout << "You guessed right and doubled your bet" << endl;
		amount = amount + (bet * 2);
		return amount;
	}
	else
	{
		cout << "You guessed wrong" << endl;
		amount = amount - bet;
		return amount;
	}
}

int main()
{
	srand(SEED);
	const int Id1 = 515485684;
	const int Id2 = 123456789;
	const int r = N + 4; // Game Rounds
	int amount = 0;
	int sum = 0;
	char c = '\0';
	bool flag_2 = true;
	int s[r] = { 0 };
	int d1[r] = { 0 };
	int d2[r] = { 0 };
	char op[r] = { '\0' };
	int arr_amount[r] = { 0 };
	int rounds = 0;

	cout << Id1 << endl << Id2 << endl;
	cout << "Please choose the total amount for the game" << endl;
	cin >> amount;


	for (int i = 1; i <= r; i++)
	{


		do {
			cout << "Please choose a sum to play with" << endl;
			cin >> sum;
		} while (CheckSum(sum, amount));
		s[i - 1] = sum;
		do
		{
			cout << "Please guess the next larger (L) or smaller (S) or equal (E) to 7 " << endl;
			cin >> c;
			if (c == 'S' || c == 'L' || c == 'E')
				flag_2 = false;
			else
				flag_2 = true;

		} while (flag_2);
		op[i - 1] = c;

		int c_1 = 0, c_2 = 0, c_3 = 0;
		c_1 = rand() % 6 + 1;
		c_2 = rand() % 6 + 1;
		c_3 = c_1 + c_2;
		cout << "The dice roll result is " << c_1 << " and " << c_2 << endl;
		d1[i - 1] = c_1;
		d2[i - 1] = c_2;
		amount = Calculate(sum, c_3, amount, c);
		arr_amount[i - 1] = amount;

		cout << "You played " << i << " rounds out of " << r << " rounds, you have " << amount << " left to play with" << endl;
		cout << "------" << endl;


		if (amount == 0)
		{
			rounds = i;
			arr_amount[i - 1] = { 0 };
			cout << "You lost all your money, good luck next time" << endl;
			break;
		}
		else if (i == r)
		{
			rounds = i;
			cout << "Good game you have " << amount << " left" << endl;
			break;
		}
	}
	cout << "Game Summary" << endl;
	cout << "Player started with " << s[0] << endl;
	for (int i = 1; i <= rounds; i++)
		printf("Round %d : player bet on %d, player guess was %c, dice were %d, and %d, player has %d left.\n", i, s[i - 1], op[i - 1], d1[i - 1], d2[i - 1], arr_amount[i - 1]);

#ifdef _WIN32            // only on Windows  
	std::cout << "\nPress Enter to exit...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
#endif	
	return 0;

}
