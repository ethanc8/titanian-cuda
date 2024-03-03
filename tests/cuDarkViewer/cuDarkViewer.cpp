// includes, system
#include <cstdint>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

#include <cuda.h>

typedef struct CUdarkExportTableInfo {
  std::string name;
  CUuuid uuid;
  std::unordered_map<size_t, std::string> nameTable;
} CUdarkExportTableInfo;

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    std::vector<CUdarkExportTableInfo> tableInfos = { 
        {"CTX_CREATE_BYPASS", {0x0C, 0xA5, 0x0B, 0x8C, 0x10, 0x04, 0x92, 0x9A, 0x89, 0xA7, 0xD0, 0xDF, 0x10, 0xE7, 0x72, 0x86}, {
            {1, "ctx_create_v2_bypass"},
        }},
        {"CUEXP_127d4831", {0x12, 0x7d, 0x48, 0x31, 0xee, 0x33, 0x57, 0x44, 0x97, 0x42, 0xb8, 0x44, 0x7b, 0x7a, 0x23, 0x64}, {
            {0x28/4, "cuexp_127d4831_28"},
            {0x30/4, "cuexp_127d4831_30"},
        }},
        {"HEAP_ACCESS", {0x19, 0x5B, 0xCB, 0xF4, 0xD6, 0x7D, 0x02, 0x4A, 0xAC, 0xC5, 0x1D, 0x29, 0xCE, 0xA6, 0x31, 0xAE}, {
            {1, "heap_alloc"},
            {2, "heap_free"},
        }},
        {"CONTEXT_WRAPPER", {0x26, 0x3e, 0x88, 0x60, 0x7c, 0xd2, 0x61, 0x43, 0x92, 0xf6, 0xbb, 0xd5, 0x00, 0x6d, 0xfa, 0x7e}, {
            {2, "unwrap_context"},
        }},
        {"CUEXP_2C8E0AD8", {0x2c, 0x8e, 0x0a, 0xd8, 0x07, 0x10, 0xab, 0x4e, 0x90, 0xdd, 0x54, 0x71, 0x9f, 0xe5, 0xf7, 0x4b}, {
            {0x18/4, "cuexp_2c8e0ad8_18"},
            {0x38/4, "cuexp_2c8e0ad8_38"}
        }},
        {"TOOLS_TLS", {0x42, 0xd8, 0x5a, 0x81, 0x23, 0xf6, 0xcb, 0x47, 0x82, 0x98, 0xf6, 0xe7, 0x8a, 0x3a, 0xec, 0xdc}, {
            {0x10/4, "cuexp_get_thread_context"},
        }},
        {"CUEXP_CONTEXT", {0x21, 0x31, 0x8c, 0x60, 0x97, 0x14, 0x32, 0x48, 0x8c, 0xa6, 0x41, 0xff, 0x73, 0x24, 0xc8, 0xf2}, {
            {0x18/4, "cuexpContext_getDevice"},
            {0x20/4, "cuexpContext_getContextNumber"},
            {0x80/4, "cuexp_21318c60_80"},
            {0x138/4, "cuexp_21318c60_138"},
        }},
        {"CUDART_INTERFACE", {0x6b, 0xd5, 0xfb, 0x6c, 0x5b, 0xf4, 0xe7, 0x4a, 0x89, 0x87, 0xd9, 0x39, 0x12, 0xfd, 0x9d, 0xf9}, {
            {1, "get_module_from_cubin"},
            {2, "get_primary_context"},
            {6, "get_module_from_cubin_ex1"},
            {7, "cudart_interface_fn7"},
            {8, "get_module_from_cubin_ex2"},
            {9, "launch_kernel"},
            // {0x10/4, "cuexp_get_primary_context"},
            {0x30/4, "cuexp_register_module"},
            {0x38/4, "cuexp_unregister_module"},
        }},
        {"CUEXP_CUPTI", {0x7c, 0xb6, 0x3f, 0x9b, 0x9c, 0xa4, 0x8e, 0x42, 0xa4, 0x84, 0xbe, 0xb6, 0x6e, 0x6a, 0xed, 0x7f}, {
            {0x100/4, "cuexpCUPTI_init"},
            {0x1e0/4, "cuexp_7cb63f9b_1e0"},
        }},
        {"DLSS", {0x7f, 0x92, 0x12, 0xd6, 0x26, 0x1d, 0xdd, 0x4d, 0x8a, 0xf6, 0x38, 0xdd, 0x1a, 0xeb, 0x10, 0xae}, {
            {3, "dlss_cuInit"},
            {7, "dlss_start1"},
            {9, "dlss_start2"},
            {12, "dlss_module_load"},
            {14, "dlss_module_get_function"},
            {22, "dlss_feature_evaluate2"},
            {37, "dlss_feature_evaluate1"},
            {39, "dlss_feature_evaluate_init"}
        }},
        {"CUEXP_FUNCTION", {0x6e, 0x16, 0x3f, 0xbe, 0xb9, 0x58, 0x44, 0x4d, 0x83, 0x5c, 0xe1, 0x82, 0xaf, 0xf1, 0x99, 0x1e}, {
            {0x28/4, "cuexp_function_get_name"},
            {0x90/4, "cuexpFunction_setCacheConfig"},
            {0xd8/4, "cuexp_6e163fbe_d8"},
            {0x108/4, "cuexpFunction_get_arg_count"},
            {0x110/4, "cuexpFunction_get_arg_descriptor"},
            {0x130/4, "cuexp_6e163fbe_130"},
            {0x150/4, "cuexp_module_iterate_on_functions"},
            {0x1a8/4, "cuexp_6e163fbe_1a8"},
            {0x1b8/4, "cuexp_6e163fbe_1b8"}
        }},
        {"TOOLS_RUNTIME_CALLBACK_HOOKS", {0xa0, 0x94, 0x79, 0x8c, 0x2e, 0x74, 0x2e, 0x74, 0x93, 0xf2, 0x08, 0x00, 0x20, 0x0c, 0x0a, 0x66}, {
            {2, "tools_runtime_callback_hooks_fn2"},
            {6, "tools_runtime_callback_hooks_fn6"},
            // We have the signatures for these but we don't know what they do
            // {0x8/4, "cuexp_a094798c_08"},
            // {0x10/4, "cuexp_a094798c_10"},
            // {0x18/4, "cuexp_a094798c_18"},
            // {0x20/4, "cuexp_a094798c_20"},
            // {0x28/4, "cuexp_a094798c_28"},
            // {0x30/4, "cuexp_a094798c_30"},
        }},
        {"CUEXP_A31746D1", {0xa3, 0x17, 0x46, 0xd1, 0x54, 0x75, 0xef, 0x4e, 0xae, 0xb6, 0xdf, 0xb1, 0x47, 0x6a, 0xdd, 0x6c}, {
            {0x288/4, "cuexpDevice_get_primary_context_refcount"},
        }},
        {"CUEXP_A6B1FF99", {0xa6, 0xb1, 0xff, 0x99, 0xec, 0xc4, 0xc9, 0x4f, 0x92, 0xf9, 0x19, 0x28, 0x66, 0x3d, 0x55, 0x85}, {
            {0x28/2, "cuexp_a6b1ff99_28"},
        }},
        {"DEVICE_EXTENDED_RT", {0xB1, 0x05, 0x41, 0xE1, 0xF7, 0xC7, 0xC7, 0x4A, 0x9F, 0x64, 0xF2, 0x23, 0xBE, 0x99, 0xF1, 0xE2}, {
            {5, "device_get_attribute_ex"},
            {13, "device_get_something"},
            {0x8/4, "cuexpDevice_get"},
            {0x10/4, "cuexpDevice_getCount"},
            {0x28/4, "cuexpDevice_getAttribute"},
            {0x30/4, "cuexp_b10541e1_30"},
            {0x40/4, "cuexp_b10541e1_40"},
        }},
        {"CONTEXT_LOCAL_STORAGE_INTERFACE_V301", {0xc6, 0x93, 0x33, 0x6e, 0x11, 0x21, 0xdf, 0x11, 0xa8, 0xc3, 0x68, 0xf3, 0x55, 0xd8, 0x95, 0x93}, {
            // 0x0 cuexpContext_kvstore_add
            {0, "context_local_storage_insert"},
            // 0x8 cuexpContext_kvstore_delete
            {1, "context_local_storage_remove"},
            // 0x10 cuexpContext_kvstore_get
            {2, "context_local_storage_get"},
            {3, "(should be null)"},
        }},
        {"ANTI_ZLUDA", {0xd4, 0x08, 0x20, 0x55, 0xbd, 0xe6, 0x70, 0x4b, 0x8d, 0x34, 0xba, 0x12, 0x3c, 0x66, 0xe1, 0xf2}, {
            {1, "zluda_check"},
        }},
        {"CUEXP_STATE", {0xd7, 0xbd, 0x8a, 0xf8, 0xe7, 0xac, 0xca, 0x4a, 0xbd, 0xbc, 0xfb, 0x1f, 0x1b, 0x3f, 0xcf, 0x33}, {
            {0x18/4, "cuexp_getCudaState"},
        }}
    };
    // Pointer to array of void* 
    void** exportTable = NULL;
    for(CUdarkExportTableInfo tableInfo : tableInfos) {
        cuGetExportTable((const void**)&exportTable, &tableInfo.uuid);
        printf("Table %s: %p\n", tableInfo.name.c_str(), exportTable);
        if(exportTable == NULL) { continue; }
        size_t tableSize;
        long long initialI;
        if(tableInfo.name == "CONTEXT_LOCAL_STORAGE_INTERFACE_V301") {
            tableSize = 4;
            initialI = 0;
        } else {
            tableSize = (size_t)(exportTable[0]);
            printf("  Size: %lld\n", (long long)tableSize);
            initialI = 1;
        }
        // if(tableSize >= 100) { continue; }
        for(long long i = initialI; i < tableSize; i++) {
            if(tableInfo.nameTable.count(i) > 0) {
                printf("  [%lld] = %p %s\n", i, exportTable[i], tableInfo.nameTable[i].c_str());
            } else {
                printf("  [%lld] = %p\n", i, exportTable[i]);
            }
        }
        // std::cout << "Table " << tableInfo.name << ": " << // " [" << (size_t)(exportTable[0]) <<"] :" << std::endl;
    }
    return 0;
}
