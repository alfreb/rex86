gnx86
=====

gnx86 is not x86. But it is a free (as in freedom) computer, or at least a seed for one. Free computers are necessary for GNUsers, since [the GNU freedoms must include hardware to make any sense](http://blogg.hioa.no/alfred/2013/03/03/the-gnu-freedoms-must-include-hardware-to-make-any-sense/). 

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
The name is "gnx86" is a recursive acronym for "gnx86 is not x86" which would sound cooler if it was an actual word as well, such as a gnu or an emu. Unfortunately there are no animal names that end with x86. The first letter is of course arbitrary, but a kind of tip to the hat to [GNU](http://www.gnu.org). Apart from this there is no connection between gnx86 and GNU, except the first considers the latter a friend.
