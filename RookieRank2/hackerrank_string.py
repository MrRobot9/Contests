def isHackerrankInString(miniString, mainString, m, n):
    index = 0
    for i in miniString:
        index = mainString.find(i, index) + 1
        if index == 0 : return False
    return True

miniString = "hackerrank"
t = int(raw_input())
while t > 0:
    mainString = raw_input()
    m = len(miniString)
    n = len(mainString)
    if isHackerrankInString(miniString, mainString, m, n):
        print "YES"
    else:
        print "NO"
    t = t -1
