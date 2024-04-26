
from nystrom_approximation import NystromApproximation
from graph import Graph
import random
random.seed(250892)


def print_matrix(M):

    for arr in M:
        print(arr)

    print("\n\n")


graph = Graph(20, 3)
distance_graph = graph.get_distance_matrix()

print("Distance Matrix")
print_matrix(distance_graph)

nystrom = NystromApproximation([arr[:5] for arr in distance_graph[:5]], [arr[5:] for arr in distance_graph[:5]])

print("A")
print_matrix(nystrom.A)

print("B")
print_matrix(nystrom.B)


