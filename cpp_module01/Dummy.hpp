#pragma once

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget{
    public:
        Dummy();
        ~Dummy();

        virtual ATarget *clone() const;
};