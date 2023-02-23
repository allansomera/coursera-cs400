/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
    // Prints out the state of the game:
    // cout << *this << endl;
    // @TODO -- Finish solving the game!
    while(stacks_[2].size() != 4){
        _legalMove(0,1);
        _legalMove(0,2);
        _legalMove(1,2);
    }
}

void Game::_legalMove(unsigned idx1, unsigned idx2){
    if( stacks_[idx1].size() == 0 && stacks_[idx2].size() > 0){
        _move(idx2, idx1);
    }else if (stacks_[idx1].size() > 0 && stacks_[idx2].size() == 0){
        _move(idx1, idx2);
    }else if (stacks_[idx1].size() > 0 && stacks_[idx2].size() > 0 ){
        if(stacks_[idx1].peekTop().getLength() < stacks_[idx2].peekTop().getLength()){
            _move(idx1, idx2);
        }else{
            _move(idx2, idx1);
        }
    }
}

void Game::_move(unsigned idx1, unsigned idx2){
    stacks_[idx2].push_back(stacks_[idx1].removeTop());
}

// Default constructor to create the initial state:
Game::Game() {
    // Create the three empty stacks:
    for (int i = 0; i < 3; i++) {
        Stack stackOfCubes;
        stacks_.push_back( stackOfCubes );
    }

    // Create the four cubes, placing each on the [0]th stack:
    Cube blue(4, uiuc::HSLAPixel::BLUE);
    stacks_[0].push_back(blue);

    Cube orange(3, uiuc::HSLAPixel::ORANGE);
    stacks_[0].push_back(orange);

    Cube purple(2, uiuc::HSLAPixel::PURPLE);
    stacks_[0].push_back(purple);

    Cube yellow(1, uiuc::HSLAPixel::YELLOW);
    stacks_[0].push_back(yellow);
}

std::ostream& operator<<(std::ostream & os, const Game & game) {
    for (unsigned i = 0; i < game.stacks_.size(); i++) {
        os << "Stack[" << i << "]: " << game.stacks_[i];
    }
    return os;
}
