import subprocess
import sys
import os
import json
langs = ['C++11', 'C++17', 'C++20', 'C++23', 'C11', 'PyPy7.3.17', 'Python3.12.3', 'Java8', 'Java11', 'Java17', 'Java21']
def process_submission(code, lang, problem, tl):
    #code: path to source code
    #lang: language (see database schema)
    #problem: problem name
    #tl: time limit (seconds)

    if lang not in langs:
        raise Exception('Language not supported')

    #returns if it passes the test cases
    if not os.path.exists(f"Problems/{problem}"):
        return False
    if code.endswith(".py"):
        code = "python3 " if lang == "Python3.12.3" else "pypy3 " + code
    elif code.endswith(".cpp"):
        compile = subprocess.run(["g++", code, "-O2", "-static", "-std="+lang.lower()])
        if compile.returncode != 0:
            return False
        code = "./a.out"
    elif code.endswith(".java"):
        compile = subprocess.run(["javac", code, "--release", lang[4:]])
        if compile.returncode != 0:
            return False
        code = "java " + code[:-5]
    else:
        return False
    interactor = ""
    solution = ""
    checker = ""
    generator = ""
    from compile import compile as compileCode
    for i in os.listdir(f"Problems/{problem}"):
        if i.startswith("interactor"):
            interactor = compileCode(f"Problems/{problem}/{i}")
        if i.startswith("solution") and not i.endswith(".java"):
            solution = compileCode(f"Problems/{problem}/{i}")
        if i.startswith("checker"):
            checker = compileCode(f"Problems/{problem}/{i}")
        if i.startswith("generator"):
            generator = compileCode(f"Problems/{problem}/{i}")
    tcs = json.load(open(f"Problems/{problem}/testcases.json"))
    for tc in tcs:
        inp = tc["input"]
        if inp.startswith("%%"):
            inp = inp[inp.find(':')+1:]
            inp = inp.split(",")
            inp = subprocess.run([*generator.split(), *inp], text=True, capture_output=True).stdout
        if interactor == "":
            real = subprocess.run(solution.split("  "), text=True, input=inp, capture_output=True).stdout
            try:
                sub = subprocess.run(code.split(), text=True, input=inp, timeout=tl, capture_output=True).stdout
            except:
                return False
            if checker == "":
                if real.strip().split() != sub.strip().split():
                    return False
            else:
                with open("t1.txt", "w") as f:
                    f.write(inp)
                with open("t2.txt", "w") as f:
                    f.write(sub)
                with open("t3.txt", "w") as f:
                    f.write(real)
                c = subprocess.run([*checker.split("  "), "t1.txt", "t2.txt", "t3.txt"], text=True, capture_output=True).returncode
                os.remove("t1.txt")
                os.remove("t2.txt")
                os.remove("t3.txt")
                if c != 0:
                    return False
        else:
            try:
                c = subprocess.run([*interactor.split("  "), code], timeout=tl, capture_output=True, text=True, input=inp)
            except:
                return False
            if c.returncode != 0:
                return False
    return True
if __name__ == '__main__':
    print(process_submission(sys.argv[1],sys.argv[2],sys.argv[3], 5))
    os.remove("a.out")