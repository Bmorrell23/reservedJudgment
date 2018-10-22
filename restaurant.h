#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>
#include "activity.h"

class Restaurant : public Activity
{
	public:
		Restaurant(const std::string& name, const std::string& description, 
			  const std::string& score, const std::string& tags)
		: Activity(name, description, score, tags){}
};

#endif //MOVIE_H
