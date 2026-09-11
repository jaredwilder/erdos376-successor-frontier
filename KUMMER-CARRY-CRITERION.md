# Erdős #376 — exact Kummer carry criterion

Author: Jared Wilder. Public release: 2026-09-11.

## Theorem

Because `105=3*5*7`,

`gcd(C(2n,n),105)=1`

if and only if adding `n+n` creates no carry in bases 3, 5, and 7.

Equivalently:

- every base-3 digit of `n` is at most 1;
- every base-5 digit of `n` is at most 2;
- every base-7 digit of `n` is at most 3.

## Proof

Kummer's theorem says that `v_p(C(2n,n))` equals the number of carries when adding `n+n` in base `p`.

Thus `p` does not divide `C(2n,n)` exactly when the doubling has no base-`p` carry. A digit `d` doubles without carry precisely when

`2d<p`,

or `d<=(p-1)/2`.

Apply this for `p=3,5,7`. Since 105 is squarefree, avoiding all three prime divisors is equivalent to coprimality with 105.

## Relation to the successor computation

This theorem explains exactly why the repository's simultaneous digit restrictions are the arithmetic condition relevant to the central binomial coefficient. The 1,006-digit object in the repository is therefore an explicit `n` satisfying

`gcd(C(2n,n),105)=1`.

The theorem is an exact reformulation of the divisibility condition. Questions about infinitely many such integers or their distribution require additional arguments.
