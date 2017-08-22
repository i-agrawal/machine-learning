# About the Repository

This repository is currently a work in progress and aims to implement and explain
  concepts of machine learning with examples and implementations.  
The visualization is thanks to the great program gnuplot which you can install
  using your system's package manager like homebrew on Mac, apt on Debian, yum
  on Redhat, Chocolatey on windows, etc.

# Machine Learning

Machine learning is a type of artifical intelligence that allows
  a computer to learn to do a task instead of being explicitly
  programmed to.  

For example, let us say we are trying to detect if there is an orange
  in a given picture.  
Normally we would have the computer look for a solid orange circle,
  which is the same as explicitly telling the computer how to detect
  an orange.  
The machine learning way would be to get a bunch of pictures of oranges
  and non-oranges. Then we show the computer one picture at a time
  and have our computer guess if a picture is an orange or not. Depending
  on whether the guess was correct or not, the computer changes the way
  it guesses a bit. Eventually the computer will be accurate at detecting
  oranges even though we never directly told it "look for orange blobs".  

The machine learning example is simplified but it is what
  people actually do in practice to detect objects that are more
  complex than an orange like birds, cars, and human faces.  
There are different parts of the machine learning example that were
  important and I would like to explain them.  

First of all, in the example, we gathered a bunch of pictures of
  oranges and non-oranges. This collection of images is what
  people refer to as data.  
Data is the information used to train our computer for whatever
  we want it to learn.  
For example, if we switched from pictures of orange and non-oranges
  to pictures of birds and non-birds then the computer in the example
  would have learned to detect birds rather than oranges.  
How data is fed to our computer is important and will be discussed
  later in the repository.  

After collecting the pictures for data, we had our computer guess
  if the picture was correct or not. In this part, the computer
  would change how it guessed based on if it got the last guess
  right or not. This is called training and is when the computer
  actually learns.  
There are many different ways for a computer to learn and they
  are different machine learning algorithms which we will get to
  later. Some examples are regression, neural networks, and
  support vector machines.  
These different machine learning algorithms are generally grouped
  into two categories, supervised and unsupervised. Although we will
  go over them later just know a general difference. In supervised. the
  correct answer is provided with every example and we use the correct
  answers to get the computer to learn something. In unsupervised, the
  computer is not trying to guess a correct answer, rather the computer
  is trying to find some underlying structure in the data like groupings
  or finding anomalies in the data.  

Finally, after our computer is good enough at detecting oranges on our
  the data of our provided pictures, we will stop the training and do
  validation and testing.  
This is an important topic which we will get into later as well.  

That is all for this part of the repository. Happy Learning!
