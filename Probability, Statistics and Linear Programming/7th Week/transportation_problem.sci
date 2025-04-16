C = [
   19 30 50
   70 30 40
   40 8 70
]
supply = [7 9 18]
demand = [5 8 11]
total_supply = sum(supply)
total_demand = sum(demand)
if total_supply > total_demand then
   demand = [demand, total_supply - total_demand]
   C = [C, zeros(3, 1)]
elseif total_demand > total_supply then
   supply = [supply, total_demand - total_supply]
   C = [C, zeros(1, size(C, 2))]
end
[m, n]= size(C)
X = zeros(m, n)
i = 1
j = 1
s = supply
d = demand
while i <= m & j <= n
   alloc = min(s(i), d(j))
   X(i, j) = alloc
   s(i) = s(i) - alloc
   d(j) = d(j) - alloc
   if s(i) == 0 then
      i = i + 1;
   elseif d(j) == 0 then
      j = j + 1
   end
end
disp("Initial basic Feasible Solution using NWCR")
disp(X)
while %t
   u = zeros(1, m)
   v = zeros(1, n)
   u(:) = %nan
   v(:) = %nan
   u(1) = 0
   for k = 1:100
      for i = 1:m
         for j = 1:n
            if X(i, j) > 0 then
               if ~isnan(u(i)) & isnan(v(j)) then
                  v(j) = C(i, j) - u(i)
               elseif isnan(u(i)) & ~isnan(v(j)) then
                  u(i) = C(i, j) - v(j)
               end
            end
         end
      end
   end
   delta = C - (u' * ones(1, n) + ones(m, 1) * v)
   if min(min(delta)) >= 0 then
      break;
   else
      [mini, minj] = find(delta == min(min(delta)))
      i = mini(1); j = minj(1)
      path = X
      path(i, j) = -1
      rows = find(path(:, j) > 0)
      cols = find(path(i, :) > 0)
      theta = []
      for r = 1:length(rows)
         for c = 1:length(cols)
            if path(rows(r), cols(c)) > 0 then
               theta = [theta, X(rows(r), cols(c))]
            end
         end
      end
      min_theta = min(theta)
      for r = 1:m
         for c = 1:n
            if path(r, c) < 0 then
               X(r, c) = X(r, c) + min_theta
            elseif path(r, c) > 0 then
               X(r, c) = X(r, c) - min_theta
            end
         end
      end
   end
end
disp("Optimal Transportation Table: ")
disp(X)
min_cost = sum(sum(C .* X))
printf("Total Minimum Transportation Cost: %d", min_cost)
