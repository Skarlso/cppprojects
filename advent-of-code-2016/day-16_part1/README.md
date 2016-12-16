# Day 16 Timing

With loops

```bash
01101011101100011
./solution  1.52s user 0.13s system 99% cpu 1.661 total
```

With recursion

```bash
01101011101100011
./solution  1.50s user 0.14s system 99% cpu 1.655 total
```

I think g++ does tail recursion optimization. Also, I think tail recursion in this case looks much nicer.
