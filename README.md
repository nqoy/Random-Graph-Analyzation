# Random_Graph_Analyzation

Creation of N randomly generated, undirected graphs with 1000 vertices (vertex connection is formed by a probability threshold).  
Simulation and Investigation of each graph Properties (connectivity, diameter, single vertex) with garph algorithms.  
Writing data into CVS ('1' or '0' for each graph attribute rule).  
Conclusion building and Presentation of the collected data.  



Algoritems 2 assignment.

# Guidelines: the Erdős–Rényi random graph model.

####Task background:
Random graphs can help analyze complex networks and may help us understand how have better control on them.
In this model, the number of vertices of a graph is a fixed number, but the creation of the arcs between a pair of nodes depends on a probability threshold.

#### Purpose of the task:
In this exercise ivcement a function to create random graphs and in addition we will build auxiliary functions that will help to explore features of
The graphs.
We will examine the following 3 properties of random graphs in a graph with V nodes (V is a large enough):

1. connectivity- Threshold1 = (lnV / V) :<br>
  If Threshold1 < probability then the graph does not connected with high probability,
  And if Threshold1 > probability then the graph connected at high probability.

2. graph diameter- Threshold2 =  sqrt(2lnV/V) :<br>
  if Threshold2 > probability then in high probability the graph diameter is equal to 2.
  Otherwise the diameter of the graph is greater than 2.  
  
3.Isolated node- Threshold3 = (lnV / V) :<br>
  If Threshold3 < probability then in high probability there is an isolated node graph
  And if Threshold3 > probability then in high probability does not exist in the graph of an isolated node.
  
# Simulations:

In this section we would like to test the properties of random graphs with the help of simulation.
For each of the 3,2,1 features:<br>
Choose a list of 10 possible values for probability - so that half arrays probability will be larger than the Threshold and half arrays will be
Smaller than it.  (For each of the 3 features)
500 random graphs must be drawn for V = 1000 and for each of the probabilities. Total 5000 per feature (count several)
Graphs maintain the feature and some do not.
It is worth estimating the probability that a trait exists. It is possible to calculate a ratio between the number of graphs that sustain the trait and the quantity
The total of the graphs. Results of simulations can be saved in a file - for example a CSV file. The file can be opened
Then in EXCEL and build graphs to help summarize work results.
