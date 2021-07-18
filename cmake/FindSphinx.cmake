#Look for an executable called sphinx-build
#             NAMES sphinx-build
#             DOC "C:/Users/Jonathan/AppData/Local/Programs/Python/Python38/Scripts")

#include(FindPackageHandleStandardArgs)

#Handle standard arguments to find_package like REQUIRED and QUIET
#find_package_handle_standard_args(Sphinx
#                                  "Failed to find sphinx-build executable"
#                                  SPHINX_EXECUTABLE)
find_program(SPHINX_EXECUTABLE NAMES sphinx-build
    HINTS
    $ENV{SPHINX_DIR}
    PATH_SUFFIXES bin
    DOC "Sphinx documentation generator"
)
 
include(FindPackageHandleStandardArgs)
 
find_package_handle_standard_args(Sphinx DEFAULT_MSG
    SPHINX_EXECUTABLE
)
 
mark_as_advanced(SPHINX_EXECUTABLE)