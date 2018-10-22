#include "generator.h"

Generator::Generator(const std::vector<Activity*>& activity, const Profile profile)
    : activities_(activity)
    , profile_(profile)
{

}

Activity Generator::generate() const
{
    std::string favTag = profile_.favoriteTag();

    for(auto a : activities_)
    {
        if(hasTag(a->tags(), favTag))
        {
            return *a;
        }
    }

    int index = 0;

    if(activities_.size() > 1)
        index = rand() % activities_.size();

    return *activities_[index];
}

bool hasTag(const std::vector<std::string>& tags, const std::string& tag)
{
    for(auto s: tags)
    {
        if(s == tag)
            return true;
    }

    return false;
}
