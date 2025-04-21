import json
import subprocess
import random
import os
def compile(inp: str):
    print(inp)
    if not os.path.exists("compile/map.json"):
        if not os.path.exists("compile"):
            os.mkdir("compile")
        json.dump({}, open("compile/map.json", "w"))
    mp = json.load(open("compile/map.json"))
    if inp.endswith(".py"):
        return "python3 " + inp
    txt = open(inp).read()
    if txt not in mp:
        fname = "".join([chr(random.randint(ord('a'), ord('z'))) for i in range(10)])
        fname = f"compile/{fname}"
        compile = subprocess.run(["g++", inp, "-O2", "-o", fname, "-I", "lib", "-x", "c++"])
        if compile.returncode != 0:
            print("BUHBUHBUHB")
            return ""
        mp[txt] = "./" + fname
        json.dump(mp, open("compile/map.json", "w"))
    return mp[txt]
