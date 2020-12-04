//每日三道OJ题:1204
//第一道:密码评分
#include <iostream>
#include <string>
using namespace std;
int length(string& str) {
	if (str.size() <= 4) {
		return 5;
	}
	else if (str.size() > 4 && str.size() < 8) {
		return 10;
	}
	else if (str.size() >= 8) {
		return 25;
	}
	return 0;
}
int zimu(string& str) {
	int a = 0;
	int A = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			a++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			A++;
		}
	}
	if (a + A == 0) {
		return 0;
	}
	else if (a == 0 && A != 0) {
		return 10;
	}
	else if (a != 0 && A == 0) {
		return 10;
	}
	else if (a != 0 && A != 0) {
		return 20;
	}
	return 0;
}
int num(string& str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			count++;
		}
	}
	if (count == 0) {
		return 0;
	}
	else if (count == 1) {
		return 10;
	}
	else {
		return 20;
	}
	return 0;
}
int fuhao(string& str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96) ||
			(str[i] >= 123 && str[i] <= 126)) {
			count++;
		}
	}
	if (count == 0) {
		return 0;
	}
	else if (count == 1) {
		return 10;
	}
	else {
		return 25;
	}
	return 0;
}
int award(string& str) {
	if (zimu(str) != 0 && num(str) != 0 && fuhao(str) == 0) {
		return 2;
	}
	if (zimu(str) == 10 && num(str) != 0 && fuhao(str) != 0) {
		return 3;
	}
	if (zimu(str) == 20 && num(str) != 0 && fuhao(str) != 0) {
		return 5;
	}
	return 0;
}
int main() {
	string str;
	while (getline(cin, str)) {
		int result = length(str) + num(str) + fuhao(str) + zimu(str) + award(str);
		if (result >= 90) {
			cout << "VERY_SECURE" << endl;
		}
		else if (result >= 80) {
			cout << "SECURE" << endl;
		}
		else if (result >= 70) {
			cout << "VERY_STRONG" << endl;
		}
		else if (result >= 60) {
			cout << "STRONG" << endl;
		}
		else if (result >= 50) {
			cout << "AVERAGE" << endl;
		}
		else if (result >= 25) {
			cout << "WEAK" << endl;
		}
		else {
			cout << "VERY_WEAK" << endl;
		}
	}
	return 0;
}

//第二题:下棋问题
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size(); //行

		//判断每一行是否满足
		for (int i = 0; i < row; i++) {
			int sum = 0;
			for (int j = 0; j < row; j++) {
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}
		//判断每一列是否满足
		for (int i = 0; i < row; i++) {
			int sum = 0;
			for (int j = 0; j < row; j++) {
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}
		//判断斜向下是否满足
		int sum = 0;
		for (int i = 0; i < row; i++) {
			sum += board[i][i];
		}
		if (sum == row)
			return true;
		//判断斜向上是否满足
		sum = 0;
		for (int i = 0; i < row; i++) {
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;
		return false;
	}
};
//第三道:合并两颗二叉树
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (t1 == nullptr)
		return t2;
	if (t2 == nullptr)
		return t1;
	TreeNode* root = new TreeNode(0);
	root->val = t1->val + t2->val;
	root->left = mergeTrees(t1->left, t2->left);
	root->right = mergeTrees(t1->right, t2->right);
	return root;
}