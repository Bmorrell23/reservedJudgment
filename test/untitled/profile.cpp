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
        fout << previouslyPerformed_[i]->info() << '\n';
    }

    fout << "Likes:\n";

    for(auto l = likes_.begin(); l != likes_.end(); ++l)
        fout << l->first << " " << l->second << '\n';
}

void Profile::perform(const Activity& activity)
{
    previouslyPerformed_.push_back(new Activity(activity.name(), activity.description(), activity.score(), vectorToString(activity.tags())));

    for(auto tag : activity.tags())
    {
        ++likes_[tag];
    }
}

void Profile::dislike(const Activity& activity)
{
    previouslyPerformed_.push_back(new Activity(activity.name(), activity.description(), activity.score(), vectorToString(activity.tags())));

    for(auto tag : activity.tags())
    {
        --likes_[tag];
    }
}

std::string Profile::favoriteTag() const
{
    if(likes_.size() == 0)
        return "";

    int mostLikedCount		    = 0;
    std::string mostLikedString = "";

    for(auto l = likes_.begin(); l != likes_.end(); ++l)
    {
        if(l->second > mostLikedCount)
        {
            mostLikedCount  = l->second;
            mostLikedString = l->first;
        }
    }

    return mostLikedString;
}

std::string vectorToString(const std::vector<std::string>& vs)
{
    std::string rval = "";

    for(auto s : vs)
        rval = rval + " " + s;

    return rval;
}
