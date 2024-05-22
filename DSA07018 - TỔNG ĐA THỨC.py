class Monomial:
    def __init__(self, string):
        self.coefficient, self.exponent = map(int, string.split("*x^"))
    def __add__(self, other):
        if isinstance(other, Monomial) and self.exponent == other.exponent:
            return Monomial(f"{self.coefficient + other.coefficient}*x^{self.exponent}")
        return None
    def __str__(self):
        return f"{self.coefficient}*x^{self.exponent}"
class Polynomial:
    def __init__(self, string=""):
        self.terms = {}
        if string:
            for term in string.split(" + "):
                monomial = Monomial(term)
                self.terms[monomial.exponent] = self.terms.get(
                    monomial.exponent, 0) + monomial.coefficient
    def __add__(self, other):
        result = Polynomial()
        for exponent, coefficient in self.terms.items():
            result.terms[exponent] = coefficient
        for exponent, coefficient in other.terms.items():
            result.terms[exponent] = result.terms.get(
                exponent, 0) + coefficient
        return result
    def __str__(self):
        terms = [f"{coefficient}*x^{exponent}" for exponent,
                 coefficient in sorted(self.terms.items(), reverse=True)]
        return " + ".join(terms)
def main():
    t = int(input())
    for _ in range(t):
        input1 = input()
        p1 = Polynomial(input1)
        input2 = input()
        p2 = Polynomial(input2)
        print(p1 + p2)
if __name__ == '__main__':
    main()