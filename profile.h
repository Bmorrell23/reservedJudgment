#ifndef PROFILE_H
#define PROFILE_H

#include <unordered_map>
#include <vector>
#include <fstream>
#include "activity.h"

class Profile
{
	public:
		Profile();
		~Profile();
		void perform(const Activity& activity);
		void dislike(const Activity& activity);
		std::string favoriteTag() const;

	private:
		std::unordered_map<std::string, int> likes_;
		std::vector<Activity*> previouslyPerformed_;
};

std::string vectorToString(const std::vector<std::string>& vs);

#endif //PROFILE_H
