#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int roll_the_dice(int current_position) {
	int move = rand() % 6 + 1;
	int next_position;
	if (current_position == 14)
		next_position = current_position + 1 + move;
	else {
		next_position = current_position + move;
		if (current_position >= 8 && current_position <= 15 && next_position > 15)
			next_position = next_position - 8; 
	}
	if (next_position > 22) next_position = 22;
	return next_position;
}

int count_being[23];

void play_game(int number, double * global_count_moves, double * global_count_circles) {
	//cout << "GAME# " << number << endl;
	int current_position = 0, next_position;
	int count_moves = 0;
	int count_circles = 0;
	while (current_position < 22) {
		next_position = roll_the_dice(current_position);
		count_moves++; 
		if (current_position > next_position)
			count_circles++;
		current_position = next_position;
		//cout << current_position << " ";
		count_being[current_position]++;
	}
	*global_count_moves += count_moves;
	*global_count_circles += count_circles;
	//cout << "END; count_moves = " << count_moves << "; count_circles = " << count_circles << endl << endl;
}


int main() {
	double count_moves = 0, count_circles = 0;
	int test_count = 1000000000;
	freopen("output.txt", "at", stdout);
	srand(time(0));
	for (int i = 1; i <= test_count; i++)
		play_game(i, &count_moves, &count_circles);
	cout << "count_moves = " << count_moves / test_count << endl 
		 << "count_circles = " << count_circles / test_count << endl << endl;
	for (int i = 1; i <= 22; i++)
		cout << i << "\t" << count_being[i] << endl;
	cout << endl;
}
