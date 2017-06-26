
//#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

#define mkLoc(x, y) (x | (y << 4))
#define getLocX(l) (l & 0x0f) //0x0f = 00001111 //(((uint8_t)(l) << 4) >> 4)
#define getLocY(l) ((uint8_t)(l) >> 4)


enum Piece {
   Pawn, Rook, Knight, Bishop, Queen, King
};

enum Color {
   Black, White
};

typedef union BoardPiece {
   uint64_t uint16;

   struct {
      uint8_t loc : 8; //8x8=64
      uint8_t col : 1;
      uint8_t piece : 3;
   };
} BoardPiece;


typedef struct Board {
   uint8_t next_to_move : 1;

   //v1: array of each color pieces
   //uint16_t white_pieces[8];
   //uint16_t black_pieces[8];

   //v2: array of all pieces
   uint16_t grid[64];
   uint8_t white_indices[8]; //index in grid
   uint8_t black_indices[8]; //index in grid

} Board;


typedef union Move {
   uint16_t uint16;
   struct {
      uint8_t start;
      uint8_t end;
   };
} Move;

void print_bp(BoardPiece bp) {
   printf("x: %i; y: %i\n", getLocX(bp.loc), getLocY(bp.loc));

   switch (bp.col) {
      case Black:
         printf("black\n");
         break;
      case White:
         printf("white\n");
         break;
      default:
         break;
   }

}


int main() {
   BoardPiece bp;
   bp.loc = mkLoc(3, 2);
   bp.col = White;
   bp.piece = Rook;

   print_bp(bp);
}


