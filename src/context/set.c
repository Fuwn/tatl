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
#include <string.h>

#include <tatl/context/set.h>

void tatl_context_set_mute(struct tatl_context *context, int mute) {
  context->_mute = mute;
}

void tatl_context_set_tag(struct tatl_context *context, const char *const tag) {
  free(context->_tag);

  context->_tag = malloc(strlen(tag) * sizeof(char));

  strcpy(context->_tag, tag);
}
