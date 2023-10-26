#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){
}

TargetGenerator::~TargetGenerator(){}


void    TargetGenerator::learnTargetType(ATarget* tmp)
{
    if (tmp)
        _targ.insert(std::make_pair(tmp->getType(), tmp->clone()));
}

void    TargetGenerator::forgetTargetType(std::string const &tmp){
    std::map<std::string, ATarget *>::iterator it = _targ.find(tmp);

    if (it != _targ.end())
        delete it->second;
    _targ.erase(tmp);
}

ATarget* TargetGenerator::createTarget(std::string const &tmp){
    std::map<std::string, ATarget *>::iterator it = _targ.find(tmp);
    if (it != _targ.end())
        return _targ[tmp];
    return NULL;
}