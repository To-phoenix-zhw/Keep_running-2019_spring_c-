#define LOCAL
#include <iostream>
#include <cstring>
#include <cstdio>
// �������±���ȻҪ�����У����ʳ����˾Ͳ��� 
// ��������໥�Ĺ�ϵ�������ǳ���Ҫ�����Ҷ����˳��Ҳ�ǳ���Ҫ
// ���˳�������⣬�϶���ͨ��������� 
// �������ú������һ�¶�̬��Ч��
// ��Ȼ���Ǵ��ĸ�����·�������ִ��Ч��ȴ����������͹ҹ� 
using namespace std;
// �ö����� 
class DotArray {   //�������
    const int maxcol, maxrow;
    int num;
public:
	DotArray(int d);
    virtual void showrow(int times) const;
//    void test();
};
class DA0 : public DotArray {   //0�ĵ���
	char model[7][6];
public:
	DA0(int d);
    virtual void showrow(int times) const;
};
DA0::DA0(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "*   *");
	strcpy(model[2], "*   *");
	strcpy(model[3], "*   *");
	strcpy(model[4], "*   *");
	strcpy(model[5], "*   *");
	strcpy(model[6], "*****");
}
void DA0::showrow(int times) const {
	cout<<model[times];
}
class DA1 : public DotArray {   //1�ĵ���
	char model[7][6];
public:
	DA1(int d);
    virtual void showrow(int times) const;
};
DA1::DA1(int d):DotArray(d) {
	for (int i = 0; i < 7; i++) {
		strcpy(model[i], "    *"); 
	}
}
void DA1::showrow(int times) const {
	cout<<model[times];
}

class DA2 : public DotArray {   //2�ĵ���
	char model[7][6];
public:
	DA2(int d);
    virtual void showrow(int times) const;
};
DA2::DA2(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "    *");
	strcpy(model[2], "    *");
	strcpy(model[3], "*****");
	strcpy(model[4], "*    ");
	strcpy(model[5], "*    ");
	strcpy(model[6], "*****");
}
void DA2::showrow(int times) const {
	cout<<model[times];
}

class DA3 : public DotArray {   //3�ĵ���
	char model[7][6];
public:
	DA3(int d);
    virtual void showrow(int times) const;
};
DA3::DA3(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "    *");
	strcpy(model[2], "    *");
	strcpy(model[3], "*****");
	strcpy(model[4], "    *");
	strcpy(model[5], "    *");
	strcpy(model[6], "*****");
}
void DA3::showrow(int times) const {
	cout<<model[times];
}

class DA4 : public DotArray {   //4�ĵ���
	char model[7][6];
public:
	DA4(int d);
    virtual void showrow(int times) const;
};
DA4::DA4(int d):DotArray(d) {
	strcpy(model[0], "*   *");
	strcpy(model[1], "*   *");
	strcpy(model[2], "*   *");
	strcpy(model[3], "*****");
	strcpy(model[4], "    *");
	strcpy(model[5], "    *");
	strcpy(model[6], "    *");
}
void DA4::showrow(int times) const {
	cout<<model[times];
}

class DA5 : public DotArray {   //5�ĵ���
	char model[7][6];
public:
	DA5(int d);
    virtual void showrow(int times) const;
};
DA5::DA5(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "*    ");
	strcpy(model[2], "*    ");
	strcpy(model[3], "*****");
	strcpy(model[4], "    *");
	strcpy(model[5], "    *");
	strcpy(model[6], "*****");
}
void DA5::showrow(int times) const {
	cout<<model[times];
}

class DA6 : public DotArray {   //6�ĵ���
	char model[7][6];
public:
	DA6(int d);
    virtual void showrow(int times) const;
};
DA6::DA6(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "*    ");
	strcpy(model[2], "*    ");
	strcpy(model[3], "*****");
	strcpy(model[4], "*   *");
	strcpy(model[5], "*   *");
	strcpy(model[6], "*****");
}
void DA6::showrow(int times) const {
	cout<<model[times];
}

