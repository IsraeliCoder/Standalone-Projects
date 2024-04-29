

import numpy as np

from nystrom_approximation import NystromApproximation
from graph import Graph
import random
random.seed(250892)

from mds import MDS, landmark_MDS
import matplotlib.pyplot as plt


def print_matrix(M):

    for arr in M:
        print(arr)

    print("\n\n")

graph = Graph(20, 3)
distance_graph = graph.get_distance_matrix()

if True:
    lands = np.array([0, 1, 2, 3, 4, ],dtype=int)

    x2 = landmark_MDS(np.array(distance_graph)[lands, :], lands= lands, dim=2)
    plt.figure()
    colors = ['navy', 'turquoise', 'darkorange']


    plt.scatter(x2[:,0], x2[:,1], alpha=.8)
    plt.legend(loc='best', shadow=False, scatterpoints=1)
    plt.title('MDS of IRIS dataset')
    plt.show()

    exit()

print("Distance Matrix")
print_matrix(distance_graph)

nystrom = NystromApproximation([arr[:5] for arr in distance_graph[:5]], [arr[5:] for arr in distance_graph[:5]])

print("A")
print_matrix(nystrom.A)

print("B")
print_matrix(nystrom.B)

nystrom.calculateC()
print("C result")
print_matrix(nystrom.C)

X,Y = nystrom.calculateXY()

#print(2)

#exit()

K = nystrom.get_full_matrix()
print("K matrix")
print_matrix(K)

def euclidean_dist_from_gram(gram):
    temp = np.tile(np.diag(gram), (nystrom.m + nystrom.k,1))
    return temp + temp.T - 2*gram

g = np.tile(np.expand_dims(np.diag(K), 0), np.array([len(K),1]))
euclidean_dist = g + np.transpose(g) - 2*np.array(K)

print_matrix(euclidean_dist_from_gram(np.array(K)).tolist())
