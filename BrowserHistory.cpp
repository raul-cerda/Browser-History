#include "BrowserHistory.h"

BrowserHistory::BrowserHistory() {
    // TO BE COMPLETED
	iter = pages.begin();
}

//no dynamic memory means no destructor needed
BrowserHistory::~BrowserHistory() {
    // TO BE COMPLETED
}

//check if list is empty or user on first page, otherwise pop and replace old sites with new
void BrowserHistory::visitSite(Webpage newSite) {
    // TO BE COMPLETED
	if (pages.empty() || pages.size() == 1)
	{
		pages.push_back(newSite);
		history.push_back(newSite);
		iter = prev(pages.end());
	}
	else
	{
		iter = pages.erase(next(iter), pages.end());
		pages.push_back(newSite);
		history.push_back(newSite);
		iter = prev(pages.end());
	}
}

string BrowserHistory::getURL() {
    // TO BE COMPLETED
	return iter->getURL();
}

size_t BrowserHistory::getNavSize() {
    // TO BE COMPLETED
	return pages.size();
}

//check if iterator is already at first page, then back
string BrowserHistory::back() {
    // TO BE COMPLETED
	if(iter != pages.begin())
		iter--;
	return iter->getURL();
}

//check if any pages are available to forward into first
string BrowserHistory::forward() {
    // TO BE COMPLETED
	if (iter != prev(pages.end()))
		iter++;
	return iter->getURL();
}

//read file while taking action based on word found in text like 'new' or 'back'
void BrowserHistory::readHistory(string fileName) {
    // TO BE COMPLETED
	ifstream myfile;
	myfile.open(fileName);
	if (!myfile)
		cout << "Error opening file";
	else
		cout << "Opened file successfully" << endl;
	string action;
	string urlName;
	int urlDate = 0;
	while (myfile >> action)
	{
		if (action == "new")
		{
			myfile >> urlName;
			myfile >> urlDate;
			visitSite(Webpage(urlName, urlDate));
		}
		else if (action == "back")
			back();
		else if (action == "forward")
			forward();
	}
	myfile.close();
}

//iterate from first to current and print along the way
void BrowserHistory::printBackSites() {
    // TO BE COMPLETED
	for (list<Webpage>::iterator it1 = pages.begin(); it1 != iter; it1++)
		cout << it1->getURL() << endl;
	cout << endl;
}

//iterate from current to end and print along the way
void BrowserHistory::printForwardSites() {
    // TO BE COMPLETED
	for (list<Webpage>::iterator it1 = iter; it1 != pages.end(); it1++)
		cout << it1->getURL() << endl;
	cout << endl;
}

//iterate through entire history list and print every entry
void BrowserHistory::printFullHistory() {
    // TO BE COMPLETED
	for (list<Webpage>::iterator it1 = history.begin(); it1 != history.end(); it1++)
		cout << it1->getURL() << endl;
	cout << endl;
}
