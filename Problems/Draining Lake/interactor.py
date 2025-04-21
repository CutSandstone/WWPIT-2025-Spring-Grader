import subprocess
import sys
debug = False

inp = sys.stdin.read().splitlines()
n = int(inp[0])
inp = inp[1:]
while len(inp[-1]) == 0:
    inp = inp[:-1]
cmd = sys.argv[1].split()
runner = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, bufsize=1)
runner.stdin.write(str(len(inp))+"\n")
if debug:print("Interactor:",str(len(inp)))
runner.stdin.flush()
for i in inp:
    x,y = map(int,i.split())
    runner.stdin.write(str(n)+"\n")
    runner.stdin.flush()
    if debug:print("Interactor:",str(n))
    for j in range(n+2):
        if j == n+1:
            exit(1)
        line = runner.stdout.readline()
        if debug:print("Submission:",line,end="")
        line = line.split()
        assert len(line) == 3 and line[0] in "!?"
        rx = int(line[1])
        ry = int(line[2])
        assert 1 <= rx <= n and 1 <= ry <= n
        if line[0] == '!':
            assert rx == x and ry == y
            break
        elif abs(rx-x)+abs(ry-y) <= j:
            runner.stdin.write("0\n")
            if debug:print("Interactor: 0")
        else:
            runner.stdin.write("1\n")
            if debug:print("Interactor: 1")
        runner.stdin.flush()
