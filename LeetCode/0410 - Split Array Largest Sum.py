class Solution:
    def splitArray(self, a: List[int], m: int) -> int:
        n = len(a)
        def find(x: int):
            ret = 0
            cur = 0
            for i in a:
                if cur + i > x:
                    ret += 1
                    cur = i
                else:
                    cur += i
            return ret + 1
        lower = max(a)
        upper = max(a) * n
        answer = -1
        while lower <= upper:
            middle = (lower + upper) // 2
            if find(middle) > m:
                lower = middle + 1
            else:
                answer = middle
                upper = middle - 1
        return answer
        