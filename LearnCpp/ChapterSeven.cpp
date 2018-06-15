#include "stdafx.h"
#include "ChapterSeven.h"
#include <assert.h>

ChapterSeven::ChapterSeven(void)
{
}

ChapterSeven::~ChapterSeven(void)
{
}
namespace chpterSeven
{
	struct travel_time
	{
 		int hours;
 		int mins;
	};

	struct rect
	{
		double x;
		double y;
	};
	struct polar
	{
		double distance;
		double angle;
	};
    void functionAndArray(void);
	/**
	* @brief Compute sum of array
	* @param [in] arr    the array
	* @param [in] size   the len of array
	* @return	the some of array
	*/
	int sum_arr(int arr[], int size);
	int fill_arr(int arr[], int limit);
	int sum_arr_tow_dimen(int arr[][4], int size);
	int sum_arr(const int * begin, const int * end);
	void funcAndCstyleString(void);
	int c_in_str(const char * str, char c);
	char * buildstr(char c, int n);
	void funcAndStruct(void);
	void show_polar(polar dapos);
	void show_polar(const polar * dapos);
	travel_time sum(travel_time t1, travel_time t2);
	polar rect_to_polar(rect xypos);
	polar rect_to_polar(const rect * xypos);
	void rect_to_polar(const rect * xypos, polar * dapos);
	void countDown(int n);
	/**
	* Beside ar[low] and ar[high] are ‘|’， others are ' '.
	* Call this method whill paint ar[mid] to ‘|’
	*/
	void paintRulerInMid(char ar[], int low, int high, int level);
	void paintRuler(void);
	void estimate(int lines, double(*pf)(double))
	{
		double x = (*pf)(0);

	}
	double compute1(double x);
	double compute2(double x);
	
}
int main(int argc, char* argv[])
{
	using namespace std;
	using namespace chpterSeven;
	functionAndArray();
	int arr[8] = {0,0,0,0,0,0,0,0};
	int i = fill_arr(arr, 5);
	cout << i << endl;

	int data[3][4] = { {1,2,3,4},{9,8,7,6},{2,4,6,8} };
	assert(sum_arr_tow_dimen(data, 3) == 60);
	funcAndCstyleString();
	char * cpn = buildstr('c', 10);
	assert(strcmp(cpn, "cccccccccc") == 0);
	funcAndStruct();
	rect pos1 = { 1.0,1.0 };
	show_polar(rect_to_polar(pos1));
	show_polar(&rect_to_polar(&pos1));
	countDown(5);
	paintRuler();

	void(*pf)(char *, int, int, int);
	pf = paintRulerInMid;
	void(*pf_countDown)(int);
	pf_countDown = countDown;
	estimate(1, compute1);
	estimate(2, compute2);
	return 0;
}

namespace chpterSeven
{
	double compute1(double x)
	{
		
		return 0.0;
	}
	double compute2(double x)
	{
		for (int i = 0; i < 1000000; i++);
		return 0.0;
	}
	void paintRuler()
	{
		using namespace std;
		const int SIZE = 66;
		const int LEVEL = 6;
		char ruler[SIZE];
		for (size_t i = 0; i < SIZE; i++)
		{
			ruler[i] = ' ';
		}
		ruler[SIZE-1] = '\0';
		int min = 0;
		int max = SIZE - 2;
		ruler[min] = ruler[max] = '|';
		cout << ruler << endl;
		for (int i = 1; i <= LEVEL; i++)
		{
			paintRulerInMid(ruler, min, max, i);
			cout << ruler << endl;
			for (size_t  j = 1; j < max; j++)
			{
				ruler[j] = ' ';
			}
		}
	}
	void paintRulerInMid(char ar[], int low, int high, int level)
	{
		if (level == 0)
		{
			return;
		}
		int mid = (high + low) / 2;
		ar[mid] = '|';
		paintRulerInMid(ar, low, mid, level - 1);
		paintRulerInMid(ar, mid, high, level - 1);
		
	}
	void countDown(int n)
	{
		using namespace std;
		cout << "Count Down : " << n << endl;
		if (n == 0)
		{
			return;
		}
		else
		{
			countDown(n - 1);
		}
	}
	void rect_to_polar(const rect * xypos, polar * dapos)
	{
		dapos->distance = sqrt(xypos->x * xypos->y + xypos->y * xypos->y);
		dapos->angle = atan2(xypos->y, xypos->x);
	}

