Let's look at the constraints of this problem. The length of the equation will be at most 10.
Let's look at the constraints of this problem. The length of the equation will be at most 10.
So in how many ways can we put 2 brackets such that they are separated by the '+'?
If you do some simple maths you can understand that this problem can be done by a simple brute force.
Heres what we are gonna do.
​
Find the index of the +, let's call it idx
Start from index 0 till idx-1, since we can put bracket before the numbers.
Similarly iterate from idx+1 till the end, keeping track of the final result.
Let's see the code to make it more clear.