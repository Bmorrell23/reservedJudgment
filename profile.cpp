#include "profile.h"

Profile::Profile()
	: likes_()
	, previouslyPerformed_()
{

}

Profile::~Profile()
{
	std::fstream fout("profile.txt");

	fout << "Previous Activities: \n";

	for(size_t i = 0; i < previouslyPerformed_.size(); ++i)
	{
		fout << previouslyPerformed_[i].info() << '\n';
	}

	fout << "Likes:\n";

	for(auto l = likes_.begin(); l != likes_.end(); ++l)
		fout << l->first << " " << l->second << '\n';
}

void Profile::perform(const Activity& activity)
{
	previouslyPerformed_.push_back(activity);

	for(auto tag : activity.tags())
	{
		++likes_[tag];
	}
}

void Profile::dislike(const Activity& activity)
{
	previouslyPerformed_.push_back(activity);

	for(auto tag : activity.tags())
	{
		--likes_[tag];
	}
}
