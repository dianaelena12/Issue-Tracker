#include <exception>

using namespace std;

class NotOpenException : public exception
{
public:
	const char* what() const throw()
	{
		return "The issue is not open!";
	}
};

class EmptyStringException : public exception
{
public:
	const char* what() const throw()
	{
		return "The description is empty!";
	}
};

class NotClosedException : public exception
{
public:
	const char* what() const throw()
	{
		return "You cannot remove a issue that's not closed!";
	}
};

class DuplicateException : public exception
{
public:
	const char* what() const throw()
	{
		return "There is a similar issue registered allready!";
	}
};

class NotTesterException : public exception
{
public:
	const char* what() const throw()
	{
		return "Only the testers can add issues!";
	}
};

class NotProgrammerException : public exception
{
public:
	const char* what() const throw()
	{
		return "Only the programmers can resolve issues!";
	}
};