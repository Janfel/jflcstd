project('jflcstd', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

inc = include_directories('include')

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_JFLCSTD']

lib_src = 'src/stack.c'
jflcstd = shared_library('jflcstd',
  sources : lib_src,
  include_directories : inc,
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

# Tests
test_exe = executable('stack', 'test/stack_test.c',
  include_directories : inc,
  link_with : jflcstd,
)
test('stack', test_exe)

# Make this library usable as a Meson subproject.
jflcstd_dep = declare_dependency(
  include_directories: inc,
  link_with : jflcstd)

# Make this library usable from the system's
# package manager.
inst_hdrs = ['include/jflcstd.h','include/stack.h','include/macros.h']
install_headers(inst_hdrs, subdir : 'jflcstd')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'jflcstd',
  filebase : 'jflcstd',
  description : 'JFL C Standard Library',
  subdirs : 'jflcstd',
  libraries : jflcstd,
  version : '0.1',
)
