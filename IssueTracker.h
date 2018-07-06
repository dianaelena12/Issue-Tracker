#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include "Exceptions.h"
#include "ui_IssueTracker.h"
#include "Controller.h"

class IssueTracker : public QWidget, public Observer
{
	Q_OBJECT

public:
	IssueTracker(User user,Controller& c,QWidget *parent = Q_NULLPTR);
	~IssueTracker();

	void update();
	void add();
	void remove();
	void resolve();

private:
	Ui::IssueTracker ui;
	Controller& ctrl;
	User user;
};
