# lab6

COMP2011 Lab6
Responsive image
Number Tower from THOSE GAMES
"Those games" you've seen in ads and want to play before.

Introduction
Welcome to Lab 6! In this lab, you will be provided with the Number Tower from "those games" in C++ code. Your objective is to write a recursive function to find the path to win the game.

In Number Tower, your goal is to boost your number, also known as strength, to defeat all the monsters. You have to visit every tower, and you must complete every floor of a tower before moving on to the next tower. On each floor, your strength will be boosted or shrunk depending on what you encounter. There is a boss in the last tower, so choose your path wisely to gain as much strength as possible to defeat the boss! The following is a clip of a game showcase:

Tasks
Start your coding with the skeleton code: lab6.cpp and main.cpp (last modified 21 Oct 7.27pm). Download both files and place them in the same directory. You only need to modify lab6.cpp.

Your task is to complete the recursive function with a helper function in lab6.cpp that finds and returns a path to win the game given the stage.

main.cpp contains the game code that calls your implementation in lab6.cpp, so please DO NOT modify main.cpp.

The following lecture notes may be useful for this lab:

Array
Function II: Recursion
Separate Compilation
Each stage is represented as a 2D array of C strings.

The first dimension is the tower number, with a maximum of 4.
The second dimension is the floor number, with a maximum of 4. You can assume that all towers have the same number of floors.
The C string represents the monster or item you encounter, indicated by an operator followed by a number (an integer).
'+' and '*' are for addition and multiplication (boost items).
'-' and '/' are for subtraction and integer division (debuffs). You will be knocked out immediately if your strength is non-positive after the encounter.
'M' represents the monster encounter.
The number represents the strength of the monster.
You obtain the strength of the monster if you have higher strength than the monster.
Otherwise, you will be knocked out immediately (your strength becomes -1).
An example stage is:

char stage[4][4][20] = {
    {"+5","*2","M10"},
    {"-8","/2","M28"}
};
In this stage, there are 2 towers.

In the 1st tower, the encounters from Floor 0 to Floor 3 are: +5, *2, and a monster with strength 10.
In the 2nd tower, the encounters from Floor 0 to Floor 3 are: -8, /2, and a monster with strength 28.
Say your initial strength is 7. A path that leads to a win is [0, 2, 1], [0, 2, 1], getting you a strength of 44 after the first tower and a strength of 32 after the second tower.

Complete the following functions in the provided code:

calculate_strength(): The helper function that returns the strength after the encounter.
find_path(): The recursive function that
Finds the path that leads to a win.
"Returns" the path by overwriting elements in the input parameter stage_path.
Returns the strength after taking the path.
You only need to complete the 2 base cases and 4 lines of code (look for TODO) for the recursive case.
You can find the details in the comments in the provided code.
Sample Output
We have provided 3 test cases for you in the skeleton code. They will be run consecutively when you run the program.

Place lab6.cpp and main.cpp in the same directory. Open the terminal in the directory.

Run this code to compile your code:

g++ -std=c++11 main.cpp lab6.cpp -o lab6
Run the executable:

./lab6.exe
If you implement the function correctly, you should see "Congrats! You won!" for all test cases. For example:

Test case 0:
Your final decision: ((0 2 1), (0 2 1))
You are now in tower 0
Your strength = 5. You decide to go to floor 0 with +5
Your strength now is 10.
Your strength = 10. You decide to go to floor 2 with M10
Your strength now is 20.
Your strength = 20. You decide to go to floor 1 with *2
Your strength now is 40.
You are now in tower 1
Your strength = 40. You decide to go to floor 0 with -8
Your strength now is 32.
Your strength = 32. You decide to go to floor 2 with M28
Your strength now is 60.
Your strength = 60. You decide to go to floor 1 with /2
Your strength now is 30.
Congrats! You won!

Test case 1:
Your final decision: ((0 3 2 1), (0 1 2 3), (1 2 0 3))
You are now in tower 0
Your strength = 5. You decide to go to floor 0 with +15
Your strength now is 20.
Your strength = 20. You decide to go to floor 3 with M20
Your strength now is 40.
Your strength = 40. You decide to go to floor 2 with *3
Your strength now is 120.
Your strength = 120. You decide to go to floor 1 with -5
Your strength now is 115.
You are now in tower 1
Your strength = 115. You decide to go to floor 0 with -10
Your strength now is 105.
Your strength = 105. You decide to go to floor 1 with /3
Your strength now is 35.
Your strength = 35. You decide to go to floor 2 with M20
Your strength now is 55.
Your strength = 55. You decide to go to floor 3 with M40
Your strength now is 95.
You are now in tower 2
Your strength = 95. You decide to go to floor 1 with -80
Your strength now is 15.
Your strength = 15. You decide to go to floor 2 with /5
Your strength now is 3.
Your strength = 3. You decide to go to floor 0 with +10
Your strength now is 13.
Your strength = 13. You decide to go to floor 3 with M10
Your strength now is 23.
Congrats! You won!

Test case 2:
Your final decision: ((0 1), (0 1), (0 1), (1 0))
You are now in tower 0
Your strength = 5. You decide to go to floor 0 with +8
Your strength now is 13.
Your strength = 13. You decide to go to floor 1 with M12
Your strength now is 25.
You are now in tower 1
Your strength = 25. You decide to go to floor 0 with +5
Your strength now is 30.
Your strength = 30. You decide to go to floor 1 with *2
Your strength now is 60.
You are now in tower 2
Your strength = 60. You decide to go to floor 0 with /2
Your strength now is 30.
Your strength = 30. You decide to go to floor 1 with M18
Your strength now is 48.
You are now in tower 3
Your strength = 48. You decide to go to floor 1 with M25
Your strength now is 73.
Your strength = 73. You decide to go to floor 0 with -25
Your strength now is 48.
Congrats! You won!
Your algorithm should be able to provide an optimal solution if implemented correctly, even though the winning path might not be unique.

As long as you have non-negative strength at the end, it is considered a win. The following is a path demonstrating a loss:

Test case 0:
Your final decision: ((0 1 2), (0 2 1))
You are now in tower 0
Your strength = 5. You decide to go to floor 0 with +5
Your strength now is 10.
Your strength = 10. You decide to go to floor 1 with *2
Your strength now is 20.
Your strength = 20. You decide to go to floor 2 with M10
Your strength now is 30.
You are now in tower 1
Your strength = 30. You decide to go to floor 0 with -8
Your strength now is 22.
Your strength = 22. You decide to go to floor 2 with M28
Your strength now is -1.
You lose D:
