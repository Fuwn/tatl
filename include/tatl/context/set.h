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

#ifndef TATL_CONTEXT_SET
#define TATL_CONTEXT_SET

#include <tatl/context.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Set a Tatl context's mute status
 *
 * Muting a Tatl context disables any output that the context may produce.
 */
void tatl_context_set_mute(struct tatl_context *, int);
/* Set a Tatl context's tag */
void tatl_context_set_tag(struct tatl_context *, const char *);

#ifdef __cplusplus
}
#endif

#endif /* TATL_CONTEXT_SET */
