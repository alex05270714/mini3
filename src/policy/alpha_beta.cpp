#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./alpha_beta.hpp"
#include <math.h>

using namespace  std;


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Alpha_beta::get_move(State *state, int depth,int player,int alpha,int beta) {
    
   
    state->get_legal_actions();
    Move to_return;
    
    if (player)
    {
        int best_move_value = INT_MIN;
        for ( auto action : state->legal_actions)
        {       
            int try_value = minimax(state->next_state(action),depth - 1, false, alpha , beta);
            alpha = max(try_value,alpha);
            if(alpha >= beta)
                break;
            if(try_value > best_move_value )
            {
                best_move_value = try_value;
                to_return = action ;
            }
        }
        return to_return;
    }
    else
    {
        int best_move_value = INT_MAX;
        for ( auto action : state->legal_actions)
        {       
            int try_value = minimax(state->next_state(action),depth - 1, true,alpha , beta );
            beta = min(try_value,beta);
            if(alpha >= beta)
                break;
            if(try_value < best_move_value )
            {
                best_move_value = try_value;
                to_return = action ;
            }
        }
        return to_return;
    }
    
    
}

int Alpha_beta::minimax(State *state, int depth , bool maximizingPlayer, int alpha , int beta )
{
    state->get_legal_actions();
    if(depth == 0 || state -> game_state == WIN)
    {
        return state -> evaluate();
    }
    if (maximizingPlayer)
    {
        int best_move_value = INT_MIN;
        for ( auto action : state->legal_actions)
        {       
            int try_value = minimax(state->next_state(action),depth - 1, false ,alpha, beta);
            alpha = max(try_value,alpha);
            if(alpha >= beta)
                break;
            if(try_value > best_move_value )
            {
                best_move_value = try_value;
            }
        }
        return best_move_value;
    }
    else
    {
        int best_move_value = INT_MAX;
        for ( auto action : state->legal_actions)
        {       
            int try_value = minimax(state->next_state(action),depth - 1, true , alpha, beta);
            beta = min(try_value,beta);
            if(alpha >= beta)
                break;
            if(try_value < best_move_value )
            {
                best_move_value = try_value;
            }
        }
        return best_move_value;
    }
    
}




