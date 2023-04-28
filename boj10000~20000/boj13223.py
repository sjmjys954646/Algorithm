h,m,s = map(int,input().split(':'))
eh,em,es = map(int,input().split(':'))

ans = eh * 3600 + em * 60 + es - h*3600 - 60*m-s
if(ans <= 0) :
    ans += 86400
eh = ans // 3600
ans = ans % 3600
em = ans // 60
es = ans % 60

if eh < 10 :
    eh = "0" + str(eh)
if em < 10:
    em = "0" + str(em)
if es < 10:
    es = "0" + str(es)

print(f"{eh}:{em}:{es}")
