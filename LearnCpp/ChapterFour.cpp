#include "StdAfx.h"
#include <assert.h>
#include "ChapterFour.h"


using namespace std;
ChapterFour::ChapterFour(void)
{
}

ChapterFour::~ChapterFour(void)
{
}

void basic(void);
void structBasic(void);
void unionBaisc(void);
void enumBaisc(void);
void pointerBasic(void);
void newBasic(void);
void newDynamicArray(const int size);
void pointerAndString(void);
void newDynamicStruct(void);

void practice(void);
void exercize5(void);
int main(int argc, char* argv[])
{
	basic();
	structBasic();
	unionBaisc();
	enumBaisc();
	pointerBasic();
	newBasic();
	newDynamicArray(15);
	pointerAndString();
	newDynamicStruct();

	practice();
	exercize5();

}
void exercize5(void)
{
	struct CandyBar
	{
		string brand;
		double wight;
		int kol;
	};

	CandyBar snack = {
		"Mocha Munch",
		123.366,
		344
	};
	assert(snack.kol == 344);

	CandyBar bars[2];
	bars[0] = snack;


	assert(bars[0].kol == 344);

	CandyBar *p_bars = new CandyBar[2];
	p_bars[1].kol = 144;
	assert(p_bars[1].kol == 144);

}
void practice(void)
{
	// 1.
	char actor[30];
	short betsie[100];
	float chuck[13];
	long double dipse[64];

	// 2,3
	int odds[5] = {1,3,5,7,9};
	int even = odds[0] + odds[4];
	assert(even == 10);

	// 5
	char food[20] = "cheeseburger";
	char *pf = new char[strlen(food) + 1];
	strcpy(pf, food);
	assert(strcmp(pf, food) == 0);

	// 6,7
	struct fish
	{
		int type;
		int wight;
		double length;
	};

	fish f ={
		0,
		2,
		1.2
	};

	fish* pfish ;
	pfish = &f;
	assert(pfish->type == 0);

	// 8
	enum Response{Yes = 1,No = 0, Maybe = 2};
	Response r = Yes;
	assert(r == Yes);

	// 9
	double ted = 42.2;
	double* p_ted = &ted;
	assert(*p_ted == 42.2);// 不建议使用 == 判断相等，float和double赋值和实际存储有可能不同，有一定误差。

	// 10
	float treacle[10] = {0,1,2,3,4,5,6,7,8,9};
	float *pt = treacle;
	assert(pt[0] == 0);
	assert(pt[9] == 9);

	float n_float = 42.2;
	float *p_n = &n_float;
	//assert(*p_n == 42.2); //同 8，实际是42.00000001

	// 11
	int size = 10;
	int* nums = new int[size];
	delete [] nums;

	int* p_int = (int *)"nihao"; 
	//p_int[0] = 'm';// 编译通过，但运行报错
	//cout << p_int <<endl;
}

void newDynamicStruct(void)
{
	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};

	inflatable * ps = new inflatable;
	strcpy(ps->name,"Jack Ma");
	(*ps).volume = 5.0;
	ps->price = 19.8;
	assert(strcmp(ps->name, "Jack Ma") == 0);
	assert(ps->volume == 5.0);
	assert(ps->price == 19.8);
	delete ps;
	/*
	  C++ 的内存管理：
	  1.自动存储
		函数内部定义的常规变量，在所属函数被调用执行时产生，函数返回结束时消亡；有时称其占据了栈空间。
	  2.静态存储
		声明变量使用static：static double fee = 56.30;
		在函数外定义；
		这两种情况下，在整个程序执行期间都会存在；
	  3.动态存储
		通过new 和delete管理的变量。从一个内存池中存在，生命周期由new和delete控制。有时称其占据了堆空间。
		同时使用new和delete，避免内存泄露；
	*/

}
void pointerAndString()
{
	 char animal[20] = "bea";
	 const char* bird = "wren";
	 char *ps;

	 ps = animal;
	 cout << ps << endl;
	 ps = new char[strlen(animal) + 1];// 预留一个\0
	 strcpy(ps,animal);
	 assert(strlen(animal) == strlen(ps));
	 delete [] ps;

}
void newDynamicArray(const int size)
{
	int* p_intArray = new int[size];
	for(int i = 0; i < size; i++)
	{
		p_intArray[i] = i * 2;
		cout << p_intArray[i] << " " << endl;
	}

	delete [] p_intArray;
}
void newBasic(void)
{
	cout << "newBasic:"<<endl;
	// typeName pointer_name = new typeName;

	int* p_int = new int;
	*p_int = 42;
	cout << "int = " << *p_int << ", location = "  << p_int << endl;
	assert(*p_int == 42);
	

	// new 和 delete总要成对出现
	delete p_int;

	cout << "after del, int = " << *p_int << ", location = "  << p_int << endl;// 删除之后，*p_int无效，继续使用是危险的。
	assert(*p_int != 42);
}

void pointerBasic(void)
{
	int updates = 6;
	int* p_updates;// int* 是一种类型
	p_updates = &updates;
	assert(*p_updates == 6);

	int* p1, p2;// p1 是int*, 但p2是int

	*p_updates += 1;
	assert(*p_updates == 7);

	double n_double = 4.0;
	double* p_double = &n_double;

	// 不同类型的指针，都是地址，大小相同。
	assert(sizeof(p_double) == 4);
	assert(sizeof(p_updates) == 4);

	// 合法，但极其危险。必须在解引用之前，有确定的，适当的地址。vs运行时报未初始化错
	//float* p_float;
	//*p_float = 25411;// 25411存储在哪？取决于p_float的初始值。很有可能将初始值所指的那个内存区域覆盖为25411,引起意外。

	//p_float = 0xB8000000; 非法，type mismatch
	//p_float = (float*) 0xB8000000; // 合法


}
void enumBaisc(void)
{
	// 约束整数的范围
	enum color{RED, ORANGE, YELLOW};// color 成为新的类型名称
	color sky;
	sky = RED;

	enum bits{ONE = 1, TOW = 2, FOUR = 4, EIGHT = 8};

}
void unionBaisc()
{
	union one4all
	{
		int int_val;
		long long_val;
		double double_val;
	};

	one4all pail;
	pail.int_val = 4;
	pail.long_val = 4;
	pail.double_val = 4.1234;
	
	assert(sizeof(pail) == sizeof(double));

	struct widget
	{
		char name[20];
		// 匿名共用体
		union
		{
			long id_num;
			char id_char[20];
		};
	};

	widget prize;
	prize.id_num = 12;


}
void structBasic(){
	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};

	inflatable guest = 
	{
		"Jack Ma",
		1.88,
		19.99
	};

	assert(strcmp(guest.name, "Jack Ma") == 0);

	inflatable guest2 = guest;

	guest2.volume = 1.87;
	assert(&guest != &guest2);

}
void basic(void)
{
	char bird[] = "0123456789";
	assert(sizeof(bird) == 11);
	assert(strlen(bird) == 10);
	
	const int SIZE = 15;
	char name[SIZE] =  "Jack";
	assert(strlen(name) == 4);

	// strlen被'\0'截断
	char name2[SIZE] = "Jack Ma";
	assert(sizeof(name2) == 15);
	assert(strlen(name2) == 7);
	name2[5] = '\0';
	assert(strlen(name2) == 5);

}
