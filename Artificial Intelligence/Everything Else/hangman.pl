% Start the game
start :-
    Word = [t,e,s,t],
    length(Word, Len),
    create_hidden(Len, Hidden),
    play(Word, Hidden, 6).

% Create hidden word
create_hidden(0, []).
create_hidden(N, ['_'|T]) :-
    N > 0,
    N1 is N - 1,
    create_hidden(N1, T).

% Game over case
play(_, _, 0) :-
    write('Game Over! You ran out of attempts.'), nl.

% Main game loop
play(Word, Hidden, Attempts) :-
    Attempts > 0,
    write('Word: '), write(Hidden), nl,
    write('Attempts left: '), write(Attempts), nl,
    write('Enter a letter: '),
    read(Guess),
    update_word(Word, Hidden, Guess, NewHidden),
    (
        Hidden \= NewHidden ->
        write('Correct guess!'), nl,
        NewAttempts = Attempts
        ;
        write('Wrong guess!'), nl,
        NewAttempts is Attempts - 1
    ),
    (
        NewHidden = Word ->
        write('Congratulations! You guessed the word.'), nl
        ;
        play(Word, NewHidden, NewAttempts)
    ).

% Update word
update_word([], [], _, []).
update_word([H|T], [_|T1], Guess, [H|T2]) :-
    H = Guess,
    update_word(T, T1, Guess, T2).
update_word([H|T], [H1|T1], Guess, [H1|T2]) :-
    H \= Guess,
    update_word(T, T1, Guess, T2). 