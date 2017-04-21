AR = '/usr/bin/ar'
ARFLAGS = 'rcs'
CC = ['/usr/bin/gcc']
CCDEFINES = ['_DEBUG']
CCDEFINES_ST = '-D%s'
CCFLAGS = ['-O0', '-ggdb', '-g3', '-Wall', '-Werror']
CCFLAGS_DEBUG = ['-g']
CCFLAGS_MACBUNDLE = ['-fPIC']
CCFLAGS_RELEASE = ['-O2']
CCLNK_SRC_F = ''
CCLNK_TGT_F = ['-o', '']
CC_NAME = 'gcc'
CC_SRC_F = ''
CC_TGT_F = ['-c', '-o', '']
CC_VERSION = ('4', '4', '7')
COMPILER_CC = 'gcc'
COMPILER_CXX = 'g++'
CPP = '/usr/bin/cpp'
CPPPATH_ST = '-I%s'
CXX = ['g++-4.4']
CXXDEFINES_ST = '-D%s'
CXXFLAGS = ['-Wall']
CXXFLAGS_DEBUG = ['-g']
CXXFLAGS_RELEASE = ['-O2']
CXXLNK_SRC_F = ''
CXXLNK_TGT_F = ['-o', '']
CXX_NAME = 'gcc'
CXX_SRC_F = ''
CXX_TGT_F = ['-c', '-o', '']
DEST_BINFMT = 'elf'
DEST_CPU = 'x86_64'
DEST_OS = 'linux'
FULLSTATIC_MARKER = '-static'
LIBPATH_ST = '-L%s'
LIB_ST = '-l%s'
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINK_CC = ['/usr/bin/gcc']
LINK_CXX = ['g++-4.4']
NS3_ACTIVE_VARIANT = 'debug'
NS3_BUILDDIR = '/proj/expeditus/ns-allinone-3.10/ns-3.10/build'
NS3_OPTIONAL_FEATURES = []
PKG_CONFIG = ''
PREFIX = '/usr/local'
RANLIB = '/usr/bin/ranlib'
RPATH_ST = '-Wl,-rpath,%s'
SHLIB_MARKER = '-Wl,-Bdynamic'
SONAME_ST = '-Wl,-h,%s'
STATICLIBPATH_ST = '-L%s'
STATICLIB_MARKER = '-Wl,-Bstatic'
STATICLIB_ST = '-l%s'
macbundle_PATTERN = '%s.bundle'
program_PATTERN = '%s'
shlib_CCFLAGS = ['-fPIC', '-DPIC']
shlib_CXXFLAGS = ['-fPIC', '-DPIC']
shlib_LINKFLAGS = ['-shared']
shlib_PATTERN = 'lib%s.so'
staticlib_LINKFLAGS = ['-Wl,-Bstatic']
staticlib_PATTERN = 'lib%s.a'
