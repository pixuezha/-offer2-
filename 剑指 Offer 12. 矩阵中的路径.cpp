class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word) {   
		vector<vector<bool>> b(board.size(), vector<bool>(board[0].size(), true));//存储能否可走 
		vector<vector<int>> xy({ {1,0},{0,-1},{-1,0},{0,1} });//上下左右四个方向枚举 
		int index=1;//判定到字符串第几个 
		for (int i=0; i < board.size(); i++)//在矩阵中每个都要进行寻找判定 
			for (int j=0 j < board[0].size(); j++)
				if (board[i][j] == word[0] && BSF_back2(board, word, xy, i, j, index, b))//找到开头并且后续都一样返回true 
					return true;
		return false;
	}
	bool BSF_back2(vector<vector<char>>& board, string& word, vector<vector<int>>& xy, int i, int j, int index, vector<vector<bool>> b/*只能传入复制*/) {
		if (index >= word.size()) return true;//说明到尾部并且大一，所以返回为true 
		b[i][j] = false;//走完这一格设置为false不能再走 
		for (int z=0; z < 4; z++) {
			int x = i + xy[z][0], y = j + xy[z][1];
			if (x>=0 && x<board.size() && y>=0 && y<board[0].size() && b[x][y]&&board[x][y]==word[index] &&BSF_back2(board, word, xy, x, y, index + 1, b)) 
				return  true;
		}
		return false;
	}
};
