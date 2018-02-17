#ifndef MACHINE_H
#define MACHINE_H

class machine
{
  public:
    machine();
    int x, y;
    enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
};

#endif
