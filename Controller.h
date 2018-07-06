#pragma once
#include <IssueRepository.h>
#include <Observable.h>

class Controller: public Subject
{
private:
	IssueRepository repo;
public:
	Controller(IssueRepository re): repo(re) {}
	~Controller() {}

	void addIssueToRepo(Issue issue)
	{
		this->repo.addIssue(issue);
		this->notify();
	}

	void removeIssueFromRepo(string description)
	{
		this->repo.removeIssue(description);
		this->notify();
	}

	void resolve(string description,string reporter, string solver)
	{
		this->repo.removeIssue(description);
		this->repo.addIssue({ description,"Closed",reporter,solver });
		this->notify();
	}
	vector<Issue> getIssues()
	{
		return this->repo.getAllIssues();
	}
	vector<User> getAllUsers() const { return this->repo.getAllUsers(); }
};