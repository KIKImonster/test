#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<string>

//class Preson
//{
//public:
//	Person()
//	{
//		++_count;
//	}
//protected:
//	string _name;
//public:
//	static int _count;
//	
//};
//int Person::_count = 0;
//class Student :public Person
//{
//protected:
//	int _stuNum;
//};
//class Graduate :public Student
//{
//protected:
//	string _seminarCourse;
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << "人数" << Person::_count << endl;
//	Student::_count = 0;
//	cout << "人数" << Person::_count << endl;
//}

class Person
{
public:
	string _name
};
class Student :virtual public Person
{
protected:
	int _num;
};
class Teacher :virtual public Person
{
protected:
	int _id;
};
class Assistant :public Student, public Teacher
{
protected:
	string _majorCourse;
};
void Test()
{
	Assiant a;
	a.name = "peter"
}

class Car
{
protected:
	string _colour = "白色";
	string _num = "陕ABIT00";
};
class BWM :public Car
{
public:
	void Drive()
	{
		cout << "good—control" << endl;
	}
};
class Benz :public Car
{
public:
	void Drive()
	{
		cout << "good_comfortable" << endl;
	}
};
class Tire
{
protected:
	string _brand = "Michelin";
	size_t _size = 17;
};
class Car
{
protected:
	string _colour = "white color";
	string _num = "陕abit";
		Tire _t;
};
