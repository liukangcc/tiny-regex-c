from building import *

cwd  = GetCurrentDir()
path = [cwd]

src = Split("""
re.c
""")

if GetDepend(['PKG_USING_REGEX_SAMPLE']):
    src += Glob('sample/test_expreession.c')
    src += Glob('sample/test_pattern.c')
    src += Glob('sample/test_performance.c')
    src += Glob('sample/test_rand.c')

group = DefineGroup('regex', src, depend = ['PKG_USING_REGEX'], CPPPATH = path)

Return('group')
