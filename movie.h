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
		/*
		Movie();
		Movie(const std::string& name, const std::string& description, 
			  const std::string& score, const std::string& tags);
		void setName(const std::string& name);
		void setDescription(const std::string& description);
		void setScore(const std::string& score);
		void setTag(const std::vector<std::string>& tags);
		std::string name() const;
		std::string description() const;
		std::string score() const;
		std::vector<std::string> tags() const;
		std::string info() const;

	private:*/
};

/*std::string substrBefore(const std::string& s, size_t index );
std::string substrAfter(const std::string& s, size_t index);*/

#endif //MOVIE_H
