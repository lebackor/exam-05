#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
    std::map<std::string, ASpell *>::iterator it_start =_arr_spell.begin();
    std::map<std::string, ASpell *>::iterator it_end =_arr_spell.end();

    while (it_start != it_end)
    {
        if (it_start->second)
            delete it_start->second;
        it_start++;
    }
    _arr_spell.clear();
}


void    SpellBook::learnSpell(ASpell* tmp_spell)
{
    if (tmp_spell)
        _arr_spell.insert(std::make_pair(tmp_spell->getName(), tmp_spell->clone()));
}

void    SpellBook::forgetSpell(std::string const &tmp)
{
    std::map<std::string, ASpell*>::iterator it = _arr_spell.find(tmp);
    if (it != _arr_spell.end())
        delete it->second;
    _arr_spell.erase(tmp);
}

ASpell*    SpellBook::createSpell(std::string const &tmp){
    std::map<std::string, ASpell *>::iterator it = _arr_spell.find(tmp);
    if (it != _arr_spell.end())
        return _arr_spell[tmp];
    return NULL;
}