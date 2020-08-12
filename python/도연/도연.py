import turtle
import time
t = turtle.Pen()    # 터틀펜 이용을 위해 선언 
s = turtle.Screen() # 터틀 스크린 창 이동을 위해 선언

def draw(x,y):          #goto를 클릭 모듈에 넣기 위해 함수화 
    t.up()              #위치 변경 중 그려지지 않게 펜 올림.
    t.goto(x,y)

def drawblack():        #원을 그려서 남은 부분을 검은색으로 채움
    t.goto(0,0)         #중앙으로 이동
    i = 0
    for i in range(460):#450번 움직이게해서 남은 공간 다 채우게 함.(프랙탈 + 전체화면 가정시)
        t.fd(10+3*i)    #선을 계속 그림
        t.left(89.5)
    
def hclick():   #1입력시 함수 실행
    s.onscreenclick(draw)   #마우스 클릭한 위치로 원 이동
    while 1:
        Stop = int(input("위치 조정 후 0을 입력하시면 위치를 고정합니다."))
        if Stop == 0:
            x = t.xcor()    #원위치로 돌아가기 위해 사용
            y = t.ycor()
            break
        else:
            print("")
    t.down()
    t.fd(600)
    for i in range(1,7):
        t.rt(90)
        t.fd(50)
        t.rt(90)
        t.fd(600)
        t.lt(90)
        t.fd(50)
        t.lt(90)
        t.fd(600)
    t.goto(x,y)         #제자리로 돌아감 
    drawblack()         #남은 공간 채우기 함수 실행
    select() 
    
def vclick():   #2입력시 함수 실행
    s.onscreenclick(draw)   #마우스 클릭한 위치로 원 이동
    while 1:
        Stop = int(input("위치 조정 후 0을 입력하시면 위치를 고정합니다."))
        if Stop == 0:
            x = t.xcor()    #원위치로 돌아가기 위해 사용
            y = t.ycor()
            break
        else:
            print("")
    t.down()
     
    for i in range(1,8):
        t.rt(90)
        t.fd(600)
        t.lt(90)
        t.fd(50)
        t.lt(90)
        t.fd(600)
        t.rt(90)
        t.fd(50)
    t.goto(x,y)          #제자리로 돌아감 
    drawblack()          #남은 공간 채우기 함수 실행
    select()
    
def zclick():   #3입력시 함수실행
    s.onscreenclick(draw)   #마우스 클릭한 위치로 원 이동
    while 1:
        Stop = int(input("위치 조정 후 0을 입력하시면 위치를 고정합니다."))
        if Stop == 0:
            x = t.xcor()    #원위치로 돌아가기 위해 사용
            y = t.ycor()
            break
        else:
            print("")
    t.down()
     
    for i in range(1,6):
        t.fd(600)
        t.rt(170)
        t.fd(608.276)
        t.rt(190)
    t.goto(x,y)         #제자리로 돌아감
    drawblack()         #남은 공간 채우기 함수 실행
    select()
    
def select():       #1,2,3,값 이외의 값을 받았을 경우 재입력 받기 위해 함수 선언 
    answer = int(input("input h = 1 or v = 2 or z = 3(0=end):"))
    t.reset()
    t.shape("circle")   #모양은 원형으로
    t.width(50)         #그리는 두께(청소하는 두께는 50으로)
    t.color("black")    #청소된 부분의 색은 검정색으로 
    t.speed(0)          #스피드 가장 빠르게
    if answer == 1:
        hclick()
    elif answer == 2:
        vclick()
    elif answer == 3:
        zclick()
    elif answer == 0:
        print("5초 후 종료합니다.")
        time.sleep(5)
    else:
        print("옳지 않은 값을 입력하셨습니다. 입력을 다시 받습니다.")
        select()


select()            #선택함수실행 
