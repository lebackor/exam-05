#pragma once

#include <iostream>

#include "ATarget.hpp"
#include <map>

class TargetGenerator{
    private:
        TargetGenerator(TargetGenerator const &obj);
        TargetGenerator& operator=(TargetGenerator const &rhs);
        std::map<std::string, ATarget *> _targ;

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* tmp);

        void forgetTargetType(std::string const& tmp);

        ATarget* createTarget(std::string const &tmp);
};