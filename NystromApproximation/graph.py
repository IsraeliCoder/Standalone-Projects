
import copy
import random
from typing import List


class Node:

    def __init__(self, index: int):

        self.neighbours = []
        self.id = index


class Graph:

    def __init__(self, number_of_nodes: int, max_neighbours: int):

        self.number_of_nodes = number_of_nodes
        self.nodes = [Node(i) for i in range(number_of_nodes)]
        for node in self.nodes:

            temp_number_of_connections = random.randint(2, max_neighbours)
            for _ in range(len(node.neighbours), temp_number_of_connections):

                neighbours = self.nodes[random.randint(0, number_of_nodes - 1)]

                while (neighbours in node.neighbours) or neighbours == node:
                    neighbours = self.nodes[random.randint(0, number_of_nodes - 1)]

                # adding edge for both nodes
                node.neighbours.append(neighbours)
                neighbours.neighbours.append(node)

    def __get_distance_matrix_helper__(self, distance_matrix: List[List[int]], index: int):

        starting_node = self.nodes[index]
        distance = 1
        neighbours = copy.copy(starting_node.neighbours)
        next_neighbours = []

        all_nodes = set()
        all_nodes.add(starting_node)

        while neighbours:

            for node in neighbours:

                if node not in all_nodes:
                    all_nodes.add(node)

                    distance_matrix[index][node.id] = distance_matrix[node.id][index] = distance

                    for _node in node.neighbours:
                        if _node not in all_nodes:
                            next_neighbours.append(_node)

            neighbours = next_neighbours
            next_neighbours = []
            distance += 1

    def get_distance_matrix(self) -> List[List[int]]:

        n = self.number_of_nodes
        distance_matrix = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n):

            self.__get_distance_matrix_helper__(distance_matrix, i)

        return distance_matrix





