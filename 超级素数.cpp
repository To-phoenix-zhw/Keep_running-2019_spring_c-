// 各项积考虑0不是素数 
// 超级素数
#include <stdio.h>
#include <math.h>
int is_Prime(int number) {
	if (number == 0 || number == 1) return 0;
	for (int i = 2; i <= ceil(sqrt((double)number)); i++) {
		if (number % i == 0) return 0;
	}
	return 1;
}
int find_max(int* a, int count) {
	int max = a[0];
	for (int i = 0; i < count; i++) {
		if (a[i] > max) max = a[i];
	}
	return max;
}
int sum_prime(int* a, int count) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += a[i];
	}
	return sum;
}
int main() {
	int counter = 0;
	int all_prime[1000] = {0};
	for (int k = 100; k <= 999; k++) {
		if (!is_Prime(k)) continue;
		
		int sum = 0; int accumulate = 1;
		int square_sum = 0;
		
		int m = k;
		while (m != 0) {
			int temp = m % 10;
			sum += temp;
			accumulate *= temp;
			square_sum += (temp * temp); 
			m /= 10;
		} 
		if (!is_Prime(sum)) continue;
		if (!is_Prime(accumulate)) continue;
		if (!is_Prime(square_sum)) continue;
		
		all_prime[counter++] = k;
	}
	int max = find_max(all_prime, counter);
	int sum_superprime = sum_prime(all_prime, counter);
	
	for (int test = 0; test < counter; test++) {
		printf("%d ", all_prime[test]);
	}
	printf("\n");
	printf("超级素数的个数：%d\n", counter);
	printf("超级素数之和：%d\n", sum_superprime);
	printf("最大的超级素数：%d\n", max);
	
	return 0;
}
