// ʵ��excel�Ĺ��� 
#include <string>
#include <iostream>
using namespace std;
const int maxn = 100+1; // Table�����Ԫ����Ŀ 
// ֻ�ö�ά�����һ���֣�Ϊ�˷���ϰ�ߺ�ͳһ����1��ʼ 
class Cell {
public:
  Cell(char con[]); // ����һ���ַ�������Ϊ���캯�� 
  // һ����Ԫ������ݿ������ַ���Ҳ����������
  // �����Ͼ����ַ��� 
  ~Cell();

  void show();
private:
  string content;
};
Cell::Cell(char con[]) {
	content = con;
}
Cell::~Cell() {
	;
}
void Cell::show() {
	cout<<content;
}
class Table {
public: 
  Table();
  Table(int, int);
  ~Table();
  void show() const; // ��ӡ�� 
  int addRow(); // ���һ�� 
  void delRow(int n); // ɾ��ָ���� 
  int addColumn(); // ���һ�� 
  void delColumn(int n); // ɾ��ָ���� 
  void set(int, int, string);
  void set(int, int, int);
private:
  Cell *cells[maxn][maxn]; // һ����Ϊcells��Cell�����Ϊ˽�����ݳ�Ա
  // ���װmaxn��(100��) 
  int row;
  int column;
};
Table::Table() {
	row = 0;
	column = 0;
}
Table::Table(int a, int b) : row(a), column(b) {
	char str[] = "-";
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cells[i][j] = new Cell(str);
		}
	}
}
Table::~Table() {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cells[i][j]->~Cell();
			cells[i][j] = NULL;
		}
	}
}

void Table::set(int a, int b, int c) {
	int cnt = 0;
	int temp = c;
	char str[100] = {0};
	while (temp != 0) {
		str[cnt++] = (temp % 10) + 48;
		temp /= 10;
	}
	char str2[100] = {0};
	for (int i = cnt - 1; i >= 0; --i) {
		str2[cnt - i - 1] = str[i];
	}
	cells[a][b] = new Cell(str2);
}
void Table::set(int a, int b, string c) {
	char str[101] = {0}; // �ַ������Ȳ�����100��
	int i;
	for (i = 0; i < c.length(); i++) {
		str[i] = c[i];
	} 
	str[i] = '\0';
	cells[a][b] = new Cell(str);
}
void Table::show() const {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			cells[i][j]->show();
		}
		cout<<endl;
	}
}
int Table::addRow() {
	int temp = row+1;
	if (temp >= maxn) {
		cout<<"�����ʧ��"<<endl;
		return 0;
	}
	row++;
	char initial[] = "-";
	for (int i = 1; i <= column; i++) {
		cells[row][i] = new Cell(initial); 
	}
	cout<<"����гɹ�"<<endl;
	return 1;
}
int Table::addColumn() {
	int temp = column+1;
	if (temp >= maxn) {
		cout<<"�����ʧ��"<<endl;
		return 0;
	}
	column++;
	char initial[] = "-"; // ��ʾ��δ��ֵ 
	for (int i = 1; i <= row; i++) {
		cells[i][column] = new Cell(initial);
	}
	cout<<"����гɹ�"<<endl;
	return 1;
}
void Table::delRow(int n) {
	for (int i = n; i < row; i++) {
		for (int j = 1; j <= column; j++) {
			cells[i][j] = cells[i+1][j];	
		}
	}
	for (int j = 1; j <= column; j++) {
		cells[row][j]->~Cell();
		cells[row][j] = NULL; 	
	}
	row--;
} 
void Table::delColumn(int n) {
	for (int i = n; i < column; i++) {
		for (int j = 1; j <= row; j++) {
			cells[j][i] = cells[j][i+1];
		}
	}
	for (int j = 1; j <= row; j++) {
		cells[j][column]->~Cell();
		cells[j][column] = NULL;
	}
	column--;
}
int main() {
  Table tb;// Table���޲ι��캯�� 
  tb.show(); // Table�д�Ĭ�ϲ����Ĺ��캯�� 
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5); // ���ι��캯�� 
  tb1.show();
  tb1.set(1,1,30); // ��1�е�1�е��Ǹ���Ԫ����30 
  tb1.set(2,2,"hello"); // ��2�е�2�е��Ǹ���Ԫ����hello  
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
