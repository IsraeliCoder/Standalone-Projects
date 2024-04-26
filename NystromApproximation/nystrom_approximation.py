
from typing import List

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

        self.__setA__(A)
        self.__setB__(B)

    def __setA_helper__(self, i: int, j: int) -> float:

        result = self.E[i][j]

        result -= (1.0 / float(self.m)) * sum_matrix_vertical(self.E, j, self.m)
        result -= (1.0 / float(self.m)) * sum_matrix_horizontal(self.E, i, self.m)

        result += (1.0 / float(self.m ** 2)) * sum_matrix(self.E, self.m)

        return -0.5 * result

    def __setA__(self, A: List[List[float]]):

        for i in range(self.m):
            for j in range(self.m):
                A[i][j] = self.__setA_helper__(i, j)

    def __setB_helper__(self, i: int, j: int) -> float:

        result = self.F[i][j]

        result -= (1.0 / float(self.m)) * sum_matrix_vertical(self.F, j, self.m)
        result -= (1.0 / float(self.m)) * sum_matrix_horizontal(self.E, i, self.m)

        result += (1.0 / float(self.m ** 2)) * sum_matrix(self.E, self.m)

        return -0.5 * result

    def __setB__(self, B: List[List[float]]):

        for i in range(self.m):
            for j in range(self.k):
                B[i][j] = self.__setB_helper__(i, j)

