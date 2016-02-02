#!/usr/bin/ruby

$sum=0

for $i in 1..999
  $sum += $i if (($i % 5 == 0) or ($i % 3 == 0))
end

puts $sum
