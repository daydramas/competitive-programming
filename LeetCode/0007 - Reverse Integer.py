class Solution:
    def reverse(self, x: int) -> int:
        neg = bool(x < 0)
        if x < 0:
            x = -x
        y = str(x)
        z = int(y[::-1])
        if neg:
            z = -z
        if z < -2147483648 or z >= 2147483648:
            return 0
        return z
        