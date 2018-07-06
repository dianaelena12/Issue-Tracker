#pragma once
#include <string>
#include <sstream>
using namespace std;

class Issue {
private:
	string description;
	string status;
	string reporter;
	string solver;
public:
	Issue(string d, string s, string r, string sl): description(d),status(s),reporter(r),solver(sl) {}
	~Issue() {}
	string getDescription() const { return this->description; }
	string getStatus() const { return this->status; }
	string getReporter() const { return this->reporter; }
	string getSolver() const { return this->solver; }
	string toString()
	{
		stringstream s;
		s << this->description << "," << this->status << "," << this->reporter << ",";
		if (this->solver != "-")
			s << this->solver << endl;
		else
			s << "-" << endl;
		return string(s.str());
	}
};