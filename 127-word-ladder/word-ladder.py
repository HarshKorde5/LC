class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or beginWord == endWord:
            return 0

        m = len(wordList[0])
        
        wordSet = set(wordList)

        qb, qe = deque([beginWord]), deque([endWord])
        fromBegin, fromEnd = {beginWord:1}, {endWord:1}

        while qb and qe:
            if len(qb) > len(qe):
                qb, qe = qe, qb
                fromBegin, fromEnd = fromEnd, fromBegin

            for _ in range(len(qb)):
                word = qb.popleft()
                steps = fromBegin[word]

                for i in range(m):
                    for c in range(97, 123):
                        if chr(c) == word[i]:
                            continue

                        neighbor = word[:i] + chr(c) + word[i + 1:]

                        if neighbor not in wordSet:
                            continue
                        if neighbor in fromEnd:
                            return steps + fromEnd[neighbor]

                        if neighbor not in fromBegin:
                            fromBegin[neighbor] = steps  + 1
                            qb.append(neighbor)

        return 0