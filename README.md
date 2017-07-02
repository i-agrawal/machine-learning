# Machine Learning

This repository aims to implement and explain basic concepts of machine learning.  
The README.md in each folder will explain how each concept works.  
This README will serve as the introduction to machine learning and starts below.

      Imagine trying to write a program to play chess.  
      An easy solution is we have the computer calculate every outcome and choose accordingly.  
      
      
      After each player makes a move there are 400 different outcomes.  
      Okay a computer can handle that easily.  
      After each player makes another move there are 72,084 different outcomes.  
      Okay still well reachable by a computer.  
      After each player makes another move there are more than 9 million outcomes.  
      Okay thats a lot, but a computer can still handle that.  
      After each player makes another move there are more than 288 billion outcomes.  
      Okay so... yeah if thats only four moves I dont think my computer can handle it.  


Each concept comes with an implementation in c and comes with a Makefile.  
The visualization is thanks to the great program gnuplot.  

This repository is a work in progress and may have spelling mistakes (sorry :P)  
Also know that nothing here is as highly optimized as the hard working people
  that maintain machine-learning libraries and you probably would want to use
  their implementations or modify this to be faster and more portable.

Also since we use gnuplot you must be careful and follow their Copywrite when using and
especially if modifying this repository.

In order to keep an easy to read structure, the build process currently features recursive make calls. If you have ever read Peter Miller's ![paper](http://aegis.sourceforge.net/auug97.pdf) it is a potentially slow build structure but it is all for the sake of clarity so please forgive me.
