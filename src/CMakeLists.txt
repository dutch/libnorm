add_library(libnorm normmem.c)
set_target_properties(libnorm PROPERTIES PREFIX "")
target_include_directories(libnorm PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
