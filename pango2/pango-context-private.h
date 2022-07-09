/*
 * Copyright (C) 2004 Red Hat Software
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "pango-context.h"

#ifdef HAVE_CAIRO
#include <cairo.h>
#endif

struct _Pango2Context
{
  GObject parent_instance;
  guint serial;
  guint fontmap_serial;

  Pango2Language *set_language;
  Pango2Language *language;
  Pango2Direction base_dir;
  Pango2Gravity base_gravity;
  Pango2Gravity resolved_gravity;
  Pango2GravityHint gravity_hint;

  Pango2FontDescription *font_desc;

  Pango2Matrix *matrix;

  Pango2FontMap *font_map;

  Pango2FontMetrics *metrics;

  gboolean round_glyph_positions;

  GQuark palette;

  Pango2EmojiPresentation presentation;

#ifdef HAVE_CAIRO
  gboolean set_options_explicit;

  cairo_font_options_t *set_options;
  cairo_font_options_t *surface_options;
  cairo_font_options_t *merged_options;
#endif
};
