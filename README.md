# RSA Factoring Challenge

## Tasks

### [factorize.c](./factorize.c)
This program attempts to factorize a number into a product of two smaller integers.

- **Usage**: `factorize <file>`
  - `<file>`: A file containing natural numbers (one number per line) to factorize.
  - The program will factorize each number into two factors: `p` and `q`.
  - It is assumed that:
    - All lines contain valid natural numbers greater than 1.
    - No extra spaces or empty lines are present.
    - The file ends with a newline.

- **Output Format**: `n = p * q`
  - Each line will output the factorization of the number in the format:
    ```
    n = p * q
    ```
  - `p` and `q` do not need to be prime numbers.

---

### [rsa_factorize.c](./rsa_factorize.c)
This task focuses on finding two prime numbers that are factors of an RSA modulus `n`.

- **Usage**: `rsa_factorize <file>`
  - `<file>`: A file containing a single RSA modulus number `n`.
  - The program will find the prime factors `p` and `q` such that:
    ```
    n = p * q
    ```
  - It is assumed that the input file contains only one valid RSA modulus.

- **Output Format**: `n = p * q`
  - The output will follow the format:
    ```
    n = p * q
    ```
  - Both `p` and `q` must be prime numbers.

---

### Notes
- Ensure that the input file is formatted correctly, as described.
- Performance may vary based on the size of `n`, especially for RSA modulus factorization, as it involves prime factorization.