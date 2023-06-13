#include "game.h"
#include "blocks.cpp"
#include <iostream>
#include <random>
#include <vector>

Game::Game(){};

Block *Game::popRandomBlock() {
  if (blocks.empty()) {
    blocks = getDefaultBlocks();
  }

  int randomIndex = rand() % blocks.size();
  Block *chosenBlock = blocks[randomIndex];

  blocks.erase(blocks.begin() + randomIndex);

  chosenBlock->center();
  return chosenBlock;
};

std::vector<Block *> Game::getDefaultBlocks() {
  return {new SBlock(), new ZBlock(), new TBlock(), new LBlock(),
          new JBlock(), new OBlock(), new IBlock()};
};

void Game::draw() {
  grid.draw();
  currentBlock->draw();
};
