#pragma once

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class Polymorph : public ASpell{
    public:
        Polymorph();
        ~Polymorph();

    virtual ASpell *clone() const;
};