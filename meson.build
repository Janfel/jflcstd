project('jflcstd', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_JFLCSTD']

shlib = shared_library('jflcstd', 'jflcstd.c',
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

test_exe = executable('jflcstd', 'jflcstd_test.c',
  link_with : shlib)
test('jflcstd', test_exe)

# Make this library usable as a Meson subproject.
jflcstd_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('jflcstd.h', subdir : 'jflcstd')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'jflcstd',
  filebase : 'jflcstd',
  description : 'Meson sample project.',
  subdirs : 'jflcstd',
  libraries : shlib,
  version : '0.1',
)
