enum{_ADD};
#include "microlang.h"

//Multiply: r1 * r2
mov(r1,4) // r1 = 4
mov(r2,6) // r2 = 6

//Need two registers, to remember both args.
//Since it can be 0
mov(r3,0) // r3 = 0
mov(r4,0) // r4 = 0

//Jmp
mov(ra,0)
mov(r1,1)
jne(r1,) 

//JE //17
#define ex_JE __LINE__ 
mov(ra,0) 
mov(r1,0)
jne(r1,__LINE__ +4) //r0 != r1 -> JMP
mov(r2,1)
add(r2,1)
jne(r2,__LINE__ +1) //r0 == r1
// >NO
// >YES

add(r1,r2) // r1 += r2
mov(r3,100) // r3 = 100
add(r1,r3) // r1 += r3
end() // exit

cout << "Line: " << ex_JE << endl;

