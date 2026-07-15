#pragma once
#include <iostream>

namespace JangJiwon2593266
{
	class timeOfDay
	{
		int hour;
		int minute;
		void testHour() { if (hour < 0 || hour > 23) { std::cout << "Invalid hour\n"; } }
		void testMinute() { if (minute < 0 || minute > 59) { std::cout << "Invalid minute\n"; } }
	public:
		timeOfDay(int h = 0, int m = 0) :hour{ h }, minute{ m } { testHour(); testMinute(); }
		void input()
		{
			std::cout << "Enter Hour: "; std::cin >> hour; testHour();
			std::cout << "Enter Minute: "; std::cin >> minute; testMinute();
		}
		void setHour(int h) { hour = h; testHour(); }
		void setMinute(int m) { minute = m; testMinute(); }
		void print() const
		{
			if (hour < 10) std::cout << "0"; std::cout << hour << ":";
			if (minute < 10) std::cout << "0"; std::cout << minute;
		}
		int getHour() const { return hour; }
		int getMinute() const { return minute; }

		timeOfDay operator++()
		{
			++minute; //minute = minute + 1; minute += 1;
			if (minute == 60) { minute = 0; ++hour; }
			if (hour == 24) { hour = 0; }

			return timeOfDay{ hour, minute };
		}
		timeOfDay operator++(int)
		{
			timeOfDay temp{*this};
			++(*this);

			return temp;
		}
		timeOfDay& operator+=(int m)
		{
			minute += m;
			if (minute >= 60) { hour += minute / 60; minute %= 60; }
			if (hour >= 24) { hour %= 24; }
			return *this;
		}
		friend std::istream& operator>>(std::istream& is, timeOfDay& t)
		{
			std::cout << "Enter hour: "; is >> t.hour; t.testHour();
			std::cout << "Enter minute: "; is >> t.minute; t.testMinute();

			return is;
		}
		friend std::ostream& operator<<(std::ostream& of, const timeOfDay& t)
		{
			if (t.hour < 10) os << "0"; os << t.hour << ":";
			if (t.minute < 10) os << "0"; os << t.minute;

			return os;
		}
		friend bool operator==(const timeOfDay& t1, const timeOfDay& t2)
		{
			return t1.hour == t2.hour && t1.minute == t2.minute;
		}
		friend timeOfDay operator+(const timeOfDay& t1, const timeOfDay& t2)
		{
			int minute1{ t1.hour * 60 + t1.minute };
			int minute2{ t2.hour * 60 + t2.minute };
			int totalMinute{ minute1 + minute2 };
			int newMinute{ totalMinute % 60 };
			int newHour{ totalMinute / 60 };
			if (newHour > 23) newHour %= 24; //newHour = newHour & 24;

			return timeOfDay{ newHour, newMinute };
		}
	};
}