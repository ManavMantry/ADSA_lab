# Function Growth Comparison in C

This project demonstrates the **comparison of growth rates** of different mathematical functions using C.  
It evaluates 12 functions over a range of values of `n`, prints their values, and determines their asymptotic ordering using `qsort`.

---

## 📌 Features
- Defines **12 different mathematical functions** (polynomial, logarithmic, exponential, etc.).
- Evaluates them at multiple values of `n` (`2, 4, 8, ..., 1024`).
- Dynamically prints function values for comparison.
- Uses **`qsort`** to order functions based on their growth at large `n`.
- Shows how functions behave as `n` increases.

---

## ⚙️ Functions Defined
1. `n * log2(n)`
2. `12 * sqrt(n)`
3. `1/n`
4. `n^(log2(n))`
5. `100*n^2 + 6*n`
6. `n^0.51`
7. `n^2 - 324`
8. `50*sqrt(n)`
9. `2*n^3`
10. `3^n`
11. `(2^32) * n`
12. `log2(n)`

---

## 🖥️ Code Overview
- **Function Pointers**: An array stores all function references.
- **Struct `FuncVal`**: Used for sorting function values.
- **Sorting**: Implemented with `qsort()` to order functions based on growth at a large value of `n`.

---

## ▶️ Example Output
          Dynamic Growth Comparison:

          n = 2 
          n*log2(n)       = 2.000000e+00
          12*sqrt(n)      = 1.697056e+01
          1/n             = 5.000000e-01
          n^(log2(n))     = 2.000000e+00
          100*n^2+6n      = 4.120000e+02
          n^0.51          = 1.424050e+00
          n^2-324         = -3.200000e+02
          50*sqrt(n)      = 7.071068e+01
          2*n^3           = 1.600000e+01
          3^n             = 9.000000e+00
          2^32*n          = 8.589935e+09
          log2(n)         = 1.000000e+00
          
          n = 4
          n*log2(n)       = 8.000000e+00
          12*sqrt(n)      = 2.400000e+01
          1/n             = 2.500000e-01
          n^(log2(n))     = 1.600000e+01
          100*n^2+6n      = 1.624000e+03
          n^0.51          = 2.027919e+00
          n^2-324         = -3.080000e+02
          50*sqrt(n)      = 1.000000e+02
          2*n^3           = 1.280000e+02
          3^n             = 8.100000e+01
          2^32*n          = 1.717987e+10
          log2(n)         = 2.000000e+00
          
          n = 8
          n*log2(n)       = 2.400000e+01
          12*sqrt(n)      = 3.394113e+01
          1/n             = 1.250000e-01
          n^(log2(n))     = 5.120000e+02
          100*n^2+6n      = 6.448000e+03
          n^0.51          = 2.887858e+00
          n^2-324         = -2.600000e+02
          50*sqrt(n)      = 1.414214e+02
          2*n^3           = 1.024000e+03
          3^n             = 6.561000e+03
          2^32*n          = 3.435974e+10
          log2(n)         = 3.000000e+00
          
          n = 16
          n*log2(n)       = 6.400000e+01
          12*sqrt(n)      = 4.800000e+01
          1/n             = 6.250000e-02
          n^(log2(n))     = 6.553600e+04
          100*n^2+6n      = 2.569600e+04
          n^0.51          = 4.112455e+00
          n^2-324         = -6.800000e+01
          50*sqrt(n)      = 2.000000e+02
          2*n^3           = 8.192000e+03
          3^n             = 4.304672e+07
          2^32*n          = 6.871948e+10
          log2(n)         = 4.000000e+00
          
          n = 32
          n*log2(n)       = 1.600000e+02
          12*sqrt(n)      = 6.788225e+01
          1/n             = 3.125000e-02
          n^(log2(n))     = 3.355443e+07
          100*n^2+6n      = 1.025920e+05
          n^0.51          = 5.856343e+00
          n^2-324         = 7.000000e+02
          50*sqrt(n)      = 2.828427e+02
          2*n^3           = 6.553600e+04
          3^n             = 1.853020e+15
          2^32*n          = 1.374390e+11
          log2(n)         = 5.000000e+00
          
          n = 64
          n*log2(n)       = 3.840000e+02
          12*sqrt(n)      = 9.600000e+01
          1/n             = 1.562500e-02
          n^(log2(n))     = 6.871948e+10
          100*n^2+6n      = 4.099840e+05
          n^0.51          = 8.339726e+00
          n^2-324         = 3.772000e+03
          50*sqrt(n)      = 4.000000e+02
          2*n^3           = 5.242880e+05
          3^n             = 3.433684e+30
          2^32*n          = 2.748779e+11
          log2(n)         = 6.000000e+00
          
          n = 128
          n*log2(n)       = 8.960000e+02
          12*sqrt(n)      = 1.357645e+02
          1/n             = 7.812500e-03
          n^(log2(n))     = 5.629500e+14
          100*n^2+6n      = 1.639168e+06
          n^0.51          = 1.187619e+01
          n^2-324         = 1.606000e+04
          50*sqrt(n)      = 5.656854e+02
          2*n^3           = 4.194304e+06
          3^n             = 1.179018e+61
          2^32*n          = 5.497558e+11
          log2(n)         = 7.000000e+00
          
          n = 256
          n*log2(n)       = 2.048000e+03
          12*sqrt(n)      = 1.920000e+02
          1/n             = 3.906250e-03
          n^(log2(n))     = 1.844674e+19
          100*n^2+6n      = 6.555136e+06
          n^0.51          = 1.691229e+01
          n^2-324         = 6.521200e+04
          50*sqrt(n)      = 8.000000e+02
          2*n^3           = 3.355443e+07
          3^n             = 1.390085e+122
          2^32*n          = 1.099512e+12
          log2(n)         = 8.000000e+00
          
          n = 512
          n*log2(n)       = 4.608000e+03
          12*sqrt(n)      = 2.715290e+02
          1/n             = 1.953125e-03
          n^(log2(n))     = 2.417852e+24
          100*n^2+6n      = 2.621747e+07
          n^0.51          = 2.408395e+01
          n^2-324         = 2.618200e+05
          50*sqrt(n)      = 1.131371e+03
          2*n^3           = 2.684355e+08
          3^n             = 1.932335e+244
          2^32*n          = 2.199023e+12
          log2(n)         = 9.000000e+00
          
          n = 1024
          n*log2(n)       = 1.024000e+04
          12*sqrt(n)      = 3.840000e+02
          1/n             = 9.765625e-04
          n^(log2(n))     = 1.267651e+30
          100*n^2+6n      = 1.048637e+08
          n^0.51          = 3.429675e+01
          n^2-324         = 1.048252e+06
          50*sqrt(n)      = 1.600000e+03
          2*n^3           = 2.147484e+09
          3^n             = inf
          2^32*n          = 4.398047e+12
          log2(n)         = 1.000000e+01
          
          Order of functions by growth
           1/n  < log2(n)  < n^0.51  < 12*sqrt(n)  < 50*sqrt(n)  < n*log2(n)  < n^2-324  < 100*n^2+6n  < 2*n^3  < 2^32*n  < n^(log2(n))  < 3^n
---

## 🚀 Compilation & Execution

### Compile
```bash
Lab01-1_OrderofGrowth.exe
