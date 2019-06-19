// 2019-4-22 
#include <iostream>
#include <cmath>

class NumberSet;

class Number {
	private: 
		int num;	
	public:			
		Number(int n);
		Number(const Number &n);
		~Number();
		void add(const Number &n);
		void mul(const Number &n);
		NumberSet split();//Number������һ��NumberSet������NumberSet��û����
		// �������˶���
		// �����NumberSet��ǰ�� 
		bool isPrime() const;
		void show() const;
		int GetNum() const;
};

class NumberSet {
	private:
		Number *nums[20];//ʵ����һ����̬���ϣ����װ20��Ԫ�� 
		int size; 
	public:
		NumberSet();
		~NumberSet();
		bool add(const Number &n);
		Number sum();
		Number square_sum();
		Number multi();	
};

Number::Number(int n):num(n) { };
Number::Number(const Number &n):num(n.num) {
//	std::cout<<"Number copy constructor!!!"<<std::endl;
}
Number::~Number() {
//	std::cout<<"Number die!!!"<<std::endl;
}
void Number::add(const Number &n) {
	num += n.num;
}
void Number::mul(const Number &n) {
	num *= n.num;
}
NumberSet Number::split() {
	NumberSet ns;
	int n = num;
	while (n != 0) {
		int d = n % 10;
		Number dig(d);
		ns.add(dig);
		n = n / 10; 
	}
	return ns;
}//Number������һ��NumberSet������NumberSet��û����
		// �������˶���
		// �����NumberSet��ǰ�� 
bool Number::isPrime() const {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i <= ceil(sqrt(double(num))); ++i) {
		if (num % i == 0)
			return false;
	} 
	return true;
}
void Number::show() const {
	std::cout<<num<<std::endl;
}

int Number::GetNum() const {
	return num;
}
NumberSet::NumberSet() {
	size = 0;
	for (int i = 0; i < 20; ++i) {
		nums[i] = NULL;
	}
}
NumberSet::~NumberSet() {
	for (int i = 0; i < size; ++i) {
		delete nums[i];
	}
}
bool NumberSet::add(const Number &n) {
	if (size != 20 && nums[size] == NULL) {
		nums[size++] = new Number(n);
//				size += 1; 
		return true;	
	} 
	return false;
}
Number NumberSet::sum() {
	Number sum(0);
	for (int i = 0; i < size; ++i) {
		if (nums[i] != NULL) {
			sum.add(*(nums[i])); 
		}
	} 
	return sum;
}
Number NumberSet::square_sum() {
	Number square_sum(0);
	for (int i = 0; i < size; ++i) {
		if (nums[i] != NULL) {
			double temp1 = nums[i] -> GetNum();
			double temp = temp1 * temp1;
			square_sum.add(Number(temp));
		}
	}
	return square_sum;
}
Number NumberSet::multi() {
	Number multi(1);
	for (int i = 0; i < size; ++i) {
		if (nums[i] != NULL) {
			multi.mul(*(nums[i]));
		}
	}
	return multi;
}
 
class SuperPrime : public Number {
	private:
		int num;
		static int counter;
		static int max;
	public:
		SuperPrime(int n) :num(n), Number(n) {};
		
		bool isSuperPrime() const {
			Number n(num); 
			if (n.isPrime()) {
				NumberSet ns = n.split();
				Number sum = ns.sum();
				Number sqsum = ns.square_sum();
				Number multi = ns.multi(); 
				if(sqsum.isPrime() && sum.isPrime() && multi.isPrime()) {
					return true;		
				}
			}
			return false;
		}
		void compare(const SuperPrime &n) {
			if (n.num > num) {
				num = n.num;
			}
		}
		void count() {
			num++;
		}
		void show() {
			std::cout<<SuperPrime::num<<std::endl;
		} 
		// ��Number���̳���sum��������Ȼ������sum�Ĺ����ǲ�ͬ��
		// ����Ҫ����sum
		
		void add(const SuperPrime& n) {
			num += n.num;
		} 
		
/*		static void GetCounter() {
			std::cout<<"total counting of SuperPrime is:"<<counter<<std::endl;
		}
		static void GetMax() {
			std::cout<<"The max number of SuperPrime is:"<<max<<std::endl;
		}
*/
};
//int SuperPrime::counter = 0;
//int SuperPrime::max = 0;
int main() {
	SuperPrime sum(0), counter(0), max(0);
	for (int i = 100; i <= 999; i++) {
		SuperPrime sp(i);
		if (sp.isSuperPrime()) {
			sum.add(sp);
			counter.count();
			max.compare(sp);
		}
	}
	std::cout << "���������ĸ�����";
	counter.show();
	std::cout << "��������֮�ͣ�"; 
	sum.show();
	// sum����������num����Ϊsum���̳���Number
	// ���ִ�е��Ǽ̳�������sum���������Ǹı�̳��������Ǹ�num
	// �������⣬Ӧ��ִ���ĸ�sum 
	std::cout << "���ĳ���������";
	max.show();	
	return 0;
}
