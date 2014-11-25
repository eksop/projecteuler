#!/usr/bin/ruby

def solution
  arr = get_unique(100, 100)
  puts arr.count
end

def get_unique(a, b)
  $val = []
  for i in 2..a
    for j in 2..b
      n = i**j
      $val << n
    end
  end
  return $val.uniq.sort
end

$Main
solution
