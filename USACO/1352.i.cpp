#include <iostream>
#include <set>
#include <vector>

int T, C;
std::set<int> targets;
std::string commands;

std::vector<int> calc_suffix(int offset, int final_pos) {
	std::vector<int> suffix(C + 1, 0);

	int pos = final_pos + offset;
	std::set<int> visited;
	for (int i = 0; i < C; ++i) {
		switch (commands[C - i - 1]) {
		case 'L':
			++pos;
			break;
		case 'R':
			--pos;
			break;
		case 'F':
			if (targets.count(pos) && !visited.count(pos))
				++suffix[i + 1];

			visited.insert(pos);
			break;
		}

		suffix[i + 1] += suffix[i];
	}

	return suffix;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> T >> C;

	for (int i = 0; i < T; ++i) {
		int x;
		std::cin >> x;

		targets.insert(x);
	}

	std::cin >> commands;

	std::vector<int> prefix(C + 1, 0);

	int pos = 0;
	std::set<int> visited;
	for (int i = 0; i < C; ++i) {
		switch (commands[i]) {
		case 'L':
			--pos;
			break;
		case 'R':
			++pos;
			break;
		case 'F':
			if (targets.count(pos) && !visited.count(pos))
				++prefix[i + 1];

			visited.insert(pos);
			break;
		}

		prefix[i + 1] += prefix[i];
	}

	auto two_right = calc_suffix(2, pos);
	auto one_right = calc_suffix(1, pos);
	auto two_left = calc_suffix(-2, pos);
	auto one_left = calc_suffix(-1, pos);

	int ans = prefix[C];
	pos = 0;
	visited.clear();
	for (int i = 0; i < C; ++i) {
		int hit = targets.count(pos) && !visited.count(pos);

		switch (commands[i]) {
		case 'L':
			--pos;
			ans = std::max(ans, prefix[i] + two_right[C - i]);
			ans = std::max(ans, prefix[i] + hit + one_right[C - i]);
			break;
		case 'R':
			++pos;
			ans = std::max(ans, prefix[i] + two_left[C - i]);
			ans = std::max(ans, prefix[i] + hit + one_left[C - i]);
			break;
		case 'F':
			visited.insert(pos);
			ans = std::max(ans, prefix[i] - hit + one_right[C - i]);
			ans = std::max(ans, prefix[i] - hit + one_left[C - i]);
			break;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
