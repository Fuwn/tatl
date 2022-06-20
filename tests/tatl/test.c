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

#include <string.h>

#include <tatl/context/get.h>
#include <tatl/context/set.h>
#include <tatl/macros.h>

static struct tatl_context context;

TATL_TEST(dummy_pass) { return 1; }
TATL_TEST(dummy_fail) { return 0; }
TATL_TEST(tatl_context_get_total_works) {
  return *tatl_context_get_total(&context) == 3;
}
TATL_TEST(tatl_context_get_passed_works) {
  return *tatl_context_get_passed(&context) == 2;
}
TATL_TEST(tatl_context_get_failed_works) {
  return *tatl_context_get_failed(&context) == 1;
}
TATL_TEST(tatl_context_get_tag_works) {
  return !strcmp(*tatl_context_get_tag(&context), "hi");
}
TATL_TEST(tatl_context_get_mute_works) {
  return *tatl_context_get_mute(&context) == 1;
}

int main(void) {
  TATL_NEW();

  /* The dummy Tatl context to test using Tatl... Tatl-ception. */
  tatl_new(&context);
  /* Mute the output of the dummy Tatl context */
  tatl_context_set_mute(&context, 1);
  /* Add a predictable tag to the dummy Tatl context to test */
  tatl_context_set_tag(&context, "hi");
  /* Add predictable tests to the dummy Tatl context to test */
  tatl_add(&context, "dummy_pass", dummy_pass);
  tatl_add(&context, "dummy_pass 2", dummy_pass);
  tatl_add(&context, "dummy_fail", dummy_fail);
  tatl_run(&context);

  /* Our "real" Tatl context which tests our dummy Tatl context */
  tatl_context_set_tag(&TATL_CONTEXT, "tests/test.c");
  TATL_ADD("tatl_context_get_total", tatl_context_get_total_works);
  TATL_ADD("tatl_context_get_passed", tatl_context_get_passed_works);
  TATL_ADD("tatl_context_get_failed", tatl_context_get_failed_works);
  TATL_ADD("tatl_context_get_tag", tatl_context_get_tag_works);
  TATL_ADD("tatl_context_get_mute", tatl_context_get_mute_works);
  TATL_FINISH();

  tatl_destroy(context);

  return *tatl_context_get_exit_code(&TATL_CONTEXT);
}
