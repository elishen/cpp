
s = input()

lst = s.split()
lstW = []
lstN = []

for w in lst: 
	if w.isdigit():
		lstN.append(w)
	else:
		lstW.append(w)

lstN.sort()
lstW.sort()

idxW = 0
idxN = 0

for w in lst:
	if w.isdigit():
		print(lstN[idxN], end=" ")
		idxN += 1
	else:
		print(lstW[idxW], end=" ")
		idxW += 1

print()
