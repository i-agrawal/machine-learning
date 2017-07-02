# Machine Learning

This repository aims to implement and explain basic concepts of machine learning.  
The README.md in each folder will explain how each concept works.  
This README will serve as the introduction to machine learning and starts below.

      Imagine trying to write a program to play chess.
      An easy solution is we have the computer calculate every outcome and choose accordingly.
      Let see how that would work out.
      
        Moves           Outcomes        
        1               400
        2               72,084
        3               9+ million
        4               288+ billion
        ...
        40              More electrons than in the universe
      
      So yeah... I dont think my computer can even handle 4 moves.
      And a large amount of chess bots just calculate 3 moves ahead.
      Instead we are going to look at how children learn to play chess.
      
        A child does not bother trying to calculate everything.
        A child tries playing a game first.
        Then when they lose they will try again.
        After repeating this process again and again the child will get better.
      
      That is what we should do.
      And that is what machine learning is all about.
      We give the computer experience and have it learn to do something.
      
      Now there are two main ways we can get our computer to learn:
      
        Supervised Learning - Given examples with their outcome
                              the computer must learn to predict
                              the outcome.

        Unsupervised Learning - Given examples without the outcome
                                the computer must give us some
                                information about them.

      As an example for supervised learning, lets say we are asked
        to predict what the height a girl at 10 years old.
      And we are given the following
      
                             Female height vs. age
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
      Obviously there is no perfect line but we want an ok fit.
      
        height (in)
            │
         80 │                                                     x
            │                                   x   x     x x  _____‾‾‾‾
            │                   x       x   x x   x  _____‾‾‾‾‾   x   x
            │             x x x   x   x    _____‾‾‾‾‾
         40 │       x   x x   x x_____‾‾‾‾‾
            │     x   x_____‾‾‾‾‾
            │_____‾‾‾‾‾
            │
          0 └──────────────────────────────────────────────────────────
            0                          10                            20
                                 age (years)
      
      I created this beautiful line above to predict height given age.
      And if you were to fit a straight line to this graph you would
        probably get something similar.
      
      I know you would get something similar because you would create
        your line trying to hit the points in the graph.
      
      And that is what supervised learning is.
      Given an input and the correct output the computer must somehow
        learn to predict the correct output.
      Now if you looked at the data you may see it would be better fit
        as a curved line rather than straight and we will get into
        that later.
      
      
      After supervised learning, there is unsupervised learning.
      For an example of unsupervised learning lets say we are given
        some data and we need to find some information.
      
                     Amount of Gene A and B Expressed
          Gene A
            │
            │                                 x   x
            │                                   x   x x
            │                   x x           x   x x
            │                 x x     x     x
            │           x       x   x
            │     x x     x
            │       x x
            │
            └───────────────────────────────────────────────
                                 Gene B
      
      Keep in mind that we are not trying to predict Gene A given B.
      From looking at the data, some pretty good information we can find
        is that there are 3 groups of people.
      
          
Each concept comes with an implementation in c and comes with a Makefile.  
The visualization is thanks to the great program gnuplot.  

This repository is a work in progress and may have spelling mistakes (sorry :P)  
Also know that nothing here is as highly optimized as the hard working people
  that maintain machine-learning libraries and you probably would want to use
  their implementations or modify this to be faster and more portable.

Also since we use gnuplot you must be careful and follow their Copywrite when using and
especially if modifying this repository.

In order to keep an easy to read structure, the build process currently features recursive make calls. If you have ever read Peter Miller's ![paper](http://aegis.sourceforge.net/auug97.pdf) it is a potentially slow build structure but it is all for the sake of clarity so please forgive me.
