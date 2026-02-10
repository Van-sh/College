centigrade_to_fahrenheit(C, F) :-
    F is (C * 9 / 5) + 32.
below_freezing(C) :-
    C < 0.
