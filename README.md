<h1 align="center">Tatl</h1>
<p align="center"><b>Tiny Test Framework for C89</b></p>

## Usage

For simply C++ integration, checkout [Tael](https://github.com/Fuwn/tael)!

### Complex

Tatl can be used via it's included testing context and utilities.

An example of this method of using Tatl can be seen in
[`examples/addition.c`](examples/addition.c).

### Macro

Tatl can be used via an included set of utility macros.

```c
#include <tatl/macros.h>

TATL_TEST(addition_works) { return TATL_IS(2 + 2, 4); }

int main(void) {
  TATL_NEW();
  TATL_ADD("add works", addition_works);
  TATL_FINISH();

  return 0;
}
```

The output with the previous example:

```shell
running 4 tests
dummy ... ok (0ms)
add works ... ok (0ms)
dummy long ... ok (0ms)
should fail ... FAILED (0ms)

test result: FAILED. 3 passed (4 steps); 1 failed (0ms)

```

## Examples

More examples can be found in the [`examples/`](examples) directory.

## License

This project is licensed with the [GNU General Public License v3.0](LICENSE).
