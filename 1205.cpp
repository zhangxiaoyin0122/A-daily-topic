//每日三道OJ题:1205
//第一道:
class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b) {
			if (a > b) {
				a /= 2;
			}
			else {
				b /= 2;
			}
		}
		return a;
	}
};
//第二道:
#include <iostream>
#include <vector>
using namespace std;

void erjinzhi(vector<int>& vec, int byte) {
	while (byte) {
		int tmp = byte % 2;
		byte = byte / 2;
		vec.push_back(tmp);
	}
}
int main() {
	int byte;
	while (cin >> byte) {
		vector<int> vec;
		erjinzhi(vec, byte);
		int result = 0;
		int count = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == 1) {
				count++;
			}
			else {
				result = count > result ? count : result;
				count = 0;
			}
		}
		result = count > result ? count : result;
		cout << result << endl;
	}
	return 0;
}

//第三道:
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2)
			return nullptr;
		int lenA = 0;
		int lenB = 0;
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		while (cur1) {
			lenA++; //统计A链表的长度
			cur1 = cur1->next;
		}
		while (cur2) {
			lenB++;//统计B链表的长度
			cur2 = cur2->next;
		}
		cur1 = pHead1;
		cur2 = pHead2;
		int sz = abs(lenA - lenB); //求两个链表长度差的绝对值
		//让长的链表先走绝对值步
		if (lenA > lenB) {
			while (sz--) {
				cur1 = cur1->next;
			}
		}
		else {
			while (sz--) {
				cur2 = cur2->next;
			}
		}
		//然后在共同走,指针相等则找出第一个公共节点
		while (cur1 && cur2) {
			if (cur1 == cur2) {
				return cur1;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return nullptr;
	}
};