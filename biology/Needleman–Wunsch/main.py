

from ScoreFunction import ScoreFunction

# DNA BASE = AGCT


# S = AA -> S' = A-A
# T = ATA-> T' = ATA

# S =  AAAATA -> S' = -A
# T = BBAAACA -> T' = BB
# F = { gap = -10, missmatch - 1, match = 2 }


memory = {}


# 3 ^ (S+T)
def best_match(S: str, T: str, F: ScoreFunction):

    if S in memory:

        if T in memory[S]:

            return memory[S][T]

    if S == "":
        return len(T) * F.gap, "-" * len(T), T
    if T == "":
        return len(S) * F.gap, S, "-" * len(S)

    s = S[-1]
    t = T[-1]

    # s, -

    score_s_and_gap, s_s_and_gap, s_t_and_gap = best_match(S[:-1], T, F)
    score_s_and_gap += F.gap
    # t, -

    score_t_and_gap, t_s_and_gap, t_t_and_gap = best_match(S, T[:-1], F)
    score_t_and_gap += F.gap

    # t, s

    score_normal, s_normal, t_noraml = best_match(S[:-1], T[:-1], F)
    score_normal += F.score(s, t)

    arr = [score_s_and_gap, score_t_and_gap, score_normal]
    idx = arr.index(max(arr))

    to_return = (0, "", "")
    if idx == 0:
        to_return = (score_s_and_gap, s_s_and_gap + s, s_t_and_gap + "-")
    if idx == 1:
        to_return = (score_t_and_gap, t_s_and_gap + "-", t_t_and_gap + t)
    if idx == 2:
        to_return = (score_normal, s_normal + s, t_noraml + t)

    if S not in memory:
        memory[S] = {}

    memory[S][T] = to_return
    return to_return


fun = ScoreFunction(-3, -1, 1)

S = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
T = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

print(best_match(S, T, fun))

