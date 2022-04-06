#include "../std_lib_facilities.h"

template<typename T>
void incr(T& t, int n){
  for(auto& i : t){
    i+=n;
  }
}

template<typename T>
void my_cout(const T& t){
   for(auto& i : t){
      cout << i << ' ';
   }
cout << endl;
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
  for(Iter1 p = f1; p != e1; ++p){
    *f2 = *p;
    f2++;
  }
  return f2;
}

int main()
try{
 int const size = 10;

 array<int, size> ai;
 for(int i=0; i<size; i++){
   ai[i] = i;
 }
 cout << "First ai: ";
 my_cout(ai);

 vector<int>  vi;
 for(int i=0; i<size; i++){
    vi.push_back(i);
  }
 cout << "First vi: ";
 my_cout(vi);

 list<int> li;
 for(int i=0; i<size; i++){
  li.push_back(i);
 }
 cout << "First li: ";
 my_cout(li);

 array<int, size> aicp = ai;
 vector<int> vicp= vi;
 list<int> licp= li;

 incr(aicp,2);
 incr(vicp,3);
 incr(licp,5);

 cout << "Increased ai by 2 : ";
 my_cout(aicp);

 cout << "Increased vi by 3 : ";
 my_cout(vicp);

 cout << "Increased li by 5 : ";
 my_cout(licp);

 my_copy(aicp.begin(),aicp.end(),vicp.begin());
 my_copy(licp.begin(),licp.end(),aicp.begin());

 cout << "ai coppied into vi: ";
 my_cout(vicp);

 cout << "li coppied into ai: ";
 my_cout(aicp);

 vector<int>::iterator vmark;

 vmark = find(vicp.begin(), vicp.end(), 3);

 if(vmark == vicp.end()){
  cout << "3 was not found in the vector! " << endl;
 }else{
  cout << "3 was found on the "<< distance(vicp.begin(), vmark) << ". position" << endl;
 }

list<int>::iterator lmark;

lmark = find(licp.begin(), licp.end(), 27);

if(lmark == licp.end()){
 cout << "27 was not found in the list! " << endl;
}else{
 cout << "27 was found on the "<< distance(licp.begin(), lmark) << ". position" << endl;
}

 return 0;
}catch(exception& e){
 cerr << "Exception: " << e.what() <<endl;
 return 1;
}catch(...){
 cerr << "Somethiung went wrong" << endl;
 return 2;
}
