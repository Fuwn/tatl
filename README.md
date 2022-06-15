<h1 align="center">Tatl</h1>
<p align="center"><b>Tiny Test Framework for C89</b></p>

## Usage

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

## Examples

More examples can be found in the [`examples/`](examples) directory.

## License

This project is licensed with the [GNU General Public License v3.0](LICENSE).
