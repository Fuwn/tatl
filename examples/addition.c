/*
 * This file is part of Tatl <https://github.com/Fuwn/tatl>.
 * Copyright (C) 2022-2022 Fuwn <contact@fuwn.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2022-2022 Fuwn <contact@fuwn.me>
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <tatl/tatl.h>

/* Obtain the result of a two number addition operation */
int add(int, int);
int dummy(void);
int add_works(void);
int dummy_long(void);
int dummy_longer(void);
int should_fail(void);

int main(void) {
  struct tatl_context context;

  tatl_new(&context);
  tatl_add(&context, "dummy", dummy);
  tatl_add(&context, "add works", add_works);
  tatl_add(&context, "dummy long", dummy_long);
#ifdef _MSC_VER
  tatl_add(&context, "dummy longer", dummy_longer);
#endif
  tatl_add(&context, "should fail", should_fail);
  tatl_finish(&context);

  return 0;
}

int add(int a, int b) { return a + b; }

int dummy(void) { return 1; }

int add_works(void) { return TATL_IS(add(1, 2), 3); }

int dummy_long(void) {
  int i;

  for (i = 0; i < 100000000; ++i) {
  }

  return 1;
}

int dummy_longer(void) {
  int i;

  for (i = 0; i < 1000000000; ++i) {
  }

  return 1;
}

int should_fail(void) { return TATL_IS(1, 2); }
