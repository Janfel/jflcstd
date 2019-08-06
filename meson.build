project('jflcstd', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_JFLCSTD']

lib_src = 'src/jflcstd.c'
shlib = shared_library('jflcstd',
  sources : lib_src,
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

test_src = 'test/jflcstd_test.c'
test_exe = executable('jflcstd',
  sources : test_src,
  link_with : shlib,
)
test('jflcstd', test_exe)

# Make this library usable as a Meson subproject.
jflcstd_dep = declare_dependency(
  include_directories: include_directories('include'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
inst_hdrs = 'include/jflcstd.h'
install_headers(inst_hdrs, subdir : 'jflcstd')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'jflcstd',
  filebase : 'jflcstd',
  description : 'JFL C Standard Library',
  subdirs : 'jflcstd',
  libraries : shlib,
  version : '0.1',
)
