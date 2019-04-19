// 进制转换c++
#define LOCAL
#include <iostream>
#include <cstring>

const int maxn = 25; 	// 存储各位数值的数组大小 
 
class Number {
	public:
		Number(int a, int b) {
			value = a;
			system = b;
		}
		Number converto(int n) {
			Number *p = new Number(0, 0); 
			p->value = 0;
			p->system = 0;
			memset(p->number, 0, sizeof(p->number));
			int temp = value;
			int division = temp / n;
			int left = temp % n;
			int counter = 0; 
			char num[maxn] = {0};
			
			num[counter++] = left + '0';
			
			while (division) {
				temp = division;
				division = temp / n;
				left = temp % n;
				num[counter++] = left + '0';
			}
			
			strcpy(p->number, num);
			return *p;
		}
		void show() {
			int len = strlen(number);
			for (int i = len - 1; i >= 0; i--) {
				std::cout<<number[i];
			}
			std::cout<<std::endl;
		}
	private:
		int value;
		int system;
		char number[maxn];
};

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif 
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1, 10);     //n1是10进制正整数
        Number no3 = no1.converto(n2);  //no3是n2进制的正整数
        no3.show();     //输出结果
    }
	return 0;
} 
