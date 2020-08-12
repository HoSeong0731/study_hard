import turtle
image = "C:/236139172236138168.gif" #파일위치,파일이름,파일형식(지원형식:gif)
screen = turtle.Screen()            #스크린 변수 생성 
screen.setup(350,350)               #터틀펜 창 크기 지정
screen.addshape(image)              #터틀펜 모양에 이미지 변수 추가 
turtle.shape(image)                 #모양을 이미지로
