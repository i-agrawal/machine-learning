# Matrices and Machine Learning

Machine learning is tied to linear algebra and matrices.  
Although this may seem like a complicated subject it actually is pretty simple.  
I recommend reading the linear regression explanation before this.  


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
       and thats where matrices come in

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
         │ 2  1 │  *   │ 1 │   =  │ 3 │
         │ 3  1 │      └   ┘      │ 4 │
         └      ┘                 └   ┘

       Now you probably don't understand what happened.
       But you can see that the left matrix is our x values
       with a bunch of ones.
       The middle matrix is our m and b from y = mx + b.
       And the y is the same answer we got above.
       The way matrices works is below:

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

       Matrix Multiplication then does this
       it does 1st row * 1st column and adds it altogether
       all into the spot 1, 1 like below

                           ↓
            ┌      ┐     ┌   ┐     ┌           ┐     ┌   ┐
         →  │ 1  1 │     │ 1 │     │ 1*1 + 1*1 │     │ 2 │
            │ 2  1 │  *  │ 1 │  =  │           │  =  │   │
            │ 3  1 │     └   ┘     │           │     │   │
            └      ┘               └           ┘     └   ┘

       and then it would do 2nd row * 1st column and add it together
       all into spot 2, 1 like below

                           ↓
            ┌      ┐     ┌   ┐     ┌           ┐     ┌   ┐
            │ 1  1 │     │ 1 │     │ 1*1 + 1*1 │     │ 2 │
         →  │ 2  1 │  *  │ 1 │  =  │ 2*1 + 1*1 │  =  │ 3 │
            │ 3  1 │     └   ┘     │           │     │   │
            └      ┘               └           ┘     └   ┘

       and then it would do 3rd row * 1st column and add it together
       all into spot 3, 1 like below

                           ↓
            ┌      ┐     ┌   ┐     ┌           ┐     ┌   ┐
            │ 1  1 │     │ 1 │     │ 1*1 + 1*1 │     │ 2 │
            │ 2  1 │  *  │ 1 │  =  │ 2*1 + 1*1 │  =  │ 3 │
         →  │ 3  1 │     └   ┘     │ 3*1 + 1*1 │     │ 4 │
            └      ┘               └           ┘     └   ┘

       and if there was a second column it would do it over again but
       with the 1st row * 2nd column and add it all together in spot 1, 2.
       Anyways if you notice the resulting matrix when rewritten is:

            ┌           ┐     ┌           ┐
            │ 1*1 + 1*1 │     │ 1*m + 1*b │
            │ 2*1 + 1*1 │  =  │ 2*m + 1*b │  =  [ mx + b ]
            │ 3*1 + 1*1 │     │ 3*1 + 1*1 │
            └           ┘     └           ┘

      thats right, this is how matrix multiplication is tied in with
      machine learning. It even works in more dimensions like 3D.
      
      We have the following 3D points in (x, y, z)

       (0, 1, 10), (2, -1, 7), (4, -3, 2)

      and we guess some random line z = 3x + 5y + 6
      now we could calculate each one by hand or:


          [ x   y   1 ]  *  guess  =    z
          ┌           ┐     ┌   ┐     ┌    ┐
          │ 0   1   1 │     │ 3 │     │ 11 │
          │ 2  -1   1 │  *  │ 5 │  =  │  7 │
          │ 4  -3   1 │     │ 6 │     │  3 │
          └           ┘     └   ┘     └    ┘

      and voila, the matrix multiplication works in 3D space.
      And even more uses such as making equations easier.

      like       z = 3x + 5y + 6
      becomes    z = guess * inputs

      and if you read the linear regression explanation we had
      the error function of

      2D         (correct - (mx + b))^2       / (2 * number of points)
      3D         (correct - (ax + by + c))^2  / (2 * number of points)
      now        (correct - guess * inputs)^2 / (2 * rows)

      and for all the math people who know derivatives (others can skip)
      before you needed to take derivatives with respect m and b or
      a, b, and c but now it is simply one equation

      slope      inputs * (guess * inputs - outputs) / rows

      and there are even more reasons to use matrices but I think this
      is good enough.

Hopefully you can see why we are using matrices, not only because computers  
handle them better but they also (sort of) simply the math which we all  
know is for the better.  
