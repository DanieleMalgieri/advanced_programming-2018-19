/* Store the numbers contained in file `temperatures.txt` into an `std::vector<double>` and compute:
  - the mean
  - the median
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<double> read_from_file(string filename);
void print_vector(const vector<double>& v);
double mean(const vector<double>& v);
double median(const vector<double>& v);

int main()
{
	vector<double> temperatures = read_from_file("temperatures.txt");
	sort(temperatures.begin(), temperatures.end());
	//print_vector(temperatures);
	double mean_temp = mean(temperatures);
	cout << "the mean temperature is: " << mean_temp <<"° C"<<endl;
	double median_temp = median(temperatures);
	cout << "the median temperature is: " << median_temp <<"° C"<<endl;
	return 0;
}


vector<double> read_from_file(string filename)  //partially found on StackOverflow
{
	
	ifstream ifile(filename, ios::in);
	vector<double> temps;

	//check the file
	if (!ifile.is_open()) {
	cerr << "There was a problem opening the input file!\n";
	exit(1);
	}

	double num = 0.0;
	while (ifile >> num) temps.push_back(num);
	return temps;
}

void print_vector(const vector<double>& v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] <<endl;
}
	
double mean(const vector<double>& v)
{
	double _sum{0};	
	for (int i=0; i< v.size(); i++) _sum += v[i];
	double _mean = _sum/v.size();
	return _mean;
}

double median(const vector<double>& v)
{	
	double _median{0};
	if(v.size()%2==1)_median = v[(int) v.size()/2+1];
	else _median = (v[(int) v.size()/2]+v[(int) (v.size()+1)/2])/2;
	return _median;
}






