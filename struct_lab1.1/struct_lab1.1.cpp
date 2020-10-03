#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

struct datetime
{
	int day, month, year, second, minute, hour;
	void method_set(int d, int m, int y, int h, int min, int s);
	void method_output(datetime a);
	int method_next_date(datetime a);
	int method_previous_date(datetime a);
	int method_conversion(datetime a);
}time1, time2, time3;

struct timedelta
{
	int day, month, year, second, minute, hour;
	void method_output_d(timedelta a);
}timedelta1, timedelta2, timedelta3;

//function subheadings

void minuss(datetime a, datetime a2, timedelta &a3);
void reverse_conversion(int a, datetime& a1);
void reverse_conversion1(int a, timedelta& a1, datetime &a2);
int Err(int &j, int d, int m, int y);
int Err2(int &j1, int h, int m, int s);
void memory_array(datetime *&a, int n);
void fill_file(int n);
void fill_array(datetime *&a, int n);
void var9(datetime*&a, int n);
void task2(char b, datetime a, timedelta a2, datetime &a3);
void task3(char b, timedelta a, timedelta a2, timedelta &a3);

int main()
{
	srand(time(NULL));
	int n, n1;
	int d, m, y, s, min, h, j = 0, j1 = 0;
	while (true)
	{
		cout << "________________________________________________________________________" << endl;
		cout << "Hello! Choose an action" << endl;
		cout << "1) Set the first time" << endl;
		cout << "2) Set the second time" << endl;
		cout << "3) Output the first time " << endl;
		cout << "4) Output the second time" << endl;
		cout << "5) Getting the next date" << endl;
		cout << "6) Getting the previous date" << endl;
		cout << "7) Array" << endl;
		cout << "8) Unix time" << endl;
		cout << "9) Datetime1 - datetime2 = timedelta1" << endl;
		cout << "10) datetime1 -+ timedelta = datetime2" << endl;
		cout << "11) timdelta1 -+ timedelta2 = timedelta3" << endl;
		cout << "0) Exit the program" << endl;
		cout << "12) Test" << endl;
		cout << "________________________________________________________________________" << endl;
		cin >> n;
		if (n > 12 || n < 0)
		{
			cout << "Error" << endl;
		}
		else 
		{
			switch (n)
			{
			case 1:
				cout << "________________________________________________________________________" << endl;
				cout << "Enter the date" << endl << "________________________________________________________________________" << endl;
				cin >> d >> m >> y;
				Err(j, d, m, y);
				if (j == 0)
				{
					cout << "Error." << "________________________________________________________________________" << endl;
					break;
				}
				else
				{
					cout << "Okey. Now enter the time" << endl << "________________________________________________________________________" << endl;
					cin >> h >> min >> s;
					Err2(j1, h, m, s);
					if (j1 == 0)
					{
						cout << "Error." << "________________________________________________________________________" << endl;
					}
					else
					{
						time1.method_set(d, m, y, h, min, s);
					}
				}
				break;
			case 2:
				cout << "________________________________________________________________________" << endl;
				cout << "Enter the date" << endl << "________________________________________________________________________" << endl;
				cin >> d >> m >> y;
				Err(j, d, m, y);
				if (j == 0)
				{
					cout << "Error." << "________________________________________________________________________" << endl;
					break;
				}
				else
				{
					cout << "Okey. Now enter the time" << endl << "________________________________________________________________________" << endl;
					cin >> h >> min >> s;
					Err2(j1, h, m, s);
					if (j1 == 0)
					{
						cout << "Error." << "________________________________________________________________________" << endl;
					}
					else
					{
						time2.method_set(d, m, y, h, min, s);
					}
				}
				break;
			case 3:
				cout << "________________________________________________________________________" << endl;
				time1.method_output(time1);
				break;
			case 4:
				cout << "________________________________________________________________________" << endl;
				time2.method_output(time2);
				break;
			case 5:
				cout << "________________________________________________________________________" << endl;
				{int x1 = 0;
				x1 = time1.method_next_date(time1);
				reverse_conversion(x1, time1);
				time1.method_output(time1);
				break;
				}
			case 6:
				cout << "________________________________________________________________________" << endl;
				{int x1 = 0;
				x1 = time1.method_previous_date(time1);
				reverse_conversion(x1, time1);
				time1.method_output(time1);
				break;
				}
			case 7: //********************************************************************
			{
				int ni = 0;
				int z = 1;
				datetime *x = 0;
				while (z == 1)
				{
					cout << "________________________________________________________________________" << endl;
					cout << "Choose an action" << endl;
					cout << "1) Create array" << endl;
					cout << "2) Fill the file with data" << endl;
					cout << "3) Fill an array with data from a file" << endl;
					cout << "4) Display array of data" << endl;
					cout << "5) Var9" << endl;
					cout << "0) Main menu" << endl;
					cout << "________________________________________________________________________" << endl;
					cin >> n1;
					switch (n1)
					{
					case 1:
					{
						cout << "________________________________________________________________________" << endl;
						int n2;
						cout << "Enter N" << endl;
						cin >> n2;
						ni = n2;
						memory_array(x, n2);
						for (int i = 0; i < n2; i++)
						{
							x[i].day = 0;
							x[i].month = 0;
							x[i].year = 0;
							x[i].hour = 0;
							x[i].minute = 0;
							x[i].second = 0;
						}
						break;
					}
					case 2:
					{
						cout << "________________________________________________________________________" << endl;
						int n3;
						cout << "Enter N" << endl;
						cin >> n3;
						fill_file(n3);
						break;
					}
					case 3:
					{
						cout << "________________________________________________________________________" << endl;
						char buff[50];
						fill_array(x, ni);
						break;
					}
					case 4:
					{
						cout << "________________________________________________________________________" << endl;
						int k = 0;
						for (int i = 0; i < ni; i++)
						{
							k++;
							cout << k << ") " << x[i].day << "." << x[i].month << "." << x[i].year << "   " << x[i].hour << ":" << x[i].minute << ":" << x[i].second << endl;
						}
						break;
					}
					case 5:
					{
						cout << "________________________________________________________________________" << endl;
						var9(x, ni);
						break;
					}
					case 0:
						z = 0;
						delete[]x;
						break;
					}
				}
				break;
			}
			case 8:
			{
				cout << "________________________________________________________________________" << endl;
				time_t t = time(NULL);
				reverse_conversion(t, time3);
				cout << "Unix time is  " << time3.day << "." << time3.month << "." << time3.year << "   " << time3.hour << ":" << time3.minute << ":" << time3.second << endl;
				break;
			}
			case 9:
			{
				int nk;
				cout << "________________________________________________________________________" << endl;
				cout << "Enter N" << endl;
				cin >> nk;
				if (nk > 2 || nk < 1)
				{
					cout << "Error" << endl;
				}
				else
				{
					if (nk == 1)
					{
						minuss(time1, time2, timedelta1);
						timedelta1.method_output_d(timedelta1);
					}
					else
					{
						minuss(time1, time2, timedelta2);
						timedelta2.method_output_d(timedelta2);
					}
				}
				break;
			}
			case 10:
			{
				char b[2];
				cout << "________________________________________________________________________" << endl;
				cout << "Please enter + or -" << endl;
				cin >> b;
				task2(*b, time1, timedelta1, time2);
				time2.method_output(time2);
				break;
			}
			case 11:
			{
				char b[2];
				cout << "________________________________________________________________________" << endl;
				cout << "Please enter + or -" << endl;
				cin >> b;
				task3(*b, timedelta1, timedelta2, timedelta3);
				timedelta1.method_output_d(timedelta1);
				cout << "------------------------------" << endl;
				timedelta2.method_output_d(timedelta2);
				cout << "------------------------------" << endl;
				timedelta3.method_output_d(timedelta3);
				break;
			}
			case 0:
				return 0;
			case 12:
				cout << "________________________________________________________________________" << endl;
				int x;
				x = time1.method_conversion(time1);
				cout << "date to time conversion" << endl;
				cout << x << endl << "________________________________________________________________________" << endl;
				cout << "date to time reserve conversion" << endl;
				reverse_conversion(x, time1);
				time1.method_output(time1);
			}
		}
	}
}

