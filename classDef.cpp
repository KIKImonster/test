#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct A
{
public:// 默认
	int _a;

	void fun()
	{
		cout << " struct  A fun()" << endl;
	}
};

//定义的类不占内存，类似于一个设计图纸，
//后面创建的 类 类型的变量 的过程叫类的实例化，
//变量： 对象   -->自定义类型的变量一般习惯称为对象
class B
{
private://默认 此外还有其他俩个（private）（public）不是默认；
	int _a;//成员变量给了个下划线，一般会给类的成员变量加个下划线，作以区别普通变量，习惯

	void fun()
	{
		cout << "class B fun()" << endl;
	}
	void fun2();

};
void B::fun2()
{
	cout << "fun2()" << endl;
}

void test()
{
	A a;//类的实例化
	B b;

	a.fun();
	a._a = 1;

	//b.fun2(); 默认私有，不可访问



}

class C
{
	int _c;

};

class D
{
	int _c;
	void fun1()
	{
		int a = 1;
		float b = 2.0;
		char c = 'a';
	}
};

class E
{
};

class F
{
	char _c1;
	double _d2;
	int _a3;
	char _d4;
	class H
	{
double _e;
    char _b;
	int _a;
	char _d;
	};
	H _h;

};

void test2()
{
	cout << sizeof(C) << " " << sizeof(D) << " " << sizeof(E)  << " " <<sizeof(F) << endl;
}//4 4 1;当为空的时候默认给一个标记字节1，大小；有其他成员时这个1便没了


//对象模型中，只存放普通成员变量，不存放成员函数
//成员函数放在公共的代码段

//空类的大小为‘1’；一个字节的标记
//int main()
//{
//	test2();
//}

//class Date
//{
//public://this：指针类型：类类型* const
//	//this指针只存在在成员函数中，编译器自动添加（不用化=画蛇添足）不需要显式定义，只存在在成员函数中
//	//this不是类的成员，只是一个函数形参，一般存在栈上，一般会做优化，在不做解引用的时候可以为空
//	void Display()//Display（Date* const this) 始终指向当前调用此函数的对象，指向不会改变
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2020, 5, 17);
//	d2.SetDate(2020, 6, 1);
//	d1.Display();
//	d2.Display();
//	return 0;
//}

class AA
{
	//空类：六个底层函数
	//构造函数： 函数名和类名相同， 无返回值 ，可以重载，编译器在创建时自动调用
	//只有当类没有定义任何构造函数时，编译期才会自动生成一个无参构造，
	//如果有了，编译器不会再自动生成

	//默认构造：指向存在一个
	//1.编译器默认生成    有了构造后不会默认创建了
	//2.显式定义的无参构造
	//3.全缺省构造函数
};
