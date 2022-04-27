Think it like this way:
Each pair element can be treated as a NODE in graph.
Given Pair: [u,x] [x,y] [y,v]
​
If we consider above pair, then can you say that u->x->y->v WILL form a connected component in the graph??
Now, as per question, CHAR at these places, can be swapped any number of time. Out of all the possibility, can you guess which will give the lexicographically smallest string??
Ans-> If we consider that above pair map to char set {y,z,x,a} in original string, then just sort the {y,z,x,a} => {a,x,y,z} <= This is the best swap we can do to generate lexicographically smallest string.
​
....
We will do above for all the connected component, then in final we have our answer.
...
Few Points to note:
[0,3] [0,3] <= Duplicated pair are allowed
[0,3] [3,0] <= reverse pair also allowed
make sure when creating the graph, you do not add extra edges for above cases.