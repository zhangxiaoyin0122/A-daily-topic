//每日三道OJ题:1130
//第一道:
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int first = 0;
	int second = 1;
	int third = first;
	while (third < N) {
		third = first + second;
		first = second;
		second = third;
	}
	int result = 0;
	int a = N - first;
	int b = third - N;
	result = a < b ? a : b;
	cout << result << endl;
	return 0;
}
//第二道:
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> s;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] != '(' && A[i] != ')') {
				return false;
			}
			if (A[i] == '(') {
				s.push(A[i]);
			}
			else if (A[i] == ')' && !s.empty()) {
				s.pop();
			}
			else {
				return false;
			}
		}
		if (s.empty())
			return true;
		return false;
	}
};

//第三道
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (!stack2.empty()) {
			stack2.pop();
		}
		else {
			while (!stack1.empty()) {
				int tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
			stack2.pop();
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};