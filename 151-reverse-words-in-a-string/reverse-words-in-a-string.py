class Solution:
    def reverseWords(self, s: str) -> str:
        x = s.split()
        x.reverse()
        return " ".join(x)
        