cmake_minimum_required(VERSION 3.10)

project("Example")
set(CMAKE_C_STANDARD 11)

# Include M*LIB headers in the project using GIT.
include (ExternalProject)
set(EP_MLIB "mlib")
ExternalProject_Add (
	${EP_MLIB}	
	PREFIX            ${EP_MLIB}
	GIT_REPOSITORY    https://github.com/P-p-H-d/mlib
	GIT_TAG           V0.5.0
	GIT_SHALLOW       ON
	BUILD_ALWAYS      OFF
	CONFIGURE_COMMAND ""
	BUILD_COMMAND     ""
	INSTALL_COMMAND   cd <SOURCE_DIR> && make install PREFIX=<INSTALL_DIR>
)
ExternalProject_Get_Property(${EP_MLIB} install_dir)
include_directories(${install_dir}/include)
        
# Define our target and add M*LIB as dependency.
add_executable(example main.c )
add_dependencies(example ${EP_MLIB} )
