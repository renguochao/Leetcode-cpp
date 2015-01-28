Given a list of non negative integers, arrange them such that they form the largest number.
For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.

Key point in this problem: using this compare method
to sort the vector containing the input num
in this problem, to generate the largest formed number
we need to compare two numbers to determine which number should be 
positioned before another one.
for example: 30 and 34, we need to compare 3034 with 3430,
then we found that 3430 > 3034. 
According the above example, we can find some tricky point 
just concatenate two numbers, and find the greatest result.
