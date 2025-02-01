/*
2. Define a class for rational numbers. A rational number is a number that
can be represented as the quotient of two integers. For example, 1/2, 3/4,
64/2, and so forth are all rational numbers. (By 1/2, etc., we mean the
everyday meaning of the fraction, not the integer division this expression
would produce in a C++ program.) Represent rational numbers as two val-
ues of type int, one for the numerator and one for the denominator. Call
the class Rational.
Include a constructor with two arguments that can be used to set the
member variables of an object to any legitimate values. Also include a
constructor that has only a single parameter of type int; call this single
parameter whole_number and define the constructor so that the object
will be initialized to the rational number whole_number/1. Also include a
default constructor that initializes an object to 0 (that is, to 0/1).
Overload the input and output operators >> and <<. Numbers are to be
input and output in the form 1/2, 15/32, 300/401, and so forth. Note
that the numerator, the denominator, or both may contain a minus
sign, so -1/2, 15/32, and -300/-401 are also possible inputs. Overload
all of the following operators so that they correctly apply to the type
Rational: ==, <, <=, >, >=, +, -, *, and /. Also write a test program to test
your class.
695696
Chapter 11 / Friends, Overloaded Operators, and Arrays in Classes
(Hints: Two rational numbers a/b and c/d are equal if a*d equals
c*b. If b and d are positive rational numbers, a/b is less than c/d
provided a*d is less than c*b. You should include a function to nor-
malize the values stored so that, after normalization, the denomi-
nator is positive and the numerator and denominator are as small
as possible. For example, after normalization 4/-8 would be repre-
sented the same as -1/2. You should also write a test program to test
your class.)
*/