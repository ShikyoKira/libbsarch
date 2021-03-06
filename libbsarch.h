#pragma once

#include <stdint.h>

#include <dxgiformat.h>

#include "DDS.h"

#ifdef BSARCH_DLL_EXPORT
#define BSARCH_DLL_API(ReturnType) extern "C" __declspec(dllexport) ReturnType __stdcall
#else
#define BSARCH_DLL_API(ReturnType) extern "C" __declspec(dllimport) ReturnType __stdcall
#endif

typedef void* bsa_archive_t;
typedef void* bsa_file_data_t;
typedef void* bsa_entry_list_t;
typedef void* bsa_file_record_t;
typedef void* bsa_folder_record_t;

typedef struct bsa_dds_info_s {
  uint32_t width, height, mipmaps;
} bsa_dds_info_t;

typedef struct bsa_dds_header_s {
  uint32_t magic; // DDS_MAGIC
  struct DirectX::DDS_HEADER header;
} bsa_dds_header_t;

typedef struct bsa_file_data_result_s {
  uint32_t size;
  bsa_file_data_t data;
} bsa_file_data_result_t;

typedef enum bsa_archive_state_e {
  stReading, stWriting
} bsa_archive_state_t;

typedef enum bsa_archive_type_e {
  baNone, baTES3, baTES4, baFO3, baSSE, baFO4, baFO4dds
} bsa_archive_type_t;

typedef void (*bsa_file_dds_info_proc_t)(bsa_archive_t bsa_archive, char **filename, bsa_dds_info_t dds_info);
typedef bool (*bsa_file_iteration_proc_t)(bsa_archive_t bsa_archive, char **filename, bsa_file_record_t file_record, bsa_folder_record_t folder_record, void *context);

BSARCH_DLL_API(bsa_entry_list_t) bsa_entry_list_create();
BSARCH_DLL_API(void) bsa_entry_list_free(bsa_entry_list_t *entry_list);
BSARCH_DLL_API(uint32_t) bsa_entry_list_count(bsa_entry_list_t *entry_list);
BSARCH_DLL_API(void) bsa_entry_list_add(bsa_entry_list_t *entry_list, char *entry_string);
BSARCH_DLL_API(uint32_t) bsa_entry_list_get(bsa_entry_list_t *entry_list, uint32_t index, uint32_t string_buffer_size, char *string_buffer);

BSARCH_DLL_API(bsa_archive_t) bsa_create();
BSARCH_DLL_API(void) bsa_free(bsa_archive_t archive);
BSARCH_DLL_API(void) bsa_load_from_file(bsa_archive_t archive, char *filename);
BSARCH_DLL_API(void) bsa_create_archive(bsa_archive_t archive, char *filename, bsa_archive_type_t archive_type, bsa_entry_list_t entry_list);
BSARCH_DLL_API(void) bsa_save(bsa_archive_t archive);
BSARCH_DLL_API(void) bsa_add_file_from_disk(bsa_archive_t archive, char *root_dir, char *filename);
BSARCH_DLL_API(void) bsa_add_file_from_memory(bsa_archive_t archive, char *filename, uint32_t size, bsa_file_data_t data);
BSARCH_DLL_API(bsa_file_record_t) bsa_find_file_record(bsa_archive_t archive, char *filename);
BSARCH_DLL_API(bsa_file_data_result_t) bsa_extract_file_data_by_record(bsa_archive_t archive,  bsa_file_record_t file_record);
BSARCH_DLL_API(bsa_file_data_result_t) bsa_extract_file_data_by_filename(bsa_archive_t archive, char *filename);
BSARCH_DLL_API(void) bsa_file_data_free(bsa_archive_t archive, bsa_file_data_result_t file_data_result);
BSARCH_DLL_API(void) bsa_extract_file(bsa_archive_t archive,  char *filename, char *save_as);
BSARCH_DLL_API(void) bsa_iterate_files(bsa_archive_t archive, bsa_file_iteration_proc_t file_iteration_proc, void *context);
BSARCH_DLL_API(bool) bsa_file_exists(bsa_archive_t archive, char *filename);
BSARCH_DLL_API(void) bsa_get_resource_list(bsa_archive_t archive, bsa_entry_list_t entry_result_list, char *folder);
BSARCH_DLL_API(void) bsa_resolve_hash(bsa_archive_t archive, uint64_t hash, bsa_entry_list_t entry_result_list);
BSARCH_DLL_API(void) bsa_close(bsa_archive_t archive);

BSARCH_DLL_API(uint32_t) bsa_filename_get(bsa_archive_t *archive, uint32_t string_buffer_size, char *string_buffer);
BSARCH_DLL_API(bsa_archive_type_t) bsa_archive_type_get(bsa_archive_t *archive);
BSARCH_DLL_API(uint32_t) bsa_version_get(bsa_archive_t *archive);
BSARCH_DLL_API(uint32_t) bsa_format_name_get(bsa_archive_t *archive, uint32_t string_buffer_size, char *string_buffer);
BSARCH_DLL_API(uint32_t) bsa_file_count_get(bsa_archive_t *archive);
BSARCH_DLL_API(uint32_t) bsa_archive_flags_get(bsa_archive_t *archive);
BSARCH_DLL_API(void) bsa_archive_flags_set(bsa_archive_t *archive, uint32_t flags);
BSARCH_DLL_API(uint32_t) bsa_file_flags_get(bsa_archive_t *archive);
BSARCH_DLL_API(void) bsa_file_flags_set(bsa_archive_t *archive, uint32_t flags);
BSARCH_DLL_API(bool) bsa_compress_get(bsa_archive_t *archive);
BSARCH_DLL_API(void) bsa_compress_set(bsa_archive_t *archive, bool flags);
BSARCH_DLL_API(bool) bsa_share_data_get(bsa_archive_t *archive);
BSARCH_DLL_API(void) bsa_share_data_set(bsa_archive_t *archive, bool flags);

BSARCH_DLL_API(void) bsa_file_dds_info_callback_set(bsa_archive_t *archive, bsa_file_dds_info_proc_t file_dds_info_proc);
