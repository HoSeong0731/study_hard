t = 0.01; %t값
Hz = 11;  %freq값
for i = 1:20    %t값을 열로
    for j = 1:20%freq값을 행으로 
        A(i,j)= cos(2*pi*Hz*t); %A값을 받는 과정
        Hz = Hz + 1; %후위증가
    end
    Hz = 11;      %반복문을 돌린 후 초기화
    t = t + 0.01; %후위증가
end
b=load("output.mat").output(:,1); %b값 불러오기

x = slv(A,b);   % slv함수 실행 

function [L,U,b] = slu(A,b) % L(하삼각행렬)과 U(상삼각행렬)값을 반환하는 함수 
    [n,n] = size(A);        % 행렬의 사이즈 값을 구한다.
    tol = 1.e-6;            % 0에 가까운 양수 값을 대입한다.
    for k = 1:n             % 사이즈까지 반복한다. 
        if abs(A(k,k)) < tol    %주 대각선 값에 절댓값을 취한 값이 0이면
             for a = k+1 : n            % a가 k+1부터 n이 될 때까지
                if abs(A(a,k)) > tol    % 피벗이 0이 아니면
                    temp=A(k,:);        % 행렬의 값 교환 
                    A(k,:)=A(a,:);      % C의 정렬알고리즘 응용 
                    A(a,:)=temp;        % C의 정렬알고리즘 응용 
                    temp2=b(k);         % 열벡터도 같이 교환 
                    b(k)=b(a);          % C의 정렬알고리즘 응용 
                    b(a)=temp2;         % C의 정렬알고리즘 응용 
                    break;              % if문 탈출
                end
             end
        end                         
        L(k,k) = 1;                 % 하삼각행렬의 주대각선에 1을 넣음 
        for i = k+1 : n             % 반복문의 조건 
            L(i,k) = A(i,k)/A(k,k); % K열에 대한 곱을 L에 넣는다.
            for j = k + 1:n         % 하삼각행렬의 조건에 맞게 계산한다. 
                A(i,j) = A(i,j) - L(i,k)*A(k,j);    %이 부분은 0이 된다. 
            end
        end
        for j = k:n             % 값이 나올 수 있는 범위들 
            U(k,j) = A(k,j);    % A = LU 이미 L을 만들고 온 것이므로 U로 옮김. 
        end
    end
end
function x = slv(A,b) % Solve Ax = b using L and U from slu(A).
    [L,U,b]=slu(A,b); % 하삼각행렬과 상삼각행렬의 값을 받아온다.
    s=0;              % 변수 초기화
    [n, n] = size(A); % 사이즈 값 전달.
    for k = 1:n       % Forward
        for j = 1:k-1 % 반복문 조건 
            s = s + L(k,j)*c(j);    % [L]{d} = {b}
        end
        c(k) = b(k) - s;    % c라는 새로운 행렬을 구함.
        s = 0;              % s값 초기화 
    end
    for k = n:-1:1          % backward
        t = 0;              % t값 초기화 
        for j =  k+ 1:n     % 역 치환 
            t = t + U(k,j)*x(j);    % [U]{x} = {d}
        end
        x(k) = (c(k) - t)/U(k,k);   % 피벗별로 나누기
    end
    
    disp('inv(A)*b 공식을 이용해 근을 구한 값')
    X = inv(A)*b;    %X값은 행렬곱셈의 역으로 구하기
    disp(X)                 %출력
    disp('LU분해법을 이용해 근을 구한 값')
    disp(x')       % x는 열 단위로 저장된 상태기 때문에, Transpose 해준 x' 출력
    disp('결론: 역행렬공식을 사용해 구한 값과 LU분해법을 사용해 구한 값이 같다.')
    disp('그래프는 다음과 같다.')
    subplot(1,2,1),plot(X,'-r'),title('inv(U)*inv(L)*b 공식을 이용해 근을 구한 값')    %X그래프
    subplot(1,2,2),plot(x,'-b'),title('LU분해법을 이용해 근을 구한 값')                %x그래프 
end