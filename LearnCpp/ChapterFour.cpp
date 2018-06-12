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
	assert(*p_ted == 42.2);// ������ʹ�� == �ж���ȣ�float��double��ֵ��ʵ�ʴ洢�п��ܲ�ͬ����һ����

	// 10
	float treacle[10] = {0,1,2,3,4,5,6,7,8,9};
	float *pt = treacle;
	assert(pt[0] == 0);
	assert(pt[9] == 9);

	float n_float = 42.2;
	float *p_n = &n_float;
	//assert(*p_n == 42.2); //ͬ 8��ʵ����42.00000001

	// 11
	int size = 10;
	int* nums = new int[size];
	delete [] nums;

	int* p_int = (int *)"nihao"; 
	//p_int[0] = 'm';// ����ͨ���������б���
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
	  C++ ���ڴ����
	  1.�Զ��洢
		�����ڲ�����ĳ������������������������ִ��ʱ�������������ؽ���ʱ��������ʱ����ռ����ջ�ռ䡣
	  2.��̬�洢
		��������ʹ��static��static double fee = 56.30;
		�ں����ⶨ�壻
		����������£�����������ִ���ڼ䶼����ڣ�
	  3.��̬�洢
		ͨ��new ��delete����ı�������һ���ڴ���д��ڣ�����������new��delete���ơ���ʱ����ռ���˶ѿռ䡣
		ͬʱʹ��new��delete�������ڴ�й¶��
	*/

}
void pointerAndString()
{
	 char animal[20] = "bea";
	 const char* bird = "wren";
	 char *ps;

	 ps = animal;
	 cout << ps << endl;
	 ps = new char[strlen(animal) + 1];// Ԥ��һ��\0
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
	

	// new �� delete��Ҫ�ɶԳ���
	delete p_int;

	cout << "after del, int = " << *p_int << ", location = "  << p_int << endl;// ɾ��֮��*p_int��Ч������ʹ����Σ�յġ�
	assert(*p_int != 42);
}

void pointerBasic(void)
{
	int updates = 6;
	int* p_updates;// int* ��һ������
	p_updates = &updates;
	assert(*p_updates == 6);

	int* p1, p2;// p1 ��int*, ��p2��int

	*p_updates += 1;
	assert(*p_updates == 7);

	double n_double = 4.0;
	double* p_double = &n_double;

	// ��ͬ���͵�ָ�룬���ǵ�ַ����С��ͬ��
	assert(sizeof(p_double) == 4);
	assert(sizeof(p_updates) == 4);

	// �Ϸ���������Σ�ա������ڽ�����֮ǰ����ȷ���ģ��ʵ��ĵ�ַ��vs����ʱ��δ��ʼ����
	//float* p_float;
	//*p_float = 25411;// 25411�洢���ģ�ȡ����p_float�ĳ�ʼֵ�����п��ܽ���ʼֵ��ָ���Ǹ��ڴ����򸲸�Ϊ25411,�������⡣

	//p_float = 0xB8000000; �Ƿ���type mismatch
	//p_float = (float*) 0xB8000000; // �Ϸ�


}
void enumBaisc(void)
{
	// Լ�������ķ�Χ
	enum color{RED, ORANGE, YELLOW};// color ��Ϊ�µ���������
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
		// ����������
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

	// strlen��'\0'�ض�
	char name2[SIZE] = "Jack Ma";
	assert(sizeof(name2) == 15);
	assert(strlen(name2) == 7);
	name2[5] = '\0';
	assert(strlen(name2) == 5);

}
