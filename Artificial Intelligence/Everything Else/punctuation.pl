remove_punctuation(Input, Clean) :-string_chars(Input, Chars),
    include(is_alnum_or_space, Chars, CleanChars),
    string_chars(Clean, CleanChars).

is_alnum_or_space(Char) :-
    char_type(Char, alnum);
    char_type(Char, space).