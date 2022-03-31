# Random-Graph-Analyzation
Algorithms 2 course assignment

## Guidelines: the Erdős–Rényi random graph model.

### Task background:
Random graphs can help analyze complex networks and may help us understand how have better control them.
In this model, the number of vertices of a graph is a fixed number, but the creation of the arcs between a pair of nodes depends on a probability threshold.

### Purpose:
Examining the following 3 graph properties: (where V is the number vertices)
#### 1. Connectivity - `Threshold1 = (lnV / V)` :<br>
```
  If Threshold1 < probability -> high probability for the graph [not] to be connected.
  If Threshold1 > probability -> high probability for the graph to be connected.
```
#### 2. Graph Diameter - `Threshold2 =  sqrt(2lnV/V)` :<br>
````
  If Threshold2 > probability -> high probability for the graph's diameter to equal 2,
  Otherwise the diameter of the graph is greater than 2.
````
#### 3. Node Isolation - `Threshold3 = (lnV / V)` :<br>
````
  If Threshold3 < probability -> high probability for the graph to include an isolated node.
  If Threshold3 > probability -> high probability for the graph [not] to include an isolated node.
````
  
### Simulations:
To assert the  graph properties, the following process must be executed:
Choose a list of 10 possible values for probability - 5 smaller and 5 bigger than the property threshold. (for each property).
Genatate 500 random graphs that includes V = 1000 nodesת for each probability values. 5000 graphs in total per property.

### Results:
Some Graphs maintain the properties and some don't, the closer the probability is to the threshold the clearer the property is reflected.
It is worth estimating the probability that a trait exists.
The Results of the simulations can be saved to a file, for example a CSV, and the data collected can be analyzed on that file.

### Research results:
![IsIsolated](https://github.com/nqoy/Random_Graph_Analyzation/blob/main/Isolation.png)

![Diameter](https://github.com/nqoy/Random_Graph_Analyzation/blob/main/Diameter.png)

![Connectivity](https://github.com/nqoy/Random_Graph_Analyzation/blob/main/Connectivity.png)
