# agora
N villagers visit the market (agora) every xi days (i has value 0-(N-1)).
What is the soonest when villagers from all villages will meet with only one village at most unrepresented.

The program reads (input) in the form of a file .
Input:
File : 1st line has N number of villages , 2nd line has xi the days that pass inbetween visits to the market for each village (ex. village 0 visits the market every x0 days).
Solution:
2 lists are created that have as their i-th element either the lcm of all villages before village i or after village i, of which 2 we find the lcm , aka next meeting day of all villages except the i-th.Of these we find the least lcm.
The lcm is calculated with the help of gcd (greatest common divident).
Output:
Next meeting day , number of village missing from the meeting
