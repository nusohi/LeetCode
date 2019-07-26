#include "solution.h"
#include <iostream>
#include <vector>
#include <tuple>
using std::get;
using std::tuple;


void T10() {
	Solution solution;
	std::vector<tuple<string, string>> tests = {
		tuple<string,string>("a",""),
		tuple<string,string>("a",".*..a"),
		tuple<string,string>("ab",".*c"),
		tuple<string,string>("aa",".*"),
		tuple<string,string>("a","a*"),
		tuple<string,string>("aa","a*"),
		tuple<string,string>("","")
	};

	for (tuple<string, string> t : tests) {
		std::cout 
			<< get<0>(t) << " -> " 
			<< get<1>(t) << " -> " 
			<< solution.isMatch(get<0>(t), get<1>(t)) 
			<< std::endl;
	}
}