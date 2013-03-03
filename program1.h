
//Labels
enum labels{_XOK,_YOK,_LOOP,_DONE};


#define X rb
#define Y rc

//Includes the macro-language setup
#include "asm_gnx86.h"

//Multiply: r1 * r2
mov(X,18) // r1 = 18
mov(Y,4) // r2 = 4

//Need two registers, to remember both args.
//Since it can be 0

#define NUL ra
#define i ra //Us ra both for NUL, and iterator
#define tmp r2
#define ONE r3
mov(NUL,0) // r1 = 0 
mov(ONE,1) // r3 = 0
mov(tmp,0) // r2 = 0

//If X == 0 -> End
jne(X,_XOK) // ra is 0. X!=0 -> OK
jne(ONE,_DONE) // tmp!=ra <=> 1!=0 -> _DONE
lbl(_XOK)

//If Y == 0 -> End
jne(Y,_YOK) // ra is 0. Y!=0 -> OK
jne(ONE,_DONE) // Y==0 -> _DONE
lbl(_YOK)

lbl(_LOOP)
add(tmp,Y) // Add Y to res
add(i,ONE) // Increment counter
jne(X,_LOOP) //If ra!=X -> _LOOP

lbl(_DONE)
end() // exit
