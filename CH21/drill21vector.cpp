#include "../std_lib_facilities.h"

template<typename T>
void printout(vector<T>& v){
	for(auto& a : v)
		cout << a << endl;
	cout << endl;
}

template<typename T, typename C>
void print_in_pair(vector<T>& t,vector<C>& c){
	for(int i = 0; i<t.size(); ++i){
		cout << "(" << t[i] << " , " << c[i] << ")\n";
	} 
}

template<typename T>
T sum(vector<T>& t){
	T sum = 0;
	for(auto& a : t)
	sum += a;
  return sum;
}

int main(){
	vector<double> vd;

	ifstream ifile {"bemenet2.txt"};
	while(!ifile.eof()){
		double temp;
		ifile >> temp;
		vd.push_back(temp);
	}
	ifile.close();
	cout << "VD AFTER IFSTREAM:\n";
	printout(vd);

	vector<int> vi(vd.size());

	copy(vd.begin(),vd.end(),vi.begin());

	cout << "VI AFTER COPYING VD IN IT:\n";
	printout(vi);

	cout << "VD AND VI IN PAIR PER LINE:\n";
	print_in_pair(vd,vi);

	cout << endl;
	cout << "SUM OF VD: " << sum(vd) << endl;
	cout << "SUM OF VI: " << sum(vi) << endl;
	cout << "DIFF BETWEEN VD AND VI: " << sum(vd)-sum(vi) <<endl;

	reverse(vd.begin(), vd.end());
	cout << "REVERSED VD:\n";
	printout(vd);

	cout << "MEAN VALUE OF VD: " << sum(vd)/vd.size() <<endl;

	vector<double> vd2;
	for(int i = 0; i < vd.size(); i++){
		if (vd[i] < (sum(vd)/vd.size())){
			vd2.push_back(vd[i]);
		}
	}
	cout << "VD2 ALIAS VD1 BUT SMALLER THEN THE MEAN VALUE:\n";
	printout(vd2);

	sort(vd.begin(), vd.end());
	cout << "SORTED VD:\n";
	printout(vd);
	return 0;
}