#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title){
    this->name = name;
    this->title = title;
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){ std::cout << name << ": My job here is done!" << std::endl; }


Warlock& Warlock::operator=(Warlock const &rhs)
{
    this->name = rhs.name;
    this->title = rhs.title;
    return *this;
}

std::string const & Warlock::getName() const
{
    return this->name;
}


std::string const & Warlock::getTitle() const{
    return this->title;
}

void    Warlock::setTitle(std::string const &title)
{
    this->title = title;
}

void    Warlock::introduce() const {
    std::cout << name << ": I am "<< name <<", "<< title << "!" << std::endl;

}

void    Warlock::learnSpell(ASpell* tmp_spell)
{
    if (tmp_spell)
        arr_targ.insert(std::make_pair(tmp_spell->getName(), tmp_spell->clone()));
}


void    Warlock::forgetSpell(std::string forgetspl){

    std::map<std::string, ASpell*>::iterator it = arr_targ.find(forgetspl);
    if (it != arr_targ.end())
        delete it->second;
    arr_targ.erase(forgetspl);
}


void    Warlock::launchSpell(std::string spellname, ATarget const &targ)
{
    ASpell* spell =  arr_targ[spellname];
    if (spell)
        spell->launch(targ);
}