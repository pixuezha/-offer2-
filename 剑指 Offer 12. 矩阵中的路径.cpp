class Solution {
public:
    bool exist(vector<vector<char>>& board, string& word) {   
		vector<vector<bool>> b(board.size(), vector<bool>(board[0].size(), true));//�洢�ܷ���� 
		vector<vector<int>> xy({ {1,0},{0,-1},{-1,0},{0,1} });//���������ĸ�����ö�� 
		int index=1;//�ж����ַ����ڼ��� 
		for (int i=0; i < board.size(); i++)//�ھ�����ÿ����Ҫ����Ѱ���ж� 
			for (int j=0 j < board[0].size(); j++)
				if (board[i][j] == word[0] && BSF_back2(board, word, xy, i, j, index, b))//�ҵ���ͷ���Һ�����һ������true 
					return true;
		return false;
	}
	bool BSF_back2(vector<vector<char>>& board, string& word, vector<vector<int>>& xy, int i, int j, int index, vector<vector<bool>> b/*ֻ�ܴ��븴��*/) {
		if (index >= word.size()) return true;//˵����β�����Ҵ�һ�����Է���Ϊtrue 
		b[i][j] = false;//������һ������Ϊfalse�������� 
		for (int z=0; z < 4; z++) {
			int x = i + xy[z][0], y = j + xy[z][1];
			if (x>=0 && x<board.size() && y>=0 && y<board[0].size() && b[x][y]&&board[x][y]==word[index] &&BSF_back2(board, word, xy, x, y, index + 1, b)) 
				return  true;
		}
		return false;
	}
};
