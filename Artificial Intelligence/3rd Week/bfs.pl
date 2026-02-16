edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(e, g).

bfs(Start, Path) :-
    bfs_queue([[Start]], Path).

bfs_queue([], []).
bfs_queue([[Node | PathToNode] | RemainingQueue], [Node | TotalPath]) :-
    findall([Neighbor, Node | PathToNode],
    (edge(Node, Neighbor), \+ member(Neighbor, [Node | PathToNode])),
    Neighbors),
    append(RemainingQueue, Neighbors, NewQueue),
    bfs_queue(NewQueue, TotalPath).
