
import pickle
from classesG import Generated1


class Stam(Generated1):

    def __init__(self, name: str, number: int):
        Generated1.__init__(self)
        self.name = name
        self.number = number


obj1 = Stam("Compy", 777)

obj1bin_with_pickle = pickle.dumps(obj1)


def stam_to_bin(obj: Stam):

    to_return = []
    for ch in obj.name:
        to_return.append(ch)

    to_return.append('\0')

    number = obj.number
    for _ in range(4):
        to_return.append(number % 256)
        number /= 256

    return to_return

obj1bin_with_our_serilization = stam_to_bin(obj1)

print(2)
