#include "IssueTracker.h"

IssueTracker::IssueTracker(User user,Controller& c,QWidget *parent)
	: QWidget(parent), ctrl(c), user(user)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->user.getName() + "---->"+ this->user.getType()));

	this->ctrl.registerObserver(this);
	this->update();
	QObject::connect(ui.AddButton, &QPushButton::clicked, this, &IssueTracker::add);
	QObject::connect(ui.RemoveButton, &QPushButton::clicked, this, &IssueTracker::remove);
	QObject::connect(ui.resolveButton, &QPushButton::clicked, this, &IssueTracker::resolve);
}

IssueTracker::~IssueTracker()
{
	this->ctrl.unregisterObserver(this);
}


void IssueTracker::update()
{
	this->ui.issueList->clear();
	vector<Issue> all = this->ctrl.getIssues();
	for (auto &t : all) {
		QString current = "";
		current += QString::fromStdString(t.toString());
		QListWidgetItem* item = new QListWidgetItem{ current };
		this->ui.issueList->addItem(item);
	}
}

void IssueTracker::add()
{
	string description = this->ui.descriptionBox->text().toStdString();
	try {
		if (this->user.getType() != "tester")
			throw NotTesterException();
		Issue i{ description,"Open",this->user.getName(),"-" };
		this->ctrl.addIssueToRepo(i);
		this->ui.descriptionBox->clear();
	}
	catch (NotTesterException e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		messageBox.setFixedSize(500, 200);
		this->ui.descriptionBox->clear();
		return;
	}
	catch (DuplicateException e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		messageBox.setFixedSize(500, 200);
		this->ui.descriptionBox->clear();
		return;
	}
	
}

void IssueTracker::remove()
{
	string all = this->ui.issueList->selectedItems().at(0)->text().toStdString();
	if (all == "")
		return;

	stringstream elem(all);
	vector<string> aux;
	string current;
	while (getline(elem, current, ','))
		aux.push_back(current);

	try
	{
		if (aux[1] != "Closed")
			throw NotClosedException();
		this->ctrl.removeIssueFromRepo(aux[0]);
		this->update();
	}
	catch (NotClosedException e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		messageBox.setFixedSize(500, 200);
		return;
	}
}

void IssueTracker::resolve()
{
	string all = this->ui.issueList->selectedItems().at(0)->text().toStdString();
	if (all == "")
		return;

	stringstream elem(all);
	vector<string> aux;
	string current;
	while (getline(elem, current, ','))
		aux.push_back(current);

	try
	{
		if (this->user.getType() != "programmer")
			throw NotProgrammerException();
		if (aux[1] != "Open")
			throw NotOpenException();
		this->ctrl.resolve(aux[0], aux[2], this->user.getName());

	}
	catch (NotProgrammerException e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		messageBox.setFixedSize(500, 200);
		return;
	}
	catch (NotOpenException e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.what()));
		messageBox.setFixedSize(500, 200);
		return;
	}
}
