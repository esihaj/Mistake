#include <random>
#include <functional>
#include <limits>
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

int main(int argc, char const *argv[])
{
	ofstream out("list_rnd_6");
	auto rnd3 = bind(uniform_int_distribution<int>{0,numeric_limits<int32_t>::max()}, mt19937(random_device{}()));
	set<int> randoms;
	vector<int> r;
	for(int i =0; i<1000000;i++)
		randoms.insert(rnd3());
	r.assign(randoms.begin(), randoms.end());
	/*for(auto i = randoms.begin(); i!= randoms.end(); i++)
		r.push_back(*i);*/
	cout<<"number of elemnts = "<<r.size()<<endl;
	//int not_present = r[r.size() -1];

	for(auto i = r.begin(); i!= r.end(); i++)
		out<<*i<<endl;

	cout<<*(r.end() -1)<<endl;
	r.pop_back();
	random_shuffle(r.begin(), r.end());
	for(auto i = r.begin(); i < r.end() - 1; i++)
		out<<*i<<endl;
	out<<*(r.end() -1);
	out.close();
	return 0;
}
