#ifndef LANGDEF_H
#define LANGDEF_H

//Instruction set
enum{_END,_ADD,_MOV,_JNE,_LBL};

//Shorthand register names
enum{ra,rb,rc,rd,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10};

//Definition of register size
//The idea is that changing it here will make it work everywhere
typedef short reg;

//Definition of instruction
typedef struct{
  reg keyw;
  reg arg1;
  reg arg2;
}ins;

// Definition of program (array of instructions)
typedef ins prog;

//Definition of register set (array of chars) 
typedef reg* regs;

/*********
 SYNTAX
**********/

//Add registers:  X <= X + Y, where X is a register, Y a register or an rvalue
//READS REG: rX,rY
//MODIFIES: rX
#define add(X,Y) {_ADD,X,Y},

//Assignment: X <= Y, where X is a register, Y a register or an rvalue
//READS REG: rX,rY
//MODIFIES: rX
#define mov(X,Y) {_MOV,X,Y},

//Conditional jump: iptr <= Y if ra != X, else iptr++ as usual
//READS REG: ra
//MODIFIES: iptr
#define jne(X,Y) {_JNE,X,Y},

//Compare ... unused?
#define cmp(X,Y) {_CMP,X,Y},

//Label for jumps
//Would normally be decided compile-time
#define lbl(X) {_LBL,X,0},


//Syntactical start
#define start() 

//Syntactical end - needed to make program a valid array-initialization
#define end() {0,0,0}};

#endif

/*********
 ~SYNTAX
**********/

/*
 NOTES:

 Every program must start with this declaration:
  
  char prog[][3]={
 
 This is taken care of by including microlang.h, which in turn includes langdef.h

 Example code:
 --
 #include microlang.h

  mov(r1,4)
  mov(r2,6)
  add(r1,r2)
  end() 
 
 --
 Now r1 will contain 10
 
 - The program can be made into a precompiled header
 - Arithmetic on register names is automatically supported, so r10+10 is r20 

*/

