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

#ifndef TATL_MACROS
#define TATL_MACROS

#include <tatl/context.h>

/* Shorthand for creating and initialising a new Tatl context with safe defaults
 *
 * Creates a new tatl_context and calls tatl_new on that context
 */
#define TATL_NEW()                                                             \
  struct tatl_context __context;                                               \
                                                                               \
  __context._total = 0;                                                        \
                                                                               \
  tatl_new(&__context)

/* Shorthand for tatl_finish */
#define TATL_FINISH() tatl_finish(&__context)

/* Shorthand for tatl_add */
#define TATL_ADD(tag, test) tatl_add(&__context, tag, test)

/* Define and name a test */
#define TATL_TEST(reference)                                                   \
  int reference(void);                                                         \
                                                                               \
  int reference(void)

/* Access the Tatl macro context */
#define TATL_CONTEXT __context

/* Evaluate two values' equality */
#define TATL_IS(a, b) (a == b)

#endif /* TATL_MACROS */
