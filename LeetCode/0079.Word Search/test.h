#include "solution.h"
#include <iostream>
#include <vector>
using namespace std;


void T79() {
	vector<string> words = {
		"AB",
		"ABCDEFGHI",
		"EC",
		"",
		"ABCB",
		"ABFDAS",
		"ABC",
		"ABCCE"
	};
	vector<vector<char>> board_1 = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	vector<vector<char>> board_2 = {
		{'D','E','C'},
		{'F','A','B'},
		{'G','H','I'}
	};
	vector<vector<char>> board = {
		{'B','A'},
	};

	Solution solution;

	for (string word : words)
	{
		std::cout << word << " -> " << solution.exist(board, word) << std::endl;
	}
}
