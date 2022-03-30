#include "../std_lib_facilities.h"

using namespace std;

template<typename T>
struct S
{
	S(T v = 0) : val{v} {}
	T& get();
	const T& get() const;
	//void set(T new_val) { val = new_val; }
	void operator=(const T& new_val);
private:
	T val;
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::operator=(const T& new_val){
	val = new_val;
}

template<typename T>
void read_val(T& v){
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os,vector<T>& v){
	os << "{ ";
	for (int i = 0; i < v.size();i++)
	{
		os << v[i] << (i < v.size()-1 ? ", ": " ");
	}
	os << "}\n";
	return os;
}

template<typename T>
istream& operator>>(istream& is,vector<T>& v){
	char ch = 0;
	is >> ch;
	if (ch != '{'){
		is.unget();
		return is;
	}
	for (T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	return is;
}

int main()
{
	S<int> is = {1};
	S<char> cs = {'A'};
	S<double> ds = {1.1};
	S<string> ss = {"alma"};
	S<vector<int>> ivs = {vector<int>{1,2,3,4,5}};

	cout << "S<int> is = " << is.get() << endl;
	cout << "S<char> cs = " << cs.get() << endl;
	cout << "S<double> ds = " << ds.get() << endl;
	cout << "S<string> ss = " << ss.get() << endl;

	cout << "S<int> is = " << is.get() << endl;
	cout << "S<char> cs = " << cs.get() << endl;
	cout << "S<double> ds = " << ds.get() << endl;
	cout << "S<string> ss = " << ss.get() << endl;
	cout << "S<vector<int>> ivs = ";
	for(auto& a : ivs.get()){
		cout << a << ' ';
	}
	cout << '\n';

	cout << "Adjon meg egy int értéket!" << endl; 
	int is1;
	read_val(is1);
	S<int> is2 = {is1};
	cout << "S<int> is2 = " << is2.get() << endl;

	cout << "Adjon meg egy char értéket!" << endl; 
	char cs1;
	read_val(cs1);
	S<char> cs2 = {cs1};
	cout << "S<char> cs2 = " << cs2.get() << endl;

	cout << "Adjon meg egy double értéket!" << endl; 
	double ds1;
	read_val(ds1);
	S<double> ds2 = {ds1};
	cout << "S<double> ds2 = " << ds2.get() << endl;

	cout << "Adjon meg egy string értéket!" << endl; 
	string ss1;
	read_val(ss1);
	S<string> ss2 = {ss1};
	cout << "S<string> ss2 = " << ss2.get() << endl;

	cout << "Adjon meg egy vektort {val,val,val} formátumban!" << endl; 
	vector<int> vec;
	read_val(vec);
	S<vector<int>> ivs2 = {vec};

	cout << "S<vector<int>> ivs2: " << ivs2.get() << endl;

	return 0;
}