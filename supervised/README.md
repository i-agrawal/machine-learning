# Supervised Learning

This README will discuss supervised learning.

      Machine learning algorithms can be largely split into two categories:
      
        Supervised learning and Unsupervised learning
      
      Right now we will start talking about the former, supervised learning.
      Its name kind of gives a hint of how it works.
      In supervised learning you tell the computer what to do from
        the correct answers.
      As an example lets look at the data from the introduction.

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
      
      And now we are supposed to make a line to predict the height of a person
        from their age.
      Now a good way to do that is put a line through the graph.
      You would probably make your line start from the bottom left and end
        at around the top right.
      And you dont even question how we got the same line.
      All we are doing is making a line that is close to the points.

      In machine learning the height of these points is the right or 
        correct answer.
      And the way we made out line was trying to hit the right answers.
      And supervised learning does the same thing, it tries to get the computer
        to make a good line by having it hit the right answers.