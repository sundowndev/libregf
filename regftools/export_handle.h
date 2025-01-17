/*
 * Export handle
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

#if !defined( _EXPORT_HANDLE_H )
#define _EXPORT_HANDLE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "log_handle.h"
#include "regftools_libcerror.h"
#include "regftools_libregf.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct export_handle export_handle_t;

struct export_handle
{
	/* The libregf input file
	 */
	libregf_file_t *input_file;

	/* The notification output stream
	 */
	FILE *notify_stream;

	/* The ascii codepage
	 */
	int ascii_codepage;

	/* Value to indicate if abort was signalled
	 */
	int abort;
};

int export_handle_initialize(
     export_handle_t **export_handle,
     libcerror_error_t **error );

int export_handle_free(
     export_handle_t **export_handle,
     libcerror_error_t **error );

int export_handle_signal_abort(
     export_handle_t *export_handle,
     libcerror_error_t **error );

int export_handle_set_ascii_codepage(
     export_handle_t *export_handle,
     const system_character_t *string,
     libcerror_error_t **error );

int export_handle_print_data(
     export_handle_t *export_handle,
     FILE *stream,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error );

int export_handle_open_input(
     export_handle_t *export_handle,
     const system_character_t *filename,
     libcerror_error_t **error );

int export_handle_close_input(
     export_handle_t *export_handle,
     libcerror_error_t **error );

int export_handle_export_filetime(
     export_handle_t *export_handle,
     const char *value_name,
     uint64_t value_64bit,
     libcerror_error_t **error );

int export_handle_export_key(
     export_handle_t *export_handle,
     const system_character_t *key_path,
     size_t key_path_length,
     libregf_key_t *key,
     log_handle_t *log_handle,
     libcerror_error_t **error );

int export_handle_export_key_path(
     export_handle_t *export_handle,
     const system_character_t *key_path,
     log_handle_t *log_handle,
     libcerror_error_t **error );

int export_handle_export_file(
     export_handle_t *export_handle,
     log_handle_t *log_handle,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _EXPORT_HANDLE_H ) */