//description of methods and functions
//Задание 1 (усложненное)
void minuss(datetime a, datetime a2, timedelta &a3)
{
	int d = 0, m = 0, y = 0, h = 0, min = 0 , s = 0;
	int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
	int d2 = a2.day, m2 = a2.month, y2 = a2.year, h2 = a2.hour, min2 = a2.minute, s2 = a2.second;
	if (s1 < s2)
	{
		min1=min1-1;
		s1 += 60;
		s = s1 - s2;
	}
	else
	{
		s = s1 - s2;
	}
	if (min1 < min2)
	{
		h1 = h1 - 1;
		min1 += 60;
		min = min1 - min2;
	}
	else
	{
		min = min1 - min2;
	}
	if (h1 < h2)
	{
		d1 -= 1;
		h1 += 24;
		h = h1 - h2;
	}
	else
	{
		h = h1 - h2;
	}
	if (d1 < d2)
	{
		if (m1 >= 1 && m1 <= 12)//12 месяцев
		{
			if (m1 == 2)//февраль
			{
				if (y % 4 == 0) //високосный или нет
				{
					m1 -= 1;
					d1 += 29;
					d = d1 - d2;
				}
				else
				{
					m1 -= 1;
					d1 += 28;
					d = d1 - d2;
				}
			}
			if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
			{
				m1 -= 1;
				d1 += 31;
				d = d1 - d2;
			}
			if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
			{
				m1 -= 1;
				d1 += 30;
				d = d1 - d2;
			}
		}
	}
	else
	{
		d = d1 - d2;
	}
	if (m1 < m2)
	{
		y1 -= 1;
		m1 += 12;
		m = m1 - m2;
	}
	else
	{
		m = m1 - m2;
	}
	if (y1 < y2)
	{
		y = (y2 - y1)*-1;
		m *= -1;
		d *= -1;
		h *= -1;
		min *= -1;
		s *= -1;
	}
	else
	{
		y = y1 - y2;
	}
	a3.day = d;
	a3.month = m;
	a3.year = y;
	a3.hour = h;
	a3.minute = min;
	a3.second = s;
} 
//Задание 2 (усложненное)
void task2(char b, datetime a, timedelta a2, datetime &a3)
{
	if (b == '-') 
	{
		int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
		int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
		int d2 = a2.day, m2 = a2.month, y2 = a2.year, h2 = a2.hour, min2 = a2.minute, s2 = a2.second;
		if (y2 < 0)
		{

			int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
			int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
			int d2 = -1 * a2.day, m2 = -1 * a2.month, y2 = -1 * a2.year, h2 = -1 * a2.hour, min2 = -1 * a2.minute, s2 = -1 * a2.second;
			s = s1 + s2;
			if (s >= 60)
			{
				s -= 60;
				min1 += 1;
			}
			min = min1 + min2;
			if (min >= 60)
			{
				min -= 60;
				h1 += 1;
			}
			h = h1 + h2;
			if (h >= 24)
			{
				h -= 24;
				d1 += 1;
			}
			d = d1 + d2;
			if (m1 >= 1 && m1 <= 12)//12 месяцев
			{
				if (m1 == 2)//февраль
				{
					if (y % 4 == 0) //високосный или нет
					{
						if (d > 29)
						{
							d -= 29;
							m1 += 1;
						}
					}
					else
					{
						if (d > 28)
						{
							d -= 28;
							m1 += 1;
						}
					}
				}
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
				{
					if (d > 31)
					{
						d -= 31;
						m1 += 1;
					}
				}
				if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
				{
					if (d > 30)
					{
						d -= 30;
						m1 += 1;
					}
				}
			}
			m = m1 + m2;
			if (m > 12)
			{
				m -= 12;
				y1 += 1;
			}
			y = y1 + y2;
			a3.day = d;
			a3.month = m;
			a3.year = y;
			a3.hour = h;
			a3.minute = min;
			a3.second = s;

		}
		if (s1 < s2)
		{
			min1 = min1 - 1;
			s1 += 60;
			s = s1 - s2;
		}
		else
		{
			s = s1 - s2;
		}
		if (min1 < min2)
		{
			h1 = h1 - 1;
			min1 += 60;
			min = min1 - min2;
		}
		else
		{
			min = min1 - min2;
		}
		if (h1 < h2)
		{
			d1 -= 1;
			h1 += 24;
			h = h1 - h2;
		}
		else
		{
			h = h1 - h2;
		}
		if (d1 < d2)
		{
			if (m1 >= 1 && m1 <= 12)//12 месяцев
			{
				if (m1 == 2)//февраль
				{
					if (y % 4 == 0) //високосный или нет
					{
						m1 -= 1;
						d1 += 29;
						d = d1 - d2;
					}
					else
					{
						m1 -= 1;
						d1 += 28;
						d = d1 - d2;
					}
				}
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
				{
					m1 -= 1;
					d1 += 31;
					d = d1 - d2;
				}
				if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
				{
					m1 -= 1;
					d1 += 30;
					d = d1 - d2;
				}
			}
		}
		else
		{
			d = d1 - d2;
		}
		if (m1 < m2)
		{
			y1 -= 1;
			m1 += 12;
			m = m1 - m2;
		}
		else
		{
			m = m1 - m2;
		}
		if (y1 < y2)
		{
			y = (y2 - y1)*-1;
			m *= -1;
			d *= -1;
			h *= -1;
			min *= -1;
			s *= -1;
		}
		else
		{
			y = y1 - y2;
		}
		a3.day = d;
		a3.month = m;
		a3.year = y;
		a3.hour = h;
		a3.minute = min;
		a3.second = s;
	}
	if(b == '+')
	{
    int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
	int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
	int d2 = a2.day, m2 = a2.month, y2 = a2.year, h2 = a2.hour, min2 = a2.minute, s2 = a2.second;
	if (y2 < 0)
	{
		int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
		int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
		int d2 = -1*a2.day, m2 = -1 * a2.month, y2 = -1 * a2.year, h2 = -1 * a2.hour, min2 = -1 * a2.minute, s2 = -1 * a2.second;
		if (s1 < s2)
		{
			min1 = min1 - 1;
			s1 += 60;
			s = s1 - s2;
		}
		else
		{
			s = s1 - s2;
		}
		if (min1 < min2)
		{
			h1 = h1 - 1;
			min1 += 60;
			min = min1 - min2;
		}
		else
		{
			min = min1 - min2;
		}
		if (h1 < h2)
		{
			d1 -= 1;
			h1 += 24;
			h = h1 - h2;
		}
		else
		{
			h = h1 - h2;
		}
		if (d1 < d2)
		{
			if (m1 >= 1 && m1 <= 12)//12 месяцев
			{
				if (m1 == 2)//февраль
				{
					if (y % 4 == 0) //високосный или нет
					{
						m1 -= 1;
						d1 += 29;
						d = d1 - d2;
					}
					else
					{
						m1 -= 1;
						d1 += 28;
						d = d1 - d2;
					}
				}
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
				{
					m1 -= 1;
					d1 += 31;
					d = d1 - d2;
				}
				if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
				{
					m1 -= 1;
					d1 += 30;
					d = d1 - d2;
				}
			}
		}
		else
		{
			d = d1 - d2;
		}
		if (m1 < m2)
		{
			y1 -= 1;
			m1 += 12;
			m = m1 - m2;
		}
		else
		{
			m = m1 - m2;
		}
		if (y1 < y2)
		{
			y = (y2 - y1)*-1;
			m *= -1;
			d *= -1;
			h *= -1;
			min *= -1;
			s *= -1;
		}
		else
		{
			y = y1 - y2;
		}
		a3.day = d;
		a3.month = m;
		a3.year = y;
		a3.hour = h;
		a3.minute = min;
		a3.second = s;
	}
	s = s1 + s2;
	if (s >= 60)
	{
		s -= 60;
		min1 += 1;
	}
	min = min1 + min2;
	if (min >= 60)
	{
		min -= 60;
		h1 += 1;
	}
	h = h1 + h2;
	if (h >= 24)
	{
		h -= 24;
		d1 += 1;
	}
	d = d1 + d2;
	if (m1 >= 1 && m1 <= 12)//12 месяцев
	{
		if (m1 == 2)//февраль
		{
			if (y % 4 == 0) //високосный или нет
			{
				if (d > 29)
				{
					d -= 29;
					m1 += 1;
				}
			}
			else
			{
				if (d > 28)
				{
					d -= 28;
					m1 += 1;
				}
			}
		}
		if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
		{
			if (d > 31)
			{
				d -= 31;
				m1 += 1;
			}
		}
		if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
		{
			if (d > 30)
			{
				d -= 30;
				m1 += 1;
			}
		}
	}
	m = m1 + m2;
	if (m > 12)
	{
		m -= 12;
		y1 += 1;
	}
	y = y1 + y2;
	a3.day = d;
	a3.month = m;
	a3.year = y;
	a3.hour = h;
	a3.minute = min;
	a3.second = s;
    }
}
//Задание 3 (усложненное)
void task3(char b, timedelta a, timedelta a2, timedelta &a3)
{
	if (b == '-')
	{
		int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
		int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
		int d2 = a2.day, m2 = a2.month, y2 = a2.year, h2 = a2.hour, min2 = a2.minute, s2 = a2.second;
		if (y2 < 0)
		{

			int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
			int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
			int d2 = -1 * a2.day, m2 = -1 * a2.month, y2 = -1 * a2.year, h2 = -1 * a2.hour, min2 = -1 * a2.minute, s2 = -1 * a2.second;
			s = s1 + s2;
			if (s >= 60)
			{
				s -= 60;
				min1 += 1;
			}
			min = min1 + min2;
			if (min >= 60)
			{
				min -= 60;
				h1 += 1;
			}
			h = h1 + h2;
			if (h >= 24)
			{
				h -= 24;
				d1 += 1;
			}
			d = d1 + d2;
			if (m1 >= 1 && m1 <= 12)//12 месяцев
			{
				if (m1 == 2)//февраль
				{
					if (y % 4 == 0) //високосный или нет
					{
						if (d > 29)
						{
							d -= 29;
							m1 += 1;
						}
					}
					else
					{
						if (d > 28)
						{
							d -= 28;
							m1 += 1;
						}
					}
				}
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
				{
					if (d > 31)
					{
						d -= 31;
						m1 += 1;
					}
				}
				if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
				{
					if (d > 30)
					{
						d -= 30;
						m1 += 1;
					}
				}
			}
			m = m1 + m2;
			if (m > 12)
			{
				m -= 12;
				y1 += 1;
			}
			y = y1 + y2;
			a3.day = d;
			a3.month = m;
			a3.year = y;
			a3.hour = h;
			a3.minute = min;
			a3.second = s;

		}
		else
		{
			if (s1 < s2)
			{
				min1 = min1 - 1;
				s1 += 60;
				s = s1 - s2;
			}
			else
			{
				s = s1 - s2;
			}
			if (min1 < min2)
			{
				h1 = h1 - 1;
				min1 += 60;
				min = min1 - min2;
			}
			else
			{
				min = min1 - min2;
			}
			if (h1 < h2)
			{
				d1 -= 1;
				h1 += 24;
				h = h1 - h2;
			}
			else
			{
				h = h1 - h2;
			}
			if (d1 < d2)
			{
				if (m1 >= 1 && m1 <= 12)//12 месяцев
				{
					if (m1 == 2)//февраль
					{
						if (y % 4 == 0) //високосный или нет
						{
							m1 -= 1;
							d1 += 29;
							d = d1 - d2;
						}
						else
						{
							m1 -= 1;
							d1 += 28;
							d = d1 - d2;
						}
					}
					if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
					{
						m1 -= 1;
						d1 += 31;
						d = d1 - d2;
					}
					if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
					{
						m1 -= 1;
						d1 += 30;
						d = d1 - d2;
					}
				}
			}
			else
			{
				d = d1 - d2;
			}
			if (m1 < m2)
			{
				y1 -= 1;
				m1 += 12;
				m = m1 - m2;
			}
			else
			{
				m = m1 - m2;
			}
			if (y1 < y2)
			{
				y = (y2 - y1)*-1;
				m *= -1;
				d *= -1;
				h *= -1;
				min *= -1;
				s *= -1;
			}
			else
			{
				y = y1 - y2;
			}
			a3.day = d;
			a3.month = m;
			a3.year = y;
			a3.hour = h;
			a3.minute = min;
			a3.second = s;
		}
	}
	if (b == '+')
	{
		int d = 0, m = 0, y = 0, h = 0, min = 0, s = 0;
		int d1 = a.day, m1 = a.month, y1 = a.year, h1 = a.hour, min1 = a.minute, s1 = a.second;
		int d2 = a2.day, m2 = a2.month, y2 = a2.year, h2 = a2.hour, min2 = a2.minute, s2 = a2.second;
		if (y2 < 0)
		{
			d2 = -1 * d2, m2 = -1 * m2, y2 = -1 * y2, h2 = -1 * h2, min2 = -1 * min2, s2 = -1 * s2;
			if (s1 < s2)
			{
				min1 = min1 - 1;
				s1 += 60;
				s = s1 - s2;
			}
			else
			{
				s = s1 - s2;
			}
			if (min1 < min2)
			{
				h1 = h1 - 1;
				min1 += 60;
				min = min1 - min2;
			}
			else
			{
				min = min1 - min2;
			}
			if (h1 < h2)
			{
				d1 -= 1;
				h1 += 24;
				h = h1 - h2;
			}
			else
			{
				h = h1 - h2;
			}
			if (d1 < d2)
			{
				if (m1 >= 1 && m1 <= 12)//12 месяцев
				{
					if (m1 == 2)//февраль
					{
						if (y % 4 == 0) //високосный или нет
						{
							m1 -= 1;
							d1 += 29;
							d = d1 - d2;
						}
						else
						{
							m1 -= 1;
							d1 += 28;
							d = d1 - d2;
						}
					}
					if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
					{
						m1 -= 1;
						d1 += 31;
						d = d1 - d2;
					}
					if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
					{
						m1 -= 1;
						d1 += 30;
						d = d1 - d2;
					}
				}
			}
			else
			{
				d = d1 - d2;
			}
			if (m1 < m2)
			{
				y1 -= 1;
				m1 += 12;
				m = m1 - m2;
			}
			else
			{
				m = m1 - m2;
			}
			if (y1 < y2)
			{
				y = (y2 - y1)*-1;
				m *= -1;
				d *= -1;
				h *= -1;
				min *= -1;
				s *= -1;
			}
			else
			{
				y = y1 - y2;
			}
			a3.day = d;
			a3.month = m;
			a3.year = y;
			a3.hour = h;
			a3.minute = min;
			a3.second = s;
		}
		else {
			s = s1 + s2;
			if (s >= 60)
			{
				s -= 60;
				min1 += 1;
			}
			min = min1 + min2;
			if (min >= 60)
			{
				min -= 60;
				h1 += 1;
			}
			h = h1 + h2;
			if (h >= 24)
			{
				h -= 24;
				d1 += 1;
			}
			d = d1 + d2;
			if (m1 >= 1 && m1 <= 12)//12 месяцев
			{
				if (m1 == 2)//февраль
				{
					if (y % 4 == 0) //високосный или нет
					{
						if (d > 29)
						{
							d -= 29;
							m1 += 1;
						}
					}
					else
					{
						if (d > 28)
						{
							d -= 28;
							m1 += 1;
						}
					}
				}
				if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12)//месяцы с 31 днем
				{
					if (d > 31)
					{
						d -= 31;
						m1 += 1;
					}
				}
				if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)//месяцы с 30 днями
				{
					if (d > 30)
					{
						d -= 30;
						m1 += 1;
					}
				}
			}
			m = m1 + m2;
			if (m > 12)
			{
				m -= 12;
				y1 += 1;
			}
			y = y1 + y2;
			a3.day = d;
			a3.month = m;
			a3.year = y;
			a3.hour = h;
			a3.minute = min;
			a3.second = s;
		}
	}
}
//метод добавления
void datetime::method_set(int d, int m, int y, int h, int min, int s)
{
	day = d;
	month = m;
	year = y;
	hour = h;
	minute = min;
	second = s;
} //Ввод времени 
//метод вывода
void datetime::method_output(datetime a)
{
	cout << "Date is " << a.day << "." << a.month << "." << a.year << endl << "Time is " << a.hour << ":" << a.minute << ":" << a.second << endl;
} //вывод
//перевод в секунды
int datetime::method_conversion(datetime a)
{
	int x = 0;
	for (int y = 1970; y <= a.year; y++)
	{
		if (y == a.year)//дошли до введенного года
		{
			for (int m = 1; m <= a.month; m++)//идём до введенного месяца
			{
				if (m == a.month)//дошли до введенного месяца
				{
					if (m == 2)
					{
						if (y % 4 == 0)
						{
							for (int d = 1; d <= a.day; d++)
							{
								if (d == a.day)//дошли до введенного дня
								{
									break;
								}
								else
									x += 86400;
							}
						}
						else if (y % 4 != 0)
						{
							for (int d = 1; d <= a.day; d++)
							{
								if (d == a.day)//дошли до введенного дня
								{
									break;
								}
								else
									x += 86400;
							}
						}
					}//високосный или нет
					else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					{
						for (int d = 1; d <= a.day; d++)
						{
							if (d == a.day)//дошли до введенного дня
							{
								break;
							}
							else
								x += 86400;
						}
					}//31 день
					else if (m == 4 || m == 6 || m == 9 || m == 11)
					{
						for (int d = 1; d <= a.day; d++)
						{
							if (d == a.day)//дошли до введенного дня
							{
								break;
							}
							else
								x += 86400;
						}
					}//30 дней
				}
				else
				{
					if (m == 2)
					{
						if (y % 4 == 0)
						{
							for (int d = 1; d <= 29; d++)
							{
								x += 86400;
							}
						}
						else if (y % 4 != 0)
						{
							for (int d = 1; d <= 28; d++)
							{
								x += 86400;
							}
						}
					}//високосный или нет
					else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
					{
						for (int d = 1; d <= 31; d++)
						{
							x += 86400;
						}
					}//31 день
					else if (m == 4 || m == 6 || m == 9 || m == 11)
					{
						for (int d = 1; d <= 30; d++)
						{
							x += 86400;
						}
					}//30 дней
				}
			}
		}
		else
		{
			for (int m = 1; m <= 12; m++)
			{
				if (m == 2)
				{
					if (y % 4 == 0)
					{
						for (int d = 1; d <= 29; d++)
						{
							x += 86400;
						}
					}
					else if (y % 4 != 0)
					{
						for (int d = 1; d <= 28; d++)
						{
							x += 86400;
						}
					}
				}//високосный или нет
				else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				{
					for (int d = 1; d <= 31; d++)
					{
						x += 86400;
					}
				}//31 день
				else if (m == 4 || m == 6 || m == 9 || m == 11)
				{
					for (int d = 1; d <= 30; d++)
					{
						x += 86400;
					}
				}//30 дней
			}
		}
	}
	x += (a.second + (a.minute * 60) + (a.hour * 3600));
	return x;
} // перевод даты в секунды
//следующая дата
int datetime::method_next_date(datetime a)
{
	int x;
	x = a.method_conversion(a);
	x += 86400;
	return x;
}
//обратный перевод
void reverse_conversion(int a, datetime& a1)
{
	int j = 0;
	int x = a, y = 1970;
	int seconds, minutes, hours;
	const int hours_in_day = 24;
	const int mins_in_hour = 60;
	const int secs_to_min = 60;
	seconds = x % secs_to_min;
	a1.second = seconds;
	minutes = x / secs_to_min % mins_in_hour;
	a1.minute = minutes;
	hours = x / secs_to_min / mins_in_hour % hours_in_day;
	a1.hour = hours;
	x -= seconds + (minutes * 60) + (hours * 3600);
	for (x; x >= 0; y++)
	{
		a1.year = y;
		if (x <= 31622400)
		{
			for (int m = 1; m <= 12; m++)
			{
				if (m == 2)
				{
					if (y % 4 == 0)
					{
						for (int d = 1; d <= 29; d++)
						{
							x -= 86400;
							if (x < 0)
							{
								a1.day = d;
								a1.month = m;
								j = 1;
								break;
							}
						}
					}
					else if (y % 4 != 0)
					{
						for (int d = 1; d <= 28; d++)
						{
							x -= 86400;
							if (x < 0)
							{
								a1.day = d;
								a1.month = m;
								j = 1;
								break;
							}
						}
					}
				}//високосный или нет
				else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				{
					for (int d = 1; d <= 31; d++)
					{
						x -= 86400;
						if (x < 0)
						{
							a1.day = d;
							a1.month = m;
							j = 1;
							break;
						}
					}
				}//31 день
				else if (m == 4 || m == 6 || m == 9 || m == 11)
				{
					for (int d = 1; d <= 30; d++)
					{
						x -= 86400;
						if (x < 0)
						{
							a1.day = d;
							a1.month = m;
							j = 1;
							break;
						}
					}
				}//30 дней
				if (j == 1)
					break;
			}
		}
		else
		{
			for (int m = 1; m <= 12; m++)
			{
				if (m == 2)
				{
					if (y % 4 == 0)
					{
						for (int d = 1; d <= 29; d++)
						{
							x -= 86400;
						}
					}
					else if (y % 4 != 0)
					{
						for (int d = 1; d <= 28; d++)
						{
							x -= 86400;
						}
					}
				}//високосный или нет
				else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				{
					for (int d = 1; d <= 31; d++)
					{
						x -= 86400;
					}
				}//31 день
				else if (m == 4 || m == 6 || m == 9 || m == 11)
				{
					for (int d = 1; d <= 30; d++)
					{
						x -= 86400;
					}
				}//30 дней
			}
		}
	}
}
//проверка на корректность даты
int Err(int &j, int d, int m, int y)
{
	if (m >= 1 && m <= 12)//12 месяцев
	{
		if (m == 2)//февраль
		{
			if (y % 4 == 0) //високосный или нет
			{
				if (d >= 1 && d <= 29)
				{
					return j = 1;
				}
				else
				{
					return j = 0;
				}
			}
			else
			{
				if (d >= 1 && d <= 28)
				{
					return j = 1;
				}
				else
				{
					return j = 0;
				}
			}
		}
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)//месяцы с 31 днем
		{
			if (d >= 1 && d <= 31)
			{
				return j = 1;
			}
			else
			{
				return j = 0;
			}
		}
		if (m == 4 || m == 6 || m == 9 || m == 11)//месяцы с 30 днями
		{
			if (d >= 1 && d <= 30)
			{
				return j = 1;
			}
			else
			{
				return j = 0;
			}
		}
	}
	else
	{
		return j = 0;
	}
}
//проверка на корректность времени
int Err2(int &j1, int h, int m, int s)
{
	if (h >= 0 && h < 24)
	{
		if (m < 60 && m >= 0)
		{
			if (s < 60 && s >= 0)
			{
				return j1 = 1;
			}
			else
			{
				return j1 = 0;
			}
		}
		else
		{
			return j1 = 0;
		}
	}
	else
	{
		return j1 = 0;
	}
}
//вывод timedel
void timedelta::method_output_d(timedelta a)
{
	cout << "Date is " << a.day << "." << a.month << "." << a.year << endl << "Time is " << a.hour << ":" << a.minute << ":" << a.second << endl;
} //вывод
//предыдущая дата
int datetime::method_previous_date(datetime a)
{
	int x;
	x = a.method_conversion(a);
	x -= 86400;
	return x;
}
//выделение памяти массиву
void memory_array(datetime *&a, int n)
{
	a = new datetime[n];
}
//заполнение файла
void fill_file(int n)
{
	ofstream f("1111.txt");
	if (!f.is_open())
	{
		cout << "Error. The file cannot be opened" << endl;
	}
	else
	{
		int d, m = 0, y, h, mi, s;
		for (int i = 0; i <= n - 1; i++)
		{
			h = 1 + rand() % 23;
			mi = 1 + rand() % 59;
			s = 1 + rand() % 59;
			d = 1 + rand() % 31;
			if (d <= 31)
			{
				y = rand() % 80 + 1970;
				while (true)
				{
					m = 1 + rand() % 12;
					if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
					{
						break;
					}
				}
			}
			if (d <= 30)
			{
				y = rand() % 80 + 1970;
				while (true)
				{
					m = 1 + rand() % 12;
					if ((m == 4) || (m == 6) || (m == 9) || (m == 11) || (m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
					{
						break;
					}
				}
			}
			if (d <= 29)
			{
				y = rand() % 80 + 1970;
				while (true)
				{
					m = 1 + rand() % 12;
					if ((m == 2) || (m == 4) || (m == 6) || (m == 9) || (m == 11) || (m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
					{
						break;
					}
				}
				if (d == 29)
				{
					while (true)
					{
						y = rand() % 80 + 1970;
						if (y % 4 == 0)
						{
							break;
						}
					}
				}
			}
			f << "!"<< d << "." << "@" << m << "." << "#" << y << "." << "-" << "$" << h << ":" << "%" << mi << ":" << "^" << s << "."<<"\n";
		}
		f.close();
	}
}
//заполнение массива данными из файла
void fill_array(datetime *&a, int n)
{
	ifstream f("1111.txt");
	if (!f.is_open())
	{
		cout << "Error. The file cannot be opened" << endl;
	}
	else
	{
		char buff[50];
		if (!f.is_open())
		{
			cout << "Error. The file cannot be opened" << endl;
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				f.getline(buff, 50);
				for (int i=0;i<50; i++)
				{
					if (buff[i] == '!')// день
					{
						if (buff[i + 2] == '.')
						{
						    a[j].day= ((buff[i + 1]))-'0';
						}
						else
						{
							a[j].day = (int(buff[i + 1])-'0') * 10 + (int(buff[i + 2])-'0');
						}
					}
					if (buff[i] == '@')//месяц
					{
						if (buff[i + 2] == '.')
						{
							a[j].month = int(buff[i + 1])-'0';
						}
						else
						{
							a[j].month = (int(buff[i + 1])-'0') * 10 + (int(buff[i + 2])-'0');
						}
					}
					if (buff[i] == '#')//год
					{
						a[j].year = (int(buff[i + 1])-'0') * 1000 + (int(buff[i + 2])-'0') * 100 + (int(buff[i + 3])-'0') * 10 + (int(buff[i + 4])-'0');
					}
					if (buff[i] == '$')//часы
					{
						if (buff[i + 2] == ':')
						{
							a[j].hour = int(buff[i + 1])-'0';
						}
						else
						{
							a[j].hour = (int(buff[i + 1])-'0') * 10 + (int(buff[i + 2])-'0');
						}
					}
					if (buff[i] == '%')//минуты
					{
						if (buff[i + 2] == ':')
						{
							a[j].minute = int(buff[i + 1]-'0');
						}
						else
						{
							a[j].minute = (int(buff[i + 1])-'0') * 10 + (int(buff[i + 2])-'0');
						}
					}
					if (buff[i] == '^')//секунды
					{
						if (buff[i + 2] == '.')
						{
							a[j].second = int(buff[i + 1])-'0';
						}
						else
						{
							a[j].second = (int(buff[i + 1])-'0') * 10 + (int(buff[i + 2])-'0');
						}
					}
					if (buff[i] == '\0')
					{
						break;
					}
				}
			}
			f.close();
		}
	}
}
//Деватый вариант
void var9(datetime*&a, int n)
{
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1].month == a[i].month && a[i + 1].month == a[i].month)
		{
			k++;
			cout << k << ") " << a[i].day << "." << a[i].month << "." << a[i].year << "   " << a[i].hour << ":" << a[i].minute << ":" << a[i].second << endl;
		}
	}
}