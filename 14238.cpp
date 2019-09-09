#include <iostream>
using namespace std;

char str[52];
char ans[52];
bool dp[51][51][51][3][3];
int cnt[3];
int S = 0;

bool solve(int idx, int a, int b, int c, int pprev, int prev)
{
	bool &ret = dp[a][b][c][pprev][prev];

	if (ret) return false;
	ret = true;

	if (idx == (S - 1)) {
		int last;
		for (int i = 0; i < 3; i++) {
			if (cnt[i]) last = i;
		}
		if (last == 0) {
			ans[idx] = 'A';
			return true;
		}
		if (last == 1 && prev != 1) {
			ans[idx] = 'B';
			return true;
		}
		if (last == 2 && pprev != 2 && prev != 2) {
			ans[idx] = 'C';
			return true;
		}
		return false;
	}

	if (cnt[0] > 0) {
		ans[idx] = 'A', cnt[0]--;
		if (solve(idx + 1, a + 1, b, c, prev, 0)) return true;
		cnt[0]++;
	}
	if (cnt[1] > 0 && prev != 1) {
		ans[idx] = 'B', cnt[1]--;
		if (solve(idx + 1, a, b + 1, c, prev, 1)) return true;
		cnt[1]++;
	}
	if (cnt[2] > 0 && pprev != 2 && prev != 2) {
		ans[idx] = 'C', cnt[2]--;
		if (solve(idx + 1, a, b, c + 1, prev, 2)) return true;
		cnt[2]++;
	}
	return false;
}
int main()
{
	int idx = 0;
	char chr;

	scanf("%s", &str);

	while (1) {
		chr = str[idx];
		if (chr == '\0') break;
		else S++, cnt[chr - 'A']++;
		idx++;
	}

	if (solve(0, 0, 0, 0, 0, 0)) printf("%s\n", ans);
	else printf("-1\n");
	return 0;
}
[출처] 백준 : 출근기록(14238번)|작성자 주인장