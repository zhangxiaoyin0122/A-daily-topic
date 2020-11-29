//每日三道OJ题:1129
//第一道:
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int w, h;
	cin >> w >> h;
	//初始化二维数组
	vector<vector<int>> vec(w, vector<int>(h, 0));
	int result = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (vec[i][j] == 0) {
				result++;
				if (i + 2 < w) {
					vec[i + 2][j] = -1;
				}
				if (j + 2 < h) {
					vec[i][j + 2] = -1;
				}
			}
		}
	}
	cout << result << endl;
	return 0;
}
//第二道:
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int i = 0;
		bool ret = true;
		if (str[i] == '-') {
			ret = false;
			i++;
		}
		else if (str[i] == '+') {
			i++;
		}
		long count = 0;
		for (; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				count = count * 10 + str[i] - '0';
			}
			else {
				count = 0;
				break;
			}
		}
		if (ret == false) {
			count = -count;
		}
		return count;
	}
};
//第三道
ListNode* addInList(ListNode* head1, ListNode* head2) {
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	stack<ListNode*> st1;
	stack<ListNode*> st2;
	while (head1 != nullptr) {
		st1.push(head1);
		head1 = head1->next;
	}
	while (head2 != nullptr) {
		st2.push(head2);
		head2 = head2->next;
	}
	int jinwei = 0;
	while (!st1.empty() || !st2.empty()) {
		int sum = jinwei;
		if (!st1.empty()) {
			sum += st1.top()->val;
			head1 = st1.top();
			st1.pop();
		}
		if (!st2.empty()) {
			sum += st2.top()->val;
			if (st2.size() > st1.size()) {
				head1 = st2.top();
			}
			st2.pop();
		}
		if (sum < 10) {
			jinwei = 0;
			head1->val = sum;
		}
		else {
			jinwei = sum / 10;
			head1->val = sum % 10;
		}
	}
	if (jinwei > 0) {
		head2 = new ListNode(jinwei);
		head2->next = head1;
		return head2;
	}
	return head1;
}
};