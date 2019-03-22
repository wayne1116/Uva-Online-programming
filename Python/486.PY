while True:
    line=input()
    if line=='': break
    line1=line.split()
    mul=1
    if line1[0]=='negative': mul=-1
    sum1=0
    result=0
    for i in range(len(line1)):
        if line1[i]=='zero': sum1+=0
        elif line1[i]=='one': sum1+=1
        elif line1[i]=='two': sum1+=2
        elif line1[i]=='three': sum1+=3
        elif line1[i]=='four': sum1+=4
        elif line1[i]=='five': sum1+=5
        elif line1[i]=='six': sum1+=6
        elif line1[i]=='seven': sum1+=7
        elif line1[i]=='eight': sum1+=8
        elif line1[i]=='nine': sum1+=9
        elif line1[i]=='ten': sum1+=10
        elif line1[i]=='eleven': sum1+=11
        elif line1[i]=='twelve': sum1+=12
        elif line1[i]=='thirteen': sum1+=13
        elif line1[i]=='fourteen': sum1+=14
        elif line1[i]=='fifteen': sum1+=15
        elif line1[i]=='sixteen': sum1+=16
        elif line1[i]=='seventeen': sum1+=17
        elif line1[i]=='eighteen': sum1+=18
        elif line1[i]=='nineteen': sum1+=19
        elif line1[i]=='twenty': sum1+=20
        elif line1[i]=='thirty': sum1+=30
        elif line1[i]=='forty': sum1+=40
        elif line1[i]=='fifty': sum1+=50
        elif line1[i]=='sixty': sum1+=60
        elif line1[i]=='seventy': sum1+=70
        elif line1[i]=='eighty': sum1+=80
        elif line1[i]=='ninety': sum1+=90
        else:
            if line1[i]=='hundred': sum1*=100
            elif line1[i]=='thousand': sum1*=1000
            elif line1[i]=='million': sum1*=1000000
            result+=sum1
            sum1=0
    print((result+sum1)*mul)
    line1.clear()