class DA7 : public DotArray {   //7�ĵ���
	char model[7][6];
public:
	DA7(int d);
    virtual void showrow(int times) const;
};
DA7::DA7(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "    *");
	strcpy(model[2], "    *");
	strcpy(model[3], "    *");
	strcpy(model[4], "    *");
	strcpy(model[5], "    *");
	strcpy(model[6], "    *");
}
void DA7::showrow(int times) const {
	cout<<model[times];
}

class DA8 : public DotArray {   //8�ĵ���
	char model[7][6];
public:
	DA8(int d);
    virtual void showrow(int times) const;
};
DA8::DA8(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "*   *");
	strcpy(model[2], "*   *");
	strcpy(model[3], "*****");
	strcpy(model[4], "*   *");
	strcpy(model[5], "*   *");
	strcpy(model[6], "*****");
}
void DA8::showrow(int times) const {
	cout<<model[times];
}

class DA9 : public DotArray {   //9�ĵ���
	char model[7][6];
public:
	DA9(int d);
    virtual void showrow(int times) const;
};
DA9::DA9(int d):DotArray(d) {
	strcpy(model[0], "*****");
	strcpy(model[1], "*   *");
	strcpy(model[2], "*   *");
	strcpy(model[3], "*****");
	strcpy(model[4], "    *");
	strcpy(model[5], "    *");
	strcpy(model[6], "*****");
}
void DA9::showrow(int times) const {
	cout<<model[times];
}

class DAPrinter {
private:
    const int num;
    DotArray *das[4]; //���4��������� 0<=x<=9999
    int size;
public:
	DAPrinter(int n1):num(n1) {
		size = 0;
		for (int i = 0; i < 4; i++) {
			das[i] = NULL;
		}
	}
	~DAPrinter() {
		for (int i = 0; i < 4; i++) {
			delete das[i];
		}
	}
    void split() {
    	int t = num;
    	while(t != 0) {
    		int d = t % 10;
    		if (size != 4 && das[size] == NULL) {
    			das[size++] = new DotArray(d);
//				(*das[0]).test();
			}
    		t /= 10;
		}
	}
    void print() {
    	cout<<num<<":"<<endl;
    	for (int k = 0; k < 7; k++) {
	    	for (int i = size - 1; i >= 0; i--) {
	    		(*das[i]).showrow(k);
	    		cout<<"  ";
			}
			reset();    		
		}
	}
    void reset() {
    	cout<<endl;// ����һ�� 
	}
};

//void DotArray::test() {
//	cout<<num<<"DotArray test!!!"<<endl; 
//}

DotArray::DotArray(int d):maxcol(5), maxrow(7) {
	num = d;
}
void DotArray::showrow(int times) const {
	if (num == 0) {
		DotArray* zero = new DA0(num); 
		zero->showrow(times);
	} else if (num == 1) {
		DotArray* one = new DA1(num);
		one->showrow(times);
	} else if (num == 2) {
		DotArray* two = new DA2(num);
		two->showrow(times);
	} else if (num == 3) {
		DotArray* three = new DA3(num);
		three->showrow(times);
	} else if (num == 4) {
		DotArray* four = new DA4(num);
		four->showrow(times);
	} else if (num == 5) {
		DotArray* five = new DA5(num);
		five->showrow(times);
	} else if (num == 6) {
		DotArray* six = new DA6(num);
		six->showrow(times);
	} else if (num == 7) {
		DotArray* seven = new DA7(num);
		seven->showrow(times);
	} else if (num == 8) {
		DotArray* eight = new DA8(num);
		eight->showrow(times);
	} else if (num == 9) {
		DotArray* nine = new DA9(num);
		nine->showrow(times);
	}
}

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
    	int n1;
        std::cin >> n1;
        DAPrinter p(n1);
        p.split();
        p.print();
    }
    return 0;
}
