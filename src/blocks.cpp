#include "block.h"

class LBlock : public Block {
public:
  LBlock() {
    cells[0] = {Position{0, 2}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
    cells[1] = {Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{2, 2}};
    cells[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 0}};
    cells[3] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{2, 1}};
  }

  int id() { return 1; }
};

class JBlock : public Block {
public:
  JBlock() {
    cells[0] = {Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
    cells[1] = {Position{0, 1}, Position{0, 2}, Position{1, 1}, Position{2, 1}};
    cells[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 2}};
    cells[3] = {Position{0, 1}, Position{1, 1}, Position{2, 0}, Position{2, 1}};
  }

  int id() { return 2; }
};

class IBlock : public Block {
public:
  IBlock() {
    cells[0] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{1, 3}};
    cells[1] = {Position{0, 2}, Position{1, 2}, Position{2, 2}, Position{3, 2}};
    cells[2] = {Position{2, 0}, Position{2, 1}, Position{2, 2}, Position{2, 3}};
    cells[3] = {Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{3, 1}};
  }

  int id() { return 3; }
};

class OBlock : public Block {
public:
  OBlock() {
    cells[0] = {Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1}};
    cells[1] = {Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1}};
    cells[2] = {Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1}};
    cells[3] = {Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1}};
  }

  int id() { return 4; }
};

class SBlock : public Block {
public:
  SBlock() {
    cells[0] = {Position{0, 1}, Position{0, 2}, Position{1, 0}, Position{1, 1}};
    cells[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 2}};
    cells[2] = {Position{1, 1}, Position{1, 2}, Position{2, 0}, Position{2, 1}};
    cells[3] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{2, 1}};
  }

  int id() { return 5; }
};

class TBlock : public Block {
public:
  TBlock() {
    cells[0] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
    cells[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
    cells[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
    cells[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 1}};
  }

  int id() { return 6; }
};

class ZBlock : public Block {
public:
  ZBlock() {
    cells[0] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{1, 2}};
    cells[1] = {Position{0, 2}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
    cells[2] = {Position{1, 0}, Position{1, 1}, Position{2, 1}, Position{2, 2}};
    cells[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 0}};
  }

  int id() { return 7; }
};
