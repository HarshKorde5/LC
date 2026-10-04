class Solution:
        #     // can current r,c reach m,n or -1,-1
        # // need to check to ways pacific and atlantic
        # // pacific = has r,c reached {0,0-n} {0-m,0}
        # // atlantic = has r,c reached {m-1, 0-n} {0-m,n-1}
        # // iff both pacific and atlantic is reached then add r,c to result
        # // water can flow iff neighboring cell is less-than-or-equal-to current cell - then dfs()

        # //can we gather cells which contribute to result of reaching both oceans and add them up at once in result so to save compute time?
        
    def pacificAtlantic_tle(self, heights: List[List[int]]) -> List[List[int]]:
        ROWS, COLS = len(heights), len(heights[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        pacific = atlantic = False

        def dfs(r, c, prevVal):
            nonlocal pacific, atlantic
            if r < 0 or c < 0:
                pacific = True
                return
            if r >= ROWS or c >= COLS:
                atlantic = True
                return
            if heights[r][c] > prevVal:
                return

            tmp = heights[r][c]
            heights[r][c] = float('inf')
            for dx, dy in directions:
                dfs(r + dx, c + dy, tmp)
                if pacific and atlantic:
                    break
            heights[r][c] = tmp

        res = []
        for r in range(ROWS):
            for c in range(COLS):
                pacific = False
                atlantic = False
                dfs(r, c, float('inf'))
                if pacific and atlantic:
                    res.append([r, c])
        return res


    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ROWS, COLS = len(heights), len(heights[0])
        pac, atl = set(), set()

        def dfs(r, c, visit, prevHeight):
            if((r,c) in visit or r < 0 or c < 0 or r == ROWS or c == COLS or heights[r][c] < prevHeight):
                return

            visit.add((r,c))
            dfs(r + 1, c, visit, heights[r][c])
            dfs(r - 1, c, visit, heights[r][c])
            dfs(r, c + 1, visit, heights[r][c])
            dfs(r, c - 1, visit, heights[r][c])

        for c in range(COLS):
            dfs(0, c, pac, heights[0][c])
            dfs(ROWS - 1, c, atl, heights[ROWS-1][c])

        for r in range(ROWS):
            dfs(r, 0, pac, heights[r][0])
            dfs(r, COLS-1, atl, heights[r][COLS-1])

        res = []
        for r in range(ROWS):
            for c in range(COLS):
                if (r,c) in pac and (r,c) in atl:
                    res.append([r,c])

        return res