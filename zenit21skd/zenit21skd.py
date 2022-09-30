list = [int(input()) for _ in range(int(input()))]
windows2 = [list[i: i + 2] for i in range(len(list) - 1)]   # dvojice technikou posuvneho okna
windows3 = [list[i: i + 3] for i in range(len(list) - 2)]   # trojice technikou posuvneho okna
down = sum(x[0] < x[1] for x in windows2)                   # zhorsenia
up = sum(x[0] > x[1] for x in windows2)                     # zlepsenia
stay = sum(x[0] < x[1] and x[1] > x[2] for x in windows3)   # vrcholy
print(up, down, stay)