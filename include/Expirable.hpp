#pragma once

#include <iostream>
using namespace std;

class Expirable{
  protected:
    int lifespan;

  public:
    Expirable(int lifespan) { this->lifespan = lifespan; }
    void age() { lifespan--; }
    bool isExpired(){ return lifespan <= 0;}
};
