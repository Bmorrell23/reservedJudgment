#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include "activity.h"

class Movie : public Activity
{
	public:
		Movie(const std::string& name, const std::string& description, 
			  const std::string& score, const std::string& tags)
		: Activity(name, description, score, tags){}
};
#endif //MOVIE_H
