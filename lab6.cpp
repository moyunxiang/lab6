#include <iostream>
using namespace std;

const int MAX_NUM_TOWER = 4;
const int MAX_NUM_FLOOR = 4;
const int MAX_ENCOUNTER_LENGTH = 10;

// Helper function to copy values an array to another. Provided.
void copy_floor(int to[], const int from[]){
    for (int i=0; i<MAX_NUM_FLOOR; i++){
        to[i] = from[i];
    }
}

// Helper function to calculate strength based on operation
/** 
 * TODO: Given the current strength and an encounter, calculate the new strength.
 * An encounter is a C string that contains an operator and a number (an integer), e.g. "+10", "M15", "*2", "M35".
 * The operator can be '+', '-', '*', '/', or 'M'.
 * - '+' and '-' are normal addition and subtraction.
 * - '*' is multiplication.
 * - '/' is integer division.
 * - 'M' represents the monster encounter. If the current strength is greater than the number, you defeat the monster and add the number to the strength. Otherwise, assign -1 to strength.
 * Note that you need to extract the number from the C string and convert it to an integer before performing the operation.
 */

int calculate_strength(int strength, const char encounter[MAX_ENCOUNTER_LENGTH]) {
    if (encounter[0] == 'M') {
        int m_value = atoi(encounter + 1);
        if (strength > m_value) {
            strength += m_value;
        } else {
            return -1;
        }
    } else {
        char operation = encounter[0];
        int value = atoi(encounter + 1); 

        switch (operation) {
            case '+':
                strength += value;
                break;
            case '-':
                strength -= value;
                break;
            case '*':
                strength *= value;
                break;
            case '/':
                if (value != 0) {
                    strength /= value;
                }
                break;
            default:
                break;
        }
    }
    return strength;
}

// Core recursive function
/**
 * TODO: Complete the missing blocks/lines in this recursive function find_path() that takes the following parameters:
 * - stage: a 2D array of C strings that represents the towers and floors. Each tower has at most 4 floors, and each floor has a encounter in C string.
 * - num_tower: the number of towers.
 * - current_tower: the current tower number (counts from 0).
 * - num_floor: the number of floors in each tower.
 * - explored_floor_count: the number of floors that have been explored in the current tower.
 * - explored_floor: an array of integers that contains the floor numbers of the explored floors in the current tower.
 * - strength: the current strength.
 * - floor_path: an array of integers that you will write the best path for this tower given the floor you explored. Use it as pass-by-reference to return the path.
z * The function should return the highest strength that you can achieve in this stage, i.e., the strength after taking the best path.
 */
int find_path(const char stage[][MAX_NUM_FLOOR][MAX_ENCOUNTER_LENGTH], int num_tower, int current_tower, 
    int num_floor, int explored_floor_count, int explored_floor[],
    int strength, int floor_path[], int stage_path[][MAX_NUM_FLOOR]){
    // TODO Base case 1: If the current tower is out of bounds, return the strength
    if(current_tower > num_tower)
    	return strength;
    // End of TODO

    // TODO Base case 2: If all floors have been explored, write the explored floor to floor path (backtracking), then return the strength
    if(explored_floor_count == num_floor)
	    return strength;
    // End of TODO

    // Recursive case
    int highest_strength = -1;
    int best_floor_path[MAX_NUM_FLOOR];
    // Try every unexplored floor in the current tower.
    for (int i=0; i<num_floor; i++){
        int selected_floor = i;
        // Check if the floor is already explored
        bool is_selected = false;
        for (int j=0; j<explored_floor_count; j++){
            if (selected_floor == explored_floor[j]){
                is_selected = true;
            }
        }
        if (is_selected){
            continue;
        }

        // Calculate the new strength
        int new_strength = calculate_strength(strength, stage[current_tower][selected_floor]);
        if (new_strength <= 0){
            continue;
        }

        // Recursion
        explored_floor[explored_floor_count] = selected_floor;
        int recursion_floor_path[MAX_NUM_FLOOR];
        // TODO: Complete the recursive function call to obtain the highest strength for the current floor selection
        int recursion_result = find_path();
        // End of TODO

        // Keep track of the highest strength and the best floor path
        if (recursion_result > highest_strength){
            highest_strength = recursion_result;
            copy_floor(best_floor_path, recursion_floor_path);
        }
    }

    // If the current tower is fully explored, backtrack the best path for the current floor and call the recursive function for the next tower
    if (explored_floor_count == 0){
        // TODO: Backtrack the best path for the current tower using a line of code (Use copy_floor())

        // End of TODO

        int floor_explored[MAX_NUM_FLOOR];
        int floor_path[MAX_NUM_FLOOR];
        // TODO: Complete the recursive function call to move to the next tower
        find_path();
        // End of TODO
    }

    // TODO: Backtrack the best path for the current floor selection using a line of code (Use copy_floor())
        
    // End of TODO
    return highest_strength;
}