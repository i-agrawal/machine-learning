# Linear Regression

Linear Regression want to do the Following


       we have a bunch of points
       we want to find a line connecting those points
       so we want to get the correct y = mx + b (yes math I am sorry)


       For example we have the following

     4 |        o
     3 |
     2 |    o
     1 |  o
     0 |_ _ _ _ _
        0 1 2 3 4

       as you can see the points are (1, 1), (2,2), and (4,4)
       and we can all tell the line between these points is y = x (like below)

     4 |        /
     3 |      /
     2 |    /
     1 |  /
     0 |/ _ _ _ _
        0 1 2 3 4


        but what if the points aren't on a straight line?

     4 |      o
     3 |
     2 |    o
     1 |o
     0 |_ _ _ _ _
        0 1 2 3 4

       our new points are (0, 1), (2, 2), (3, 4)
       so how are we supposed to get a straight line for that?

       lets start by making a guess for the line like y = x


     4 |      o /
     3 |      /
     2 |    o
     1 |o /
     0 |/ _ _ _ _
        0 1 2 3 4

       turns out that is an decent guess
       but obviously our guess is not perfect

       so just how wrong is our guess?

       well each point has a distance from the line
       and the bigger the distance the worse our answer is
       so lets calculate just how wrong we are

       because our guess is y = x
       we guess at x = 0 that y = 0
       in reality our guess should give us (0, 1)
       so we are off by 1

       we guess at x = 2 that y = 2
       hey our guess is right so our distance is 0
       so far we are off by 1 still

       we guess at x = 3 that y = 3
       and the point is (3, 4) so we are off of by 1.
       so we are in total off by 2

       so basically our error = all the distances of points from our line added together
       but wait, if the point is below our line, we can get a negative distance
       to avoid that, lets square the distance and now it is positive
       so now our error = all the distances of points from our line squared and then added together

       wait a second... that is a function
       it takes in our line and the actual points and returns a number of how wrong our line is
       f(our line, actual points) = sum of (each actual point - our line's guess)^2

       so why does it matter that it is a function?
       a function is a line
       and this line just so happens to have a minimum


     4 |\       /
     3 | \     /
     2 |   \ /
     1 |
     0 |_ _ _ _ _
        0 1 2 3 4

       that is what a y = x^2 graph looks like
       and it always has a bottom
       that is called the minimum
       and that minimum point is when our guess is the least wrong
       and when our guess is the least wrong that must mean
       we found the best answer and the best y = mx + b

       but how do we get to the minimum?
       there is the slow, math, linear algebra way
       and then there is the faster way
       through the math you all know and love, calculus (*cheers everywhere*)
       lets put a point on the y = x^2 graph above


     4 |\       /
     3 |  o    /
     2 |   \ /
     1 |
     0 |_ _ _ _ _
        0 1 2 3 4


       as you can guess the point needs to move to the right
       to reach the minimum
       the reason we know this is the slope is pointing that way
       and how do we get slope of a function
       through derivatives (yay!)

       so we continuously move in the direction pointed by the derivative
       until we reach the minimum
       and we have our answer

And that is how Linear Regression works
The actual implementation follows the same rules
just will go over the actual
