% sumac(l1l2...ln, Col)= Col, if n = 0
%						 sumac(l2l3...ln, Col + l1), if n > 0
%						 
% scmain(l1l2...ln) = sumac(l1l2...ln, 0)

% sumac(L - list, col - number, r - number)
% flow model (i, i, o) (i, i, i)
% 
% scmain(L - list, r - number)
% flow model (i, o) (i, i)


sumac([], Col, Col).
sumac([H|T], Col, R):-
    newCol is Col+H,
    sumac(T, newCol, R).

scmain(L, R):- sumac(L, 0, R).

% Count nb occurences with collector

% countCol(l1l2...ln, E, Col):
%	- Col, if l = {}
%   - countCol(l2l3...ln, E, Col + 1), if l1 = E
%	- countCol(l2l3...ln, E, Col), if l1 \= E
%

% flow model (i, i, i, o) (i, i, i, i)


countCol([], _, Col, Col).

countCol([H|T], E, Col, R):-
    H = E, !,
    newCol is Col + 1,
    countCol(T, E, newCol, R).

countCol([_|T], E, Col, R):-
    % H\=E,
    countCol(T, E, Col, R).

countColMain(L, E, R):- countCol(L, E, 0, R).


% Write a predicate to remove from a list of elements that appear only once

% ex. [1,2,1,4,1,3,4] -> [1,1,4,1,4]


% removeUniqueElem(l1l2...ln, c1c2...cn):
%	- [], if n = 0
%	- l1 U removeUniqueElem(l2...ln, c1c2...cn), if countCol(c1c2...cb, l1) > 1
%	- removeUniqueElem(l2...ln, c1c2...cn), otherwise
%	
%	
% removeMain(l1l2...ln) - removeUniqueElem(l1l2...ln, l1l2...ln)
%
%
%
%
% removeUniqueElem(L - list, C - copy list, R - result list)
% flow model (i, i, o)
% 
% 
% 
% 
% 
%

removeUniqueElem([], _, []).
removeUniqueElem([H|T], CL, [H|TR]):-
    countColMain(CL, H, N),
    N > 1,
    removeUniqueElem(T, CL, TR).

removeUniqueElem([H|T], CL, R):-
    countColMain(CL, H, 1), 
    removeUniqueElem(T, CL, R).

removeUniqueElemMain(L, R):-removeUniqueElem(L, L, R).
    

% removeUniqueCol(l1l2...ln, CL, Col):
%	- Col, if n = 0
%	- removeUniqueCol(l2l3...ln, CL, addEnd(Col, l1)),
%			if count(CL, l1)>1
%	- removeUniqueCol(l2...ln, Cl, Col), if count(Cl, l1)==1
%
%
%
%
%
%
%
%

addEnd([], E, [E]).
addEnd([H|T], E, [H|TR]):-
    addEnd(T, E, TR).

% removeUniqueCol(L-list, CL-copy list, Col - collector list, R - result list)
% (i, i, i, o)

removeUniqueCol([], _, Col, Col).

removeUniqueCol([H|T], CL, Col, R):-
    countColMain(CL, H, N),
    N > 1,
    addEnd(Col, H, newCol),
    removeUniqueCol(T, CL, newCol, R).

removeUniqueCol([H|T], CL, Col, R):-
    countColMain(CL, H, 1),
    removeUniqueCol(T, CL, Col, R).

removeCM(L, R):- removeUniqueCol(L, L, [], R).


    
    
    
    
    
    
    
    
    
    

