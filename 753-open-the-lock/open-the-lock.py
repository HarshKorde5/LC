class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if target == "0000":
            return 0

        visit = set(deadends)
        if "0000" in visit:
            return -1

        begin = {"0000"}
        end = {target}

        steps = 0

        while begin and end:
            if len(begin) > len(end):
                begin, end = end, begin

            steps += 1
            temp = set()

            for lock in begin:
                for i in range(4):
                    for j in [-1, 1]:
                        digit = str((int(lock[i]) + j + 10) % 10)
                        nextlock = lock[:i] + digit + lock[i+1:]

                        if nextlock in end:
                            return steps

                        if nextlock in visit:
                            continue
                        
                        visit.add(nextlock)
                        temp.add(nextlock)

            begin = temp

        return -1