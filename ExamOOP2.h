#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamOOP2.h"

class ExamOOP2 : public QMainWindow
{
	Q_OBJECT

public:
	ExamOOP2(QWidget *parent = Q_NULLPTR);

private:
	Ui::ExamOOP2Class ui;
};
