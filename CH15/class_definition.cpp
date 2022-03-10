#include "../std_lib_facilities.h"

// tiltott karakterek felsorolasa
const vector<char> forbidden = {
	';',
	':',
	'[',
	']',
	'*',
	'&',
	'^',
	'%',
	'$',
	'#',
	'@',
	'!',
	'"',
	39 // basically the char ' 
};

// hibakezeles osztalya
class invalid {};

struct Person {
private:
	string first_name;
	string last_name;
	int age;
public:
	bool valid(); // hibakezeles valid e az input
	Person() : first_name(""), last_name(""), age(0) {if(!valid()) throw invalid(); }
	Person(int i) : first_name(""), last_name(""), age(i) {if(!valid()) throw invalid(); }
	Person(string ss,string s) : first_name(ss), last_name(s), age(0) {if(!valid()) throw invalid(); }
	Person(string ss,string s, int a) : first_name(ss), last_name(s), age(a) {if(!valid()) throw invalid(); }
	friend ostream& operator<<(ostream& os, Person& ps); // operator overload output 
	friend istream& operator>>(istream& in, Person& ps); // operator overload input 
	void const get_age(); // 5. feladat fuggvenyei
	void const get_name();
};

ostream& operator<<(ostream& os, Person& ps)
{
    os << ps.first_name << " " << ps.last_name << " " << ps.age << endl;
    return os;
}

istream& operator>>(istream& in, Person& ps)
{
    in >> ps.first_name >> ps.last_name >> ps.age;
    Person(ps.first_name,ps.last_name,ps.age);
    return in;
}

void const Person::get_age(){
	int c;
	cin >> c;
	age = c;
	if(!valid()) throw invalid();
};

void const Person::get_name(){
	string s;
	cin >> s;
	first_name = s;
	string ss;
	cin >> ss;
	last_name = ss;
	if(!valid()) throw invalid();
};

bool Person::valid(){

	bool b = true; 

	if(age < 0 || age > 150) b = false;  // hibakezeles age re

	for(int i=0;i<forbidden.size();i++){

		char c;
		c = forbidden[i];
		
		if(first_name.find(c) != string::npos){  // hibakezeles first name karaktereire
			b = false;
		}
		if(last_name.find(c) != string::npos){  // hibakezeles last name karaktereire
			b = false;
		}
	}

	if(first_name == "" && last_name != "") b = false; // hibakezeles hogy mind2 name van e

	if(last_name == "" && first_name != "") b = false;


	return b;
};

int main()
try{

	/* since its private it wont work anymore
	Person p1;
	p1.name = "Goofy";
	p1.age = 63;
	cout << p1.name << " " << p1.age << endl;
	*/

	// 2. feladat
	Person p1("Big","Goofy",63);
	cout <<"Welcome " << p1 << endl;

	// 3. feladat
	cout << "Enter a name and an age for a preson please: " << endl;
	Person p2;

	cin >> p2;
	cout <<"Your newborn's name and age: " << p2 << endl;

	// 5. feladat
	cout << "Enter a name and an age for a preson please: " << endl;
	Person p3;

	p3.get_name();
	p3.get_age();

	cout <<"Your newborn's name and age: " << p3 << endl;

	// 8. feladat
	vector<Person> army;
	cout << "Enter 5 name each followed by and age for your new army " << endl;
	for(int i=0; i<5; i++){
		string n;
		string nn;
		int a;
		cin >> nn >> n >> a;
		army.push_back(Person(nn,n,a));
	};
	cout << "Here are your soldiers: " << endl;
	for(int i=0; i<5; i++){
		cout << army[i];
	};

	return 0;

}catch(invalid){

	cerr << "Invalid data! (forbidden char in name or not both supplied or age not in 0-150 range)" << endl;

	return 1;
}catch(exception& e){

	cerr << e.what() << endl;

	return 2;
}catch(...) {

	cerr << "exception\n";

	return 3;
}