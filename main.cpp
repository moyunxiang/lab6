#include <iostream>
using namespace std;

const int MAX_NUM_TOWER = 4;
const int MAX_NUM_FLOOR = 4;
const int MAX_ENCOUNTER_LENGTH = 10;

int find_path(const char tower[][MAX_NUM_FLOOR][MAX_ENCOUNTER_LENGTH], int num_tower, int current_tower, 
    int num_floor, int explored_floor_count, int explored_floor[],
    int strength, int floor_path[], int stage_path[][MAX_NUM_FLOOR]);

// A hard-coded verison of calculate_strength() for testing
int testing_calculate_strength(int tc, int strength, int op_idx[2]){
    if (tc==0) {
        if (op_idx[0]==0 && op_idx[1]==0) return strength + 5;
        else if (op_idx[0]==0 && op_idx[1]==1) return strength * 2;
        else if (op_idx[0]==0 && op_idx[1]==2 && strength >= 10) return strength + 10;
        else if (op_idx[0]==1 && op_idx[1]==0) return strength - 8;
        else if (op_idx[0]==1 && op_idx[1]==1) return strength / 2;
        else if (op_idx[0]==1 && op_idx[1]==2 && strength >= 28) return strength + 28;
        else return -1;
    } else if (tc==1) {
        if (op_idx[0]==0 && op_idx[1]==0) return strength + 15;
        else if (op_idx[0]==0 && op_idx[1]==1) return strength - 5;
        else if (op_idx[0]==0 && op_idx[1]==2) return strength * 3;
        else if (op_idx[0]==0 && op_idx[1]==3 && strength >= 20) return strength + 20;
        else if (op_idx[0]==1 && op_idx[1]==0) return strength - 10;
        else if (op_idx[0]==1 && op_idx[1]==1) return strength / 3;
        else if (op_idx[0]==1 && op_idx[1]==2 && strength >= 20) return strength + 20;
        else if (op_idx[0]==1 && op_idx[1]==3 && strength >= 40) return strength + 40;
        else if (op_idx[0]==2 && op_idx[1]==0) return strength + 10;
        else if (op_idx[0]==2 && op_idx[1]==1) return strength - 80;
        else if (op_idx[0]==2 && op_idx[1]==2) return strength / 5;
        else if (op_idx[0]==2 && op_idx[1]==3 && strength >= 10) return strength + 10;
        else return -1;
    } else if (tc==2) {
        if (op_idx[0]==0 && op_idx[1]==0) return strength + 8;
        else if (op_idx[0]==0 && op_idx[1]==1 && strength >= 12) return strength + 12;
        else if (op_idx[0]==1 && op_idx[1]==0) return strength + 5;
        else if (op_idx[0]==1 && op_idx[1]==1) return strength * 2;
        else if (op_idx[0]==2 && op_idx[1]==0) return strength / 2;
        else if (op_idx[0]==2 && op_idx[1]==1 && strength >= 18) return strength + 18;
        else if (op_idx[0]==3 && op_idx[1]==0) return strength - 25;
        else if (op_idx[0]==3 && op_idx[1]==1 && strength >= 25) return strength + 25;
        else return -1;
    } else {
        return -1;
    }
}

int main(){
    int test_stages_tower_size[3][2] = {{2, 3}, {3, 4}, {4, 2}};
    char test_stages[3][MAX_NUM_TOWER][MAX_NUM_FLOOR][MAX_ENCOUNTER_LENGTH] = {
        {
            {"+5", "*2", "M10"},
            {"-8", "/2", "M28"}
        },
        {
            {"+15", "-5", "*3", "M20"},
            {"-10", "/3", "M20", "M40"},
            {"+10", "-80", "/5", "M10"}
        },
        {
            {"+8", "M12"},
            {"+5", "*2"},
            {"/2", "M18"},
            {"-25", "M25"}
        }
    };
    int initial_strength = 5;
    int final_path[MAX_NUM_TOWER][MAX_NUM_FLOOR];
    int floor_explored[MAX_NUM_FLOOR];
    int floor_path[MAX_NUM_FLOOR];

    for (int tc=0; tc<3; tc++){
        cout << "Test case " << tc << ":" << endl;
        find_path(test_stages[tc], test_stages_tower_size[tc][0], 0, test_stages_tower_size[tc][1], 0, floor_explored, initial_strength, floor_path, final_path);
        //Test path validity
        bool explored_floors[MAX_NUM_TOWER][MAX_NUM_FLOOR] = {false};
        for (int i=0; i<test_stages_tower_size[tc][0]; i++){
            for (int j=0; j<test_stages_tower_size[tc][1]; j++){
                cout<<final_path[i][j]<<endl;
                if (final_path[i][j] < 0 || final_path[i][j] >= test_stages_tower_size[tc][1]){
                    cout << "Test case " << tc+1 << " failed! Invalid floor selected!";
                    return 0;
                }
                if (explored_floors[i][final_path[i][j]]){
                    cout << "Test case " << tc+1 << " failed! Floor selected more than once!";
                    return 0;
                }
                explored_floors[i][final_path[i][j]] = true;
            }
        }
        
        //Test path optimality
        cout << "Your final decision: (";
        for(int i=0; i<test_stages_tower_size[tc][0]; i++){
            cout << "(";
            for(int j=0; j<test_stages_tower_size[tc][1]; j++) cout << final_path[i][j] << ' ';
            cout << "\b)";
            if (i != test_stages_tower_size[tc][0]-1) cout << ", ";
        }
        cout << ")" << endl;

        bool live = true;
        int strength = initial_strength;
        for(int i=0; i<test_stages_tower_size[tc][0]; i++){
            cout << "You are now in tower " << i << endl;
            for(int j=0; j<test_stages_tower_size[tc][1]; j++){
                int selected_floor = final_path[i][j];
                cout << "Your strength = " << strength << ". You decide to go to floor " << selected_floor << " with " << test_stages[tc][i][selected_floor] << endl;
                int op_idx[2] = {i, selected_floor};
                strength = testing_calculate_strength(tc, strength, op_idx);
                cout << "Your strength now is " << strength << "." << endl;
                if (strength <= 0){
                    cout << "You lose D:" << endl << endl;
                    live = false;
                    break;
                }
            }
            if (!live) break;
        }
        if (strength>=0) cout << "Congrats! You won!" << endl << endl;
    }

    return 0;
}