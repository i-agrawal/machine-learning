# Machine Learning

This repository aims to implement and explain basic concepts of machine learning.  
The README.md in each folder will explain how each concept works.  
This README will serve as the introduction to machine learning and starts below.

      Imagine trying to write a program to play chess.
      An easy solution is we have the computer calculate every outcome and choose accordingly.
      Let see how that would work.
      
        After each player makes one move there are 400 different outcomes.
        After each player makes two moves there are 72,084 different outcomes.
        After each player makes three moves there are more than 9 million outcomes.
        After each player makes four moves there are more than 288 billion outcomes.
        After each player makes fourty moves there are more moves than electrons in the universe.
      
      So yeah... I dont think my computer cant even handle 4 moves.
      Lets not calculate every outcome.
      
      Instead lets look at how children learn to play the game.
      
        A child would just try playing the game first.
        Then when they lose they will try again.
        After repeating this process again and again the child will get better.
      
      That is what we should do.
      And that is what machine learning is all about.
      We give the computer experience and have it learn to do something.
      
      There are two types of learning, supervised and unsupervised.
      For supervised, Lets say we are asked to predict the height
        of a ten year old and we are given the following graph.

        height (in)
            │
         80 │                                                     x
            │                                   x   x     x x   x   x
            │                   x       x   x x   x   x x     x   x   x
            │             x x x   x   x   x   x
         40 │       x   x x   x x   x
            │     x   x   x
            │       x
            │
          0 └──────────────────────────────────────────────────────────
            0                          10                            20
                                 age (years)

        An ok way to predict height would be a straight line in the graph.
        Obviously there is no perfect line but we an ok fit.

        height (in)
            │
         80 │                                                     x
            │                                   x   x     x x  ____/‾‾‾‾
            │                   x       x   x x   x  ____/‾‾‾‾‾   x   x
            │             x x x   x   x    ____/‾‾‾‾‾
         40 │       x   x x   x x____/‾‾‾‾‾
            │     x   x____/‾‾‾‾‾
            │____/‾‾‾‾‾
            │
          0 └──────────────────────────────────────────────────────────
            0                          10                            20
                                 age (years)
        
         I created the line 

          
Each concept comes with an implementation in c and comes with a Makefile.  
The visualization is thanks to the great program gnuplot.  

This repository is a work in progress and may have spelling mistakes (sorry :P)  
Also know that nothing here is as highly optimized as the hard working people
  that maintain machine-learning libraries and you probably would want to use
  their implementations or modify this to be faster and more portable.

Also since we use gnuplot you must be careful and follow their Copywrite when using and
especially if modifying this repository.

In order to keep an easy to read structure, the build process currently features recursive make calls. If you have ever read Peter Miller's ![paper](http://aegis.sourceforge.net/auug97.pdf) it is a potentially slow build structure but it is all for the sake of clarity so please forgive me.
