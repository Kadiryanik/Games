#include "Z.h"

#define BIGGEST_EDGE    3
#define TOTAL_SHAPE_NUM 2

#define CC_CHAR_SHAPE   CHAR_SPACE
#define CC_COLOR_SHAPE  COLOR_FG_RED

const int shapes[BIGGEST_EDGE * TOTAL_SHAPE_NUM][BIGGEST_EDGE] = {
  { 1, 1, 0 },
  { 0, 1, 1 },
  { 0, 0, 0 },

  { 0, 1, 0 },
  { 1, 1, 0 },
  { 1, 0, 0 }
};

/*------------------------------------------------------------------------------*/
Z::Z() : Shape(BIGGEST_EDGE, BIGGEST_EDGE, CC_CHAR_SHAPE, CC_COLOR_SHAPE){
  // init first shape as matrix
  for(int i = 0; i < BIGGEST_EDGE; i++){
    for(int j = 0; j < BIGGEST_EDGE; j++){
      matrix[i][j] = shapes[(currentMatrixIndex * BIGGEST_EDGE) + i][j];
    }
  }
}

/*------------------------------------------------------------------------------*/
Z::~Z(){
  for( int i = 0 ; i < height; i++){
      delete[] matrix[i];
  }
  // delete actual matrix
  delete[] matrix;
}

/*------------------------------------------------------------------------------*/
void Z::rotate(){
  currentMatrixIndex = (currentMatrixIndex + 1) % TOTAL_SHAPE_NUM;

  for(int i = 0; i < BIGGEST_EDGE; i++){
    for(int j = 0; j < BIGGEST_EDGE; j++){
      matrix[i][j] = shapes[(currentMatrixIndex * BIGGEST_EDGE) + i][j];
    }
  }
}

/*------------------------------------------------------------------------------*/
