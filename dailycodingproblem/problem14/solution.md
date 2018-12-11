The principle of Monte Carlo method is to generate a large number of random points and see how many fall in the circle enclosed by the unit square.

```
PI ≈ 4 * num_inner_points / num_total_points
with R = 1 / 2
```

Since the circle is vertically and horizontally symmetric, calculating on a quarter is good enough.

```C++
double EstimatePi()
{
    int inner = 0, total = 0;
    for (double x = 0; x < 0.5; x += 0.0001)
    {
        for (double y = 0; y < 0.5; y += 0.0001)
        {
            if (4 * (x * x + y * y) <= 1)
                inner++;
            total++;
        }
    }

    return (int)(4000 * (double)inner / total) / (double)1000;
}
```
