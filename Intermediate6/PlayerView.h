
#pragma once
#include "Observer.h"
#include "Player.h"

class PlayerView : public Observer {
  public:
    PlayerView();
    PlayerView(Player* s);
    ~PlayerView();
    void Update();
    void display();
  private:
    Player *_subject;
};