#ifndef BSARCH_DLL_EXPORT
#define BSARCH_DLL_EXPORT 1
#endif

#include "libbsarch.h"

BSARCH_DLL_API(bsa_entry_list_t) bsa_entry_list_create() {
  return NULL;
}

BSARCH_DLL_API(void) bsa_entry_list_free(bsa_entry_list_t *entry_list) {
  return;
}

BSARCH_DLL_API(uint32_t) bsa_entry_list_count(bsa_entry_list_t *entry_list) {
  return 0;
}

BSARCH_DLL_API(void) bsa_entry_list_add(bsa_entry_list_t *entry_list, char *entry_string) {
  return;
}

BSARCH_DLL_API(uint32_t) bsa_entry_list_get(bsa_entry_list_t *entry_list, uint32_t index, uint32_t string_buffer_size, char *string_buffer) {
  return 0;
}

BSARCH_DLL_API(bsa_archive_t) bsa_create() {
  return NULL;
}

BSARCH_DLL_API(void) bsa_free(bsa_archive_t archive) {
  return;
}

BSARCH_DLL_API(void) bsa_load_from_file(bsa_archive_t archive, char *filename) {
  return;
}

BSARCH_DLL_API(void) bsa_create_archive(bsa_archive_t archive, char *filename, bsa_archive_type_t archive_type, bsa_entry_list_t entry_list) {
  return;
}

BSARCH_DLL_API(void) bsa_save(bsa_archive_t archive) {
  return;
}

BSARCH_DLL_API(void) bsa_add_file_from_disk(bsa_archive_t archive, char *root_dir, char *filename) {
  return;
}

BSARCH_DLL_API(void) bsa_add_file_from_memory(bsa_archive_t archive, char *filename, uint32_t size, bsa_file_data_t data) {
  return;
}

BSARCH_DLL_API(bsa_file_record_t) bsa_find_file_record(bsa_archive_t archive, char *filename) {
  return NULL;
}

BSARCH_DLL_API(bsa_file_data_result_t) bsa_extract_file_data_by_record(bsa_archive_t archive, bsa_file_record_t file_record) {
  return { 0 };
}

BSARCH_DLL_API(bsa_file_data_result_t) bsa_extract_file_data_by_filename(bsa_archive_t archive, char *filename) {
  return { 0 };
}

BSARCH_DLL_API(void) bsa_file_data_free(bsa_archive_t archive, bsa_file_data_result_t file_data_result) {
  return;
}

BSARCH_DLL_API(void) bsa_extract_file(bsa_archive_t archive, char *filename, char *save_as) {
  return;
}

BSARCH_DLL_API(void) bsa_iterate_files(bsa_archive_t archive, bsa_file_iteration_proc_t file_iteration_proc, void *context) {
  return;
}

BSARCH_DLL_API(bool) bsa_file_exists(bsa_archive_t archive, char *filename) {
  return false;
}

BSARCH_DLL_API(void) bsa_get_resource_list(bsa_archive_t archive, bsa_entry_list_t entry_result_list, char *folder) {
  return;
}

BSARCH_DLL_API(void) bsa_resolve_hash(bsa_archive_t archive, uint64_t hash, bsa_entry_list_t entry_result_list) {
  return;
}

BSARCH_DLL_API(void) bsa_close(bsa_archive_t archive) {
  return;
}

BSARCH_DLL_API(uint32_t) bsa_filename_get(bsa_archive_t *archive, uint32_t string_buffer_size, char *string_buffer) {
  return 0;
}

BSARCH_DLL_API(bsa_archive_type_t) bsa_archive_type_get(bsa_archive_t *archive) {
  return bsa_archive_type_t::baNone;
}

BSARCH_DLL_API(uint32_t) bsa_version_get(bsa_archive_t *archive) {
  return 0;
}

BSARCH_DLL_API(uint32_t) bsa_format_name_get(bsa_archive_t *archive, uint32_t string_buffer_size, char *string_buffer) {
  return 0;
}

BSARCH_DLL_API(uint32_t) bsa_file_count_get(bsa_archive_t *archive) {
  return 0;
}

BSARCH_DLL_API(uint32_t) bsa_archive_flags_get(bsa_archive_t *archive) {
  return 0;
}

BSARCH_DLL_API(void) bsa_archive_flags_set(bsa_archive_t *archive, uint32_t flags) {
  return;
}

BSARCH_DLL_API(uint32_t) bsa_file_flags_get(bsa_archive_t *archive) {
  return 0;
}

BSARCH_DLL_API(void) bsa_file_flags_set(bsa_archive_t *archive, uint32_t flags) {
  return;
}

BSARCH_DLL_API(bool) bsa_compress_get(bsa_archive_t *archive) {
  return false;
}

BSARCH_DLL_API(void) bsa_compress_set(bsa_archive_t *archive, bool flags) {
  return;
}

BSARCH_DLL_API(bool) bsa_share_data_get(bsa_archive_t *archive) {
  return false;
}

BSARCH_DLL_API(void) bsa_share_data_set(bsa_archive_t *archive, bool flags) {
  return;
}

BSARCH_DLL_API(void) bsa_file_dds_info_callback_set(bsa_archive_t *archive, bsa_file_dds_info_proc_t file_dds_info_proc) {
  return;
}
