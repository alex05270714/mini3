#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Alpha_beta{
public:
  static Move get_move(State *state, int dept,int player,int alpha,int beta);
  static int alpha_beta(State *state, int depth , bool maximizingPlayer,int alpha , int beta);
};

