#include <QtWidgets/QApplication>
#include "IssueTracker.h"
#include "IssueRepository.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IssueRepository r;
	Controller ctrl(r);
	vector<User> all = ctrl.getAllUsers();
	User u1{ "", "" };
	IssueTracker* w;
	for (auto u : all) {
		w = new IssueTracker{ u,ctrl };
		w->show();
	}
	
	return a.exec();
}
