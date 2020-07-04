#include "Webpage.h"
//basic constructors and get methods only
Webpage::Webpage() 
{
    // TO BE COMPLETED
	url = "";
	urlTime = 0;
}

Webpage::Webpage(const string& webpageURL, const time_t& timeVisited) {
    // TO BE COMPLETED
	url = webpageURL;
	urlTime = timeVisited;
}

string Webpage::getURL() {
    // TO BE COMPLETED
	return url;
}

time_t Webpage::getTime() {
    // TO BE COMPLETED
	return urlTime;
}