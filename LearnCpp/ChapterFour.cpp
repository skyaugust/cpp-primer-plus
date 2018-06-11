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
int main(int argc, char* argv[])
{
	basic();
	unionBaisc();
	enumBaisc();
	pointerBasic();
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

	// 合法，但极其危险。必须在解引用之前，有确定的，适当的地址。
	float* p_float;
	*p_float = 25411;// 25411存储在哪？取决于p_float的初始值。很有可能将初始值所指的那个内存区域覆盖为25411,引起意外。

	//p_float = 0xB8000000; 非法，type mismatch
	p_float = (int*) 0xB8000000; // 合法


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
