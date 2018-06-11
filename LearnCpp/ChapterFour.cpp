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

	// �Ϸ���������Σ�ա������ڽ�����֮ǰ����ȷ���ģ��ʵ��ĵ�ַ��
	float* p_float;
	*p_float = 25411;// 25411�洢���ģ�ȡ����p_float�ĳ�ʼֵ�����п��ܽ���ʼֵ��ָ���Ǹ��ڴ����򸲸�Ϊ25411,�������⡣

	//p_float = 0xB8000000; �Ƿ���type mismatch
	p_float = (int*) 0xB8000000; // �Ϸ�


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
