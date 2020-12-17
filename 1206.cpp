#include <algorithm>
using namespace std;

bool isSushu(int num) {
	int n = sqrt(num);
	for (int i = 2; i <= n; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int num;
	int i;
	while (cin >> num) {
		int half = num / 2;
		for (i = half; i > 0; i--) {
			if (isSushu(i) && isSushu(num - i)) {
				break;
			}

		}
		cout << i << endl;
		cout << num - i << endl;
	}
	return 0;
}
//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж����
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return m | n;
	}
};
//������:
class Solution {
public:
	class Sum {
	public:
		Sum() {
			_sum += _i;
			++_i;
		}
	};
	int Sum_Solution(int n) {
		_sum = 0;
		_i = 1;
		Sum arr[n];
		return _sum;
	}
	static int _sum;
	static int _i;
};

int Solution::_sum = 0;
int Solution::_i = 1;