cmake_minimum_required (VERSION 3.5)
project (mg)

set (MG_SRC autoexec.c basic.c bell.c buffer.c cinfo.c dir.c display.c
	echo.c extend.c file.c fileio.c funmap.c help.c kbd.c keymap.c
	line.c macro.c main.c match.c modes.c paragraph.c
	re_search.c region.c search.c spawn.c tty.c ttyio.c ttykbd.c
	undo.c util.c version.c window.c word.c yank.c
	cmode.c cscope.c dired.c grep.c tags.c
)

if(CMAKE_SYSTEM_NAME MATCHES "DragonFly")
set (REALLOC_SRC reallocarray.c)
endif()

add_executable (mg ${MG_SRC} ${REALLOC_SRC})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  find_package (PkgConfig REQUIRED)
  pkg_check_modules (BSD REQUIRED libbsd-overlay)
  link_directories (${BSD_LIBRARY_DIRS})
  string (REPLACE ";" " " LIBBSD_FLAGS "${BSD_CFLAGS}")
  target_link_libraries (mg ${BSD_LIBRARIES})
endif()

set (CMAKE_C_FLAGS "-Wall -DREGEX ${LIBBSD_FLAGS}")
target_link_libraries (mg ncurses util)
