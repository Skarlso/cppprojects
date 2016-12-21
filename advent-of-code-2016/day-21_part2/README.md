# Day 21.

TIL: NEVER user boost::split in loops.

With split in loops:

```bash
time ./solution input.txt abcdefgh fbgdceah
Found: hegbdcfa
./solution input.txt abcdefgh fbgdceah  26.94s user 0.06s system 99% cpu 27.106 total
```

Without split in loops:

```bash
time ./solution input.txt abcdefgh fbgdceah
Found: hegbdcfa
./solution input.txt abcdefgh fbgdceah  1.59s user 0.01s system 99% cpu 1.604 total
```
