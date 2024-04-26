
from graph import Graph
import random
random.seed(250892)

graph = Graph(20, 3)
distance_graph = graph.get_distance_matrix()

for arr in distance_graph:
    print(arr)

