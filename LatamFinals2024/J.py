import math

pi = 3.141592653589793

def comp(a, b):
    if a[0] == b[0]:
        return a[2] < b[2]
    else:
        return a[0] < b[0]

def main():
    t, n = map(int, input().split())
    
    a = [[0] * 3 for _ in range(n)]
    
    tangente = math.tan(t * pi / 180)
    
    x = 0.0
    h = 0.0
    catetoAdyacente = 0.0
    
    for i in range(n):
        x, h = map(float, input().split())
        catetoAdyacente = h / tangente
        a[i] = [x, h, catetoAdyacente]
    
    a.sort()

    reached = a[0][0]
    notCovered = 0.0
    
    if reached != 0:
        notCovered += reached
    
    newReach = 0.0
    for i in range(n):
        newReach = a[i][0] + a[i][2]
        if reached < a[i][0]:
            notCovered += a[i][0] - reached
        
        if newReach > reached:
            reached = newReach
    
    print(f"{reached - notCovered:.6f}")

if __name__ == "__main__":
    main()
