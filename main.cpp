#include <iostream>
#include "pieces.h"
#include "board_functions.h"
#include "check_legal.h"
#include "move_take.h"

Piece piece;

int main() {
    std::vector<Piece> poshis;
    char color = 'w';
    add_all_moves(color);
    while (!detect_checkmate(color)) {
        poshis.push_back(piece);
        print_board();
        color = turn(color);
        add_all_moves(color);
        int similiar = 0;
        for (int i = 0; i < poshis.size(); i++) {
            if (same_pos(poshis[i],piece)) {
                similiar += 1;
            }
        }
        if (similiar == 2) {
            break;
        }
    } 
    print_board();
    if (color == 'w' && detect_check_new_pos('w',piece)) {
        std::cout << "Checkmate! Black Wins";
    }
    else if (color == 'b' && detect_check_new_pos('b', piece)) {
        std::cout << "Checkmate! White Wins";
    }
    else {
        std::cout << "Draw!";
    }
    return 0;
}
