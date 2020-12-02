//每日三道OJ题:
//第一道:两种排序方法
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool len(vector<string>& vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i + 1].size() < vec[i].size())
			return false;
	}
	return true;
}
bool dec(vector<string>& vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i].compare(vec[i + 1]) > 0)
			return false;
	}
	return true;
}
int main() {
	vector<string> vec;
	int n;
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	if (dec(vec) && len(vec)) {
		cout << "both\n";
	}
	else if (dec(vec) && !len(vec)) {
		cout << "lexicographically\n";
	}
	else if (len(vec) && !dec(vec)) {
		cout << "lengths\n";
	}
	else {
		cout << "none\n";
	}
	return 0;
}
//第二道:求最大公因数
#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int C = A % B; 
	while (C) {
		A = B;
		B = C;
		C = A % B;
	}
	cout << B << endl;
	return 0;
}
//第三道:最小公倍数 = 两数乘积/最大公因数
#include <iostream>
using namespace std;

int main() {   
 A, B;
	cin >> A >> B; //  15  6
	int tmp = A * B;
	int C = A % B; 
	while (C) {
		A = B;
		B = C;
		C = A % B;
	}
	cout << tmp / B << endl;
	return 0;
}
//第四道:二叉树的最近公共节点(递归)
	
int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
	if (root == nullptr)
		return -1;
	if (root->val == o1 || root->val == o2)
		return root->val;
	int left = lowestCommonAncestor(root->left, o1, o2);
	int right = lowestCommonAncestor(root->right, o1, o2);
	if (left == -1)
		return right;
	if (right == -1)
		return left;
	return root->val;
}
