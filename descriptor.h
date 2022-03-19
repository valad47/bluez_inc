/*
 *   Copyright (c) 2021 Martijn van Welie
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 *
 */

#ifndef BINC_DESCRIPTOR_H
#define BINC_DESCRIPTOR_H

#include <gio/gio.h>
#include "forward_decl.h"

typedef void (*OnDescReadCallback)(Descriptor *descriptor, const GByteArray *byteArray, const GError *error);

typedef void (*OnDescWriteCallback)(Descriptor *descriptor, const GByteArray *byteArray, const GError *error);

void binc_descriptor_set_read_cb(Descriptor *descriptor, OnDescReadCallback callback);

void binc_descriptor_set_write_cb(Descriptor *descriptor, OnDescWriteCallback callback);

Descriptor *binc_descriptor_create(Device *device, const char *path);

void binc_descriptor_free(Descriptor *descriptor);

void binc_descriptor_read(Descriptor *descriptor);

void binc_descriptor_write(Descriptor *descriptor, const GByteArray *byteArray);

void binc_descriptor_set_uuid(Descriptor *descriptor, const char *uuid);

void binc_descriptor_set_char_path(Descriptor *descriptor, const char *path);

void binc_descriptor_set_char_uuid(Descriptor *descriptor, const char *uuid);

const char *binc_descriptor_get_char_path(Descriptor *descriptor);

const char *binc_descriptor_get_uuid(Descriptor *descriptor);

const char *binc_descriptor_to_string(Descriptor *descriptor);

void binc_descriptor_set_flags(Descriptor *descriptor, GList *flags);

Device *binc_descriptor_get_device(const Descriptor *descriptor);

#endif //BINC_DESCRIPTOR_H
