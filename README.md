# erdos376-successor-frontier

**An explicit 1,006-digit integer above 10^1000 whose base-3 digits are all ≤ 1, base-5 digits
all ≤ 2, and base-7 digits all ≤ 3 — with two independent implementations and a matching
SHA-256.**

Author: Jared Wilder. First public timestamp: 2026-09-11. Computation dated 2026-08-31.

---

## The object

`result_10e1000_primary.txt` holds a single decimal integer, 1,006 digits long, beginning

```
6648341784810543686763252701549801974897...
```

and ending

```
...3352330758364059436406195682601857609512
```

It is claimed to be the **least** integer at or above 10^1000 that is simultaneously
3-restricted, 5-restricted and 7-restricted in the sense of Erdős 376.

## Verified from scratch, 2026-09-11

Re-checked directly from the committed bytes, with no reliance on the shipped receipts:

| check | result |
|---|---|
| decimal digits | **1,006** |
| N ≥ 10^1000 | **yes** |
| maximum base-3 digit | **1** (must be ≤ 1) |
| maximum base-5 digit | **2** (must be ≤ 2) |
| maximum base-7 digit | **3** (must be ≤ 3) |
| SHA-256 of the decimal plus a newline | `20b4c56371db6929ffe00d73fd8c2cf7be50f25f9ddbaaa96f7f4f31da2a2847` |
| documented SHA-256 | **identical** |
| `result_10e1000_independent.txt` | **agrees digit for digit with the primary** |

The two result files come from **two independently written programs** — `next376.cpp` and
`next376_alt.cpp`, with a third implementation in `next376.py`. They agree.

The run header records the cost: `D=1000 it=11620 sec=18.9143 digits=1006 good=1` — eleven
thousand six hundred and twenty successor jumps, under nineteen seconds.

## The method, and what makes it terminate

The accompanying note states the closure property the search rests on:

> "If `S_3 ∩ S_5 ∩ S_7` contains some integer `y ≥ T`, the iteration terminates, and its terminal
> fixed point is the **least** common member at least `T`."

That is what turns an unbounded search into a finite one: repeatedly jump to the next member of
each restricted set, and the process is monotone and lands on the least common member ≥ T rather
than merely *a* member.

## What is and is not claimed

**Claimed:** this specific 1,006-digit integer satisfies all three digit restrictions, exceeds
10^1000, is reproducible from the shipped source, and is the least such integer at or above
10^1000 *according to the successor closure argument and two agreeing implementations*.

**Not claimed:** an exhaustive enumeration of all solutions below 10^1000. The published
July-2026 exhaustive treatment counted **all** solutions through 10^100; this is a different kind
of statement — a single certified witness far above that range, not a census. Those two should
not be compared as if they were the same quantity.

**Not claimed:** anything about Erdős 376 itself, which remains open. The minimality assertion
rests on the closure argument in the note, which is an argument and not a proof-assistant
theorem.

## Reproduce it

The C++ and Python implementations are both here. The digit checks need nothing but arbitrary
precision integers:

```
max base-3 digit of N  must be <= 1
max base-5 digit of N  must be <= 2
max base-7 digit of N  must be <= 3
```

`SHA256SUMS` ships with the packet and covers every file.

## License

Apache-2.0.
