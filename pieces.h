#pragma once
#include <vector>

/* A structure for a chess piece contains their 
file number, rank number, and whether they are taken or not.
The structure Piece contains vectors of structures
for both black and white: i.e. piece.white_pawn would contain all
structures of piece.white_ pawns. */

struct pawn {
    int file;
    int rank;
    bool taken;
    std::vector<std::pair<int, int>> moves;
};
struct knight {
    int file;
    int rank;
    bool taken;
    std::vector<std::pair<int, int>> moves;
};
struct bishop {
    int file;
    int rank;
    bool taken;
    std::vector<std::pair<int, int>> moves;
};
struct rook {
    int file;
    int rank;
    bool taken;
    std::vector<std::pair<int, int>> moves;
    bool can_castle;
};
struct queen {
    int file;
    int rank;
    bool taken;
    std::vector<std::pair<int, int>> moves;
};
struct king {
    int file;
    int rank;
    std::vector<std::pair<int, int>> moves;
    bool can_castle;
};
struct enpassant {
    int file;
    int rank;
    bool taken;
};

struct Piece {
    std::vector<pawn> white_pawn = { {0,6,false},{1,6,false},{2,6,false},{3,6,false},{4,6,false},{5,6,false},{6,6,false},{7,6,false} };
    std::vector<knight> white_knight = { {1,7,false} , {6,7,false} };
    std::vector<bishop> white_bishop = { {2,7,false} , {5,7,false} };
    std::vector<rook> white_rook = { {0,7,false,{},true} , {7,7,false,{},true} };
    std::vector<queen> white_queen = { {3,7,false} };
    king white_king = {4,7,{},true };
    enpassant white_enpassant = { -1,-1,true };
    std::vector<pawn> black_pawn = { {0,1,false},{1,1,false},{2,1,false},{3,1,false},{4,1,false},{5,1,false},{6,1,false},{7,1,false} };
    std::vector<knight> black_knight = { {1,0,false} , {6,0,false} };
    std::vector<bishop> black_bishop = { {2,0,false} , {5,0,false} };
    std::vector<rook> black_rook = { {0,0,false,{},true} , {7,0,false,{},true} };
    std::vector<queen> black_queen = { {3,0,false} };
    king black_king = {4,0,{},true };
    enpassant black_enpassant = { -1,-1,true };

};
