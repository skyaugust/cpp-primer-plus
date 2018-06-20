#include "StdAfx.h"
#include "assert.h"
using namespace std;
namespace ChapterEight
{

	void inlineFuction(void);
	/**
	 Inline fuction' codes are compiled in the caller fuction;
	 Some compile would not regard your inline fuction as turly inline if it has recurse structure or for-each codes.
	*/
	inline double squre(double x) { return x * x; }
	/**
	  The reference variable is used in formal parameters.

	*/
	void referenceVar(void);

	/**
		Pass by reference.
	*/
	inline void swap(int & x, int & y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
	void refAndStruct(void);
	struct sysop
	{
		char name[26];
		char qutoe[64];
		int used;

	};
	const sysop & use(sysop & sysopref);
	void wow(char * content = "Ni Hao", int n = 1);
	void funcTemplate(void);
	/**
	  函数模板在编译时生成对应参数类型的函数代码
	*/
	template <class Any>
	void swap_template(Any &a, Any &b);

	/**
	  A box to contain something.
	*/
	struct box
	{
		char maker[40];
		float height;
		float width;
		float length;
		float volume;

	};
	void displayBox(const box & b);
	void computeBoxVolume(box & b);
	double mass(double density, double volume = 1.0);
	//void repeat(int re = 5, const char* content);// Invalid: Default argument not at the end of parameter list

	template <class Any>
	Any max(const Any &a, const Any &b);

	template<>
	box max(const box & a, const box & b);

	template<>
	void swap_template<box>(box & b1, box &b2);
	int called_times = 0;
	void displayString(const char * str, int flag);

	// 8.7
	template <class Any>
	Any maxn(Any * t_arry, int size);

	template<>
	char* maxn<char *>(char** t_arry, int size);
}

int main(int arg, char * argv[])
{
	using namespace ChapterEight;
	inlineFuction();
	referenceVar();
	int x = 3;
	int y = 2;
	swap(x, y);
	assert(x == 2);
	assert(y == 3);
	wow();
	wow("Hello.");

	box b = {
		"Wan",
		1.5,
		2.0,
		3.4,
		48
	};
	displayBox(b);
	computeBoxVolume(b);
	assert(b.volume - 10.2 < 0.01 || 10.2 - b.volume < 0.01);
	int v = 2;
	int u = 3;
	assert(max(v, u) == 3);
	double vd = 4;
	double vu = 6;
	assert(max(vd, vu) == 6);

	box a =
	{
		"qiang",
		5.0,
		96.5,
		3.4,
		0
	};
	computeBoxVolume(a);
	box c = max(a, b);
	displayBox(c);
	int nums[] = { 5,9,2,4,8,541,85 };
	assert(maxn(nums, 7) == 541);
	double nums_double[] = { 2,6,3,4,6,432 };
	assert(maxn(nums_double, 6) == 432);
	char *arrys[4] = { "123","ni hao","hello","OK" };
	assert(strcmp("ni hao", maxn(arrys, 4)) == 0);
}

namespace ChapterEight
{

	void inlineFuction(void)
	{
		double a = 3, b = 4;
		a = squre(a);
		b = squre(3 + 4);
		assert(a == 9);
		assert(b == 49);
	}
	void referenceVar(void)
	{
		int rats;
		int & rodents = rats;

		// Ref is alia
		assert(&rats == &rodents);
		int * const ptr = &rats;

		// Ref is the same with const pointer.
		// Once ptr piont to the rats, it cannot be pointed to other var.
		assert(ptr == &rats);
	}
	void refAndStruct(void)
	{
		sysop looper =
		{
			"Rick Looper",
			"I'm a goto kind of guy.",
			0
		};

		sysop copycat = use(looper);
		assert(copycat.used == 1);
		use(looper);
		assert(copycat.used == 2);
		use(copycat);
		assert(looper.used == 3);
		int a = 2, b = 3;
		swap_template(a, b);
		assert(b == 2);
		assert(a == 3);
		double m = 2, n = 3;
		swap_template(m, n);
		assert(m == 3);
		assert(n == 2);



	}
	const sysop & use(sysop & sysopref)
	{
		// TODO: insert return statement here
		sysopref.used++;
		return sysopref;
	}
	void wow(char * content, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << content << endl;
		}
	}
	void displayBox(const box & b)
	{
		cout << b.maker << endl;
		cout << b.height << endl;
		cout << b.length << endl;
		cout << b.volume << endl;

	}
	void computeBoxVolume(box & b)
	{
		b.volume = b.height * b.width * b.length;
	}
	void repeat(int re, const char * content)
	{
	}
	template<class Any>
	void swap_template(Any &a, Any &b)
	{
		Any tmp = a;
		a = b;
		b = tmp;
	}
	template<class Any>
	Any max(const Any & a, const Any & b)
	{
		return a > b ? a : b;
	}
	template<>
	void swap_template(box & b1, box & b2)
	{
	}
	template<>
	char * maxn(char ** t_arry, int size)
	{
		int max_len = strlen(t_arry[0]);
		char * max_char_ptr = t_arry[0];
		for (int i = 1; i < size; i++)
		{
			if (strlen(t_arry[i]) > max_len)
			{
				max_len = strlen(t_arry[i]);
				max_char_ptr = t_arry[i];

			}
		}
		return max_char_ptr;
	}
	template<class Any>
	Any maxn<Any>(Any * t_arry, int size)
	{
		Any max = t_arry[0];
		for (int i = 1; i < size; i++)
		{
			if (t_arry[i] > max) max = t_arry[i];
		}
		return max;
	}
	template<>
	box max(const box & a, const box & b)
	{

		return a.volume > b.volume ? a : b;
	}
}