#include "block.h"

class LBlock : public Block {
public:
  LBlock() {
    rotations[0] = {Position{0, 2}, Position{1, 0}, Position{1, 1},
                    Position{1, 2}};
    rotations[1] = {Position{0, 1}, Position{1, 1}, Position{2, 1},
                    Position{2, 2}};
    rotations[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2},
                    Position{2, 0}};
    rotations[3] = {Position{0, 0}, Position{0, 1}, Position{1, 1},
                    Position{2, 1}};
  }

  int id() { return 1; }

  void center() { move(0, 3); }
};

class JBlock : public Block {
public:
  JBlock() {
    rotations[0] = {Position{0, 0}, Position{1, 0}, Position{1, 1},
                    Position{1, 2}};
    rotations[1] = {Position{0, 1}, Position{0, 2}, Position{1, 1},
                    Position{2, 1}};
    rotations[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2},
                    Position{2, 2}};
    rotations[3] = {Position{0, 1}, Position{1, 1}, Position{2, 0},
                    Position{2, 1}};
  }

  int id() { return 2; }

  void center() { move(0, 3); }
};

class IBlock : public Block {
public:
  IBlock() {
    rotations[0] = {Position{1, 0}, Position{1, 1}, Position{1, 2},
                    Position{1, 3}};
    rotations[1] = {Position{0, 2}, Position{1, 2}, Position{2, 2},
                    Position{3, 2}};
    rotations[2] = {Position{2, 0}, Position{2, 1}, Position{2, 2},
                    Position{2, 3}};
    rotations[3] = {Position{0, 1}, Position{1, 1}, Position{2, 1},
                    Position{3, 1}};
  }

  int id() { return 3; }

  void center() { move(-1, 3); }
};

class OBlock : public Block {
public:
  OBlock() {
    rotations[0] = {Position{0, 0}, Position{0, 1}, Position{1, 0},
                    Position{1, 1}};
    rotations[1] = {Position{0, 0}, Position{0, 1}, Position{1, 0},
                    Position{1, 1}};
    rotations[2] = {Position{0, 0}, Position{0, 1}, Position{1, 0},
                    Position{1, 1}};
    rotations[3] = {Position{0, 0}, Position{0, 1}, Position{1, 0},
                    Position{1, 1}};
  }

  int id() { return 4; }

  void center() { move(0, 4); }
};

class SBlock : public Block {
public:
  SBlock() {
    rotations[0] = {Position{0, 1}, Position{0, 2}, Position{1, 0},
                    Position{1, 1}};
    rotations[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2},
                    Position{2, 2}};
    rotations[2] = {Position{1, 1}, Position{1, 2}, Position{2, 0},
                    Position{2, 1}};
    rotations[3] = {Position{0, 0}, Position{0, 1}, Position{1, 1},
                    Position{2, 1}};
  }

  int id() { return 5; }

  void center() { move(0, 3); }
};

class TBlock : public Block {
public:
  TBlock() {
    rotations[0] = {Position{0, 1}, Position{1, 0}, Position{1, 1},
                    Position{1, 2}};
    rotations[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2},
                    Position{2, 1}};
    rotations[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2},
                    Position{2, 1}};
    rotations[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1},
                    Position{2, 1}};
  }

  int id() { return 6; }

  void center() { move(0, 3); }
};

class ZBlock : public Block {
public:
  ZBlock() {
    rotations[0] = {Position{0, 0}, Position{0, 1}, Position{1, 1},
                    Position{1, 2}};
    rotations[1] = {Position{0, 2}, Position{1, 1}, Position{1, 2},
                    Position{2, 1}};
    rotations[2] = {Position{1, 0}, Position{1, 1}, Position{2, 1},
                    Position{2, 2}};
    rotations[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1},
                    Position{2, 0}};
  }

  int id() { return 7; }

  void center() { move(0, 3); }
};
