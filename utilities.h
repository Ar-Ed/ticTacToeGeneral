//(done) make a tie state 
//(done) make a general tictactoe that is nxn square where n is user choice
//(done for now) polish ui
//(done) fix the bug which emerges when a character input is taken
//add run-time quit

#pragma once
#include <iostream>
#include <vector>

short input_check(short x, short y, std::vector<std::vector<char> > &position, short size);

void take_input(std::vector<std::vector<char> > &position, short turn, short size);

void display_game(std::vector<std::vector<char> > &position, short size);

char game_status(std::vector<std::vector<char> > position,short size);