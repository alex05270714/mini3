#include <cstdlib>
#include <climits>
#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth, int player) {
    
   
    state->get_legal_actions();
    Move to_return;
    
    if (player)
    {
        int best_move_value = INT_MIN;
        for ( auto action : state->legal_actions)
        {       
            int try_value = minimax(state->next_state(action),depth - 1, false);
            
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
            int try_value = minimax(state->next_state(action),depth - 1, true);
            if(try_value < best_move_value )
            {
                best_move_value = try_value;
                to_return = action ;
            }
        }
        return to_return;
    }
    
    
}

int Minimax::minimax(State *state, int depth , bool maximizingPlayer)
{
    if(state -> legal_actions.empty())
        state->get_legal_actions();
    if(depth == 0 || state -> legal_actions.empty())
    {
        return state -> evaluate();
    }
    if (maximizingPlayer)
    {
        int best_move_value = INT_MIN;
        for ( auto action : state->legal_actions)
        {       
            int try_value = minimax(state->next_state(action),depth - 1, false );
            
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
            int try_value = minimax(state->next_state(action),depth - 1, true );
            if(try_value < best_move_value )
            {
                best_move_value = try_value;
            }
        }
        return best_move_value;
    }
    
}




