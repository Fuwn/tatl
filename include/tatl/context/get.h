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

#ifndef TATL_CONTEXT_GET
#define TATL_CONTEXT_GET

#include <tatl/context.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Get a Tatl context's total number of tests */
size_t *tatl_context_get_total(struct tatl_context *);
/* Get a Tatl context's total number of passing tests */
size_t *tatl_context_get_passed(struct tatl_context *);
/* Get a Tatl context's total number of failing tests */
size_t *tatl_context_get_failed(struct tatl_context *);
/* Get a Tatl context's tag */
char *tatl_context_get_tag(struct tatl_context *);
/* Get a Tatl context's mute status */
int *tatl_context_get_mute(struct tatl_context *);
/* Get a Tatl context's exit code */
int *tatl_context_get_exit_code(struct tatl_context *);

#ifdef __cplusplus
}
#endif

#endif /* TATL_CONTEXT_GET */
