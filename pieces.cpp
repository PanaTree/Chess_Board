#include <iostream>
#include <vector>
using namespace std;

struct pawn {
    int file;
    int rank;
    bool taken;
};

struct knight {
    int file;
    int rank;
    bool taken;
};

struct bishop {
    int file;
    int rank;
    bool taken;
};

struct rook {
    int file;
    int rank;
    bool taken;
};

struct queen {
    int file;
    int rank;
    bool taken;
};

struct king {
    int file;
    int rank;
};

struct piece {
    vector<pawn> white_pawn;
    vector<knight> white_knight;
    vector<bishop> white_bishop;
    vector<rook> white_rook;
    vector<queen> white_queen;
    struct king white_king;
    vector<pawn> black_pawn;
    vector<knight> black_knight;
    vector<bishop> black_bishop;
    vector<rook> black_rook;
    vector<queen> black_queen;
    struct king black_king;

};