solve(Cap1, Cap2, Goal) :-
    % State: (Amount in Jug1, Amount in Jug2)
    path((0, 0), (Cap1, Cap2), Goal, [(0, 0)], Path),
    print_path(Path).

path((Goal, _), _, Goal, Path, Path).
path((_, Goal), _, Goal, Path, Path).

path(CurrentState, Capacities, Goal, Visited, TotalPath) :-
    next_state(CurrentState, Capacities, NextState),
    \+ member(NextState, Visited), % Avoid infinite loops
    path(NextState, Capacities, Goal, [NextState | Visited], TotalPath).

% --- Possible Moves ---
% 1. Fill Jug 1
next_state((_, J2), (C1, _), (C1, J2)).

% 2. Fill Jug 2
next_state((J1, _), (_, C2), (J1, C2)).

% 3. Empty Jug 1
next_state((_, J2), _, (0, J2)).

% 4. Empty Jug 2
next_state((J1, _), _, (J1, 0)).

% 5. Pour Jug 1 into Jug 2 (until J2 is full)
next_state((J1, J2), (_, C2), (NJ1, C2)) :-
    J1 + J2 >= C2,
    NJ1 is J1 - (C2 - J2).

% 6. Pour Jug 1 into Jug 2 (until J1 is empty)
next_state((J1, J2), (_, C2), (0, NJ2)) :-
    J1 + J2 < C2,
    NJ2 is J1 + J2.

% 7. Pour Jug 2 into Jug 1 (until J1 is full)
next_state((J1, J2), (C1, _), (C1, NJ2)) :-
    J1 + J2 >= C1,
    NJ2 is J2 - (C1 - J1).

% 8. Pour Jug 2 into Jug 1 (until J2 is empty)
next_state((J1, J2), (C1, _), (NJ1, 0)) :-
    J1 + J2 < C1,
    NJ1 is J1 + J2.

print_path([]).
print_path([H|T]) :-
    print_path(T),
    format('State: ~w~n', [H]).