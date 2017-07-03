# Machine Learning

This repository aims to implement and explain basic concepts of machine learning.  
The README.md in each folder will explain how each concept works.  
This README will serve as the introduction to machine learning and starts below.

      Imagine trying to write a program to play chess.
      Most chess bots calculate the possible outcomes of each move and choose the move
        with the best outcomes.
      But the more moves in the future it calculates, the more outcomes.
      So just how many outcomes would there be?
      
        Moves Ahead          Possible Outcomes        
        1                    400
        2                    72,084
        3                    9+ million
        4                    288+ billion
        ...                  ...
        40                   More electrons than in the universe
      
      At around 4 moves it basically becomes too much for the computer to handle.
      That is why most chess programs that use this method usually look 3 moves ahead.
      But we dont want such a complicated approach.
      Humans dont calculate every possible move yet some can play better than a bot.
      So if we want a chess program that plays like a human we should look at
        how a human learns to play chess.
      
        Lets say we have some guy who wants to learn to play chess.
        Rather than going overboard and looking up a lot of strategy,
          he jumps right in and plays a game.
        He is not very experienced so he loses.
        But he jumps back in and plays another game.
        After playing a lot of games he gets better and better.
      
      That sounds like a pretty normal way of how a lot of people learn chess.
      It also sounds like a pretty normal way that people learn anything.
      And that is the process we use to get computers to learn.
      Machine learning is all about giving the computer experience and using
        that experience we have it learn.

      The way we give computers experience is in the form of data.
      Lets look at a new example, of height vs. age and we have the
        following data.
      
                                height vs. age
        height (in)
            │
         80 │                                                     x
            │                                   x   x     x x   x   x
            │                   x       x   x x   x   x x     x   x   x
            │                 x   x   x   x   x
         40 │         x x x   x x   x
            │     x       x
            │       x
            │
          0 └──────────────────────────────────────────────────────────
            0                          10                            20
                                   age (years)
      
      If you were to format this data it would look something like this.
      
        Age (years)       Height (in)
        2                 31
        2.5               29
        3                 40
        3.5               43
        4                 43
        4.5               39
        4.5               44
        ...               ...
      
      I will go over what this data means, how we use it, and so on
        further into the repository.
      Right now I recommend you go onto the supervised learning section.
      

Most concepts comes with an implementation in c and comes with a Makefile.  
The visualization is thanks to the great program gnuplot.  

This repository is a work in progress and may have spelling mistakes (sorry :P)  
Also know that nothing here is as highly optimized as the hard working people
  that maintain machine-learning libraries and you probably would want to use
  their implementations or modify this to be faster and more portable.

Also since we use gnuplot you must be careful and follow their Copywrite when using and
especially if modifying this repository.

In order to keep an easy to read structure, the build process currently features recursive make calls. If you have ever read Peter Miller's ![paper](http://aegis.sourceforge.net/auug97.pdf) it is a potentially slow build structure but it is all for the sake of clarity so please forgive me.
