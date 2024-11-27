# hello-world-cmake

a simple project to help me better understand cmake

## issues

<a id="issues"></a>

using the below cmake command the current 0.21.2 release of freecad is unable to locate certain header files from a homebrew installation, ie.

```
#include <xercesc/util/XercesDefs.hpp>
```

and

```
<GL/glu.h>
```

## todos

<a id="todos"></a>

- [ ] need to incorporate a basic usage with xerces-c
- [ ] need to setup a formula file in my homebrew tap ie. ipatch/us-05 that builds this project

## working with cmake via CLI

when building this project from a cli i use the below cmake command, with the idea that i am going to manually specify, the required cmake variables via the cli. my primary reason for doing this is because homebrew installs qt v5 and qt v6 in the same install prefix thus making it next to impossible to isolate and use a specific qt installation. 

```
export bp=$(brew --prefix)

```shell
cmake \
-GNinja \
-DCMAKE_MAKE_PROGRAM=$bp/opt/ninja/bin/ninja \
-DCMAKE_C_COMPILER=$bp/opt/llvm/bin/clang \
-DCMAKE_CXX_COMPILER=$bp/opt/llvm/bin/clang \
-DCMAKE_LINKER=$bp/opt/llvm/bin/lld \
-DCMAKE_FIND_USE_CMAKE_SYSTEM_PATH=FALSE \
-DCMAKE_FIND_USE_SYSTEM_ENVIRONMENT_PATH=FALSE \
-DCMAKE_IGNORE_PATH="/home/capin/homebrew/lib;/home/capin/homebrew/include/QtCore;/home/capin/homebrew/Cellar/qt;" \
..
```
