# JSPACE #376 — Successor-Closure Frontier

**Date:** 2026-08-31  
**Problem:** Erdős #376  
**Claim class:** exact finite computation + elementary minimality theorem  
**Does this solve #376?** **No.**

## Headline

A successor-closure algorithm computes the exact least integer satisfying the three Kummer no-carry conditions above an arbitrary threshold, without enumerating all earlier solutions.

Applied at the threshold `10^1000`, two independent C++ implementations return the same **1006-digit** integer after exactly **11,620 monotone jumps**.

The public July-2026 exhaustive report counted all solutions only through `10^100`; this therefore moves the explicit threshold frontier by 900 decimal orders of magnitude. This is a finite computational extension, not an infinitude proof.

## Mathematical reduction

By Kummer's theorem,

`gcd(C(2n,n),105)=1`

iff all base-3 digits of `n` are in `{0,1}`, all base-5 digits are in `{0,1,2}`, and all base-7 digits are in `{0,1,2,3}`.

Let `S_b` be one of those restricted-digit sets, and define

`succ_b(x) = min { n >= x : n in S_b }`.

Define

`F(x) = max(succ_3(x), succ_5(x), succ_7(x))`.

Starting from `x_0 = T`, iterate `x_{j+1}=F(x_j)`.

### Successor-closure theorem

If `S_3 ∩ S_5 ∩ S_7` contains some integer `y >= T`, the iteration terminates, and its terminal fixed point is the **least** common member at least `T`.

**Proof.** For any common member `y >= x_j`, each `succ_b(x_j) <= y`, hence `x_{j+1} <= y`. Thus every iterate is bounded by the least common member `y_* >= T`. The sequence is monotone nondecreasing and integer-valued, so it stabilizes. At a fixed point `x`, each successor is both `>=x` and `<=F(x)=x`, hence all equal `x`; therefore `x` lies in all three sets. Since all iterates are `<=y_*`, the terminal point equals `y_*`. QED.

This theorem is general for finite intersections of subsets of a well-ordered discrete set when exact successor oracles are available.

## Result at `10^1000`

The least common admissible integer at or above `10^1000` is the decimal integer stored verbatim in `result_10e1000_primary.txt` and `result_10e1000_independent.txt`.

Summary:

- threshold: `10^1000`
- successor jumps: `11,620`
- decimal digits: `1,006`
- ratio to threshold: approximately `664834.178481054368676325270155`
- SHA-256 of `decimal + "\n"`:
  `20b4c56371db6929ffe00d73fd8c2cf7be50f25f9ddbaaa96f7f4f31da2a2847`

Independent direct checks:

- base 3: 2,109 digits, maximum digit 1
- base 5: 1,440 digits, maximum digit 2
- base 7: 1,191 digits, maximum digit 3
- Legendre valuation of `C(2n,n)` at 3: 0
- Legendre valuation at 5: 0
- Legendre valuation at 7: 0

## Independent implementations

`next376.cpp` uses a carry-back digit rounding successor.

`next376_alt.cpp` independently implements the one-base successor as lexicographic digit-DP/backtracking.

For threshold `10^1000`, both report:

- exactly 11,620 iterations;
- the exact same 1006-digit terminal integer.

`next376.py` is a small readable reference implementation. It was brute-checked for every threshold through 20,000 against literal enumeration and reproduces the published beginning of OEIS A030979 term-for-term.

## Prior-art boundary

Known/public before this run:

- classical Kummer digit characterization;
- OEIS A030979, with public table complete through `10^70`;
- a July-2026 exhaustive cylinder-tree report proving `A(10^100)=14273` and extending the explicit table through that cutoff.

The searches performed in this run did **not** locate this successor-closure operator applied to #376 or a published least common admissible value above `10^1000`.

This is therefore best described as **candidate new finite computational progress**, pending outside replication / literature discovery. It must not be described as a solution of Erdős #376.

## Reproduce

Build and run primary:

```bash
g++ -O3 -march=native -std=c++20 next376.cpp -o next376
./next376 1000
```

Independent implementation:

```bash
g++ -O3 -march=native -std=c++20 next376_alt.cpp -o next376_alt
./next376_alt 1000
```
