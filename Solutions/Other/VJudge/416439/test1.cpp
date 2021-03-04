#include <iostream>
#include <stdio.h>
#include <time.h>

int main() {
	freopen("data.in", "r", stdin);
	unsigned int x = 0, y;
	clock_t t = clock();
	while (std::cin >> y) {
		x += y;
	}
	t = clock() - t;
	std::cout << "test1 - time: " << ((float)t)/CLOCKS_PER_SEC << '\n';
}