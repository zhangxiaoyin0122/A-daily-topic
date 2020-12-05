//ÿ������OJ��:1205
//��һ��:
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
//�ڶ���:
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

//������:
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
			lenA++; //ͳ��A����ĳ���
			cur1 = cur1->next;
		}
		while (cur2) {
			lenB++;//ͳ��B����ĳ���
			cur2 = cur2->next;
		}
		cur1 = pHead1;
		cur2 = pHead2;
		int sz = abs(lenA - lenB); //�����������Ȳ�ľ���ֵ
		//�ó����������߾���ֵ��
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
		//Ȼ���ڹ�ͬ��,ָ��������ҳ���һ�������ڵ�
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