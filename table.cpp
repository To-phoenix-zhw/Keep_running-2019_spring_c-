// 实现excel的功能 
#include <string>
#include <iostream>
using namespace std;
const int maxn = 100+1; // Table的最大单元格数目 
// 只用二维数组的一部分，为了符合习惯和统一，从1开始 
class Cell {
public:
  Cell(char con[]); // 传递一个字符数组作为构造函数 
  // 一个单元格的内容可以是字符串也可以是数字
  // 本质上就是字符串 
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
  void show() const; // 打印表 
  int addRow(); // 添加一行 
  void delRow(int n); // 删除指定行 
  int addColumn(); // 添加一列 
  void delColumn(int n); // 删除指定列 
  void set(int, int, string);
  void set(int, int, int);
private:
  Cell *cells[maxn][maxn]; // 一个名为cells的Cell类对象为私有数据成员
  // 最多装maxn个(100个) 
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
	char str[101] = {0}; // 字符串长度不超过100；
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
		cout<<"添加行失败"<<endl;
		return 0;
	}
	row++;
	char initial[] = "-";
	for (int i = 1; i <= column; i++) {
		cells[row][i] = new Cell(initial); 
	}
	cout<<"添加行成功"<<endl;
	return 1;
}
int Table::addColumn() {
	int temp = column+1;
	if (temp >= maxn) {
		cout<<"添加列失败"<<endl;
		return 0;
	}
	column++;
	char initial[] = "-"; // 表示尚未填值 
	for (int i = 1; i <= row; i++) {
		cells[i][column] = new Cell(initial);
	}
	cout<<"添加列成功"<<endl;
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
  Table tb;// Table有无参构造函数 
  tb.show(); // Table有带默认参数的构造函数 
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5); // 带参构造函数 
  tb1.show();
  tb1.set(1,1,30); // 第1行第1列的那个单元格填30 
  tb1.set(2,2,"hello"); // 第2行第2列的那个单元格填hello  
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
