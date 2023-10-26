#pragma once

#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"

#include <map>

class Warlock{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> arr_targ;
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        Warlock &operator=(Warlock const &rhs);
        std::string const & getName() const;
        std::string const & getTitle() const;
        void        setTitle(std::string const &title);

        void    introduce() const;

        void    learnSpell(ASpell* tmp_spell);
        void    forgetSpell(std::string forgetspl);
        void    launchSpell(std::string spellname, ATarget const &targ);
};