
from typing import List
import numpy as np


def sum_matrix_horizontal(M: List[List[int]], i: int, m: int):

    result = 0
    for j in range(m):
        result += M[i][j]

    return result


def sum_matrix_vertical(M: List[List[int]], j: int, m: int):

    result = 0
    for i in range(m):
        result += M[i][j]

    return result


def sum_matrix(M: List[List[int]], m: int):

    result = 0

    for i in range(m):
        for j in range(m):
            result += M[i][j]

    return result


class NystromApproximation:

    def __init__(self, E: List[List[int]], F: List[List[int]]):
        """

        :param E: landmark known matrix m * m
        :param F: landmark to other matrix m * (k = n - m)
        """

        self.E = E
        self.F = F

        self.m = m = len(E)
        self.k = k = len(F[0])

        self.A = A = [[0.0 for _ in range(m)] for _ in range(m)]
        self.B = B = [[0.0 for _ in range(k)] for _ in range(m)]

        self.__setA__()
        self.__setB__()

    def __setA_helper__(self, i: int, j: int) -> float:

        result = self.E[i][j]

        result -= (1.0 / float(self.m)) * sum_matrix_vertical(self.E, j, self.m)
        result -= (1.0 / float(self.m)) * sum_matrix_horizontal(self.E, i, self.m)

        result += (1.0 / float(self.m ** 2)) * sum_matrix(self.E, self.m)

        return -0.5 * result

    def __setA__(self):

        for i in range(self.m):
            for j in range(self.m):
                self.A[i][j] = self.__setA_helper__(i, j)

    def __setB_helper__(self, i: int, j: int) -> float:

        result = self.F[i][j]

        result -= (1.0 / float(self.m)) * sum_matrix_vertical(self.F, j, self.m)
        result -= (1.0 / float(self.m)) * sum_matrix_horizontal(self.E, i, self.m)

        result += (1.0 / float(self.m ** 2)) * sum_matrix(self.E, self.m)

        return -0.5 * result

    def __setB__(self):

        for i in range(self.m):
            for j in range(self.k):
                self.B[i][j] = self.__setB_helper__(i, j)

    def calculateC(self):

        A = np.array(self.A)
        B = np.array(self.B)

        A_INV = np.linalg.pinv(A)

        C = np.matmul(np.matmul(B.T, A_INV), B)
        self.C = C.tolist()

        return self.C

    def calculateXY(self):

        eigen_values, eigen_vectors = np.linalg.eig(np.array(self.A))

        X = np.dot(np.power(eigen_values, 0.5), eigen_vectors.T)
        Y = np.dot(np.dot(np.power(eigen_values, -0.5), eigen_vectors.T), np.array(self.B))

        return X, Y

    def get_full_matrix(self) -> List[List[float]]:

        n = self.m + self.k
        new_arr = [[0.0 for _ in range(n)] for _ in range(n)]

        for i in range(self.m):
            for j in range(self.m):
                new_arr[i][j] = self.A[i][j]

        for i in range(self.m):
            for j in range(self.k):
                new_arr[i][self.m + j] = self.B[i][j]
                new_arr[self.m + j][i] = self.B[i][j]

        for i in range(self.k):
            for j in range(self.k):
                new_arr[self.m + i][self.m + j] = self.C[i][j]

        return new_arr
