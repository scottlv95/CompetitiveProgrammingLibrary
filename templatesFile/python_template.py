import sys
input = sys.stdin.readline

# 1) inp — For taking integer inputs.

# 2) inlt — For taking List inputs.

# 3) insr — For taking string inputs. Actually it returns a List of Characters, instead of a string, which is easier to use in Python, because in Python, Strings are Immutable.

# 4) invr — For taking space seperated integer variable inputs.
############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))

    
def solve():
    pass 

if __name__ == "__main__":
    tc = inp()
    for _ in range(tc):
        solve() 
    