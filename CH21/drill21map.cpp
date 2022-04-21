#include "../std_lib_facilities.h"

template<typename T,typename C>
void printout(const map<T,C>& mp){
	for(const auto& a : mp)
		cout << a.first << ' ' << a.second << endl;
	cout << endl;
}

template<typename T,typename C>
void read(map<T,C>& mp){
	T frs;
	C scd;
	cin >> frs >> scd;
	mp[frs]=scd;
}

int sum(map<string,int>& mp){
	int sum=0;
	for(auto& a : mp){
		sum += a.second;
	}

	return sum;
}

int main()
{
	map<string,int> msi;

	msi["alma"]=12;	
	msi["korte"]=24;	
	msi["oszi"]=36;	
	msi["kajszi"]=48;	
	msi["szolo"]=60;	
	msi["mango"]=72;	
	msi["narancs"]=84;	
	msi["grapefriut"]=96;	
	msi["mandarin"]=108;	
	msi["banan"]=120;

	cout << "MSI MAP:\n";
	printout(msi);

	cout << "MSI MAP AFTER ERASE:\n";
	msi.erase(msi.begin(), msi.end());
	printout(msi);

	for(int i = 0; i<10; i++)
		read(msi);

	cout << "MSI AFTER READ FROM CIN:\n";
	printout(msi);

	cout << "SUM OF INTS IN MSI: " << sum(msi) << endl;

	map<int,string> mis;

	for(auto& e : msi)
		mis[e.second] = e.first;
	printout(mis);

	return 0;
}