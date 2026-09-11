# Erdős #376 — exact carry criterion and a 1,006-digit simultaneous witness

**An exact Kummer-theoretic characterization of `gcd(C(2n,n),105)=1`, together with an explicit 1,006-digit integer above `10^1000` satisfying the equivalent base-3/base-5/base-7 digit restrictions.** The witness is reproduced by two independently written implementations with matching SHA-256.

Author: Jared Wilder. First public timestamp: 2026-09-11. Computation dated 2026-08-31.

## Exact arithmetic criterion

By Kummer's theorem,

`gcd(C(2n,n),105)=1`

if and only if adding `n+n` creates no carry in bases 3, 5, and 7. Equivalently:

- every base-3 digit of `n` is at most 1;
- every base-5 digit of `n` is at most 2;
- every base-7 digit of `n` is at most 3.

The proof is in [`KUMMER-CARRY-CRITERION.md`](KUMMER-CARRY-CRITERION.md).

## The 1,006-digit object

`result_10e1000_primary.txt` contains a 1,006-digit decimal integer, beginning

```text
6648341784810543686763252701549801974897...
```

and ending

```text
...3352330758364059436406195682601857609512
```

It satisfies all three digit restrictions and therefore also satisfies

`gcd(C(2n,n),105)=1`.

## Independent reproduction

Rechecked directly from the committed bytes:

| check | result |
|---|---|
| decimal digits | **1,006** |
| `N >= 10^1000` | **yes** |
| maximum base-3 digit | **1** |
| maximum base-5 digit | **2** |
| maximum base-7 digit | **3** |
| SHA-256 of decimal plus newline | `20b4c56371db6929ffe00d73fd8c2cf7be50f25f9ddbaaa96f7f4f31da2a2847` |
| documented SHA-256 | **identical** |
| independent result file | **agrees digit for digit** |

The two result files come from independently written programs `next376.cpp` and `next376_alt.cpp`; a third implementation is provided in `next376.py`.

The run header records `D=1000 it=11620 sec=18.9143 digits=1006 good=1`.

## Successor method and minimality within the search construction

The search repeatedly jumps to the next member of each of the three digit-restricted sets. The accompanying closure argument shows that if their intersection contains an integer at least a threshold `T`, monotone successor iteration reaches the **least** common member at least `T`.

For `T=10^1000`, both independent implementations arrive at the same committed integer.

Thus the minimality claim is supported by the stated successor-closure argument plus independent implementations; it is not presently a proof-assistant theorem.

## Relation to smaller-range work

This 1,006-digit witness and an exhaustive census through `10^100` are different mathematical objects. The former establishes an explicit very large simultaneous solution; the latter classifies a finite range.

## Reproduce it

The C++ and Python implementations are included. Direct verification only requires arbitrary-precision arithmetic and the digit conditions above. `SHA256SUMS` covers the packet.

## License

Apache-2.0.
