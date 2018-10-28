#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {	
public:
	int i, j, row, col;
    void solve(vector<vector<char>> &board) {
  		if ((row = board.size()) <= 2 || (col = board[0].size()) <= 2)
  			return;
  		vector<int> v;
 		for (i = 0, j = 0; j < col; ++j)
 			collect(board, v);
  		for (i = row-1, j = 0; j < col; ++j)
			collect(board, v);
  		for (j = 0, i = 0; i < row; ++i)
			collect(board, v);
  		for (j = col-1, i = 0; i < row; ++i)
			collect(board, v);

  		int dx[] = {0, 1, 0, -1};
  		int dy[] = {1, 0, -1, 0};
  		for (vector<int>::iterator iter =  v.begin(); iter != v.end(); ++iter) {
  			queue<int> q;
  			q.push(*iter);
  			while (!q.empty()) {
  				for (int k = 0; k < 4; k++) {
					i = q.front()/col + dx[k];
					j = q.front()%col + dy[k];
					if (isSafe() && board[i][j] == 'O') {
						board[i][j] = '#';
						q.push(i*col+j);
					}
  				}
  				q.pop();
  			}
  		}
  		for (i = 0; i < row; ++i) {
  			for (j = 0; j < col; ++j) {
  				if (board[i][j] == 'O')
  					board[i][j] = 'X';
  				if (board[i][j] == '#')
  					board[i][j] = 'O';
  			}
  		}
	}
private:
	inline void collect(vector< vector<char> > &board, vector<int> &collection) {
		if (board[i][j] == 'O') {
  			board[i][j] = '#';
  			collection.push_back(i*col+j);
  		}
	}
	inline bool isSafe() {
		return (i > -1 && i < row && j > -1 && j < col);
	}
};

class Print2DVector
{
public:	
	void print(vector<vector<char>> &board) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j)
				cout << board[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
};




int main(int argc, char const *argv[])
{	
	char a[] = {'X', 'X', 'X', 'X'};
	char b[] = {'X', 'O', 'O', 'X'};
	char c[] = {'X', 'X', 'O', 'X'};
	char d[] = {'X', 'O', 'X', 'X'};
	vector<char> va(a, a+4);
	vector<char> vb(b, b+4);
	vector<char> vc(c, c+4);
	vector<char> vd(d, d+4);

	vector< vector<char> > v;

	v.push_back(va);
	v.push_back(vb);
	v.push_back(vc);
	v.push_back(vd);

	Print2DVector p;

	Solution solution;
	p.print(v);
	solution.solve(v);
	p.print(v);


	return 0;
}