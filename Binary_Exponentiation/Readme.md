Binary exponentiation (also known as exponentiation by squaring ) is a trick which allows to calculate a^n using only O(log(n)) multiplications (instead of O(n) multiplications required by the naive approach).

It also has important applications in many tasks unrelated to arithmetic, since it can be used with any operations that have the property of associativity : 

(X.Y).Z = X.(Y.Z)

Most obviously this applies to modular multiplication, to multiplication of matrices and to other problems.