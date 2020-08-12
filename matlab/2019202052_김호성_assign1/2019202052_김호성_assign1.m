%0단계: 값을 입력 받음 z는 나중에 후위증가로, A는 행렬을, B는 벡터를 받는다.
%i,I는 행렬과 벡터의 행값을, j와 J는 행력과 벡터의 열값을 의미한다.
%i값과 j값을 비교해 정사각행렬인지 검사한다.
z = 1;
A = input('Enter matrix A: '); % Matrix A 입력받음
B = input('Enter vector b: '); % Vector B 입력받음
[j i]=size(A);
if i == j
else
    '정사각 행렬이 아닙니다.'
    return;         
end
%1단계: (1,1)과 (m,m)의 값을 서로 바꾼다. (C에서 주로 사용한 방법)
temp =  A(1,1);
A(1,1) = A(i,j);    
A(i,j) = temp;
'1단계 출력'
A                  
%2단계: 마지막 열과 그 앞의 열 바꾸기(1단계에 for문 사용)
temp = i;           
for a=1: j
    temp(a) = A(a,i-1);
    A(a,i-1) = A(a,i);
    A(a,i) = temp(a);
end
'2단계 출력'
A                   
%3단계: 주 대각선에 1씩 더함(2단계 변형)
for a=1: i
    A(a,a) = A(a,a)+1;
end
'3단계 출력'
A                   
%4단계: 행렬 내적 계산 
%C의 크기를 맞추기 위해 zero로 한 번 초기화, 이후 0으로 다시 초기화(중복이지만, 확실하게 하기 위해)
C = zeros(j,i);
for x=1:j
    for y=1:i
        C(x,y)=0;
        for k=1:i
            C(x,y)=C(x,y)+A(x,k)*A(k,y);
        end
    end
end
A = C;
'4단계 출력'
A                 
%5단계 선형식 X 구하기 (벡터의 가장 긴 길이가 행렬의 행 길이와 다를 경우 error)
%else 중에 행 벡터 일 경우 전치시키고, linsolve함수 사용 
if i~=length(B)      
    '벡터의 지수와 행렬의 행 길이가 다릅니다.'  
    return;
else
    [J I]=size(B);      
    if I > J
        B = rot90(B,3);
    X=linsolve(C,B);
    end
end
A = X;
'5단계 출력'
A