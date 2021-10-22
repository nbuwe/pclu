https://hg.sr.ht/~nbuwe/pclu

# Introduction

This repository has as its base the latest pclu release fetched from
ftp://ftp.lcs.mit.edu/pub/pclu/CLU/DEBIAN/pclu-debian.tar.gz

It didn't work b/c of what looks like a last minute 32/64-bit mixup.

I fixed it and cleaned it up to use C99, both in the "asm" C sources
and in the compiler output.  I took the liberty of reformatting the
"asm" C sources to use a more contemporary style.  Since the upstream
will probably never release any updates this should not be a problem I
hope and it hopefully makes life quite a bit easier for people used to
more modern C.

This is still a work in progress, but in the current state it should
have a good chance of working on any Unix where Boehm GC works.


# Building Boehm GC

pclu came with its own copy of Boehm GC sources.  It was stock gc-7.2f
with two trivial wrappers added, `clu_alloc_atomic()` and `clu_alloc()`.
These two wrappers are now moved to `code/sysasm/Opt/alloc.c` and we can
remove all gc includes from `pclu_sys.h`.

Unfortunately some C code still *does* peek into the gc internals so a
public installation of gc cannot be used.

Get a copy of gc-7.2f and configure it with something like:

    ./configure \
        --enable-static=yes --enable-shared=no \
        --enable-threads=no --with-libatomic-ops=no \
        --prefix=$CLUHOME/code/gc

Build it.  Making and running gctest is a good idea if you are on
something non-mainstream.  Run make install to get the headers in
`code/gc/include` the libraries in `code/gc/lib` (and some docs in
`code/gc/share/gc`).

Since the code needs private headers you then need to either create a
symlink `code/gc/include/private` that points to `gc-7.2f/include/private`
or create that directory and copy over the headers.

To avoid touching `-I` flags in the makefiles, at least for the initial
attempts, it might be handy to create a symlink:

    cd code/include && ln -s ../gc/include/gc

and, similarly, for the library:

    cd code && ln -s gc/lib/libgc.a


# Symlinks

To be able to run the compiler out of the workspace you will need some
symlinks in place.  I don't want to commit them, at least not yet, so
I've added top-level "symlinks" target.  Run

    make symlinks

once after checkout to set things up.  Among other things it takes
care of the symlinks for gc mentioned above.


# Bootstrapping the compiler

Check `howto.install` but bear in mind that some things might be out of
date or not work.  Makefiles need more updates and clean ups.  Here's
what I do for now:

    export CLUHOME=$PWD

    # build the libpclu_opt.a library
    cd $CLUHOME/code
    make -w OPT_FLAGS='-g -O0 -Wall -Wextra -Wno-unused-label -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-variable'

    # build the compiler from the pre-generated sources
    cd $CLUHOME/code/cmp
    make -w OPT_FLAGS='-g -O0 -Wall -Wextra -Wno-unused-label -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-variable'

    # dump clu libraries: lowlev.lib  misc.lib  useful.lib
    # (think precompiled headers)
    cd $CLUHOME/lib
    make libs

    # rebuild the compiler
    cd $CLUHOME/cmpclu
    make lib	# dump cmp.lib for the compiler sources
    make -w OPT_FLAGS='-g -O0 -Wall -Wextra -Wno-unused-label -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-variable'

    # rebuild the compiler again
    make -w OPT_FLAGS='-g -O0 -Wall -Wextra -Wno-unused-label -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-variable'

    # verify the output is the same (or, if you changed the compiler,
    # check the effect of your change)
    cd $CLUHOME/code/cmp
    hg diff .


# Debugger

Clu debugger is in-process and is compiled and linked directly into
the program.  It should now be in the state where it compiles and the
debug version of hello world can actually run.  Since debugger relies
on nm(1) to get the symbol addresses, it doesn't actually work b/c of
ASLR.  Need to tweak the debug code to compile in non-PIE mode.


# Random remarks

I've tested this procedure on Ubuntu/amd64 and NetBSD/macppc.

I have not yet tried a more recent version of gc (8.x).  The original
distribution had a rather old gc-7.2f.  It worked for me on Ubuntu, so
I stuck with it, upgrading to gc-7.2g eventually.

On NetBSD you will need to use gmake.  On my 8-STABLE macppc I could
only get gc-7.2g to work and only with `-O1`.

The common idiom to compile Clu to C but don't compile the C output is
to use `-ccopt 0` (bzw. `-ccdbg 0`).  What makes the magic value `0`
magic is ... its length.  See `cc_one` in top2.clu - it won't do
anything if the command length is less than 4.
