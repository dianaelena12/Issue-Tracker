#pragma once
#include <User.h>
#include <Issue.h>
#include <vector>
#include <fstream>
#include <sstream>

class IssueRepository
{
private:
	vector<User> users;
	vector<Issue> issues;
public:
	IssueRepository()
	{
		this->readDataFromFile();
	}
	~IssueRepository() {}

	void readDataFromFile()
	{
		ifstream in("users.txt");
		string line;
		while (getline(in, line)) {
			stringstream ss{ line };
			string tolken;
			vector<string> aux;
			while (getline(ss, tolken, ',')) {
				aux.push_back(tolken);
			}
			if (aux.size() == 2)
			{
				User u{ aux[0],aux[1] };
				this->addUser(u);
			}
		}
		in.close();
		ifstream in2("issues.txt");
		while (getline(in2, line)) {
			stringstream ss{ line };
			string tolken;
			vector<string> aux;
			while (getline(ss, tolken, ',')) {
				aux.push_back(tolken);
			}
			if (aux.size() == 4)
			{
				Issue i{ aux[0],aux[1],aux[2],aux[3] };
				this->addIssue(i);
			}
		}
		in2.close();
	}

	void addUser(User u)
	{
		this->users.push_back(u);
	}

	void addIssue(Issue i)
	{
		for (auto it : this->issues) {
			if (it.getDescription() == i.getDescription())
				throw DuplicateException();
		}
		this->issues.push_back(i);
	}

	void removeIssue(string description)
	{
		for (int i = 0; i < this->issues.size(); i++) {
			if (this->issues[i].getDescription() == description)
				this->issues.erase(this->issues.begin() + i);
		}
	}

	vector<Issue> getAllIssues() const { return this->issues; }

	vector<User> getAllUsers() const { return this->users; }
};