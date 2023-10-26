#pragma once

#include <iostream>

#include "ASpell.hpp"
#include <map>
class SpellBook{
    private:
        std::map<std::string, ASpell *> _arr_spell;

    public:
        SpellBook();
        ~SpellBook();
        SpellBook& operator=(SpellBook const &rhs);

        void    learnSpell(ASpell* tmp_spell);
        void    forgetSpell(std::string const &tmp);
        ASpell* createSpell(std::string const &tmp);
};