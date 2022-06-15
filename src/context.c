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

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include <tatl/context.h>

void tatl_new(struct tatl_context *context) {
  context->_mute = 0;
  context->_exit_code = 0;
  context->_total = 0;
  context->_passed = 0;
  context->_failed = 0;
  context->_names_size = 0;
  context->_tests_size = 0;
  context->_timer = clock();
  context->_tag = malloc(1 * sizeof(char));
  context->_names = malloc(1 * sizeof(char *));
  context->_tests = malloc(1 * sizeof(int (*)(void)));
}

void tatl_destroy(struct tatl_context context) {
  free(context._tag);
  free(context._names);
  free(context._tests);
}

void tatl_summary(struct tatl_context context) {
  if (!context._mute) {
    printf("test result: %s. %zd passed (%zd steps); %zd failed (%ldms)\n",
           context._total == context._passed ? "ok" : "FAILED", context._passed,
           context._total, context._failed,
           (clock() - context._timer) * 1000 / CLOCKS_PER_SEC);
  }
}

void tatl_add(struct tatl_context *context, const char *const tag,
              int (*test)(void)) {
  context->_names_size += 1;
  context->_tests_size += 1;
  context->_names =
      realloc(context->_names, (strlen(tag) + 1) * sizeof(char *));
  context->_tests =
      realloc(context->_tests, (sizeof(test) + 1) * sizeof(int (*)(void)));
  /* context->names[context->names_size - 1] = (char *)strdup(tag); */
  context->_names[context->_names_size - 1] = tag;
  context->_tests[context->_tests_size - 1] = test;
}

void tatl_run(struct tatl_context *context) {
  size_t i;

  if (!context->_mute) {
    char *tag = malloc(strlen(context->_tag));
    size_t tag_length;

    strcpy(tag, context->_tag);

    tag_length = strlen(tag);

    printf("running %zd tests%s%s\n", context->_tests_size,
           tag_length > 0 ? " from " : "", tag_length > 0 ? tag : "");

    free(tag);
  }

  for (i = 0; i != context->_names_size; ++i) {
    clock_t timer = clock();
    int test_result = context->_tests[i]();

    context->_total += 1;

    if (test_result == 1) {
      context->_passed += 1;
    } else {
      context->_failed += 1;
      context->_exit_code = 1;
    }

    if (!context->_mute) {
      printf("%s ... %s (%ldms)\n", context->_names[i],
             test_result == 1 ? "ok" : "FAILED",
             (clock() - timer) * 1000 / CLOCKS_PER_SEC);
    }
  }
}

void tatl_finish(struct tatl_context *context) {
  tatl_run(context);

  if (!context->_mute) {
    printf("\n");
  }

  tatl_summary(*context);
  tatl_destroy(*context);

  if (!context->_mute) {
    printf("\n");
  }
}
