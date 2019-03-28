// 超级素数问题（C++版）
// 对象声明
// 对象使用
// 对象死亡
// 类的声明及定义
#include <iostream>
#include <cmath>
//using namespace std;
class SuperPrime {
	public:
		SuperPrime (int t) {
			number = t;
		}
		void add(int i) {
			number += i;
		}
		void count() {
			number++;
		}
		int check(int i) {
			if (i == 0 || i == 1) return 0;
			for (int j = 2; j <= ceil(sqrt((double)i)); j++) {
				if (i % j == 0) return 0;
			}
			return 1;			
		}
		int is_SuperPrime() {
			if (check(number)) {
				int place_sum = 0; int accumulate = 1;
				int square_sum = 0;
				
				int m = number;
				while (m != 0) {
					int temp = m % 10;
					place_sum += temp;
					accumulate *= temp;
					square_sum += (temp * temp); 
					m /= 10;
				} 	
				if (!check(place_sum)) return 0;
				if (!check(accumulate)) return 0;
				if (!check(square_sum)) return 0;
				
				return 1;							
			}
		}
		void great(int i) {
			if (i > number) {
				number = i;
			}
		}
		void show() {
			std::cout << number << std::endl;
		}
	private:
		int number;
}; 
int main() {
	SuperPrime sum(0), max(0), counter(0);
	for (int i = 100; i <= 999; i++) {
		SuperPrime sp(i);
		if (sp.is_SuperPrime()) {
			sum.add(i);
			counter.count();
			max.great(i);
		}
	}
	std::cout << "超级素数的个数：";
	counter.show();
	std::cout << "超级素数之和："; 
	sum.show();
	std::cout << "最大的超级素数：";
	max.show();	

	return 0;
} 
