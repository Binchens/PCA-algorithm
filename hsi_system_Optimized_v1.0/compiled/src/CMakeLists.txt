# Generated from hsi_system

set(filenames
	hsi_system.c
	PCA.c
	VCA.c
	LSU.c
	Source.c
	Display.c
)

include_directories(${extra_includes})
add_definitions(${extra_definitions})
add_executable(hsi_system ${filenames})

# Build library without any external library required
target_link_libraries(hsi_system orcc-native orcc-runtime ${extra_libraries})
