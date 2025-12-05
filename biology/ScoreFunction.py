
class ScoreFunction:

    def __init__(self, miss_match: int, gap: int, match: int):

        self.miss_match = miss_match
        self.gap = gap
        self.match = match

    def score(self, s : str, t : str):

        if s == "-" or t == '-':
            return self.gap
        if s == t:
            return self.match

        return self.miss_match
