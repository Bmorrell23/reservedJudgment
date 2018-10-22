#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <cstdlib>
#include "activity.h"
#include "profile.h"

class Generator
{
    public:
        Generator(const std::vector<Activity*>& activities, const Profile profile);
        Activity generate() const;

    private:
        std::vector<Activity*> activities_;
        Profile profile_;
};

bool hasTag(const std::vector<std::string>& tags, const std::string& tag);

#endif // GENERATOR_H
