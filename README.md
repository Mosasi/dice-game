# Dice Game (C++)  

Console assignment for HW 3/Q 1: start with any bankroll, then play up to 4 + N rounds (N = (ID₁ + ID₂) mod 6).  
Before each throw you enter a positive stake (≤ your balance) and guess **L** (< 7), **E** (= 7) or **S** (> 7) for the sum of two fair dice.  
• Correct L/S doubles the stake • Correct E pays ×5 • Wrong guess loses the stake.  
The game ends when you run out of money or when all rounds are finished, after which a full per-round summary is printed.  

## Build  
```bash  
# Linux / macOS  
g++ -std=c++17 -O2 -o dice_game dice_game_main.cpp
# Windows (MinGW-w64)  
g++ -std=c++17 -O2 -static -o dice_game.exe dice_game_main.cpp 
# Windows (MSVC)  
cl /std:c++17 /O2 /EHsc dice_game_main.cpp /Fe:dice_game.exe
