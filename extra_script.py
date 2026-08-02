import os, shutil
Import("env")

env.Replace(COMPILATIONDB_INCLUDE_TOOLCHAIN=True)
env.Replace(COMPILATIONDB_PATH=os.path.join("$BUILD_DIR", "compile_commands.json"))

# Copy lv_conf.h next to the lvgl folder
_src = os.path.join(env.subst("$PROJECT_DIR"), "include", "lv_conf.h")
_dst_dir = os.path.join(env.subst("$PROJECT_LIBDEPS_DIR"), env["PIOENV"])
_dst = os.path.join(_dst_dir, "lv_conf.h")
if os.path.isfile(_src) and os.path.isdir(_dst_dir):
    shutil.copy2(_src, _dst)
