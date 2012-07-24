
def options(opt):
    opt.load('compiler_cxx')

def configure(conf):
    conf.load('compiler_cxx')

    conf.env.LIB_GLUT = ['glut']

def build(bld):
    bld.program(
        target='gr',
        source=['game.cpp','world.cpp','section.cpp','player.cpp'],
        use='GLUT',
    )
