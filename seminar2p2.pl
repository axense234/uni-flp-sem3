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