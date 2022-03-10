#include "std_lib_facilities.h"

using namespace std;

class B1 {
public:
	virtual void vf() { cout << "B1::vf()\n"; } 
	void f() { cout << "B1::f()\n"; }
	virtual void pvf() { cout << "B1::pvf()\n"; }  //5.feladat
};

class D1 : public B1 {
public:
	void vf() override { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }              //4.feladat
};

void call(B1& b){
	b.vf();
	b.f();
	b.pvf();
}

//6.feladat
class D2 : public D1 {
public:
	void pvf() { cout << "D2::pvf()\n"; }  
};

//7.feladat
class B2 {
public:
	virtual void pvf() { cout << "B2::pvf()\n"; }  
};

class D21 : public B2 {
public:
	string s = "Windows is the best ops of all time SIKE";
	void pvf() override { cout << s; }
};

class D22 : public B2 {
public:
	int s = 21;;
	void pvf() override { cout << s; }
};

void call2(B2& b2){
	b2.pvf();
}

int main()
{
	// 1.feladat

	B1 b;

	b.vf();
	b.f();
	b.pvf();
	cout << endl;

	//2.feladat

	D1 d;

	d.vf();
	d.f();
	d.pvf();
	cout << endl;

	//3.feladat

	call(d);
	cout << endl;

	//6.feladat

	D2 d2;

	d2.vf();
	d2.f();
	d2.pvf();
	cout << endl;

	//7.feladat

	D21 d21;
	call2(d21);
	cout << endl;

	D22 d22;
	call2(d22);
	cout << endl;

	return 0;
}