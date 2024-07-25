#ifndef RENDER_GROUP_HPP
#define RENDER_GROUP_HPP

#include <bullet.hpp>
#include <list>
using std::list;

class RenderGroup {
  public:
    static list<Bullet*> Bullets;
};

#endif
