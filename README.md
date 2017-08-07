# About the Repository

This repository is current a work in progress and aims to implement and explain
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
We could have our computer look for orange circles in the picture and
  that would be explicitly programming the computer to detect oranges.  
The machine learning way would be to get a bunch of pictures of oranges
  and non-oranges and have our computer guess if the picture is an
  orange or not. Every guess it learns a little and eventually
  the computer will be accurate at detected oranges even though we
  never directly programmed it to look for oranges.

The machine learning approach is a bit simplified but it is what
  people actually do in practice to detect objects that are more
  complex than an orange like birds, cars, and human faces.  

Now different parts of the example should be explained.  

The bunch of pictures of oranges and non-oranges is called data
  and it is used to train the computer.  
Perhaps one of the most important parts of machine learning, the
  data determines what the computer learns.  
For example, if we switched from pictures of orange and non-oranges
  to pictures of birds and non-birds then the computer in the example
  would have learned to detect birds rather than oranges.  
Data has a bunch of different formats depending on what the data
  represents.  
If the data is simply the age of a person given height and weight
  it would look like  
```
            height (in.)  weight (lbs.)     age
person1         60            120           15
person2         72            155           24
  ...
personlast      67            150           40

```
If the data represents 400x400 black and white pictures of cars it
  would often look like this  
```
           pixel1  pixel2  ...  pixel160000      is_car
image1       18      25             180            1
image2       44      45             100            0
  ...
imagelast    15      20             255            1
```
