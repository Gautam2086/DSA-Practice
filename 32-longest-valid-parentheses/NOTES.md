We'll use stack (Surprise Surprise!)
*  unlike valid_parantheses problem we'll push indexes in stack.
*  If curr char is '(', push it's index in stack.
*  If curr char is ')', pop from stack
*    After pop(),
*      if stack is empty push curr_index in stack
*      else, we have found a valid substring and
*      len of substring will be curr_index - index_at_top_of_stack.
*  Update result with max().
*
*  Try out example to understand the algo.
​
​
// -1 helps in determining len
// if first 2 chars are valid substring i.e "()"