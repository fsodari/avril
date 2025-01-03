cmake_minimum_required(VERSION 3.28)
project(${SKBUILD_PROJECT_NAME} LANGUAGES C CXX)

find_package(Python COMPONENTS Interpreter Development.Module ${SKBUILD_SABI_COMPONENT})
find_package(nanobind CONFIG REQUIRED)

nanobind_add_module(_core src/_core.cpp
    NB_STATIC
    NB_DOMAIN avril
    STABLE_ABI
)

nanobind_add_stub(_core_stub
    MODULE _core
    OUTPUT ${SKBUILD_PROJECT_NAME}/_core.pyi
    PYTHON_PATH $<TARGET_FILE_DIR:_core>
    MARKER_FILE ${SKBUILD_PROJECT_NAME}/py.typed
    INSTALL_TIME
)
install(TARGETS _core DESTINATION ${SKBUILD_PROJECT_NAME})
