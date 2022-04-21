#include "../std_lib_facilities.h"

struct Item {
	string name;
	int iid;
	double value;
	Item() : name("notgiven"), iid(-1), value(-1) {}
	Item(string n, int i, double d): name(n), iid(i), value(d) {}
};

istream& operator>>(istream& is, Item& it){
	is >> it.name >> it.iid >> it.value;
	return is;
}

template<typename T>
void printout(const T& t){
	for( auto& elem : t){
		cout << elem.name << ' ' << elem.iid << ' ' << elem.value << endl;
	}
	cout << endl;
}

/* generikus jobb :)
void printout(const Item& it){
	cout << it.name << ' ' << it.iid << ' ' << it.value << endl;
}
*/

struct sort_by_name{
	bool operator()(const Item& a,const Item& b){return a.name < b.name;}
};

struct sort_by_iid{
	bool operator()(const Item& a,const Item& b){return a.iid < b.iid;}
};

struct sort_by_value{
	bool operator()(const Item& a,const Item& b){return a.value > b.value;}
};

int main(){
	vector<Item> vi;

	const int ifile_size = 10;

	ifstream ifile {"bemenet.txt"};
	for(int i = 0; i<ifile_size ;i++){
		Item item;
		ifile >> item;
		vi.push_back(item);
	}
	ifile.close();
	cout << "RAW VECTOR:\n";
	printout(vi);

	sort(vi.begin(),vi.end(),sort_by_name());

	cout << "BY NAME:\n";
	printout(vi);

	sort(vi.begin(),vi.end(),sort_by_iid());

	cout << "BY IID:\n";
	printout(vi);

	sort(vi.begin(),vi.end(),sort_by_value());

	cout << "BY VALUE:\n";
	printout(vi);

	vi.push_back(Item("horse shoe",99,12.34));
	vi.push_back(Item("Canon S400",9988,499.95));

	cout << "ADDED 2 TO VI:\n";
	printout(vi);

	vi.erase(remove_if(vi.begin(), vi.end(),[](const Item& item) { return item.name == "pulcsi";}));
	vi.erase(remove_if(vi.begin(), vi.end(),[](const Item& item) { return item.name == "tal";}));

	cout << "REMOIVED TAL AND PULCSI FROM VI:\n";
	printout(vi);

	vi.erase(remove_if(vi.begin(), vi.end(),[](const Item& item) { return item.iid == 9;}));
	vi.erase(remove_if(vi.begin(), vi.end(),[](const Item& item) { return item.iid == 2;}));

	cout << "REMOIVED IID 9 AND 2 FROM VI:\n";
	printout(vi);

	list<Item> li(vi.size());
	copy(vi.begin(), vi.end(), li.begin());

	cout << "RAW LIST:\n";
	printout(li);

	li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
	cout << "LI SORTED BY NAME:\n";
	printout(li);

    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    cout << "LI SORTED BY IID:\n";
	printout(li);

    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
    cout << "LI SORTED BY VALUE:\n";
	printout(li);

	li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});
    cout << "ADDED 2 TO LI:\n";
	printout(li);

	li.remove_if([](const Item& item) { return item.name == "Canon S400";});
	li.remove_if([](const Item& item) { return item.name == "honda";});

	cout << "REMOIVED HONDA and CANOC FROM LI:\n";
	printout(li);

	li.remove_if([](const Item& item) { return item.iid == 1;});
	li.remove_if([](const Item& item) { return item.iid == 5;});

	cout << "REMOIVED IID 1 AND 5 FROM LI:\n";
	printout(li);


	return 0;
}