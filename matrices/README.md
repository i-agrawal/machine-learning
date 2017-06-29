# Matrices and Machine Learning

Machine learning is tied to linear algebra and matrices.  
Although this may seem like a complicated subject it actually is pretty simple.


       lets look at linear regression as an example
       we have some points


     4 |      o
     3 |
     2 |    o
     1 |  o
     0 |_ _ _ _ _
        0 1 2 3 4

       as you can see they are (1, 1), (2, 2), (3, 4)
       and we want to try to make a line of y = mx + b that goes through them
       we don't know the best line just from looking so we will guess y = x + 1


     4 |      /
     3 |    /
     2 |  /
     1 |/ o
     0 |_ _ _ _ _
        0 1 2 3 4

       and it hits 2 points... but how do we know that?
       we plug in the x values of all the points (i.e. 1, 2, and 3)
       and our line gives us (1, 2), (2, 3), and (3, 4)

       the problem is we had to calculate those all one by one
       and thats where matrixes come in

       lets make a matrix of all the x values

         ┌   ┐
         │ 1 │
         │ 2 │
         │ 3 │
         └   ┘

       and before you say ew gross a matrix
       look at the magic that happens when we plug it into
       our y = x + 1 equation

         1   *   x    +    1    =    y
               ┌   ┐     ┌   ┐     ┌   ┐
               │ 1 │     │ 1 │     │ 2 │
         1   * │ 2 │  +  │ 1 │  =  │ 3 │
               │ 3 │     │ 1 │     │ 4 │
               └   ┘     └   ┘     └   ┘

        and we got all the values in one go.
        To humans it basically looks exactly the same
        but is different to a computer. There are a lot
        of really fast ways to multiply matrices.

        And there is even more. Lets say we try y = x + 1
        one more time in a different way:

          [ x  1 ]  *  [ m b ]  =    y
          ┌      ┐      ┌   ┐      ┌   ┐
          │ 1  1 │      │ 1 │      │ 2 │
          │ 2  1 │  +   │ 1 │   =  │ 3 │
          │ 3  1 │      └   ┘      │ 4 │
          └      ┘                 └   ┘

        Now you probably don't understand what happened.
        But you can see that the left matrix is our x values
        with a bunch of ones.
        The middle matrix is our m and b from y = mx + b.
        And the y is the same answer we got above.
        The way matrix multiplication works is below:

             ┌      ┐
          →  │ 1  1 │      Each one of these is a row
          →  │ 2  1 │
          →  │ 3  1 │
             └      ┘

               ↓  ↓
             ┌      ┐
             │ 1  1 │      Each one of these is a column
             │ 2  1 │
             │ 3  1 │
             └      ┘

             Overall there are 3 rows and 2 columns
             So this is a 3x2 matrix.
             Multiplication does this:
             it does 1st row * 1st column and adds it altogether
             all into the spot 1, 1 like below

             ┌      ┐      ┌   ┐      ┌     ┐
             │ *1  1* │      │ *1* │    │ 1*1 + 1*1 │
             │ 2  1 │  +   │ *1* │   =  │     │
             │ 3  1 │      └   ┘      │     │
             └      ┘                 └     ┘


        (0, 1, 10), (2, -1, 7), (4, -3, 2)

        and we guess some random line z = 3x + 5y + 6
        now we could calculate each one by hand or:


          [ x   y   1 ]  *  guess  =    z
          ┌           ┐     ┌   ┐     ┌    ┐
          │ 0   1   1 │     │ 3 │     │ 11 │
          │ 2  -1   1 │  *  │ 5 │  =  │  7 │
          │ 4  -3   1 │     │ 6 │     │  3 │
          └           ┘     └   ┘     └    ┘

        now you probably cant tell what is happening
