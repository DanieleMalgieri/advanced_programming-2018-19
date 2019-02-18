#include <iostream>
#include <vector>
#include <algorithm> //for sort

using namespace std;

//template <typename T> 
vector<string> read_from_cin();
//template <typename T> 
void print_vector(vector<string>& v);
vector<string> cull_repetition(vector<string>& v);

int main()
{
	vector<string> txt = read_from_cin();
	vector<string> c_txt = cull_repetition(txt);
//	print_vector(c_txt);
	return 0;
}

//template <typename T>
vector<string> read_from_cin()
{
	string e;	
	vector<string> v;
	while(cin >> e) v.push_back(e);
	sort(v.begin(),v.end());
	return v;
}

/*template <typename T>*/
void print_vector(vector<string>& v)
{
	for (size_t i; i<v.size(); i++) cout<<v[i]<<endl;
}

vector<string> cull_repetition(vector<string>& v)
{
	vector<string> e;
	//e[0] = v[0];
	for (size_t i=1; i<v.size(); i++) 
	{
		if(v[i]!=v[i-1])
		{ 
			e.push_back(v[i]);
			cout<<e[i];
		}
	}
	return e;
}
