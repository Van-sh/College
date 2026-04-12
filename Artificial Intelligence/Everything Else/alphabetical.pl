sort_sentence(Sentence, SortedSentence) :-
    atomic_list_concat(Words, ' ', Sentence),
    msort(Words, SortedWords),
    atomic_list_concat(SortedWords, ' ', SortedSentence).