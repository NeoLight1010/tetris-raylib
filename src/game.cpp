#include "game.h"
#include "blocks.cpp"
#include <iostream>
#include <memory>
#include <random>
#include <vector>

Game::Game(){};

std::shared_ptr<Block> Game::popRandomBlock() {
  if (blocks.empty()) {
    blocks = getDefaultBlocks();
  }

  int randomIndex = rand() % blocks.size();
  std::shared_ptr<Block> chosenBlock = blocks[randomIndex];

  blocks.erase(blocks.begin() + randomIndex);

  chosenBlock->center();
  return chosenBlock;
};

std::vector<std::shared_ptr<Block>> Game::getDefaultBlocks() {
  return {std::make_unique<SBlock>(), std::make_unique<ZBlock>(),
          std::make_unique<TBlock>(), std::make_unique<LBlock>(),
          std::make_unique<JBlock>(), std::make_unique<OBlock>(),
          std::make_unique<IBlock>()};
};

void Game::draw() {
  grid.draw();
  currentBlock->draw();
};
