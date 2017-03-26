#include<iostream>
#include<iterator>
#include<utility>

using namespace std;

void to_do(int list[],int m) {
	copy(list, list + m, ostream_iterator<int>(cout, " "));
	cout << endl;
}

void perm(int list[], int k, int m, void(*need_to_do) (int*, int)) {
	if (k == m) {
		(*need_to_do) (list, m);
		return;
	}
	for (int i = k; i < m; i++) {
		swap(list[k], list[i]);
		perm(list, k + 1, m, need_to_do);
		swap(list[k], list[i]);
	}
}

int main() {
	int list[] = { 1,2,3,4 };
	perm(list, 0, size(list),to_do);

	return 0;
}