	polar rect_to_polar(const rect * xypos)
	{
		using namespace std;
		polar answer;
		answer.distance = sqrt(xypos->x * xypos->y + xypos->y * xypos->y);
		answer.angle = atan2(xypos->y, xypos->x);
		return answer;
	}

	void show_polar(const polar * dapos)
	{
		const double RAD_TO_DEG = 57.29577951;
		using namespace std;
		cout << "distance = " << dapos->distance;
		cout << ", angle = " << dapos->angle * RAD_TO_DEG << " degrees\n";
	}
	
	/**
	*  结构体作为入参返回参数，会各拷贝一次，造成浪费
	*/
	polar rect_to_polar(rect xypos)
	{
		using namespace std;
		polar answer;
		answer.distance = sqrt(xypos.x * xypos.y + xypos.y * xypos.y);
		answer.angle = atan2(xypos.y, xypos.x);
		return answer;
	}
	void show_polar(polar dapos)
	{
		const double RAD_TO_DEG = 57.29577951;
		using namespace std;
		cout << "distance = " << dapos.distance;
		cout << ", angle = " << dapos.angle * RAD_TO_DEG << " degrees\n";
	}
	travel_time sum(travel_time t1, travel_time t2);
	travel_time sum(const travel_time t1, const travel_time t2)
	{
		travel_time total;
		int total_hours = t1.hours + t2.hours;
		int total_mins = t1.mins + t2.mins;
		int c_hours = total_mins / 60;
		int remains_mins = total_mins - c_hours * 60;
		
		total.hours = total_hours + c_hours;
		total.mins = remains_mins;
		return total;
	}
	
	void funcAndStruct(void)
	{
		travel_time t1 = { 2,35 };
		travel_time t2 = { 3, 45 };
		travel_time total = sum(t1, t2);
		assert(total.hours == 6);
		assert(total.mins == 20);
	}
	char * buildstr(char c, int n)
	{
		char * ps = new char[n+1];
		ps[n] = '\0';
		while(n-- > 0) 
		{
			ps[n] = c;
		}
		return ps;
	}
	int c_in_str(const char * str, char c)
	{
		int count = 0;
		while (*str)
		{
			if (*str == c)
			{
				count++;
			}
			str++;
		}
		return count;
	}
	void funcAndCstyleString(void)
	{
		char ghost[15] = "galloping";
		char * str = "zhangsan";
		assert(strlen(ghost) == 9);
		assert(strlen(str) == 8);
		assert(strlen("wang") == 4);
		assert(c_in_str("zhangsan", 'n') == 2);
		assert(c_in_str("mmc", 'm') == 2);
		int n_array[] = { -1,1,2,3,4,5 };
		assert(sum_arr(n_array + 1, n_array + 5), 15);
	}
	int sum_arr_tow_dimen(int arr[][4], int size) 
	{
		int sum = 0;
		for (int row = 0; row < size; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				sum += arr[row][col];
			}
		}
		return sum;
	}
	int sum_arr(const int * begin, const int * end)
	{
		int sum = 0;
		
		for (const int * ptr = begin; ptr != end; ptr++)
		{
			sum += *ptr;
		}

		return sum;

	}
	int fill_arr(int arr[], int limit) 
	{
		using namespace std;
		double temp;
		int i;
		for (i = 0; i < limit; i++)
		{
			cout << "Enter value #" << (i + 1) << ": ";
			cin >> temp;
			if (!cin)
			{
				cin.clear();
				while (cin.get() != '\n')
				{
					continue;
				}
				cout << "Bad input. Teminated." << endl;
				break;
			}
			else if (temp < 0)
			{
				break;
			}
			arr[i] = temp;

		}
		return sum_arr(arr, i);
	}
	void functionAndArray(void)
	{
		using namespace std;
		const int ARC_SIZE = 8;
		int cookies[ARC_SIZE] = {1,2,4,8,16,32,64,128};
		int sum = sum_arr(cookies, ARC_SIZE);
		assert(sum == 255);
		sum = sum_arr(cookies + 4, ARC_SIZE-4);
		assert(sum == (16+32+64+128));

	}

	int sum_arr(int arr[], int size)
	{
		int sum = 0;
		for(int i = 0; i < size; i++) sum += *(arr+i);
		return sum;
	}
}
