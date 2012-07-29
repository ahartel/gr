
def options(opt):
    opt.load('compiler_cxx')

def configure(conf):
    conf.load('compiler_cxx')

    conf.env.LIB_GL = ['glut','GL','GLU']

    conf.env.GAME_SOURCE = [
        'source/game.cpp',
        'source/world.cpp',
        'source/section.cpp',
        'source/player.cpp',
    ]

def build(bld):
    bld.program(
        target='gr',
        source=bld.env.GAME_SOURCE,
        use='GL',
		cxxflags='-std=c++0x',
    )
