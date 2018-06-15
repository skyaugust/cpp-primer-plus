#include "StdAfx.h"
#include "ChapterSix.h"
#include <iostream>
#include <fstream>

using namespace std;
ChapterSix::ChapterSix(void)
{
}

ChapterSix::~ChapterSix(void)
{
}
namespace chapterSix{
	void loopAndTextInput(void);
	void simpleFileInOut(void);
	void practice(void);
	void cinUse(void);
}
using namespace chapterSix;
int main6(int argc, char* argv[])
{
	//loopAndTextInput();
	//practice();
	simpleFileInOut();
	//cinUse();
	return 0;
}
namespace chapterSix{
	void cinUse(void)
	{
		char ch;
		cout << "Enter ch:" << endl;
		cin >> ch;
		cout << "Get : " << ch << endl;

		int n;
		cout << "Enter n:" << endl;
		cin >> n;
		cout << "Get : " << n << endl;

		double x;
		cout << "Enter x:" << endl;
		cin >> x;
		cout << "Get : " << x << endl;

		char word[50];
		cout << "Enter word:" << endl;
		cin >> word;
		cout << "Get : " << word << endl;
	}
	void simpleFileInOut(void)
	{
		char automobile[50];
		int year;
		double a_price;
		double d_price;

		ofstream outFile;
		outFile.open("carinfo.txt");

		// open方法默认丢弃原有内容。即carinfo.txt将被覆盖重写
		cout << "Enter the make and model of automobile:";
		cin.getline(automobile, 50);
		cout << "Enter the model year:";
		cin >> year;
		cout << "Enter the original asking price:";
		cin >> a_price;
		d_price = a_price * 0.913;
		outFile << fixed;
		outFile.setf(ios_base::showpoint);
		outFile << "Make and model: " << automobile << endl;
		outFile << "Year: " << year << endl;
		outFile << "Was Asking: " << a_price << endl;
		outFile << "Now Asking: " << d_price << endl;

		outFile.close();

	}
	void practice(void)
	{
		int j = 5;
		while(++j<9)
			cout<<j++<<endl;
		
	}
	void loopAndTextInput(void)
	{
		char ch;
		int count = 0;
		cout << "Enter ch, enter # to quit:\n";
		cin >> ch;
		while(ch != '#')
		{
			cout << ch;
			count ++;
			cin.get(ch);
		}

		cout << endl << "You entered " << count << " chs." << endl;
	}
}
