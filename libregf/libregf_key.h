/*
 * Key functions
 *
 * Copyright (C) 2009-2023, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBREGF_KEY_H )
#define _LIBREGF_KEY_H

#include <common.h>
#include <types.h>

#include "libregf_extern.h"
#include "libregf_hive_bins_list.h"
#include "libregf_io_handle.h"
#include "libregf_key_item.h"
#include "libregf_libbfio.h"
#include "libregf_libcerror.h"
#include "libregf_libcthreads.h"
#include "libregf_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libregf_internal_key libregf_internal_key_t;

struct libregf_internal_key
{
	/* The IO handle
	 */
	libregf_io_handle_t *io_handle;

	/* The file IO handle
	 */
	libbfio_handle_t *file_io_handle;

	/* The key offset
	 */
	uint32_t key_offset;

	/* The hive bins list
	 */
	libregf_hive_bins_list_t *hive_bins_list;

	/* The key item
	 */
	libregf_key_item_t *key_item;

#if defined( HAVE_LIBREGF_MULTI_THREAD_SUPPORT )
	/* The read/write lock
	 */
	libcthreads_read_write_lock_t *read_write_lock;
#endif
};

int libregf_key_initialize(
     libregf_key_t **key,
     libregf_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     uint32_t key_offset,
     libregf_hive_bins_list_t *hive_bins_list,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_free(
     libregf_key_t **key,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_is_corrupted(
     libregf_key_t *key,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_offset(
     libregf_key_t *key,
     off64_t *offset,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_name_size(
     libregf_key_t *key,
     size_t *name_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_name(
     libregf_key_t *key,
     uint8_t *name,
     size_t name_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf8_name_size(
     libregf_key_t *key,
     size_t *utf8_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf8_name(
     libregf_key_t *key,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf16_name_size(
     libregf_key_t *key,
     size_t *utf16_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf16_name(
     libregf_key_t *key,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_class_name_size(
     libregf_key_t *key,
     size_t *class_name_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_class_name(
     libregf_key_t *key,
     uint8_t *class_name,
     size_t class_name_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf8_class_name_size(
     libregf_key_t *key,
     size_t *utf8_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf8_class_name(
     libregf_key_t *key,
     uint8_t *utf8_string,
     size_t utf8_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf16_class_name_size(
     libregf_key_t *key,
     size_t *utf16_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_utf16_class_name(
     libregf_key_t *key,
     uint16_t *utf16_string,
     size_t utf16_string_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_last_written_time(
     libregf_key_t *key,
     uint64_t *filetime,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_security_descriptor_size(
     libregf_key_t *key,
     size_t *security_descriptor_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_security_descriptor(
     libregf_key_t *key,
     uint8_t *security_descriptor,
     size_t security_descriptor_size,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_number_of_values(
     libregf_key_t *key,
     int *number_of_values,
     libcerror_error_t **error );

int libregf_internal_key_get_value(
     libregf_internal_key_t *internal_key,
     int value_index,
     libregf_value_t **value,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_value(
     libregf_key_t *key,
     int value_index,
     libregf_value_t **value,
     libcerror_error_t **error );

int libregf_internal_key_get_value_by_utf8_name(
     libregf_internal_key_t *internal_key,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libregf_value_t **value,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_value_by_utf8_name(
     libregf_key_t *key,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libregf_value_t **value,
     libcerror_error_t **error );

int libregf_internal_key_get_value_by_utf16_name(
     libregf_internal_key_t *internal_key,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libregf_value_t **value,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_value_by_utf16_name(
     libregf_key_t *key,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libregf_value_t **value,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_number_of_sub_keys(
     libregf_key_t *key,
     int *number_of_sub_keys,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_sub_key(
     libregf_key_t *key,
     int sub_key_index,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

int libregf_internal_key_get_sub_key_by_utf8_name(
     libregf_internal_key_t *internal_key,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_sub_key_by_utf8_name(
     libregf_key_t *key,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_sub_key_by_utf8_path(
     libregf_key_t *key,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

int libregf_internal_key_get_sub_key_by_utf16_name(
     libregf_internal_key_t *internal_key,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_sub_key_by_utf16_name(
     libregf_key_t *key,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

LIBREGF_EXTERN \
int libregf_key_get_sub_key_by_utf16_path(
     libregf_key_t *key,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libregf_key_t **sub_key,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBREGF_KEY_H ) */

