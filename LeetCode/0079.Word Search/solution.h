#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0) return word == "";

		bool** visited = new bool*[board.size()];
		for (int i = 0; i < board.size(); i++) {
			visited[i] = new bool[board[0].size()]{ false };
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++)
				if (search(i, j, 0, visited, board, word))
					return true;
		}

		return false;
	}

	bool search(int i, int j, int key, bool **visited, vector<vector<char>>& board, string& word) {
		// 下标越界或者已访问 -> 返回
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j])
			return false;

		// 单词正确 -> 继续 | 不正确 -> 返回
		if (board[i][j] == word[key])
			key++;
		else
			return false;

		// 单词读完 -> 返回 true
		if (key == word.length()) 
			return true;

		visited[i][j] = true;	// 标记

		// 检查右下左上
		if (search(i + 1, j, key, visited, board, word)) return true;
		if (search(i, j - 1, key, visited, board, word)) return true;
		if (search(i - 1, j, key, visited, board, word)) return true;
		if (search(i, j + 1, key, visited, board, word)) return true;

		visited[i][j] = false;	// 取消标记

		return false;
	}
};