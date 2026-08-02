import os, shutil
Import("env")

env.Replace(COMPILATIONDB_INCLUDE_TOOLCHAIN=True)
env.Replace(COMPILATIONDB_PATH=os.path.join("$BUILD_DIR", "compile_commands.json"))

_include = os.path.join(env.subst("$PROJECT_DIR"), "include")
_libdeps = os.path.join(env.subst("$PROJECT_LIBDEPS_DIR"), env["PIOENV"])

# Copy lv_conf.h next to the lvgl folder (../../lv_conf.h relative to lvgl/src/)
_src = os.path.join(_include, "lv_conf.h")
_dst = os.path.join(_libdeps, "lv_conf.h")
if os.path.isfile(_src) and os.path.isdir(_libdeps):
    shutil.copy2(_src, _dst)

# Copy userSetup.h into the TFT_eSPI library as User_Setup.h
_src = os.path.join(_include, "userSetup.h")
_dst = os.path.join(_libdeps, "TFT_eSPI", "User_Setup.h")
if os.path.isfile(_src) and os.path.isdir(os.path.dirname(_dst)):
    shutil.copy2(_src, _dst)
