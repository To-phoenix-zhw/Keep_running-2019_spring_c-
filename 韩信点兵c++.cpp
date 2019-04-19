// 韩信点兵c++
#define LOCAL
#include <iostream>
class HanXin {
	public:
		HanXin() {
			many = 0;
			three = 0;
			five = 0;
			seven = 0;
		}
		void line3(int n) {
			three = n;
		}
		void line5(int n) {
			five = n;
		}
		void line7(int n) {
			seven = n;
		}
		void showMany () {
			for (int i = 10; i <= 100; i++) {
				if (i % 3 == three && i % 5 == five && i % 7 == seven) {
					many = i;
				}
			}
			if (!many) std::cout<<"Impossible\n";
			else std::cout<<many<<std::endl;
		}
	private:
		int many;
		int three;
		int five;
		int seven;
};
int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
    int n, n1, n2;
    int n3;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2 >> n3;
        HanXin hx;  //韩信
        hx.line3(n1);  //3人一排
        hx.line5(n2);   //5人一排
        hx.line7(n3);   //7人一排
        hx.showMany();
    }
    return 0;
} 
