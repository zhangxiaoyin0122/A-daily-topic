//ÿ������OJ��:1128
//��һ��:
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> vec;
	vec.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> vec[i];
	}
	int result = 0x80000000;
	int tmp = vec[0];
	for (int i = 0; i < vec.size(); i++) {
		if (tmp < 0) {
			tmp = vec[i];
		}
		else {
			tmp += vec[i];
		}
		if (result < tmp)
			result = tmp;
	}
	cout << result << endl;
	return 0;
}
//�ڶ���:
#include <iostream>
#include <string>
using namespace std;
//�ж��Ƿ�Ϊ���Ĵ�
bool HuiWen(string& str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	string strA, strB;
	getline(cin, strA);
	getline(cin, strB);
	string tmp = "";
	int count = 0;
	for (int i = 0; i <= strA.size(); i++) {
		tmp = strA;
		tmp.insert(i, strB);
		if (HuiWen(tmp)) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}

//������:
class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	void dfs(vector<int>& num, int sum, int start) {
		if (path.size() == 3 && sum == 0) {
			sort(path.begin(), path.end());
			//�жϽ�������Ƿ����ظ���Ԫ��

			result.push_back(path);
			return;
		}
		for (int i = start; i < num.size(); i++) {
			sum += num[i];
			path.push_back(num[i]);
			dfs(num, sum, i + 1);
			sum -= num[i];
			path.pop_back();
		}
	}
	vector<vector<int> > threeSum(vector<int> &num) {
		result.clear();
		path.clear();
		int sum = 0;
		dfs(num, sum, 0);
		return result;
	}
};