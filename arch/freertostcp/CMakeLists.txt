SET(SOURCE_GROUP ${SOURCE_GROUP}\\freertosTCP)

ua_add_architecture("freertosTCP")

list (FIND UA_AMALGAMATION_ARCHITECTURES "freertosTCP" _index)
if (${_index} GREATER -1 OR "${UA_ARCHITECTURE}" STREQUAL "freertosTCP")

    ua_add_architecture_file(${CMAKE_CURRENT_SOURCE_DIR}/ua_clock.c)
    ua_add_architecture_file(${CMAKE_CURRENT_SOURCE_DIR}/ua_architecture_functions.c)

    if("${UA_ARCHITECTURE}" STREQUAL "freertosTCP")
        ua_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
        ua_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../common)
        set(UA_ARCH_FREERTOS_USE_OWN_MEMORY_FUNCTIONS OFF CACHE BOOL "Enable free/malloc/etc from own implementation")
        if(UA_ARCH_FREERTOS_USE_OWN_MEMORY_FUNCTIONS)
          ua_architecture_add_definitions("-DOPEN62541_FEERTOS_USE_OWN_MEM")
        endif(UA_ARCH_FREERTOS_USE_OWN_MEMORY_FUNCTIONS)
        ua_add_architecture_header_beginning(${CMAKE_CURRENT_SOURCE_DIR}/../common/ua_freeRTOS.h
                                             ${CMAKE_CURRENT_SOURCE_DIR}/../common/ua_freeRTOSTCP.h
                                             )
    endif()
endif()
