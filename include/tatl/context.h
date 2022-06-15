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

#ifndef TATL_CONTEXT_
#define TATL_CONTEXT_

#include <time.h>

/* Hold the tests that a Tatl should complete along with data about the Tatl
 * context
 */
struct tatl_context {
  /* Muting a Tatl context disables any output that the context may produce. */
  int _mute;
  /* Set to failing if any tests within the test queue fail */
  int _exit_code;
  /* The total number of tests that have been run */
  size_t _total;
  /* The total number of passing tests that have been run */
  size_t _passed;
  /* The total number of failing tests that have been run */
  size_t _failed;
  /* The number of names of tests within the test queue */
  size_t _names_size;
  /* The number of tests within the test queue  */
  size_t _tests_size;
  /* A timer to track the length of a test or group of tests */
  clock_t _timer;
  /* The Tatl context's tag */
  char *_tag;
  /* The names of tests within the test queue */
  const char **_names;
  /* The test queue */
  int (**_tests)(void);
};

#ifdef __cplusplus
extern "C" {
#endif

/* Initialise a Tatl context with safe defaults */
void tatl_new(struct tatl_context *);
/* Clean up any resources that the Tatl context is using
 *
 * Called automatically by tatl_finish
 */
void tatl_destroy(struct tatl_context);
/* Summarise a Tatl context's test results
 *
 * Called automatically by tatl_finish
 */
void tatl_summary(struct tatl_context);
/* Add a test to the Tatl context's test queue */
void tatl_add(struct tatl_context *, const char *, int (*)(void));
/* Run all tests within the Tatl context's test queue
 *
 * Called automatically by tatl_finish
 */
void tatl_run(struct tatl_context *);
/* A comprehensive collection of tasks that calls many of the "finishing" Tatl
 * operations
 *
 * Calls tatl_run, tatl_summary, and tatl_destroy---in that order
 */
void tatl_finish(struct tatl_context *);

#ifdef __cplusplus
}
#endif

#endif /* TATL_CONTEXT_ */
