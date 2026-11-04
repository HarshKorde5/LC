class Solution:
    def taskSchedulerII(self, tasks: list[int], space: int) -> int:
        m = {}
        curr_day = 0

        for task in tasks:
            curr_day += 1

            if task in m and curr_day - m[task] <= space:
                curr_day += space - (curr_day - m[task])  + 1

            m[task] = curr_day

        return curr_day