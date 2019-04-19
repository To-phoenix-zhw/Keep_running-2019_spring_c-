// 最大公约数c++
#define LOCAL
#include <iostream>

class Number {
	int num;
	public:
		Number (int n) {
			num = n;
		}
		Number maxDivisor(const Number& n) {
			int smaller;
			if (n.num > num) smaller = num;
			else smaller = n.num;
			
			int i;
			for (i = smaller; i >= 1; i--) {
				if (num % i == 0 && n.num % i == 0) break;
			}
			
			return Number(i);
		}
		void show() {
			std::cout<<num<<std::endl;
		}
};
int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1), no2(n2);
        Number no3 = no1.maxDivisor(no2);  //最大公约数
        no3.show();
    }
    return 0;
} 
