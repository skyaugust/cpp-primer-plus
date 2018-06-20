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
	void wow(char * content, int n = 1);
	void funcTemplate(void);
	/**
	  函数模板在编译时生成对应参数类型的函数代码
	*/
	template <class Any>
	void swap_template(Any &a, Any &b);

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
		wow("Hello.");
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
		swap_template(m,n);
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
	template<class Any>
	void swap_template(Any &a, Any &b)
	{
		Any tmp = a;
		a = b;
		b = tmp;
	}
}