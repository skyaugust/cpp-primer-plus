// LearnCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cmath>

void simon(int);
double lightYearToAstroUnits(double lightYear);
void displayTime(int hours, int mins);
void chapterOne(void);
void chapterTwo(void);
void chapterThreeE1(void);
void chapterThreeE2(void);
void chapterThreeE4(void);
int _tmain(int argc, _TCHAR* argv[])
{
	chapterThreeE4();

	return 0;
}
void chapterThreeE4()
{
	using namespace std;
	const int HOURS_PER_DAY  = 24;
	const int MINS_PER_HOURS = 60;
	const int SECS_PER_MINS  = 60;

	long input_seconds;
	int days, hours, mins, secs;

	cout << "Enter the number of seconds:";
	cin >> input_seconds;
	const int INPUT_SECONDS = input_seconds;

	days = input_seconds / HOURS_PER_DAY / MINS_PER_HOURS / SECS_PER_MINS;
	input_seconds -= (days * HOURS_PER_DAY * MINS_PER_HOURS * SECS_PER_MINS);

	hours = input_seconds / MINS_PER_HOURS / SECS_PER_MINS;
	input_seconds -= (hours * MINS_PER_HOURS * SECS_PER_MINS);

	mins = input_seconds / SECS_PER_MINS;
	secs = input_seconds - mins * SECS_PER_MINS;

	cout << INPUT_SECONDS << " seconds = " 
										<< days << " days, " 
										<< hours << " hours, " 
										<< mins << " mins, " 
										<< secs << " seconds." 
										<< endl;


}
void chapterThreeE2()
{
	using namespace std;
	const float FI_IN_FACTOR = 12;
	const float KG_BG_FACTOR = 2.2;
	const float EN_M_FACTOR = 0.0254;

	float height_feet_part, height_inch_part;
	float wight;

	cout << "Enter your height(feet part):";
	cin >> height_feet_part;
	cout << "And inch part:";
	cin >> height_inch_part;
	cout << "Enter your wight(bg):";
	cin >> wight;

	float bmi = wight/2.2 / pow((height_feet_part * 12 + height_inch_part) * 0.0254,2);
	cout << "Your BMI = " << bmi;
}
void chapterThreeE1()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	const float FT_IN_FACTOR = 12;
	float height_inch = 0;
	cout << "Enter your height(inches):";
	cin >> height_inch;
	float height_feet =  height_inch / FT_IN_FACTOR;
	cout << "Transfor to height(feet):" << height_feet << endl;

}
void chapterTwo()
{
	using namespace std;
	int n_int = INT_MAX;// INT_MAX定义在 limits.h中，不同系统，范围不一样。
	short n_short = SHRT_MAX;
	long n_long = LONG_MIN;

	cout << "sizeof int : " << sizeof(int) << " bytes" << endl;
	cout << "sizeof short : " << sizeof(short) << " bytes" << endl;
	cout << "sizeof long : " << sizeof(long) << " bytes" << endl;

	cout << "Bits per byte : " << CHAR_BIT << endl;
}

void chapterOne()
{
	using namespace std;
	cout << "Come up and C++ me some time.";
	cout << endl;
	int count;
	cin >> count;
	simon(count);
	double lightYears;
	cin >> lightYears;
	cout << lightYears << " years = " << lightYearToAstroUnits(lightYears) << " astronomical units." << endl;
	int hours, mins;
	cout << "Enter the number of hours:";
	cin >> hours;
	cout << "Enter the number of minutes:";
	cin >> mins;
	displayTime(hours, mins);
}


void simon(int n)
{
	using namespace std;
	cout << "Simon touch your toes " << n << " times."<< endl;
}

double lightYearToAstroUnits(double lightYear)
{
	return lightYear * 63240;
}

void displayTime(int hours, int mins)
{
	std::cout << "Time:" << hours << ":" << mins << std::endl;
}

