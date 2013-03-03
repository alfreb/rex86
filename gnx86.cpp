#include <iostream>
#include <vector>

using namespace std;

//Including the language defs - use microlang.h in programs
#include "langdef.h"

//Number of registers
#define REGCNT 100


/*
  The microMachine class - a register machine 
*/
class microMachine{
  prog* p;
  int iptr; //Next instruction is prog[iptr]
  reg* registers;

protected:
  void exec();
  vector<int>* labels;
public:
  microMachine();  
  ~microMachine();
  
  //Run prog, return immutable ptr to registers
  const reg* run(prog* prog);
  
};

//Constructor
microMachine::microMachine(){
  registers=new reg[REGCNT];
  iptr=0;
  labels=new vector<int>(10);
}

//Destructor
microMachine::~microMachine(){
  delete registers;
}

//Execute instruction at iptr - recursively
void microMachine::exec(){
  ins i=p[iptr];
  
  //Handle each instruction
  switch(i.keyw){  
  case _END:
    cout << iptr  << ": END" << endl;
    return;
  case _MOV:
    cout << iptr  << ": MOV: r" <<i.arg1 <<" = "<< i.arg2 << endl;
    registers[i.arg1]=i.arg2;
    iptr++;
    break;
  case _ADD:
    cout << iptr  << ": ADD: r" << i.arg1 << " += " 
	 << registers[i.arg2] << endl;
    registers[i.arg1]+=registers[i.arg2];    
    iptr++;
    break;
  case _JNE:
    cout << iptr  << ": JNE: "<< registers[ra] << "==" << registers[i.arg1]
	 << ": "<<(registers[ra]!=i.arg1) 
	 << " -> " << (*labels)[i.arg2] << endl;
    iptr=registers[ra]!=registers[i.arg1] ? (*labels)[i.arg2] : iptr+1;
    break;
  case _LBL:
    cout << iptr << ": LBL, moving on" << endl;
    iptr++;
    break;
  default:
    cout << iptr  << ": Unrecognized instruction: " << i.keyw << endl;
    return;
  }

  //Clock rate
  // sleep(MhZ*...)
  sleep(1);
  exec();
}

//Administrative stuff, before eventually doing exec
const reg* microMachine::run(prog* prog){
  
  //Load program
  p=prog;
  
  //Find line numbers for jump-labels
  cout << " Sorting out labels: " << endl;
  ins* i=&p[0];
  int n=0;
  while(i->keyw!=_END){
    if(i->keyw==_LBL){
      cout << "Label " << i->arg1 << " => " << n+1 << endl;
      (*labels)[i->arg1]=n+1;
    }
    i++;
    n++;
  }

  //Start execution
  exec(); 

  
  //Beautifully self-explanatory
  return registers;  
}


int main(){

  //Create machine instance
  microMachine mm;

  //Define prog p :   
#include "program1.h"
    
  //Have the machine run the program p
  const reg* r=mm.run(p);
  
  //Echo the result - for p, this happens to be in the tmp-register
  //Other programs could have their result in any register.
  cout << "Result: " << r[tmp] << endl; 
}

