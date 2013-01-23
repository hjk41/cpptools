#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

inline std::string to_lower(const std::string & str1)
{
	std::string str = str1;
	std::transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

inline std::vector<std::string> split(const std::string & str)
{
	using namespace std;
	istringstream iss(str);
	vector<std::string> substrings;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string>>(substrings));
	return substrings;
}

template<class T>
void str2T(const string & str, T & n)
{
	istringstream iss(str);
	iss>>n;
};
