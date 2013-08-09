Free computers are necessary for GNUsers, since [the GNU freedoms must include hardware to make any sense](http://blogg.hioa.no/alfred/2013/03/03/the-gnu-freedoms-must-include-hardware-to-make-any-sense/). 

The rex86 is a computer according to the following **definition:** 

*(Computer) A working implementation of a turing complete language, using finite memory*

That means it's not necessarily a physical thing, but one of the goals of this project is that one day it might be.

###What it's currently supposed to be:
- A C++ implementation of a Turing complete register machine
- Very small
- Extremely inefficient

###What it's supposed to become:
- A pysically implementable computer
  - using a small subset of the x86 instruction set
  - With basic interrupt support
  - Serial-like I/O ports, each supporting interrupts
  - Probably no interrupt timer, except over serial I/O
- A functioning virtual machine
- Extremely small, but maybe less extremely inefficient

###Why does size matter?
Because if you really want to [control your own computing](http://www.gnu.org/philosophy/free-sw.html) you have to be able to read, and understand the source code of both your software and your hardware, in less than a lifetime. That's usually very optimistic, but if you want to be a true GNU Purist, you should. 
(Personally I'd become a GNU Purist only if there was awesome free (as in freedom) hardware available, which makes me a pragmatist.)

###What's in a name?
The original name, "gnx86" is a recursive acronym for "gnx86 is not x86". The first letter of the name is of course arbitrary, but a kind of tip to the hat to [GNU](http://www.gnu.org). The name would sound cooler if it was an actual word as well, such as "gnu" or "emu". Unfortunately there are no animal names that end with x86 - except for Tyrannosaurus Rex86. Hence the name change to rex86. Also, rex86 emulates, escapes, embeds, extends, enjoys, entangles or enrages x86.
