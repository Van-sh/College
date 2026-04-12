% Start the game
start :-
    Board = [' ',' ',' ',' ',' ',' ',' ',' ',' '],
    play(Board, x).

% Display board
display([A,B,C,D,E,F,G,H,I]) :-
    write(A), write(' | '), write(B), write(' | '), write(C), nl,
    write('---------'), nl,
    write(D), write(' | '), write(E), write(' | '), write(F), nl,
    write('---------'), nl,
    write(G), write(' | '), write(H), write(' | '), write(I), nl.

% Game loop
play(Board, Player) :-
    display(Board),
    (
        win(Board, x) -> write('Player X wins!'), nl, !;
        win(Board, o) -> write('Player O wins!'), nl, !;
        full(Board) -> write('Game Draw!'), nl;
        write('Player '), write(Player), write(', enter position (1-9): '),
        read(Pos),
        (
            move(Board, Pos, Player, NewBoard) ->
            switch(Player, Next),
            play(NewBoard, Next)
            ;
            play(Board, Player)
        )
    ).

% Switch player
switch(x, o).
switch(o, x).

% Valid move
move(Board, Pos, Player, NewBoard) :-
    Pos >= 1, Pos =< 9,
    nth1(Pos, Board, ' '),
    replace(Board, Pos, Player, NewBoard), !.

% Invalid move
move(_, _, _, _) :-
    write('Invalid move! Try again.'), nl,
    fail.

% Replace element
replace([_|T], 1, X, [X|T]).
replace([H|T], Pos, X, [H|R]) :-
    Pos > 1,
    Pos1 is Pos - 1,
    replace(T, Pos1, X, R).

% Win conditions
win([A,A,A,_,_,_,_,_,_], A) :- A \= ' '.
win([_,_,_,A,A,A,_,_,_], A) :- A \= ' '.
win([_,_,_,_,_,_,A,A,A], A) :- A \= ' '.
win([A,_,_,A,_,_,A,_,_], A) :- A \= ' '.
win([_,A,_,_,A,_,_,A,_], A) :- A \= ' '.
win([_,_,A,_,_,A,_,_,A], A) :- A \= ' '.
win([A,_,_,_,A,_,_,_,A], A) :- A \= ' '.
win([_,_,A,_,A,_,A,_,_], A) :- A \= ' '.

% Full board
    full([]).
    full([H|T]) :- H \= ' ', full(T).